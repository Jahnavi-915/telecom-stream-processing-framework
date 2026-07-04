/**
 * @file telecom_packet.c
 * @brief Telecom packet utility function implementations.
 */

#include "../include/telecom_packet.h"

#include <stdio.h>
#include <string.h>

/* -------------------------------------------------------------------------- */
/*                          Packet Initialization                             */
/* -------------------------------------------------------------------------- */

void initialize_packet(TelecomPacket *packet)
{
    if (packet == NULL)
    {
        return;
    }

    memset(packet, 0, sizeof(TelecomPacket));
}

/* -------------------------------------------------------------------------- */
/*                              Clear Packet                                  */
/* -------------------------------------------------------------------------- */

void clear_packet(TelecomPacket *packet)
{
    if (packet == NULL)
    {
        return;
    }

    memset(packet, 0, sizeof(TelecomPacket));
}

/* -------------------------------------------------------------------------- */
/*                            Validate Packet                                 */
/* -------------------------------------------------------------------------- */

bool validate_packet(const TelecomPacket *packet)
{
    if (packet == NULL)
    {
        return false;
    }

    if (packet->packet_id == 0)
    {
        return false;
    }

    if (strlen(packet->source) == 0)
    {
        return false;
    }

    if (strlen(packet->destination) == 0)
    {
        return false;
    }

    if (packet->packet_size > MAX_PAYLOAD_LENGTH)
    {
        return false;
    }

    return true;
}

/* -------------------------------------------------------------------------- */
/*                              Print Packet                                  */
/* -------------------------------------------------------------------------- */

void print_packet(const TelecomPacket *packet)
{
    if (packet == NULL)
    {
        printf("Packet is NULL.\n");
        return;
    }

    printf("\n================ Telecom Packet ================\n");

    printf("Packet ID      : %u\n", packet->packet_id);
    printf("DES ID         : %u\n", packet->des_id);
    printf("Timestamp      : %s\n", packet->timestamp);
    printf("Source         : %s\n", packet->source);
    printf("Destination    : %s\n", packet->destination);
    printf("Priority       : %u\n", packet->priority);
    printf("Traffic Type   : %s\n", packet->traffic_type);
    printf("Packet Size    : %u Bytes\n", packet->packet_size);
    printf("Payload        : %s\n", packet->payload);

    printf("===============================================\n");
}