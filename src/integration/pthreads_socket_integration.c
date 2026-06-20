#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define BUFFER_SIZE 10
#define PORT 8080
#define TOTAL_PACKETS 50

// 1. Packet structure matching the architectural workflow
typedef struct {
    int packet_id;
    int priority;
    char source[50];
    char destination[50];
    char payload[100];
} TelecomPacket;

// 2. Bounded Shared Buffer structure
typedef struct {
    TelecomPacket data[BUFFER_SIZE];
    int head;
    int tail;
    int count;
    pthread_mutex_t lock;
    pthread_cond_t not_full;
    pthread_cond_t not_empty;
} SharedBuffer;

SharedBuffer buffer;
int client_socket = -1;

int packets_generated = 0;
int packets_sent = 0;

int buffer_full_events = 0;
int buffer_empty_events = 0;

struct timeval start_time, end_time;

// Thread function declarations
void* producer_thread_func(void* arg);
void* sender_thread_func(void* arg);

int main() {
    int server_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    pthread_t producer_tid, sender_tid;

    // Initialize Shared Buffer, Mutex, and Condition Variables
    buffer.head = 0;
    buffer.tail = 0;
    buffer.count = 0;
    pthread_mutex_init(&buffer.lock, NULL);
    pthread_cond_init(&buffer.not_full, NULL);
    pthread_cond_init(&buffer.not_empty, NULL);

    // Set up TCP Socket Server
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    if (setsockopt(server_fd, SOL_SOCKET,SO_REUSEADDR | SO_REUSEPORT,&opt, sizeof(opt)) < 0)
        {
            perror("setsockopt");
            exit(EXIT_FAILURE);
        }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("[SERVER] Waiting for client connection on port %d...\n", PORT);
    if ((client_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Accept connection failed");
        exit(EXIT_FAILURE);
    }
    printf("[SERVER] Client connected successfully!\n");
    
    gettimeofday(&start_time, NULL);
    // Spawn the threads
    pthread_create(&producer_tid, NULL, producer_thread_func, NULL);
    pthread_create(&sender_tid, NULL, sender_thread_func, NULL);

    // Wait for work to complete
    pthread_join(producer_tid, NULL);
    pthread_join(sender_tid, NULL);

    gettimeofday(&end_time, NULL);
    // Cleanup resources

    double execution_time = (end_time.tv_sec - start_time.tv_sec) +(end_time.tv_usec - start_time.tv_usec)/1000000.0;
    double throughput = 0.0;

    if(execution_time > 0)
    {
        throughput = packets_sent / execution_time;
    }

    printf("\n========== Integration Statistics ==========\n");

    printf("Packets Generated    : %d\n",packets_generated);
    printf("Packets Sent         : %d\n",packets_sent);
    printf("Buffer Full Events   : %d\n",buffer_full_events);
    printf("Buffer Empty Events  : %d\n",buffer_empty_events);
    printf("Execution Time     : %.3f sec\n",execution_time);
    printf("Send Throughput    : %.2f packets/sec\n",throughput);

    printf("============================================\n");

    close(client_socket);
    close(server_fd);
    pthread_mutex_destroy(&buffer.lock);
    pthread_cond_destroy(&buffer.not_full);
    pthread_cond_destroy(&buffer.not_empty);

    printf("[SERVER] Execution finished cleanly.\n");
    return 0;
}

// PRODUCER THREAD: Generates packets and places them in the bounded shared buffer
void* producer_thread_func(void* arg) {
    for (int i = 1; i <= TOTAL_PACKETS; i++) {
        pthread_mutex_lock(&buffer.lock);

        // Block if buffer is full
        while (buffer.count == BUFFER_SIZE) {
            buffer_full_events++;
            pthread_cond_wait(&buffer.not_full, &buffer.lock);
        }

        // Add packet data to buffer
        buffer.data[buffer.tail].packet_id = i;
        buffer.data[buffer.tail].priority = 1;

        strcpy(buffer.data[buffer.tail].source, "DES-1");
        strcpy(buffer.data[buffer.tail].destination, "CLIENT-1");

        sprintf(buffer.data[buffer.tail].payload,"Telecom Data Stream Packet #%d", i);
        
        
        printf("[PRODUCER] Packet ID=%d Source=%s Destination=%s Buffered\n",
        buffer.data[buffer.tail].packet_id,
        buffer.data[buffer.tail].source,
        buffer.data[buffer.tail].destination);
        
        buffer.tail = (buffer.tail + 1) % BUFFER_SIZE;
        buffer.count++;
        packets_generated++;

        // Alert the waiting Sender Thread
        pthread_cond_signal(&buffer.not_empty);
        pthread_mutex_unlock(&buffer.lock);

        usleep(1000); // Simulate processing latency (50ms)
    }
    return NULL;
}

// SENDER THREAD: Replaces the old consumer. Fetches packets from the buffer and transmits over TCP
void* sender_thread_func(void* arg) {
    for (int i = 1; i <= TOTAL_PACKETS; i++) {
        pthread_mutex_lock(&buffer.lock);

        // Block if buffer is empty
        while (buffer.count == 0) {
            buffer_empty_events++;
            pthread_cond_wait(&buffer.not_empty, &buffer.lock);
        }

        // Retrieve packet from buffer
        TelecomPacket packet_to_send = buffer.data[buffer.head];
        buffer.head = (buffer.head + 1) % BUFFER_SIZE;
        buffer.count--;

        // Alert the waiting Producer Thread
        pthread_cond_signal(&buffer.not_full);
        pthread_mutex_unlock(&buffer.lock);

        // Network Transmission via Socket API
        printf("[SENDER] Sending Packet ID=%d From=%s To=%s\n",
        packet_to_send.packet_id,
        packet_to_send.source,
        packet_to_send.destination);
        
        ssize_t bytes_sent = send(client_socket,&packet_to_send,sizeof(TelecomPacket),0);

        if(bytes_sent <= 0)
        {
            perror("Send failed");
        }
        else
        {
            packets_sent++;
        }
    }
    return NULL;
}
