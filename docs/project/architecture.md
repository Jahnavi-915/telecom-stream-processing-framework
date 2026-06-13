# System Architecture

## Project Goal

Develop and evaluate efficient algorithms and processing frameworks for real-time telecom stream processing using multiple parallel and distributed computing approaches.

---

## Processing Approaches Under Investigation

1. POSIX Threads (Pthreads)
2. Socket Programming
3. MPI (Message Passing Interface)
4. Hybrid MPI + Pthreads Models

---

## High-Level Workflow

```text
Multiple Data Extraction Servers (DES)
                 │
                 ▼
        Communication Layer
      (Sockets / MPI Frameworks)
                 │
                 ▼
         Stream Processing Layer
      (Pthreads / MPI / Hybrid)
                 │
                 ▼
      Synchronization & Buffering
                 │
                 ▼
         Analytics & Processing
                 │
                 ▼
              Results
```

---

## Initial Prototype Architecture

The first prototype is based on a Streaming Media Player model.

```text
Streaming Source
       ↓
Producer Thread
       ↓
Shared Buffer
       ↓
Consumer Thread
       ↓
Output
```

This architecture serves as a reference model for future telecom packet processing implementations.

---

# POSIX Threads Prototype Design

### Objective

Implement a Producer-Consumer model using POSIX Threads to simulate telecom stream processing and establish a foundation for future packet processing frameworks.

### Components

#### Producer Thread

Generates frames and inserts them into a shared buffer.

#### Shared Buffer

A circular queue shared between producer and consumer threads.

#### Consumer Thread

Removes frames from the shared buffer and processes them.

### Producer-Consumer Synchronization

The producer and consumer threads communicate through a shared circular buffer.

#### Producer Workflow

1. Generate frame
2. Acquire mutex
3. Check buffer availability
4. Insert frame into buffer
5. Signal consumer
6. Release mutex

#### Consumer Workflow

1. Acquire mutex
2. Check buffer availability
3. Remove frame from buffer
4. Process frame
5. Signal producer
6. Release mutex

### Synchronization Mechanisms

The design utilizes:

* pthread_mutex_t
* pthread_cond_t (not_full)
* pthread_cond_t (not_empty)

These mechanisms ensure safe access to the shared buffer, prevent race conditions, and coordinate producer-consumer execution.

### Shared Buffer Design

The prototype uses a circular buffer with the following components:

* Queue for storing frames
* Head pointer for frame removal
* Tail pointer for frame insertion
* Count variable to track current occupancy

This design enables efficient continuous stream processing.

### Data Structure Design

The current architectural design defines a telecom-oriented Packet structure containing:

* Packet ID
* Priority
* Source Information
* Destination Information

For prototype validation, a simplified Frame structure may be used to verify synchronization and buffer management functionality before transitioning to telecom packet processing.

### Performance Metrics

The following statistics are planned for collection and analysis:

* Frames Produced
* Frames Consumed
* Buffer Full Events
* Buffer Empty Events
* Execution Time
* Throughput
* Buffer Utilization

### Future Extensions

The architecture is designed to support future enhancements including:

* Telecom Packet Processing
* Socket Programming Based Communication
* MPI Based Distributed Processing
* Hybrid MPI + POSIX Threads Models

### Expected Outcome

A reliable and scalable producer-consumer architecture capable of serving as the foundation for telecom stream processing and distributed processing frameworks.


## Future Expansion

The architecture will evolve to support:

* Multiple Data Extraction Servers
* Real-time packet streams
* Client-Server communication
* MPI-based distributed processing
* Hybrid parallel processing frameworks

