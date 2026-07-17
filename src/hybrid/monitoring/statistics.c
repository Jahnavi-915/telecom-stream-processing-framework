#include "statistics.h"

#include <stdio.h>
#include <string.h>

void initialize_statistics(SystemStatistics *stats)
{
    memset(stats, 0, sizeof(SystemStatistics));
}

void print_system_statistics(const SystemStatistics *stats)
{
    printf("\n");
    printf("=============================================\n");
    printf("  FINAL SYSTEM MONITORING DASHBOARD\n");
    printf("=============================================\n");

    printf("\nCommunication Statistics\n");
    printf("------------------------\n");
    printf("Packets Received : %u\n", stats->packets_received);

    printf("\nProcessing Statistics\n");
    printf("---------------------\n");
    printf("Packets Processed : %u\n", stats->packets_processed);
    printf("Packets Enqueued  : %u\n", stats->packets_enqueued);
    printf("Packets Dequeued  : %u\n", stats->packets_dequeued);

    printf("\nDatabase Statistics\n");
    printf("-------------------\n");
    printf("Packets Stored : %u\n", stats->packets_stored);

    printf("\nGraph Statistics\n");
    printf("----------------\n");
    printf("Vertices              : %u\n", stats->total_vertices);
    printf("Edges                 : %u\n", stats->total_edges);
    printf("Communication Volume  : %u\n",
           stats->communication_volume);

    printf("\nPerformance Statistics\n");
    printf("----------------------\n");
    printf("Execution Time : %.6f seconds\n",
           stats->execution_time);
    printf("Throughput     : %.2f packets/second\n",
           stats->throughput);

    printf("=============================================\n");
}