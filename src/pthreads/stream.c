#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

#define BUFFER_SIZE 5

// Statistics Counters
int produced_count = 0;
int consumed_count = 0;
int buffer_full_events = 0;
int buffer_empty_events = 0;
int total_buffer_occupancy = 0;
int occupancy_samples = 0;

typedef struct {
    int frame_id;
} Frame;

typedef struct {
    Frame queue[BUFFER_SIZE];
    int head;
    int tail;
    int count;
    pthread_mutex_t lock;
    pthread_cond_t not_full;
    pthread_cond_t not_empty;
} SharedBuffer;

void* producer_thread(void* arg) {
    SharedBuffer* buffer = (SharedBuffer*)arg;
    for (int i = 1; i <= 20; i++) {
        pthread_mutex_lock(&buffer->lock);
        
        while (buffer->count == BUFFER_SIZE) {
            buffer_full_events++;
            printf("[Producer] Buffer FULL. Waiting...\n");
            pthread_cond_wait(&buffer->not_full, &buffer->lock);
        }
        
        Frame new_frame;
        new_frame.frame_id = i;
        buffer->queue[buffer->tail] = new_frame;
        buffer->tail = (buffer->tail + 1) % BUFFER_SIZE;
        buffer->count++;
        total_buffer_occupancy += buffer->count;
        occupancy_samples++;

        produced_count++;
        
        printf("[Producer] Produced Frame ID: %d (Total in buffer: %d)\n", i, buffer->count);
        
        pthread_cond_signal(&buffer->not_empty);
        pthread_mutex_unlock(&buffer->lock);
        
        usleep(100000);
    }
    return NULL;
}

void* consumer_thread(void* arg) {
    SharedBuffer* buffer = (SharedBuffer*)arg;
    for (int i = 1; i <= 20; i++) {
        pthread_mutex_lock(&buffer->lock);
        
        while (buffer->count == 0) {
            buffer_empty_events++;
            printf("[Consumer] Buffer EMPTY. Waiting...\n");
            pthread_cond_wait(&buffer->not_empty, &buffer->lock);
        }
        
        Frame consumed_frame = buffer->queue[buffer->head];
        buffer->head = (buffer->head + 1) % BUFFER_SIZE;
        buffer->count--;

        consumed_count++;
        total_buffer_occupancy += buffer->count;
        occupancy_samples++;
        
        printf("[Consumer] Consumed Frame ID: %d (Total in buffer: %d)\n", consumed_frame.frame_id, buffer->count);
        
        pthread_cond_signal(&buffer->not_full);
        pthread_mutex_unlock(&buffer->lock);
        
        usleep(100000);
    }
    return NULL;
}

int main() {
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    SharedBuffer buffer;
    buffer.head = 0;
    buffer.tail = 0;
    buffer.count = 0;
    
    pthread_mutex_init(&buffer.lock, NULL);
    pthread_cond_init(&buffer.not_full, NULL);
    pthread_cond_init(&buffer.not_empty, NULL);
    
    pthread_t producer_id;
    pthread_t consumer_id;
    
    printf("Starting Telecom Stream Prototype...\n");
    
    pthread_create(&producer_id, NULL, producer_thread, &buffer);
    pthread_create(&consumer_id, NULL, consumer_thread, &buffer);
    
    pthread_join(producer_id, NULL);
    pthread_join(consumer_id, NULL);
    
    printf("Stream Processing Complete.\n");
    
    gettimeofday(&end_time, NULL);

    double execution_time =(end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
    double throughput = 0.0;

    if (execution_time > 0)
    {
        throughput = consumed_count / execution_time;
    }
    double avg_occupancy = 0.0;

    if (occupancy_samples > 0)
    {
        avg_occupancy = (double) total_buffer_occupancy /occupancy_samples;
    }
    double utilization = (avg_occupancy / BUFFER_SIZE) * 100;


    printf("\n=== Statistics ===\n");

    printf("Frames Produced : %d\n", produced_count);
    printf("Frames Consumed : %d\n", consumed_count);
    printf("Buffer Full Events : %d\n", buffer_full_events);
    printf("Buffer Empty Events : %d\n", buffer_empty_events);
    printf("Execution Time : %.4f seconds\n", execution_time);
    printf("Throughput : %.2f frames/sec\n", throughput);
    printf("Average Buffer Occupancy : %.2f\n",avg_occupancy);
    printf("Buffer Utilization : %.2f%%\n",utilization);
 
    pthread_mutex_destroy(&buffer.lock);
    pthread_cond_destroy(&buffer.not_full);
    pthread_cond_destroy(&buffer.not_empty);

    return 0;
}
