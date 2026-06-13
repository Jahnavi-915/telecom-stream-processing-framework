#ifndef PACKET_H
#define PACKET_H

struct Packet {
    int id;
    int priority;
    char source[20];
    char destination[20];
};

#endif