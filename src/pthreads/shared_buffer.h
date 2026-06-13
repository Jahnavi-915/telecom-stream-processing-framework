#ifndef SHARED_BUFFER_H
#define SHARED_BUFFER_H

#include <pthread.h>
#include "packet.h"

#define BUFFER_SIZE 5

extern Packet buffer[BUFFER_SIZE];

extern int in;
extern int out;
extern int count;

extern pthread_mutex_t mutex;
extern pthread_cond_t not_full;
extern pthread_cond_t not_empty;

#endif