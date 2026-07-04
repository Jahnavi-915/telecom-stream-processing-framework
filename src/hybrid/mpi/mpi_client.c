/**
 * @file mpi_client.c
 * @brief MPI Client implementation for the Hybrid Telecom Stream
 * Processing Framework.
 */

#include "../include/mpi_client.h"
#include "../include/config.h"
#include "../include/traffic_generator.h"
#include "../include/serialization.h"

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/* -------------------------------------------------------------------------- */
/*                         Private Helper Functions                           */
/* -------------------------------------------------------------------------- */

/**
 * @brief Send serialized packet to MPI server.
 */
static int transmit_packet(const TelecomPacket *packet);

/* -------------------------------------------------------------------------- */
/*                           Public API Functions                             */
/* -------------------------------------------------------------------------- */

int initialize_client(int *argc, char ***argv)
{
    (void)argc;
    (void)argv;

    printf("MPI Client initialized.\n");

    return 0;
}

int send_packet(const TelecomPacket *packet)
{
    return transmit_packet(packet);
}

/* -------------------------------------------------------------------------- */
/*                    Private Helper Function Implementation                  */
/* -------------------------------------------------------------------------- */

static int transmit_packet(const TelecomPacket *packet)
{
    char buffer[sizeof(TelecomPacket)];
    int bytes;

    /* Validate input */
    if (packet == NULL)
    {
        fprintf(stderr, "ERROR: Invalid packet.\n");
        return -1;
    }

    /* Serialize packet */
    bytes = serialize_packet(packet,
                             buffer,
                             sizeof(buffer));

    if (bytes == 0)
    {
        fprintf(stderr, "ERROR: Packet serialization failed.\n");
        return -1;
    }

    /* Send serialized packet to Server (Rank 0) */
    if (MPI_Send(buffer,
                 bytes,
                 MPI_BYTE,
                 SERVER_RANK,
                 0,
                 MPI_COMM_WORLD) != MPI_SUCCESS)
    {
        fprintf(stderr, "ERROR: Failed to send packet.\n");
        return -1;
    }

    printf("Client [%d]: Packet %u sent successfully.\n",
       SERVER_RANK + 1,
       packet->packet_id);

    return 0;
}

int finalize_client(void)
{
    printf("MPI Client finalized.\n");
    return 0;
}

int run_client(void)
{
    TelecomPacket packet;

    /* Generate a synthetic telecom packet */
    generate_packet(&packet);

    /* Display generated packet */
    print_packet(&packet);

    /* Send packet to server */
    if (send_packet(&packet) != 0)
    {
        fprintf(stderr, "ERROR: Failed to send packet.\n");
        return -1;
    }

    return 0;
}