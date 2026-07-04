/**
 * @file queue_interface.c
 * @brief Queue interface implementation.
 */

#include "../include/queue_interface.h"

/* -------------------------------------------------------------------------- */
/*                    Queue Interface Stub Implementation                     */
/* -------------------------------------------------------------------------- */

bool initialize_queue_interface(void)
{
    return true;
}

bool enqueue_packet(const TelecomPacket *packet)
{
    (void)packet;
    return true;
}

bool dequeue_packet(TelecomPacket *packet)
{
    (void)packet;
    return true;
}

bool is_queue_empty(void)
{
    return true;
}

bool is_queue_full(void)
{
    return false;
}

int queue_size(void)
{
    return 0;
}

void destroy_queue_interface(void)
{
}