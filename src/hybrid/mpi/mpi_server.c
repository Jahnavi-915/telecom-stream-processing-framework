/**
 * @file mpi_server.c
 * @brief MPI server implementation.
 */

#include "../include/config.h"
#include "../include/mpi_server.h"
#include "../include/queue_interface.h"
#include "../include/serialization.h"

#include <mpi.h>
#include <stdio.h>
#include <string.h>

int initialize_server(int *argc, char ***argv)
{
    (void)argc;
    (void)argv;

    if (!initialize_queue_interface())
    {
        fprintf(stderr, "ERROR: Failed to initialize communication queue.\n");
        return -1;
    }

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

    printf("Received packet from Client %d\n",
       status.MPI_SOURCE);

    /* Deserialize packet */
    if (deserialize_packet(buffer,
                           sizeof(buffer),
                           packet) == 0)
    {
        fprintf(stderr, "ERROR: Packet deserialization failed.\n");
        return -1;
    }

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
    TelecomPacket processed_packet;

    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int total_clients = world_size - 1;
    int total_packets = total_clients * DEFAULT_PACKETS_PER_CLIENT;

    for (int i = 0; i < total_packets; i++)
    {
        /* Receive packet from client */
        if (receive_packet(&packet) != 0)
        {
            fprintf(stderr, "ERROR: Failed to receive packet.\n");
            return -1;
        }

        printf("\n========== SERVER : Packet %d ==========\n", i + 1);
        printf("Queue Size After Enqueue : %d\n",
               queue_size());

        /*
         * Simulate slower processing.
         * Process one packet after every PROCESSING_BATCH_SIZE packets.
         */
        if ((i + 1) % PROCESSING_BATCH_SIZE == 0)
        {
            if (!dequeue_packet(&processed_packet))
            {
                fprintf(stderr, "ERROR: Failed to dequeue packet.\n");
                return -1;
            }

            printf("Processed Packet %u\n",
                   processed_packet.packet_id);

            printf("Queue Size After Dequeue : %d\n",
                   queue_size());
        }
    }

    /* Process remaining packets before shutdown */
    while (!is_queue_empty())
    {
        if (!dequeue_packet(&processed_packet))
        {
            break;
        }

        printf("Processed Remaining Packet %u\n",
               processed_packet.packet_id);
    }

    return 0;
}

int finalize_server(void)
{
    destroy_queue_interface();
    printf("MPI Server finalized.\n");

    return 0;
}