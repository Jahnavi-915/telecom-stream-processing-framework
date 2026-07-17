#include <stdio.h>

#include "packet_processor.h"

void process_telecom_packet(
    const TelecomPacket *packet,
    int worker_id)
{
    if (packet == NULL)
        return;

    printf(
        "[Worker-%d] Packet=%u | DES=%u | Source=%s | Destination=%s\n",
        worker_id,
        packet->packet_id,
        packet->des_id,
        packet->source,
        packet->destination);

    printf(
        "Traffic=%s | Priority=%u | Size=%u | Timestamp=%s\n",
        packet->traffic_type,
        packet->priority,
        packet->packet_size,
        packet->timestamp);
}