/**
 * @file serialization.h
 * @brief Telecom packet serialization APIs.
 */

#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include "telecom_packet.h"

#include <stddef.h>

/* -------------------------------------------------------------------------- */
/*                         Serialization APIs                                 */
/* -------------------------------------------------------------------------- */

/**
 * @brief Serialize a TelecomPacket into a byte buffer.
 *
 * @param packet Source packet.
 * @param buffer Destination buffer.
 * @param buffer_size Size of destination buffer.
 *
 * @return Number of bytes serialized.
 */
size_t serialize_packet(const TelecomPacket *packet,
                        void *buffer,
                        size_t buffer_size);

/**
 * @brief Deserialize a TelecomPacket from a byte buffer.
 *
 * @param buffer Source buffer.
 * @param buffer_size Size of source buffer.
 * @param packet Output packet.
 *
 * @return Number of bytes deserialized.
 */
size_t deserialize_packet(const void *buffer,
                          size_t buffer_size,
                          TelecomPacket *packet);

#endif /* SERIALIZATION_H */