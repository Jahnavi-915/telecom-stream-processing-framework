# POSIX Threads Implementation Documentation

## Overview

A Producer-Consumer prototype has been implemented using POSIX Threads to simulate a simplified telecom stream processing environment.

The implementation validates thread synchronization, shared buffer management, inter-thread communication, performance monitoring, and testing methodologies that will serve as the foundation for future telecom packet processing frameworks.

### Source Files

```text
src/pthreads/stream.c
    POSIX Threads Producer-Consumer prototype

src/sockets/server.c
    TCP Server implementation

src/sockets/client.c
    TCP Client implementation

producer_consumer.cpp
    Planned modular implementation structure
```

---

## Implemented Components

### Producer Thread

Responsibilities:

* Generate frames.
* Insert frames into the shared buffer.
* Wait when the buffer is full.
* Signal the consumer when new data becomes available.

---

### Consumer Thread

Responsibilities:

* Remove frames from the shared buffer.
* Process consumed frames.
* Wait when the buffer is empty.
* Signal the producer when buffer space becomes available.

---

### Shared Buffer

Implementation:

* Circular queue
* Fixed-size buffer
* Shared between producer and consumer threads

Buffer Variables:

* `head` – Next frame removal position
* `tail` – Next frame insertion position
* `count` – Current number of frames stored

The circular buffer enables continuous stream processing while efficiently utilizing memory.

---

## Synchronization Mechanisms

### Mutex

Implementation:

```c
pthread_mutex_t lock;
```

Purpose:

* Protect shared buffer access
* Prevent race conditions
* Ensure mutual exclusion during buffer operations

---

### Condition Variables

Implemented:

```c
pthread_cond_t not_full;
pthread_cond_t not_empty;
```

Purpose:

* `not_full` – Producer waits when buffer capacity is exhausted.
* `not_empty` – Consumer waits when no frames are available.

These mechanisms coordinate producer-consumer execution while avoiding busy waiting.

---

## Data Structures

### Frame Structure

Current prototype:

```c
typedef struct {
    int frame_id;
} Frame;
```

Purpose:

* Validate synchronization behavior
* Verify buffer management logic
* Support testing and performance analysis

---

## Current Prototype Configuration

Baseline Configuration:

* Buffer Size: 5
* Total Frames Generated: 20
* Producer Threads: 1
* Consumer Threads: 1
* Producer Delay: 100 ms
* Consumer Delay: 100 ms

Additional configurations were used during testing and validation.

---

## Statistics Collection

### Implemented Metrics

#### Functional Metrics

* Frames Produced
* Frames Consumed

#### Synchronization Metrics

* Buffer Full Events
* Buffer Empty Events

#### Performance Metrics

* Execution Time
* Throughput
* Average Buffer Occupancy
* Buffer Utilization

These metrics are automatically collected during execution and used for validation and performance analysis.

---

## Testing and Validation

A complete testing and validation framework was developed and executed.

### Executed Test Cases

#### Functional and Validation Tests

* TC-01 Balanced Baseline
* TC-02 Small Buffer
* TC-03 Large Buffer
* TC-04 Fast Producer
* TC-05 Fast Consumer
* TC-06 High Volume

#### Extended Performance Tests

* TC-07 Slow System
* TC-08 Fast System
* TC-09 Maximum Throughput
* TC-10 Producer Burst
* TC-11 Consumer Burst

### Validation Outcomes

The implementation successfully demonstrated:

* Correct producer-consumer synchronization
* Stable execution under varying workloads
* No frame loss
* No frame duplication
* No deadlocks
* No race conditions
* Predictable throughput scaling
* Stable buffer management behavior

---

## Performance Summary

Observed throughput ranged from:

* Approximately 2 frames/sec (Slow System)
* Approximately 98 frames/sec (Fast System)
* Approximately 29,152 frames/sec (Maximum Throughput)

The implementation remained stable across all tested workload conditions.

---

## Current Limitations

The current implementation uses a simplified Frame structure containing only a frame identifier.

The prototype currently supports:

* One Producer Thread
* One Consumer Thread
* Single Shared Buffer

Future versions will introduce additional functionality and more realistic telecom workloads.

---

## Future Enhancements

### Data Model Enhancements

Introduce telecom-oriented Packet structures containing:

* Packet ID
* Priority
* Source Information
* Destination Information

### System Enhancements

* Multiple Producers
* Multiple Consumers
* Dynamic Buffer Management
* Priority-Based Scheduling
* Packet Classification

### Framework Integration

* POSIX Threads + Socket Programming Integration
* MPI-based Distributed Processing
* Hybrid MPI + POSIX Threads Processing
* Telecom Packet Streaming Framework

### Comparative Evaluation

The testing and validation framework will also be used to evaluate:

* External team implementations
* Socket-based implementations
* MPI-based implementations
* Hybrid implementations

---

## Conclusion

The POSIX Threads Producer-Consumer prototype successfully establishes a validated reference implementation for the Telecom Stream Processing Framework project. The implementation provides correct synchronization behavior, comprehensive performance metrics, and a reusable testing framework that will support future Socket Programming, MPI, and Hybrid Parallel Processing phases.

# Socket Communication Module

## Overview

In addition to the POSIX Threads Producer-Consumer prototype, a TCP-based Socket Communication prototype has been successfully implemented and validated.

The socket module simulates telecom packet transmission between a Data Extraction Server (DES) and a receiving client.

Implemented Features:

* TCP Server
* TCP Client
* Packet Transmission
* Packet Reception
* Packet Logging
* Execution Time Measurement
* Throughput Measurement
* Packet Delivery Statistics

## Packet Structure

```c
typedef struct
{
    int packet_id;
    char payload[100];
} Packet;
```

## Communication Workflow

```text
DES Server
      ↓
TCP Socket Connection
      ↓
Client
      ↓
Packet Logging
      ↓
Statistics Collection
```

## Implemented Metrics

### Server Side

* Total Packets Sent
* Execution Time
* Send Throughput

### Client Side

* Total Packets Received
* Execution Time
* Receive Throughput

### Communication Metrics

* Packet Loss
* Delivery Success Rate
* Packet Ordering Verification

## Validation Summary

The socket communication module was validated using six test cases:

* TC1 – Functional Test
* TC2 – Small Stream Test
* TC3 – Medium Stream Test
* TC4 – High Rate Stream Test
* TC5 – High Throughput Test
* TC6 – Stress Test

## Key Results

* Maximum Sustained Throughput: ~904 packets/sec
* Total Packets Sent: 1000
* Total Packets Received: 1000
* Packet Loss: 0
* Delivery Success Rate: 100%

The implementation successfully demonstrated reliable packet transmission and stable operation under stress conditions.

# Current Project Status

## Completed

### POSIX Threads Module

* Producer Thread
* Consumer Thread
* Shared Circular Buffer
* Mutex Synchronization
* Condition Variables
* Performance Monitoring
* Validation Framework

### Socket Programming Module

* TCP Server
* TCP Client
* Packet Streaming
* Packet Logging
* Throughput Measurement
* Validation and Stress Testing

### Testing Framework

* Test Case Catalog
* Validation Checklist
* Bug Report Template
* Observation Templates
* Validation Reports

### Documentation

* Architecture Design
* Implementation Documentation
* Progress Tracking
* Testing Documentation
* Performance Analysis Reports

These deliverables establish the foundation for future telecom packet processing, distributed processing, and hybrid parallel computing implementations.

### Next Development Phase

The next phase of the project will integrate the POSIX Threads Producer-Consumer architecture with the Socket Communication module.

Target Architecture:

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

This integrated architecture will serve as the first complete telecom stream-processing prototype.

# Pthreads + Socket Integration Module

## Overview

The Pthreads + Socket Integration Module combines the POSIX Threads Producer–Consumer architecture with the TCP Socket Communication model into a single end-to-end telecom packet streaming prototype.

The implementation enables packet generation, shared-buffer synchronization, network transmission, packet reception, logging, performance monitoring, and communication validation within a unified workflow.

For detailed architecture diagrams, workflow descriptions, and design decisions, refer to:

* design/integration_design.md
* design/architecture.md

---

## Source Files

```text
src/hybrid/pthreads_socket_integration/server.c
    Integrated Pthreads + Socket Server

src/hybrid/pthreads_socket_integration/client.c
    Integrated TCP Client Receiver
```

---

## Implemented Features

### Server Side

* Producer Thread
* Shared Circular Buffer
* Sender Thread
* Mutex Synchronization
* Condition Variables
* TCP Server
* Telecom Packet Generation
* Statistics Collection

### Client Side

* TCP Client
* Packet Reception
* Packet Display
* Packet Logging
* Statistics Collection

---

## Implemented Packet Structure

```c
typedef struct {
    int packet_id;
    int priority;
    char source[50];
    char destination[50];
    char payload[100];
} TelecomPacket;
```

The packet structure was introduced to simulate telecom packet transmission and provide support for packet identification, routing information, and payload handling.

---

## Implemented Statistics

### Server Statistics

* Packets Generated
* Packets Sent
* Buffer Full Events
* Buffer Empty Events
* Execution Time
* Send Throughput

### Client Statistics

* Packets Received
* Delivery Success Rate
* Execution Time
* Receive Throughput

---

## Testing Summary

The integration module was validated using six test scenarios:

* IC-01 Functional Test
* IC-02 Small Stream Test
* IC-03 Medium Stream Test
* IC-04 High Rate Stream Test
* IC-05 High Throughput Test
* IC-06 Stress Test

---

## Validation Summary

The implementation successfully demonstrated:

* Correct Producer–Sender synchronization
* Stable Shared Buffer operation
* Reliable TCP communication
* Correct packet transmission and reception
* Packet ordering preservation
* Zero packet loss
* No race conditions
* No deadlocks
* Stable execution under varying workloads

---

## Key Results

* Maximum Send Throughput: ~927 packets/sec
* Maximum Receive Throughput: ~927 packets/sec
* Total Packets Sent: 10,000
* Total Packets Received: 10,000
* Packet Loss: 0
* Delivery Success Rate: 100%

---

## Current Status

The Pthreads + Socket Integration Module has been successfully implemented, tested, validated, and documented.

This module serves as the foundation for future Multiple DES, MPI-based, and Hybrid MPI + POSIX Threads telecom stream-processing architectures.

# MPI Distributed Processing Module

## Overview

The MPI Distributed Processing Module extends the Telecom Stream Processing Framework from shared-memory and socket-based communication to distributed-memory parallel processing.

The implementation follows a Master–Worker architecture in which a Master Process simulates a Data Extraction Server (DES) and distributes telecom packets among multiple Worker Processes using MPI message-passing mechanisms.

The module validates distributed communication, packet distribution strategies, scalability, performance monitoring, and distributed workload management.

---

## Source Files

```text
src/mpi/mpi_stream.c
    MPI Distributed Processing Implementation

reports/GROUP-E_mpi/
    MPI Test Results
    MPI Validation Report
    MPI Observations Report
```

---

## Implementation Overview

The MPI module was implemented using a Master–Worker architecture. One MPI process acts as the Master Process (Rank 0) and simulates a Data Extraction Server (DES), while the remaining MPI processes act as Worker Processes responsible for receiving and processing telecom packets.

The implementation was developed using OpenMPI and the MPI message-passing model to support distributed packet communication and workload distribution.

---

## MPI Initialization

The MPI environment is initialized using:

```c
MPI_Init(&argc, &argv);
```

Each process obtains its rank and the total number of participating processes using:

```c
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);
```

Rank 0 is designated as the Master Process, while all remaining ranks operate as Worker Processes.

---

## Telecom Packet Structure

The following packet structure was implemented:

```c
typedef struct {
    int packet_id;
    int priority;
    char source[50];
    char destination[50];
    char payload[100];
} TelecomPacket;
```

The structure stores packet identification, routing information, and payload data used during communication between the Master and Worker Processes.

---

## Packet Generation

Packet generation is performed by the Master Process.

For each packet:

* Packet ID is assigned.
* Priority value is assigned.
* Source information is populated.
* Destination Worker information is populated.
* Payload information is generated.

Implementation:

```c
packet.packet_id = i;
packet.priority = 1;

strcpy(packet.source, "DES-1");

sprintf(packet.destination,
        "Worker-%d",
        worker_rank);

sprintf(packet.payload,
        "Telecom Packet #%d",
        i);
```

---

## Packet Distribution

Packets are distributed using a Round-Robin scheduling strategy.

Implementation:

```c
worker_rank++;

if(worker_rank >= size)
{
    worker_rank = 1;
}
```

This ensures balanced workload allocation among all available Worker Processes.

Example:

```text
Packet 1 → Worker 1
Packet 2 → Worker 2
Packet 3 → Worker 3
Packet 4 → Worker 1
...
```

---

## MPI Communication

Packet transmission is implemented using:

```c
MPI_Send(
    &packet,
    sizeof(TelecomPacket),
    MPI_BYTE,
    worker_rank,
    0,
    MPI_COMM_WORLD
);
```

Worker Processes receive packets using:

```c
MPI_Recv(
    &packet,
    sizeof(TelecomPacket),
    MPI_BYTE,
    0,
    0,
    MPI_COMM_WORLD,
    MPI_STATUS_IGNORE
);
```

The implementation uses blocking communication to ensure reliable packet delivery.

---

## Worker Processing

Each Worker Process continuously receives packets from the Master Process.

For each received packet:

* Packet information is extracted.
* Statistics are updated.
* Packet details are displayed.

Workers continue processing until a termination packet is received.

---

## Termination Mechanism

A special packet ID value is used to terminate Worker Processes:

```c
packet.packet_id = -1;
```

After transmitting all packets, the Master Process sends one termination packet to every Worker Process.

Workers terminate when:

```c
if(packet.packet_id == -1)
{
    break;
}
```

This mechanism ensures clean and controlled shutdown of all MPI processes.

---

## Statistics Collection

### Master Process Statistics

The Master Process collects:

* Packets Generated
* Packets Sent
* Execution Time
* Throughput
* Communication Success Rate

### Worker Process Statistics

Each Worker Process collects:

* Packets Received
* Processing Status

### Communication Statistics

* Packet Distribution Verification
* Load Distribution Verification
* Communication Success Rate
* Packet Ordering Verification

---

## Performance Measurement

Execution time is measured using:

```c
gettimeofday()
```

Throughput is calculated as:

```text
Throughput = Packets Sent / Execution Time
```

Communication Success Rate is calculated as:

```text
Success Rate =
(Packets Sent / Packets Generated) × 100
```

---

## Validation Outcome

The implementation was validated using six MPI test cases:

* MC-01 Functional Test
* MC-02 Multiple Worker Test
* MC-03 Medium Workload Test
* MC-04 High Workload Test
* MC-05 High Throughput Test
* MC-06 Stress Test

The results demonstrated:

* Correct MPI communication
* Successful Master–Worker coordination
* Balanced Round-Robin packet distribution
* Stable distributed execution
* Zero packet loss
* 100% Communication Success Rate

---

## Current Limitations

The current implementation supports:

* Single DES source
* One Master Process
* Multiple Worker Processes
* Static Round-Robin packet distribution

Workers currently perform packet reception and basic processing only.

---

## Multi-DES MPI Implementation

The Multi-DES MPI module extends the single-DES MPI implementation by introducing multiple Data Extraction Server (DES) processes that generate telecom packets concurrently.

### Source Files

```text
src/mpi/multi_des.c
    Multi-DES MPI implementation

logs/multi_des_packets.log
    Packet log generated by the Master Process
```

### Implemented Features

* Multiple DES Processes
* Master–Worker Communication
* Telecom Packet Generation
* Round-Robin Packet Distribution
* Packet Logging
* Worker Load Collection
* Performance Monitoring
* Distributed Statistics Collection

### Process Responsibilities

**Master Process (Rank 0)**

* Receives packets from all DES processes
* Logs packet information
* Distributes packets to Workers
* Collects Worker statistics
* Generates global statistics

**DES Processes (Ranks 1–3)**

* Generate telecom packets
* Populate packet metadata
* Send packets to the Master Process

**Worker Processes**

* Receive packets from the Master Process
* Process assigned packets
* Report workload statistics

### Implemented Statistics

* Packets Generated
* Packets Received
* Packets Distributed
* Packets Processed
* Execution Time
* Throughput
* Packet Loss
* Communication Success Rate
* Average Worker Load
* Maximum Worker Load
* Minimum Worker Load

### Logging

The Master Process records all received packets in:

```text
logs/multi_des_packets.log
```

for communication verification and validation purposes.

### Validation Summary

The implementation was validated using:

* MD-01 Functional Test
* MD-02 Single Worker Test
* MD-03 Multiple Worker Test
* MD-04 Load Balancing Test
* MD-05 High Workload Test
* MD-06 Scalability Test
* MD-07 Stress Test

Results:

* Communication Success Rate = 100%
* Packet Loss = 0
* Balanced Worker Utilization
* Successful Processing of 30,000 Packets

```
```


## Future Enhancements

Planned improvements include:

* Multiple DES simulation
* Dynamic load balancing
* Telecom packet classification
* Worker-to-Master result aggregation
* Distributed statistics collection
* Hybrid MPI + POSIX Threads integration

These enhancements will extend the framework toward large-scale telecom stream-processing environments.
