#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>

#define PORT 8080
#define TOTAL_PACKETS 50

typedef struct {
    int packet_id;
    int priority;
    char source[50];
    char destination[50];
    char payload[100];
} TelecomPacket;

int packets_received = 0;
struct timeval start_time, end_time;

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    TelecomPacket incoming_packet;

    FILE *log_file =
    fopen("logs/received_packets.log", "w");

    if(log_file == NULL)
    {
        perror("Log file creation failed");
        return -1;
    }    

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 address from text to binary form (localhost)
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    printf("[CLIENT] Attempting connection to the Integration Server...\n");
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        fclose(log_file);
        return -1;
    }
    printf("[CLIENT] Connected! Ready to accept streaming packets.\n");

    gettimeofday(&start_time, NULL);

    // Continuously read structural payloads from network socket
    while (recv(sock, &incoming_packet, sizeof(TelecomPacket), 0) > 0) {
        packets_received++;

        fprintf(log_file,
            "Packet ID=%d | Priority=%d | Source=%s | Destination=%s | Payload=%s\n",
            incoming_packet.packet_id,
            incoming_packet.priority,
            incoming_packet.source,
            incoming_packet.destination,
            incoming_packet.payload);
        fflush(log_file);

        printf("\n=====================================\n");
        printf("[CLIENT RECEIVER] Packet Received\n");
        printf("Packet ID   : %d\n", incoming_packet.packet_id);
        printf("Priority    : %d\n", incoming_packet.priority);
        printf("Source      : %s\n", incoming_packet.source);
        printf("Destination : %s\n", incoming_packet.destination);
        printf("Payload     : %s\n", incoming_packet.payload);
        printf("=====================================\n");
    }

    gettimeofday(&end_time, NULL);

    double delivery_success_rate =((double)packets_received /TOTAL_PACKETS) * 100.0;
    double execution_time = (end_time.tv_sec - start_time.tv_sec) +(end_time.tv_usec - start_time.tv_usec)/1000000.0;
    double receive_throughput = 0.0;

    if (execution_time > 0)
    {
        receive_throughput = packets_received / execution_time;
    }

    printf("\n========== Client Statistics ==========\n");

    printf("Packets Received : %d\n",packets_received);
    printf("Delivery Success Rate : %.2f%%\n",delivery_success_rate);
    printf("Execution Time       : %.3f sec\n",execution_time);
    printf("Receive Throughput   : %.2f packets/sec\n",receive_throughput);

    printf("=======================================\n");

    printf("[CLIENT] Stream ended by host. Exiting.\n");

    fclose(log_file);
    close(sock);
    return 0;
}
