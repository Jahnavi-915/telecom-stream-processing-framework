#ifndef QUEUE_INTERFACE_H
#define QUEUE_INTERFACE_H

#include <stdbool.h>
#include "telecom_packet.h"

bool initialize_queue_interface(void);

bool enqueue_packet(const TelecomPacket *packet);

bool dequeue_packet(TelecomPacket *packet);

bool is_queue_empty(void);

bool is_queue_full(void);

int queue_size(void);

int max_queue_size(void);

int total_packets_enqueued(void);

int total_packets_dequeued(void);

void destroy_queue_interface(void);

#endif