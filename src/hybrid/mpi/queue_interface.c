/**
 * @file queue_interface.c
 * @brief Queue interface implementation.
 */

#include "../include/queue_interface.h"
#include "../include/config.h"

#include <stdio.h>
#include <string.h>

/* -------------------------------------------------------------------------- */
/*                      Queue Data Structure                                  */
/* -------------------------------------------------------------------------- */

#define QUEUE_CAPACITY 100

static TelecomPacket packet_queue[QUEUE_CAPACITY];

static int front = 0;
static int rear = -1;
static int current_size = 0;
static int maximum_size = 0;
static int packets_enqueued = 0;
static int packets_dequeued = 0;

/* -------------------------------------------------------------------------- */
/*                    Queue Interface Implementation                          */
/* -------------------------------------------------------------------------- */

bool initialize_queue_interface(void)
{
    front = 0;
    rear = -1;
    current_size = 0;
    maximum_size = 0;
    packets_enqueued = 0;
    packets_dequeued = 0;

    memset(packet_queue, 0, sizeof(packet_queue));

    printf("Communication queue initialized.\n");

    return true;
}

bool enqueue_packet(const TelecomPacket *packet)
{
    if (packet == NULL)
    {
        fprintf(stderr, "ERROR: Invalid packet.\n");
        return false;
    }

    if (is_queue_full())
    {
        fprintf(stderr, "ERROR: Communication queue is full.\n");
        return false;
    }

    /* Move rear to the next position */
    rear = (rear + 1) % QUEUE_CAPACITY;

    /* Store packet in queue */
    packet_queue[rear] = *packet;

    /* Update queue size */
    current_size++;

    packets_enqueued++;

    if (current_size > maximum_size)
    {
        maximum_size = current_size;
    }

    #if ENABLE_PACKET_LOGGING
    printf("Packet %u enqueued successfully. Queue Size: %d\n",
           packet->packet_id,
           current_size);
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

    if (is_queue_empty())
    {
        fprintf(stderr, "ERROR: Communication queue is empty.\n");
        return false;
    }

    /* Copy packet from the front of the queue */
    *packet = packet_queue[front];

    /* Move front to the next position */
    front = (front + 1) % QUEUE_CAPACITY;

    /* Update queue size */
    current_size--;
    packets_dequeued++;

    #if ENABLE_PACKET_LOGGING
    printf("Packet %u dequeued successfully. Queue Size: %d\n",
           packet->packet_id,
           current_size);
    #endif

    return true;
}

bool is_queue_empty(void)
{
    return (current_size==0);
}

bool is_queue_full(void)
{
    return (current_size == QUEUE_CAPACITY);
}

int queue_size(void)
{
    return current_size;
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

void destroy_queue_interface(void)
{
    front = 0;
    rear = -1;
    current_size = 0;

    printf("Communication queue destroyed.\n");
}