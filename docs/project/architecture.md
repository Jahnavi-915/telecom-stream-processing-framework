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

## Future Integration Architecture

The next phase of the project will integrate the POSIX Threads producer-consumer framework with the socket communication module.

Future workflow:

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
       ↓
Packet Processing
```

This architecture combines thread-based packet generation, shared-buffer synchronization, and socket-based communication to simulate a telecom stream-processing environment.

## Future Expansion

The architecture will evolve to support:

* Multiple Data Extraction Servers
* Real-time packet streams
* Client-Server communication
* MPI-based distributed processing
* Hybrid parallel processing frameworks

