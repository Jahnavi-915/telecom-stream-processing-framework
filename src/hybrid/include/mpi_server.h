/**
 * @file mpi_server.h
 * @brief MPI server interface for the communication prototype.
 */

#ifndef MPI_SERVER_H
#define MPI_SERVER_H

#include "telecom_packet.h"

/* Initialize the MPI server environment. */
int initialize_server(int *argc, char ***argv);

/* Receive a telecom packet from the client. */
int receive_packet(TelecomPacket *packet);

/* Execute the complete server workflow. */
int run_server(void);

/* Finalize the MPI server environment. */
int finalize_server(void);

#endif /* MPI_SERVER_H */