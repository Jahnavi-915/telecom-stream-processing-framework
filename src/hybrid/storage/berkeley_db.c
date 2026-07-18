#include "berkeley_db.h"
#include "../monitoring/monitoring.h"

#include <stdio.h>
#include <string.h>
#include <pthread.h>

static DB *database = NULL;
static pthread_mutex_t db_mutex = PTHREAD_MUTEX_INITIALIZER;

int db_initialize(const char *db_name)
{
    int ret;

    /*
     * Create a Berkeley DB handle.
     */
    ret = db_create(&database, NULL, 0);

    if (ret != 0)
    {
        fprintf(stderr, "ERROR: Failed to create Berkeley DB handle.\n");
        return -1;
    }

    /*
     * Open (or create) the database file.
     */
    ret = database->open(
            database,
            NULL,
            db_name,
            NULL,
            DB_BTREE,
            DB_CREATE,
            0);

    if (ret != 0)
    {
        fprintf(stderr, "ERROR: Failed to open Berkeley DB.\n");

        database->close(database, 0);
        database = NULL;

        return -1;
    }

    printf("INFO: Berkeley DB initialized successfully.\n");

    return 0;
}

int db_store_packet(const TelecomPacket *packet)
{
    DBT key;
    DBT value;
    int ret;

    memset(&key, 0, sizeof(DBT));
    memset(&value, 0, sizeof(DBT));

    key.data = (void *)&packet->packet_id;
    key.size = sizeof(packet->packet_id);

    value.data = (void *)packet;
    value.size = sizeof(TelecomPacket);

    pthread_mutex_lock(&db_mutex);

    ret = database->put(database, NULL, &key, &value, 0);

    pthread_mutex_unlock(&db_mutex);

    if (ret != 0)
    {
        fprintf(stderr,
                "ERROR: Failed to store Packet %u in Berkeley DB.\n",
                packet->packet_id);
        return -1;
    }
    monitoring_get_statistics()->packets_stored++;

    printf("Packet %u stored in Berkeley DB.\n", packet->packet_id);

    return 0;
}

int db_get_packet(uint32_t packet_id, TelecomPacket *packet)
{
    DBT key;
    DBT value;
    int ret;

    memset(&key, 0, sizeof(DBT));
    memset(&value, 0, sizeof(DBT));

    key.data = &packet_id;
    key.size = sizeof(packet_id);

    value.data = packet;
    value.ulen = sizeof(TelecomPacket);
    value.flags = DB_DBT_USERMEM;

    pthread_mutex_lock(&db_mutex);

    ret = database->get(database, NULL, &key, &value, 0);

    pthread_mutex_unlock(&db_mutex);

    if (ret == DB_NOTFOUND)
    {
        fprintf(stderr,
                "Packet %u not found in Berkeley DB.\n",
                packet_id);
        return -1;
    }

    if (ret != 0)
    {
        fprintf(stderr,
                "ERROR: Failed to retrieve Packet %u from Berkeley DB.\n",
                packet_id);
        return -1;
    }

    printf("Packet %u retrieved from Berkeley DB.\n", packet_id);

    return 0;
}

void db_close(void)
{
    if (database != NULL)
    {
        database->close(database, 0);
        database = NULL;

        printf("Berkeley DB closed successfully.\n");
    }

    pthread_mutex_destroy(&db_mutex);
}