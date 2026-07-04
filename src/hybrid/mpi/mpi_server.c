/**
 * @file mpi_server.c
 * @brief MPI server implementation.
 */

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

    printf("MPI Server initialized.\n");

    return 0;
}

int receive_packet(TelecomPacket *packet)
{
    char buffer[sizeof(TelecomPacket)];
    int status;

    if (packet == NULL)
    {
        fprintf(stderr, "ERROR: Invalid packet pointer.\n");
        return -1;
    }

    /* Receive serialized packet from any client */
    status = MPI_Recv(buffer,
                      sizeof(buffer),
                      MPI_BYTE,
                      MPI_ANY_SOURCE,
                      MPI_ANY_TAG,
                      MPI_COMM_WORLD,
                      MPI_STATUS_IGNORE);

    if (status != MPI_SUCCESS)
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

    /* Forward packet to processing layer */
    enqueue_packet(packet);

    printf("Server: Packet %u received successfully.\n",
       packet->packet_id);

    return 0;
}

int run_server(void)
{
    TelecomPacket packet;

    if (receive_packet(&packet) != 0)
    {
        fprintf(stderr, "ERROR: Failed to receive packet.\n");
        return -1;
    }

    printf("\n===== Received Packet =====\n");

    print_packet(&packet);

    return 0;
}

int finalize_server(void)
{
    printf("MPI Server finalized.\n");

    return 0;
}