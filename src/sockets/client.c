#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

typedef struct
{
    int packet_id;
    char payload[100];
} Packet;

int main()
{
    int sockfd;
    struct sockaddr_in server_addr;

    /* Create Socket */

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0)
    {
        perror("Socket Creation Failed");
        exit(EXIT_FAILURE);
    }

    printf("Client Socket Created\n");

    /* Configure Server Address */

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    inet_pton(AF_INET, "127.0.0.1",
              &server_addr.sin_addr);

    /* Connect To Server */

    if(connect(sockfd,
              (struct sockaddr *)&server_addr,
              sizeof(server_addr)) < 0)
    {
        perror("Connection Failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected To Server Successfully!\n");

    FILE *logfile;
    logfile = fopen("logs/received_packets.log", "w");
    
    Packet pkt;
    int packets_received = 0;
    struct timeval start, end;
    double execution_time;
    double throughput;

    gettimeofday(&start, NULL);

    for(int i=1;i<=1000;i++)
    {
        recv(sockfd,&pkt,sizeof(Packet),0);
        fprintf(logfile,
        "Packet ID : %d | Payload : %s\n",pkt.packet_id,pkt.payload);
        packets_received++;
        printf("\nPacket Received\n");
        printf("Packet ID : %d\n",pkt.packet_id);

        printf("Payload   : %s\n",pkt.payload);
    }

    gettimeofday(&end, NULL);

    execution_time =(end.tv_sec - start.tv_sec)+(end.tv_usec - start.tv_usec)/1000000.0;
    throughput = packets_received /execution_time;
    
    printf("\nTotal Packets Received = %d\n",packets_received);
    printf("Execution Time = %.6f sec\n",execution_time);

    printf("Receive Throughput = %.2f packets/sec\n",throughput);
    
    fclose(logfile);
    close(sockfd);

    return 0;
}