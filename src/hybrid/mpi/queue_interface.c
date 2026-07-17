/**
 * @file queue_interface.c
 * @brief Queue interface implementation.
 */

#include "../include/queue_interface.h"
#include "../processing/shared_buffer.h"
#include "../include/config.h"

#include <stdio.h>
#include <time.h>

/* -------------------------------------------------------------------------- */
/*                      Queue Data Structure                                  */
/* -------------------------------------------------------------------------- */

static int maximum_size = 0;
static int packets_enqueued = 0;
static int packets_dequeued = 0;
static SharedBuffer communication_buffer;

/* -------------------------------------------------------------------------- */
/*                    Queue Interface Implementation                          */
/* -------------------------------------------------------------------------- */

bool initialize_queue_interface(void)
{
    maximum_size = 0;
    packets_enqueued = 0;
    packets_dequeued = 0;

    printf("Communication queue initialized.\n");

    if (buffer_init(&communication_buffer) != BUF_OK)
    {
        fprintf(stderr, "ERROR: Failed to initialize shared buffer.\n");
        return false;
    }

    return true;
}

bool enqueue_packet(const TelecomPacket *packet)
{
    if (packet == NULL)
    {
        fprintf(stderr, "ERROR: Invalid packet.\n");
        return false;
    }
    while (enqueue(&communication_buffer, packet) == BUF_FULL)
    {
        struct timespec ts = {0, 1000000};   // 1 ms
        nanosleep(&ts, NULL);
    }

    packets_enqueued++;

    if (communication_buffer.count > maximum_size)
    {
        maximum_size = communication_buffer.count;
    }

    #if ENABLE_PACKET_LOGGING
    printf("Packet %u enqueued successfully. Buffer Size: %d\n",
        packet->packet_id,
        communication_buffer.count);
    #endif

    return true;
}

bool dequeue_packet(TelecomPacket *packet)
{
    if (packet == NULL)
    {
        fprintf(stderr, "ERROR: Invalid packet pointer.\n");
        return false;
    }
    
    if (dequeue(&communication_buffer, packet) != BUF_OK)
    {
        fprintf(stderr, "ERROR: Shared buffer is empty.\n");
        return false;
    }

    packets_dequeued++;

    #if ENABLE_PACKET_LOGGING
    printf("Packet %u dequeued successfully. Buffer Size: %d\n",
        packet->packet_id,
        communication_buffer.count);
    #endif

    return true;

}

bool is_queue_empty(void)
{
    return (communication_buffer.count == 0);
}

bool is_queue_full(void)
{
    return (communication_buffer.count == BUFFER_SIZE);
}

int queue_size(void)
{
    return communication_buffer.count;
}

int max_queue_size(void)
{
    return maximum_size;
}

int total_packets_enqueued(void)
{
    return packets_enqueued;
}

int total_packets_dequeued(void)
{
    return packets_dequeued;
}

void increment_packets_dequeued(void)
{
    packets_dequeued++;
}

SharedBuffer *get_communication_buffer(void)
{
    return &communication_buffer;
}

void destroy_queue_interface(void)
{
    buffer_destroy(&communication_buffer);
    
    printf("Communication queue destroyed.\n");
}