#include <stdio.h>

#include "packet_processor.h"
#include "../database/berkeley_db.h"

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

    if (db_store_packet(packet) != 0)
    {
        fprintf(stderr,
                "[Worker-%d] Failed to store Packet %u.\n",
                worker_id,
                packet->packet_id);
    }
}