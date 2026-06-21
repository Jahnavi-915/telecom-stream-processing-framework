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

# Socket Programming Prototype Design

### Objective

Implement a TCP-based client-server communication framework to simulate telecom packet transmission between a Data Extraction Server (DES) and a receiving client.

### Components

#### DES Server

Acts as a packet producer.

Responsibilities:

* Create TCP socket
* Listen for client connections
* Generate telecom packets
* Transmit packets to connected clients
* Collect transmission statistics

#### Client

Acts as a packet receiver.

Responsibilities:

* Establish TCP connection with DES
* Receive incoming packets
* Process received packets
* Log packet information
* Collect reception statistics

#### Communication Channel

A TCP socket connection provides reliable communication between the DES server and client.

### Socket Communication Workflow

```text
DES Server
      ↓
TCP Socket Connection
      ↓
Client
```

### Packet Streaming Workflow

```text
Packet Generation
        ↓
TCP Transmission
        ↓
Packet Reception
        ↓
Packet Logging
        ↓
Statistics Collection
```

### Packet Structure

The current prototype uses the following packet structure:

```c
typedef struct
{
    int packet_id;
    char payload[100];
} Packet;
```

Each packet contains:

* Packet Identifier
* Packet Payload

This simplified structure serves as the foundation for future telecom packet formats.

### Communication Sequence

#### Server Workflow

1. Create socket
2. Bind socket to port
3. Listen for client connections
4. Accept incoming connection
5. Generate packets
6. Send packets through TCP
7. Record transmission statistics
8. Close connection

#### Client Workflow

1. Create socket
2. Connect to server
3. Receive packets
4. Log packet information
5. Record reception statistics
6. Close connection

### Performance Metrics

The following metrics are collected:

#### Server Side

* Total Packets Sent
* Execution Time
* Send Throughput

#### Client Side

* Total Packets Received
* Execution Time
* Receive Throughput

#### Overall Communication Metrics

* Packet Loss
* Delivery Success Rate
* Packet Ordering Verification

### Logging Design

The client maintains a packet log file to record all received packets during execution.

#### Log File

```text
logs/received_packets.log
```

#### Logged Information

For each packet received:

* Packet ID
* Packet Payload

Example:

```text
Packet ID : 1 | Payload : Telecom Packet 1
Packet ID : 2 | Payload : Telecom Packet 2
```

The logging mechanism supports debugging, packet verification, and validation activities.


### Expected Outcome

A reliable TCP-based packet communication framework capable of serving as the communication layer for future telecom stream-processing architectures involving POSIX Threads, MPI, and Hybrid processing models.

# Integrated Pthreads + Socket Architecture

## Overview

The next phase of the project integrates the POSIX Threads Producer–Consumer model with the TCP Socket communication framework to establish an end-to-end telecom packet streaming architecture.

### Workflow

```text
Producer Thread
       ↓
Shared Buffer
       ↓
Sender Thread
       ↓
TCP Socket
       ↓
Client
```

### Purpose

The integrated architecture combines shared-memory processing and network communication, enabling packets generated by the Producer Thread to be transmitted through a TCP communication channel and received by a client application.

This integration represents the first complete telecom packet streaming prototype developed within the project and serves as a bridge between local stream processing and network-based communication.

### Detailed Design Documentation

Detailed information regarding:

* Component responsibilities
* Telecom packet structure
* Packet lifecycle
* Synchronization mechanisms
* Statistics collection framework
* Validation strategy
* Testing methodology
* Expected outcomes

is maintained separately in:

```text
docs/design/integration_design.md
```

to avoid duplication and provide a dedicated design document for the integration module.

### Expected Outcome

The integrated architecture will establish a complete telecom packet streaming workflow capable of packet generation, buffering, transmission, reception, and logging while maintaining synchronization correctness and communication reliability.

This architecture will serve as the foundation for future MPI-based communication, Multiple Data Extraction Server (DES) architectures, and Hybrid MPI + POSIX Threads processing frameworks.

# MPI Distributed Processing Architecture

## Overview

The MPI Distributed Processing Architecture extends the Telecom Stream Processing Framework from shared-memory processing to distributed-memory parallel processing.

The architecture introduces a Master–Worker communication model in which a Master Process coordinates packet distribution while multiple Worker Processes perform distributed packet processing.

### Workflow

```text
Data Extraction Server (DES)
            │
            ▼
      Master Process
            │
            ▼
   MPI Communication Layer
            │
    ┌───────┼───────┐
    ▼       ▼       ▼
 Worker 1 Worker 2 Worker 3
            │
            ▼
 Distributed Processing
            │
            ▼
     Statistics Collection
```

### Purpose

The MPI architecture provides:

* Distributed packet communication
* Process-level parallelism
* Scalable workload distribution
* Distributed performance evaluation
* Foundation for Multi-DES processing

### Detailed Design Documentation

Detailed information regarding:

* Master–Worker architecture
* Packet distribution strategy
* MPI communication mechanisms
* Statistics collection framework
* Validation methodology
* Performance analysis

is maintained separately in:

```text
docs/design/mpi_design.md
```

### Expected Outcome

A distributed processing framework capable of reliable packet communication, scalable workload allocation, and distributed telecom stream processing.

---

# Multi-DES MPI Architecture

## Overview

The Multi-DES Architecture extends the MPI framework by introducing multiple Data Extraction Servers operating simultaneously within the distributed processing environment.

Each DES independently generates telecom packets, which are collected and distributed through the MPI communication layer for parallel processing.

### Workflow

```text
           DES-1
             │
             ▼
           DES-2
             │
             ▼
           DES-3
             │
             ▼
    Master Coordinator
             │
             ▼
    MPI Communication Layer
             │
      ┌──────┼──────┐
      ▼      ▼      ▼
   Worker1 Worker2 Worker3
             │
             ▼
    Statistics Collection
```

### Purpose

The Multi-DES architecture provides:

* Multiple telecom traffic sources
* Concurrent packet generation
* Distributed packet collection
* Improved scalability
* Realistic telecom stream simulation
* Foundation for large-scale telecom analytics

### Detailed Design Documentation

Detailed information regarding:

* DES process architecture
* Master Coordinator responsibilities
* Worker Process design
* Packet aggregation workflow
* Load balancing strategy
* Distributed statistics collection

is maintained separately in:

```text
docs/design/multi_des_design.md
```

### Expected Outcome

A scalable distributed telecom stream-processing architecture capable of collecting packets from multiple Data Extraction Servers and processing them efficiently across multiple Worker Processes.


## Future Expansion

The architecture will evolve to support:

* Hybrid MPI + POSIX Threads processing
* Dynamic load balancing
* Telecom packet classification
* Distributed statistics aggregation
* Fault tolerance mechanisms
* Large-scale multi-node deployment

