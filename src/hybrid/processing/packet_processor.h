#ifndef PACKET_PROCESSOR_H
#define PACKET_PROCESSOR_H

#include "../include/telecom_packet.h"

/*
 * Processes a single telecom packet.
 */
void process_telecom_packet(
    const TelecomPacket *packet,
    int worker_id);

#endif /* PACKET_PROCESSOR_H */