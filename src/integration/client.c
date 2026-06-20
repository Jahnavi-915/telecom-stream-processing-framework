#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080

typedef struct {
    int packet_id;
    char payload[64];
} TelecomPacket;

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    TelecomPacket incoming_packet;

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
        return -1;
    }
    printf("[CLIENT] Connected! Ready to accept streaming packets.\n");

    // Continuously read structural payloads from network socket
    while (recv(sock, &incoming_packet, sizeof(TelecomPacket), 0) > 0) {
        printf("[CLIENT RECEIVER] Packet Received -> ID: %d | Content: %s\n", 
               incoming_packet.packet_id, incoming_packet.payload);
    }

    printf("[CLIENT] Stream ended by host. Exiting.\n");
    close(sock);
    return 0;
}
