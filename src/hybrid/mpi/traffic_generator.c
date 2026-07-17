/**
 * @file traffic_generator.c
 * @brief Synthetic telecom traffic generator.
 */

#include "../include/traffic_generator.h"
#include "../include/config.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* -------------------------------------------------------------------------- */
/*                           Generate Timestamp                               */
/* -------------------------------------------------------------------------- */

void generate_timestamp(char *timestamp)
{
    time_t now = time(NULL);

    strftime(timestamp,
             MAX_TIMESTAMP_LENGTH,
             "%Y-%m-%d %H:%M:%S",
             localtime(&now));
}

/* -------------------------------------------------------------------------- */
/*                             Generate Source                                */
/* -------------------------------------------------------------------------- */

void generate_source(char *source)
{
    sprintf(source, "Tower-%d", rand() % 10 + 1);
}

/* -------------------------------------------------------------------------- */
/*                          Generate Destination                              */
/* -------------------------------------------------------------------------- */

void generate_destination(char *destination)
{
    sprintf(destination, "Tower-%d", rand() % 10 + 1);
}

/* -------------------------------------------------------------------------- */
/*                        Generate Traffic Type                               */
/* -------------------------------------------------------------------------- */

void generate_traffic_type(char *traffic_type)
{
    const char *types[] =
    {
        "VOICE",
        "DATA",
        "SMS",
        "CONTROL"
    };

    strcpy(traffic_type, types[rand() % 4]);
}

/* -------------------------------------------------------------------------- */
/*                           Generate Payload                                 */
/* -------------------------------------------------------------------------- */

void generate_payload(char *payload)
{
    strcpy(payload, "Sample Telecom Payload");
}

/* -------------------------------------------------------------------------- */
/*                          Generate Packet                                   */
/* -------------------------------------------------------------------------- */

void generate_packet(TelecomPacket *packet, uint32_t des_id)
{
    static uint32_t packet_id = 1;

    initialize_packet(packet);

    packet->packet_id = packet_id++;
    packet->des_id = des_id;

    generate_timestamp(packet->timestamp);
    generate_source(packet->source);
    generate_destination(packet->destination);
    generate_traffic_type(packet->traffic_type);
    generate_payload(packet->payload);

    packet->priority = rand() % 5 + 1;
    packet->packet_size = strlen(packet->payload);
}