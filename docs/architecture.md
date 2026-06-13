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

## POSIX Threads Prototype Design

### Objective

Implement a Producer-Consumer model using POSIX Threads to simulate telecom stream processing.

### Components

#### Producer Thread

Generates packets and inserts them into a shared buffer.

#### Shared Buffer

A circular queue shared between producer and consumer threads.

#### Consumer Thread

Removes packets from the buffer and processes them.

### Synchronization Mechanisms

The implementation will use:

- pthread_mutex_t
- pthread_cond_t

to ensure safe access to the shared buffer and prevent race conditions.

### Performance Metrics

The following statistics will be collected:

- Packets Produced
- Packets Consumed
- Buffer Full Events
- Buffer Empty Events

### Expected Outcome

A working producer-consumer simulation that serves as the foundation for future telecom packet processing implementations.


## Future Expansion

The architecture will evolve to support:

* Multiple Data Extraction Servers
* Real-time packet streams
* Client-Server communication
* MPI-based distributed processing
* Hybrid parallel processing frameworks

