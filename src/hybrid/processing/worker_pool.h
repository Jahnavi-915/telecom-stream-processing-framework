#ifndef WORKER_POOL_H
#define WORKER_POOL_H

#include <pthread.h>

#include "shared_buffer.h"
#include "packet_processor.h"

#define DEFAULT_WORKER_COUNT 4

typedef struct WorkerPool WorkerPool;

typedef struct
{
    WorkerPool *pool;
    int worker_id;

} WorkerContext;

typedef struct WorkerPool
{
    pthread_t *threads;

    WorkerContext *contexts;

    int worker_count;

    SharedBuffer *buffer;

    volatile int stop;

} WorkerPool;

int worker_pool_init(
    WorkerPool *pool,
    SharedBuffer *buffer,
    int worker_count);

int worker_pool_start(
    WorkerPool *pool);

void worker_pool_stop(
    WorkerPool *pool);

void worker_pool_destroy(
    WorkerPool *pool);

#endif