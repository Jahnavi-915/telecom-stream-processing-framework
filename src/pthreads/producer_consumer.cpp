#include <iostream>
#include <pthread.h>

#include "packet.h"
#include "shared_buffer.h"

using namespace std;

Packet buffer[BUFFER_SIZE];

int in=0;
int out=0;
int count=0;

pthread_mutex_t mutex;
pthread_cond_t not_full;
pthread_cond_t not_empty;

void* producer(void* arg)
{   
    // Generate packet

    // Wait if buffer is full

    // Insert packet into buffer

    // Notify consumer

    return NULL;
}

void* consumer(void* arg)
{
    // Wait if buffer is empty

    // Remove packet from buffer

    // Process packet
    
    return NULL;
}

int main()
{
    return 0;
}