/**
 * @file mpi_server.c
 * @brief MPI server implementation.
 */

#include "../include/config.h"
#include "../include/mpi_server.h"
#include "../include/queue_interface.h"
#include "../include/serialization.h"
#include "../processing/worker_pool.h"
#include "../database/berkeley_db.h"
#include "../graph/graph.h"

#include <mpi.h>
#include <stdio.h>
#include <string.h>

static WorkerPool processing_pool;
Graph telecom_graph;

int initialize_server(int *argc, char ***argv)
{
    (void)argc;
    (void)argv;

    if (!initialize_queue_interface())
    {
        fprintf(stderr, "ERROR: Failed to initialize communication queue.\n");
        return -1;
    }

    if (worker_pool_init(&processing_pool,
                     get_communication_buffer(),
                     4) != 0)
    {
        fprintf(stderr, "ERROR: Failed to initialize worker pool.\n");
        return -1;
    }

    if (worker_pool_start(&processing_pool) != 0)
    {
        fprintf(stderr, "ERROR: Failed to start worker pool.\n");
        return -1;
    }

    if (db_initialize("telecom.db") != 0)
    {
        fprintf(stderr, "ERROR: Failed to initialize Berkeley DB.\n");
        return -1;
    }

    initialize_graph(&telecom_graph);

    printf("MPI Server initialized.\n");

    return 0;
}

int receive_packet(TelecomPacket *packet)
{
    char buffer[sizeof(TelecomPacket)];
    MPI_Status status;
    int mpi_status;

    if (packet == NULL)
    {
        fprintf(stderr, "ERROR: Invalid packet pointer.\n");
        return -1;
    }

    /* Receive serialized packet from any client */
    mpi_status =  MPI_Recv(buffer,
                      sizeof(buffer),
                      MPI_BYTE,
                      MPI_ANY_SOURCE,
                      MPI_ANY_TAG,
                      MPI_COMM_WORLD,
                      &status);

    if (mpi_status != MPI_SUCCESS)
    {
        fprintf(stderr, "ERROR: Failed to receive packet.\n");
        return -1;
    }

    /* Deserialize packet */
    if (deserialize_packet(buffer,
                           sizeof(buffer),
                           packet) == 0)
    {
        fprintf(stderr, "ERROR: Packet deserialization failed.\n");
        return -1;
    }

    #if ENABLE_PACKET_LOGGING
        printf("Received Packet %u from DES-%u (MPI Rank %d)\n",
        packet->packet_id,
        packet->des_id,
        status.MPI_SOURCE);
    #endif

    /* Forward packet to processing layer */
    if (!enqueue_packet(packet))
    {
        fprintf(stderr, "ERROR: Failed to enqueue packet.\n");
        return -1;
    }


    return 0;
}

int run_server(void)
{
    TelecomPacket packet;

    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int total_des = world_size - 1;
    int total_packets = total_des * DEFAULT_PACKETS_PER_CLIENT;

    /* Start performance timer */
    double start_time = MPI_Wtime();

    for (int i = 0; i < total_packets; i++)
    {
        /* Receive packet from client */
        if (receive_packet(&packet) != 0)
        {
            fprintf(stderr, "ERROR: Failed to receive packet.\n");
            return -1;
        }

        #if ENABLE_PACKET_LOGGING
        printf("\n========== SERVER : Packet %d ==========\n", i + 1);
        printf("Queue Size After Enqueue : %d\n",
               queue_size());
        #endif
    }

    double end_time = MPI_Wtime();

    while (total_packets_dequeued() < total_packets_enqueued())
    {
        struct timespec ts = {0, 1000000}; // 1 ms
        nanosleep(&ts, NULL);
    }

    double execution_time = end_time - start_time;
    double throughput = (double) total_packets / execution_time;
    double average_time = execution_time / total_packets;

    printf("\n");
    printf("========== PERFORMANCE SUMMARY ==========\n");
    printf("Data Extraction Servers : %d\n", total_des);
    printf("Packets Per DES         : %d\n", DEFAULT_PACKETS_PER_CLIENT);
    printf("Total Packets           : %d\n", total_packets);
    printf("Execution Time          : %.6f seconds\n", execution_time);
    printf("Average Time/Packet     : %.6f ms\n", average_time * 1000);
    printf("Throughput              : %.2f packets/second\n", throughput);
    printf("Maximum Queue Size      : %d\n", max_queue_size());
    printf("Packets Enqueued        : %d\n", total_packets_enqueued());
    printf("Packets Dequeued        : %d\n", total_packets_dequeued());
    printf("=========================================\n");

    return 0;
}

int finalize_server(void)
{
    worker_pool_stop(&processing_pool);

    worker_pool_destroy(&processing_pool);

    TelecomPacket retrieved_packet;
    uint32_t packet_id;

    while (1)
    {
        printf("\n========== DATABASE QUERY ==========\n");
        printf("Enter Packet ID to retrieve (1-%d) (0 to exit): ",
            total_packets_enqueued());
        fflush(stdout);

        if (scanf("%u", &packet_id) != 1)
        {
            fprintf(stderr, "Invalid input.\n");
            break;
        }

        if (packet_id == 0)
            break;

        if (packet_id > (uint32_t)total_packets_enqueued())
        {
            printf("Packet ID must be between 1 and %d.\n",
                total_packets_enqueued());
            continue;
        }

        if (db_get_packet(packet_id, &retrieved_packet) == 0)
        {
            printf("\n========== DATABASE QUERY RESULT ==========\n");
            printf("Packet ID    : %u\n", retrieved_packet.packet_id);
            printf("DES ID       : %u\n", retrieved_packet.des_id);
            printf("Source       : %s\n", retrieved_packet.source);
            printf("Destination  : %s\n", retrieved_packet.destination);
            printf("Traffic Type : %s\n", retrieved_packet.traffic_type);
            printf("Priority     : %u\n", retrieved_packet.priority);
            printf("Packet Size  : %u\n", retrieved_packet.packet_size);
            printf("Timestamp    : %s\n", retrieved_packet.timestamp);
            printf("===========================================\n");
        }
    }

    printf("\n");
    print_graph(&telecom_graph);

    print_graph_statistics(&telecom_graph);

    printf("\n========== GRAPH ANALYTICS ==========\n");

    printf("Total Communication Volume : %u packets\n",
        total_communication_volume(&telecom_graph));

    GraphVertex *active = most_active_source(&telecom_graph);

    if (active != NULL)
    {
        printf("Most Active Source Tower  : %s\n",
            active->node_name);
    }

    GraphVertex *destination =
    most_active_destination(&telecom_graph);

    if (destination != NULL)
    {
        printf("Most Active Destination Tower : %s\n",
            destination->node_name);
    }

    TopCommunicationLink top =
    get_top_communication_link(&telecom_graph);

    printf("Top Communication Link     : %s -> %s (%u packets)\n",
        top.source,
        top.destination,
        top.weight);

    printf("=====================================\n");

    printf("\n========== NODE DEGREES ==========\n");

GraphVertex *vertex = telecom_graph.vertices;

while (vertex != NULL)
{
    printf("%-10s  Out:%2u  In:%2u\n",
           vertex->node_name,
           out_degree(&telecom_graph, vertex->node_name),
           in_degree(&telecom_graph, vertex->node_name));

    vertex = vertex->next;
}

printf("==================================\n");

    free_graph(&telecom_graph);

    db_close();
    destroy_queue_interface();

    printf("MPI Server finalized.\n");

    return 0;
}