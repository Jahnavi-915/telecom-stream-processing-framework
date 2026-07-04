/**
 * @file telecom_packet.h
 * @brief Telecom packet definition and packet utility APIs.
 *
 * This module defines the TelecomPacket structure used throughout
 * the Hybrid Telecom Stream Processing Framework.
 *
 * All communication, processing, storage, graph construction,
 * and analytics modules exchange data using this structure.
 */

#ifndef TELECOM_PACKET_H
#define TELECOM_PACKET_H

#include <stdint.h>
#include <stdbool.h>

/* -------------------------------------------------------------------------- */
/*                          Packet Configuration                              */
/* -------------------------------------------------------------------------- */

#define MAX_TIMESTAMP_LENGTH      32
#define MAX_NODE_NAME_LENGTH      64
#define MAX_TRAFFIC_TYPE_LENGTH   32
#define MAX_PAYLOAD_LENGTH        256

/* -------------------------------------------------------------------------- */
/*                          Telecom Packet Structure                          */
/* -------------------------------------------------------------------------- */

typedef struct
{
    uint32_t packet_id;

    uint32_t des_id;

    char timestamp[MAX_TIMESTAMP_LENGTH];

    char source[MAX_NODE_NAME_LENGTH];

    char destination[MAX_NODE_NAME_LENGTH];

    uint32_t priority;

    char traffic_type[MAX_TRAFFIC_TYPE_LENGTH];

    uint32_t packet_size;

    char payload[MAX_PAYLOAD_LENGTH];

} TelecomPacket;

/* -------------------------------------------------------------------------- */
/*                          Packet Utility APIs                               */
/* -------------------------------------------------------------------------- */

/**
 * @brief Initialize a telecom packet.
 *
 * @param packet Pointer to TelecomPacket.
 */
void initialize_packet(TelecomPacket *packet);

/**
 * @brief Reset all packet fields.
 *
 * @param packet Pointer to TelecomPacket.
 */
void clear_packet(TelecomPacket *packet);

/**
 * @brief Validate packet contents.
 *
 * @param packet Pointer to TelecomPacket.
 *
 * @return true if packet is valid.
 * @return false otherwise.
 */
bool validate_packet(const TelecomPacket *packet);

/**
 * @brief Print packet contents.
 *
 * Used mainly for debugging and testing.
 *
 * @param packet Pointer to TelecomPacket.
 */
void print_packet(const TelecomPacket *packet);

#endif /* TELECOM_PACKET_H */