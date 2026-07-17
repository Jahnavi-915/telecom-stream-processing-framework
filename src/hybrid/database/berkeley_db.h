#ifndef BERKELEY_DB_H
#define BERKELEY_DB_H

#include <sys/types.h>
#include <stdint.h>
#include <db.h>

#include "../include/telecom_packet.h"

/*
 * Initializes the Berkeley DB database.
 *
 * Returns:
 *      0  -> Success
 *     -1  -> Failure
 */
int db_initialize(const char *db_name);

/*
 * Stores a telecom packet in the database.
 *
 * Returns:
 *      0  -> Success
 *     -1  -> Failure
 */
int db_store_packet(const TelecomPacket *packet);

/*
 * Retrieves a telecom packet using its packet ID.
 *
 * Returns:
 *      0  -> Success
 *     -1  -> Packet not found / Failure
 */
int db_get_packet(uint32_t packet_id, TelecomPacket *packet);

/*
 * Closes the database.
 */
void db_close(void);

#endif