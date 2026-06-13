#ifndef SHARED_BUFFER_H
#define SHARED_BUFFER_H

#include <pthread.h>
#include "packet.h"

#define BUFFER_SIZE 5

// Circular buffer shared between producer and consumer
extern Packet buffer[BUFFER_SIZE];

// Buffer management variables
extern int in;      // Next insertion index
extern int out;     // Next removal index
extern int count;   // Current number of packets

// Synchronization primitives
extern pthread_mutex_t mutex;
extern pthread_cond_t not_full;
extern pthread_cond_t not_empty;

#endif