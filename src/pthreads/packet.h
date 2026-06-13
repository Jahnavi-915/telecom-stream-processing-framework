#ifndef PACKET_H
#define PACKET_H

struct Packet {
    int id;                  // Unique packet identifier
    int priority;            // Packet priority level
    char source[20];         // Source node/server
    char destination[20];    // Destination node/server
};

#endif