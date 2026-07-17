#include "worker_pool.h"
#include "../include/queue_interface.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void *worker_thread(void *arg)
{
    WorkerContext *context = (WorkerContext *)arg;

    WorkerPool *pool = context->pool;

    int worker_id = context->worker_id;

    TelecomPacket packet;

    while (1)
    {
        if (dequeue(pool->buffer, &packet) == BUF_OK)
        {
            increment_packets_dequeued();
            process_telecom_packet(&packet, worker_id);
        }
        else
        {
            if (pool->stop)
                break;

            struct timespec ts = {0, 1000000}; // 1 millisecond
            nanosleep(&ts, NULL);
        }
    }

    return NULL;
}

int worker_pool_init(
    WorkerPool *pool,
    SharedBuffer *buffer,
    int worker_count)
{
    if (pool == NULL || buffer == NULL || worker_count <= 0)
        return -1;

    pool->threads = malloc(sizeof(pthread_t) * worker_count);

    if (pool->threads == NULL)
        return -1;

    pool->contexts = malloc(sizeof(WorkerContext) * worker_count);

    if (pool->contexts == NULL)
    {
        free(pool->threads);
        return -1;
    }

    pool->worker_count = worker_count;
    pool->buffer = buffer;
    pool->stop = 0;

    for (int i = 0; i < worker_count; i++)
    {
        pool->contexts[i].pool = pool;
        pool->contexts[i].worker_id = i;
    }

    return 0;
}

int worker_pool_start(
    WorkerPool *pool)
{
    if (pool == NULL)
        return -1;

    for (int i = 0; i < pool->worker_count; i++)
    {
        if (pthread_create(
                &pool->threads[i],
                NULL,
                worker_thread,
                &pool->contexts[i]) != 0)
        {
            return -1;
        }
    }

    return 0;
}

void worker_pool_stop(
    WorkerPool *pool)
{
    if (pool == NULL)
        return;

    pool->stop = 1;
}

void worker_pool_destroy(
    WorkerPool *pool)
{
    if (pool == NULL)
        return;

    for (int i = 0; i < pool->worker_count; i++)
    {
        pthread_join(pool->threads[i], NULL);
    }

    free(pool->threads);
    free(pool->contexts);

    pool->threads = NULL;
    pool->contexts = NULL;
}