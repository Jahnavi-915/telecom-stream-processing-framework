/**
 * @file traffic_generator.h
 * @brief Synthetic telecom traffic generator.
 */

#ifndef TRAFFIC_GENERATOR_H
#define TRAFFIC_GENERATOR_H

#include "telecom_packet.h"

/* -------------------------------------------------------------------------- */
/*                          Traffic Generator APIs                            */
/* -------------------------------------------------------------------------- */

/**
 * @brief Generate a complete telecom packet.
 *
 * @param packet Pointer to TelecomPacket.
 */
void generate_packet(TelecomPacket *packet);

/**
 * @brief Generate timestamp.
 */
void generate_timestamp(char *timestamp);

/**
 * @brief Generate source node.
 */
void generate_source(char *source);

/**
 * @brief Generate destination node.
 */
void generate_destination(char *destination);

/**
 * @brief Generate traffic type.
 */
void generate_traffic_type(char *traffic_type);

/**
 * @brief Generate payload.
 */
void generate_payload(char *payload);

#endif /* TRAFFIC_GENERATOR_H */