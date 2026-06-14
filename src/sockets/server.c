#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

typedef struct
{
    int packet_id;
    char payload[100];
} Packet;

int main()
{
    int server_fd;
    struct sockaddr_in server_addr;

    /* Create Socket */
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if(server_fd < 0)
    {
        perror("Socket Creation Failed");
        exit(EXIT_FAILURE);
    }

    printf("Socket Created Successfully\n");

    /* Configure Server Address */

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    /* Bind Socket */

    if(bind(server_fd,(struct sockaddr *)&server_addr,sizeof(server_addr)) < 0)
    {
        perror("Bind Failed");
        exit(EXIT_FAILURE);
    }

    printf("Bind Successful\n");

    /* Listen For Connections */

    if(listen(server_fd, 5) < 0)
    {
        perror("Listen Failed");
        exit(EXIT_FAILURE);
    }

    printf("Server Listening On Port %d\n", PORT);

    int client_fd;

    client_fd = accept(server_fd, NULL, NULL);

    if(client_fd < 0)
    {
        perror("Accept Failed");
        exit(EXIT_FAILURE);
    }

    printf("Client Connected Successfully!\n");

    Packet pkt;
    int packets_sent = 0;

    struct timeval start, end;

    gettimeofday(&start, NULL);

    for(int i=1;i<=10;i++)
    {
        pkt.packet_id = i;

        sprintf(pkt.payload,"Telecom Packet %d",i);

        send(client_fd,&pkt,sizeof(Packet),0);
        packets_sent++;
        printf("Sent Packet %d\n", i);

        sleep(1);
    }
    gettimeofday(&end, NULL);

    double execution_time;
    double throughput;

    execution_time =(end.tv_sec - start.tv_sec)+(end.tv_usec - start.tv_usec)/1000000.0;
    throughput = packets_sent /execution_time;

    printf("\nTotal Packets Sent = %d\n",packets_sent);
    printf("Execution Time = %.6f sec\n",execution_time);
    printf("Throughput = %.2f packets/sec\n",throughput);

    close(server_fd);

    return 0;
}