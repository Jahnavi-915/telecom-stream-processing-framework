#ifndef STATISTICS_H
#define STATISTICS_H

#include <stdint.h>

typedef struct
{
    /* Communication */
    uint32_t packets_received;
    uint32_t packets_sent;

    /* Processing */
    uint32_t packets_processed;
    uint32_t packets_enqueued;
    uint32_t packets_dequeued;

    /* Database */
    uint32_t packets_stored;

    /* Graph */
    uint32_t total_vertices;
    uint32_t total_edges;
    uint32_t communication_volume;

    /* Performance */
    double execution_time;
    double throughput;

} SystemStatistics;

/* Initialize statistics */
void initialize_statistics(SystemStatistics *stats);

/* Print system statistics */
void print_system_statistics(const SystemStatistics *stats);

#endif