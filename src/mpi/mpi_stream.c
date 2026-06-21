#include <stdio.h>
#include <string.h>
#include <mpi.h>
#include <sys/time.h>

#define TOTAL_PACKETS 10000

typedef struct {
    int packet_id;
    int priority;
    char source[50];
    char destination[50];
    char payload[100];
} TelecomPacket;

int packets_generated = 0;
int packets_sent = 0;
int packets_received = 0;

struct timeval start_time, end_time;

int main(int argc, char *argv[])
{
    int rank, size;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if(size < 2)
    {
        if(rank == 0)
        {
            printf("Run with at least 2 processes.\n");
        }

        MPI_Finalize();
        return 0;
    }

    TelecomPacket packet;

    if(rank == 0)
    {   
        gettimeofday(&start_time, NULL);

        int worker_rank = 1;

        printf("\n========== MASTER PROCESS ==========\n");
        printf("Total Workers : %d\n", size - 1);
        printf("Total Packets : %d\n", TOTAL_PACKETS);
        printf("====================================\n\n");

        for(int i = 1; i <= TOTAL_PACKETS; i++)
        {
            packet.packet_id = i;
            packet.priority = 1;
            
            packets_generated++;

            strcpy(packet.source, "DES-1");

            sprintf(packet.destination, "Worker-%d", worker_rank);

            sprintf(packet.payload,"Telecom Packet #%d",i);

            MPI_Send(&packet,sizeof(TelecomPacket),MPI_BYTE,worker_rank,0,MPI_COMM_WORLD);

            packets_sent++;

            printf("[MASTER] Sent Packet %d to Rank %d\n",i,worker_rank);

            worker_rank++;

            if(worker_rank >= size)
            {
                worker_rank = 1;
            }
        }

        packet.packet_id = -1;

        for(int i = 1; i < size; i++)
        {
            MPI_Send(&packet,sizeof(TelecomPacket),MPI_BYTE,i,0,MPI_COMM_WORLD);
        }

        gettimeofday(&end_time, NULL);

        double execution_time = (end_time.tv_sec - start_time.tv_sec) +(end_time.tv_usec - start_time.tv_usec) / 1000000.0;
        double throughput = 0.0;
        double success_rate = ((double)packets_sent / packets_generated) * 100.0;
        if(execution_time > 0)
        {
            throughput = packets_sent / execution_time;
        }

        printf("\n========== MPI Statistics ==========\n");

        printf("Packets Generated : %d\n", packets_generated);
        printf("Packets Sent      : %d\n", packets_sent);
        printf("Execution Time    : %.6f sec\n", execution_time);
        printf("Throughput        : %.2f packets/sec\n", throughput);
        printf("Communication Success Rate : %.2f%%\n", success_rate);

        printf("====================================\n");
    }

    else
    {
        while(1)
        {
            MPI_Recv(&packet,sizeof(TelecomPacket),MPI_BYTE,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);

            if(packet.packet_id == -1)
            {
                break;
            }

            packets_received++;

            printf("\n[WORKER %d] Received Packet ID=%d\n",rank,packet.packet_id);

            printf("Source=%s Destination=%s Payload=%s\n",packet.source,packet.destination,packet.payload);
        }
        
        printf("\n========== WORKER %d STATISTICS ==========\n", rank);
        printf("Packets Received : %d\n", packets_received);
        printf("Processing Status: Complete\n");
        printf("=========================================\n");
    }
    

    MPI_Finalize();

    return 0;
}