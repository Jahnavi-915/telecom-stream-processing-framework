/**
 * @file serialization.c
 * @brief Telecom packet serialization implementation.
 */

#include "../include/serialization.h"

#include <string.h>

/* -------------------------------------------------------------------------- */
/*                          Serialize Packet                                  */
/* -------------------------------------------------------------------------- */

size_t serialize_packet(const TelecomPacket *packet,
                        void *buffer,
                        size_t buffer_size)
{
    if (packet == NULL || buffer == NULL)
    {
        return 0;
    }

    if (buffer_size < sizeof(TelecomPacket))
    {
        return 0;
    }

    memcpy(buffer, packet, sizeof(TelecomPacket));

    return sizeof(TelecomPacket);
}

/* -------------------------------------------------------------------------- */
/*                         Deserialize Packet                                 */
/* -------------------------------------------------------------------------- */

size_t deserialize_packet(const void *buffer,
                          size_t buffer_size,
                          TelecomPacket *packet)
{
    if (buffer == NULL || packet == NULL)
    {
        return 0;
    }

    if (buffer_size < sizeof(TelecomPacket))
    {
        return 0;
    }

    memcpy(packet, buffer, sizeof(TelecomPacket));

    return sizeof(TelecomPacket);
}