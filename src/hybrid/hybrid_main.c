/**
 * @file hybrid_main.c
 * @brief Entry point of the Hybrid Telecom Stream Processing Framework.
 */

#include "include/config.h"
#include "include/mpi_client.h"
#include "include/mpi_server.h"

#include <mpi.h>
#include <stdio.h>

#include "monitoring/logger.h"

int main(int argc, char *argv[])
{
    int rank;

    /* Initialize MPI */
    MPI_Init(&argc, &argv);

    /* Get current process rank */
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == SERVER_RANK)
    {
        printf("\n===== MPI SERVER =====\n");

        initialize_server(&argc, &argv);
        run_server();
        finalize_server();
    }
    else
    {
        printf("\n===== MPI CLIENT =====\n");

        initialize_client(&argc, &argv);
        run_client();
        finalize_client();
    }

    /* Finalize MPI */
    MPI_Finalize();

    return 0;
}