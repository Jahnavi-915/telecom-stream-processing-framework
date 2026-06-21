#include <stdio.h>
#include <string.h>
#include <mpi.h>
#include <sys/time.h>

#define DES_COUNT 3
#define PACKETS_PER_DES 100

typedef struct
{
    int packet_id;
    int des_id;
    int priority;
    char source[50];
    char destination[50];
    char payload[100];
} TelecomPacket;

int main(int argc, char *argv[])
{
    int rank, size;
    FILE *log_file;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if(size < 5)
    {
        if(rank == 0)
        {
            printf("Run with at least 5 processes\n");
            printf("Rank 0  -> Master\n");
            printf("Rank 1-3 -> DES Processes\n");
            printf("Rank 4+ -> Workers\n");
        }

        MPI_Finalize();
        return 0;
    }

    TelecomPacket packet;

    int packets_generated = 0;
    int packets_received = 0;
    int packets_distributed = 0;
    int packets_processed = 0;

    struct timeval start_time, end_time;

    /* ================= MASTER ================= */

    if(rank == 0)
    {
        gettimeofday(&start_time,NULL);

        int total_expected_packets = DES_COUNT * PACKETS_PER_DES;

        int worker_start = DES_COUNT + 1;
        int worker_rank = worker_start;

        log_file = fopen("../../logs/multi_des_packets.log", "w");

        if(log_file == NULL)
        {
            printf("Unable to create log file\n");
            MPI_Finalize();
            return 1;
        }

        fprintf(log_file,"PacketID,DES_ID,Source,Destination,Payload\n");

        for(int i=0;i<total_expected_packets;i++)
        {
            MPI_Recv(&packet,sizeof(TelecomPacket),MPI_BYTE,MPI_ANY_SOURCE,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);

            packets_received++;

            fprintf(log_file,"%d,%d,%s,%s,%s\n",packet.packet_id,packet.des_id,packet.source,packet.destination,packet.payload);

            sprintf(packet.destination,"Worker-%d",worker_rank);

            MPI_Send(&packet,sizeof(TelecomPacket),MPI_BYTE,worker_rank,0,MPI_COMM_WORLD);

            packets_distributed++;

            worker_rank++;

            if(worker_rank >= size)
                worker_rank = worker_start;
        }

        packet.packet_id = -1;

        for(int i=worker_start;i<size;i++)
        {
            MPI_Send(&packet,sizeof(TelecomPacket),MPI_BYTE,i,0,MPI_COMM_WORLD);
        }

        int total_processed = 0;

        int worker_count = size - worker_start;

        int worker_loads[100];

        for(int i=worker_start;i<size;i++)
        {
            int load;

            MPI_Recv(&load,1,MPI_INT,i,1,MPI_COMM_WORLD,MPI_STATUS_IGNORE);

            worker_loads[i-worker_start] = load;

            total_processed += load;
        }

        gettimeofday(&end_time,NULL);

        double execution_time = (end_time.tv_sec - start_time.tv_sec)+(end_time.tv_usec - start_time.tv_usec)/1000000.0;

        double throughput = 0.0;

        if(execution_time > 0)
            throughput = packets_distributed/execution_time;

        int packet_loss = total_expected_packets - total_processed;

        double success_rate = 0.0;

        if(total_expected_packets > 0)
        {
            success_rate = ((double)total_processed / total_expected_packets) * 100.0;
        }

        int max_load = worker_loads[0];
        int min_load = worker_loads[0];

        for(int i=0;i<worker_count;i++)
        {
            if(worker_loads[i] > max_load)
                max_load = worker_loads[i];

            if(worker_loads[i] < min_load)
                min_load = worker_loads[i];
        }

        double avg_load = (double)total_processed / worker_count;

        printf("\n========== DES STATISTICS ==========\n");
        printf("DES-1 Generated : %d\n", PACKETS_PER_DES);
        printf("DES-2 Generated : %d\n", PACKETS_PER_DES);
        printf("DES-3 Generated : %d\n", PACKETS_PER_DES);
        printf("Total Generated : %d\n", total_expected_packets);

        printf("\n========== MASTER STATISTICS ==========\n");
        printf("Packets Received    : %d\n",packets_received);
        printf("Packets Distributed : %d\n",packets_distributed);
        printf("Execution Time      : %.6f sec\n",execution_time);
        printf("Throughput          : %.2f packets/sec\n",throughput);

        printf("\n========== WORKER LOADS ==========\n");

        for(int i=worker_start;i<size;i++)
        {
            printf("Worker %d Processed : %d\n",i,worker_loads[i-worker_start]);
        }

        printf("\n========== GLOBAL STATISTICS ==========\n");
        printf("Total Generated     : %d\n",total_expected_packets);
        printf("Total Distributed   : %d\n",packets_distributed);
        printf("Total Processed     : %d\n",total_processed);
        printf("Packet Loss         : %d\n",packet_loss);
        printf("Success Rate        : %.2f%%\n",success_rate);
        printf("Average Worker Load : %.2f\n",avg_load);
        printf("Maximum Worker Load : %d\n",max_load);
        printf("Minimum Worker Load : %d\n",min_load);
        printf("=======================================\n");
    }

    /* ================= DES ================= */

    else if(rank >= 1 && rank <= DES_COUNT)
    {
        for(int i=1;i<=PACKETS_PER_DES;i++)
        {
            packet.packet_id = i;
            packet.des_id = rank;
            packet.priority = 1;

            sprintf(packet.source,"DES-%d",rank);

            strcpy(packet.destination,"MASTER");

            sprintf(packet.payload,"Packet %d from DES-%d",i,rank);

            MPI_Send(&packet,sizeof(TelecomPacket),MPI_BYTE,0,0,MPI_COMM_WORLD);

            packets_generated++;
        }

        printf("[DES-%d] Packets Generated : %d\n",rank,packets_generated);
    }

    /* ================= WORKERS ================= */

    else
    {
        while(1)
        {
            MPI_Recv(&packet,sizeof(TelecomPacket),MPI_BYTE,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);

            if(packet.packet_id == -1)
                break;

            packets_processed++;
        }

        printf("[WORKER %d] Packets Processed : %d\n",rank,packets_processed);

        MPI_Send(&packets_processed,1,MPI_INT,0,1,MPI_COMM_WORLD);
    }

    if(rank == 0)
    {
        fclose(log_file);
    }

    MPI_Finalize();

    return 0;
}