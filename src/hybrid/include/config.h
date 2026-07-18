/**
 * @file config.h
 * @brief Global configuration parameters for the Hybrid Telecom Stream
 * Processing Framework.
 */

#ifndef CONFIG_H
#define CONFIG_H

/* -------------------------------------------------------------------------- */
/*                            MPI Configuration                               */
/* -------------------------------------------------------------------------- */

#define SERVER_RANK                0
#define DEFAULT_NUM_CLIENTS        1
#define MAX_CLIENTS                8

/* -------------------------------------------------------------------------- */
/*                         Packet Configuration                               */
/* -------------------------------------------------------------------------- */

#define DEFAULT_PACKET_RATE        100
#define DEFAULT_PACKET_SIZE        256

/* -------------------------------------------------------------------------- */
/*                         Queue Configuration                                */
/* -------------------------------------------------------------------------- */

#define DEFAULT_QUEUE_SIZE         100

/* -------------------------------------------------------------------------- */
/*                         Delay Configuration                                */
/* -------------------------------------------------------------------------- */

#define DEFAULT_DELAY_MS           100

/* -------------------------------------------------------------------------- */
/*                      Traffic Generator Configuration                       */
/* -------------------------------------------------------------------------- */

#define DEFAULT_PACKETS_PER_CLIENT 1000

/* -------------------------------------------------------------------------- */
/*                        Statistics Configuration                            */
/* -------------------------------------------------------------------------- */

#define ENABLE_LOGGING             1
#define ENABLE_STATISTICS          1
#define ENABLE_PACKET_LOGGING      1

/* Communication Queue Configuration */
#define QUEUE_CAPACITY 100

/* Queue Stress Testing */
#define PROCESSING_BATCH_SIZE 5

/* Performance Evaluation */
#define PERFORMANCE_MODE           0

#endif /* CONFIG_H */