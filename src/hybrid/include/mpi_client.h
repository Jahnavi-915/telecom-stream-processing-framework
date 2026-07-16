/**
 * @file mpi_client.h
 * @brief MPI client interface for the communication prototype.
 */

#ifndef MPI_CLIENT_H
#define MPI_CLIENT_H

#include "telecom_packet.h"

/* Initialize the MPI client environment. */
int initialize_client(int *argc, char ***argv);

/* Send a telecom packet to the server. */
int send_packet(const TelecomPacket *packet);

/* Execute the complete client workflow. */
int run_client(void);

/* Finalize the MPI client environment. */
int finalize_client(void);

#endif /* MPI_CLIENT_H */