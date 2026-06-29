# Hybrid System Design

## Purpose

This document describes the internal design of the Hybrid Telecom Stream Processing Framework.

## Implementation Strategy

The Hybrid Telecom Stream Processing Framework is developed incrementally using reusable modules from previous project phases.

The implementation strategy consists of four stages:

### Stage 1
- POSIX Threads Prototype
- TCP Socket Prototype
- Pthreads + Socket Integration
- MPI Communication
- Multi-DES Framework

### Stage 2 (Current)
- Group-E Communication Prototype
- Group-F Processing Prototype
- Independent Testing and Validation
- Cross Validation

### Stage 3
- Hybrid MPI-Pthreads Integration
- Unified Hybrid Algorithm
- End-to-End Testing

### Stage 4
- Berkeley DB
- Graph Construction
- Analytics
- Monitoring
- Cluster Deployment

---

# Module Overview

## Communication Module

### Description

Responsible for receiving telecom traffic from multiple Data Extraction Servers and distributing packets across processing nodes using MPI.

### Responsibilities

- Traffic generation
- DES communication
- MPI client-server communication
- Packet serialization
- Packet routing
- Packet distribution
- Delay injection
- Communication statistics
- Cluster communication support

### Input 

* Telecom traffic packets

### Output

* Packets forwarded to the Processing Module

---

## Processing Module

### Description

Responsible for buffering, synchronization, and parallel packet processing using POSIX Threads.

### Responsibilities

- Shared packet queue
- Thread pool management
- Producer-consumer synchronization
- Read/Write lock synchronization
- Packet processing

### Input

* Packets received from the Communication Module

### Output

* Processed packet records

---

## Storage Module


### Description

Responsible for persistent storage of processed telecom data using Berkeley DB.

### Responsibilities

- Packet storage
- Metadata storage
- Database management

### Input

- Processed packets

### Output

- Stored packet records

---

## Graph Module

### Description

Responsible for constructing communication graphs from telecom traffic.

### Responsibilities

- Vertex creation
- Edge creation
- Edge weight management
- Graph statistics generation

### Input

- Processed telecom packets

### Output

- Traffic graphs

---

## Analytics Module

### Description

Responsible for traffic analysis, graph analysis, and performance evaluation.

### Responsibilities

- Traffic analysis
- Utilization analysis
- Graph analysis
- Report generation

### Input

- Graph data
- Database records
- Performance statistics

### Output

- Analytics reports

---

## Monitoring Module

### Description

Responsible for runtime logging, statistics collection, and performance monitoring.

### Responsibilities

- Logging
- Statistics collection
- Throughput measurement
- Performance monitoring

### Input

- Runtime events

### Output

- Logs
- Statistics
- Performance metrics

---

# Data Flow

The Hybrid Telecom Stream Processing Framework follows the data flow shown below.

```text
Traffic Source
        │
        ▼
Traffic Generator
        │
        ▼
Data Extraction Servers
        │
        ▼
MPI Client(s)
        │
        ▼
MPI Server
        │
        ▼
Shared Packet Queue
        │
        ▼
Worker Thread Pool
        │
        ▼
Packet Processing Engine
        │
        ▼
Berkeley DB
        │
        ▼
Graph Construction
        │
        ▼
Analytics
```

## Step 1: Traffic Ingestion

Traffic is received from real-time streams, telecom traces, network traces, or CSV datasets.

The traffic is converted into TelecomPacket structures.

---

## Step 2: Data Extraction Servers

Multiple DES processes generate or ingest telecom traffic and forward packets to the MPI communication layer.

---

## Step 3: MPI Communication

MPI client processes receive telecom packets from one or more Data Extraction Servers (DES) and distribute them to the MPI server process for further processing. The communication layer supports both single-machine execution and future multi-node cluster deployment.

Responsibilities:

- Packet reception
- Packet routing
- Packet distribution
- Cluster communication

---

## Step 4: Shared Buffer

Packets received by the MPI server are inserted into the shared packet queue, which serves as the communication interface between the distributed communication layer and the multithreaded processing layer.

Responsibilities:

- Packet buffering
- Synchronization
- Temporary storage

---

## Step 5: Worker Thread Pool

Worker threads retrieve packets from the shared packet queue, synchronize access using shared-memory synchronization primitives, and perform packet processing in parallel.

Responsibilities:

- Parallel processing
- Workload distribution
- Packet handling

---

## Step 6: Graph Construction

Processed packets are converted into graph structures.

Graph Representation:

```text
Source Node ─────► Destination Node
```

Edge weights represent traffic volume.

---

## Step 7: Berkeley DB Storage

Processed packet records and graph information are stored persistently.

Responsibilities:

- Packet storage
- Metadata storage
- Graph storage

---

## Step 8: Analytics

The analytics engine processes stored information and generates:

- Traffic statistics
- Graph statistics
- Performance metrics
- Utilization metrics

---

## Step 9: Reporting

The generated analytics are converted into:

- Reports
- Performance summaries
- Validation reports
- Visualizations

---

# Data Structures

## TelecomPacket

The TelecomPacket structure is the primary data unit used throughout the Hybrid Telecom Stream Processing Framework.

All modules exchange information using this structure.

### Structure Definition

```c
typedef struct
{
    int packet_id;
    int des_id;

    char timestamp[32];

    char source[64];
    char destination[64];

    int priority;

    char traffic_type[32];

    int packet_size;

    char payload[256];
} TelecomPacket;
```

### Field Description

| Field | Description |
|---------|-------------|
| packet_id | Unique packet identifier |
| des_id | Source DES identifier |
| timestamp | Packet generation timestamp |
| source | Source telecom node |
| destination | Destination telecom node |
| priority | Packet priority level |
| traffic_type | Voice, Data, SMS, Control, etc. |
| packet_size | Packet size in bytes |
| payload | Packet payload information |

---

## Shared Packet Queue

The Shared Packet Queue stores TelecomPacket objects received from the communication layer before processing by the worker thread pool.

Responsibilities:

- Temporary packet storage
- Producer–consumer synchronization
- Thread-safe access

---

## Graph Edge

The Graph Engine converts packet communication into graph edges.

### Representation

```text
Source Node ─────► Destination Node
```

### Edge Attributes

- Source Vertex
- Destination Vertex
- Traffic Volume
- Packet Count

---

## Analytics Record

Analytics records are generated from processed traffic data.

Example Metrics:

- Total Packets Processed
- Throughput
- DES Utilization
- Worker Utilization
- Graph Statistics

---

# Component Mapping

This section identifies reusable components from existing implementations and new modules required for the Hybrid Telecom Stream Processing Framework.

---

## Components Reused from Previous Project Phases

### MPI Communication Framework

Source:

```text
src/mpi/
```

Reusable Components:

- MPI Initialization
- MPI Communication
- Multi-DES Framework
- Packet Distribution
- Load Distribution Logic
- Statistics Collection

Usage:

Responsible for communication between DES processes and processing nodes.

---

### Monitoring Framework

Source:

```text
src/mpi/
src/integration/
src/pthreads/
```

Reusable Components:

- Throughput Measurement
- Execution Time Measurement
- Statistics Collection
- Packet Logging

Usage:

Responsible for runtime monitoring and performance analysis.

---

## Components Reused from Group-F

### Shared Buffer Framework

Reusable Components:

- Shared Buffer
- Buffer Management
- Buffer Synchronization

Usage:

Stores packets received from the MPI layer before processing.

---

### Thread Management Framework

Reusable Components:

- Producer–Consumer Logic
- Consumer Threads
- Thread Creation
- Thread Synchronization

Usage:

Processes packets in parallel.

---

### Packet Processing Framework

Reusable Components:

- Packet Handling Logic
- Processing Functions

Usage:

Performs packet-level processing before graph construction and storage.

---

## New Modules to be Implemented

### Storage Module

Location:

```text
src/hybrid/database/
```

Responsibilities:

- Berkeley DB Integration
- Packet Storage
- Metadata Storage
- Record Retrieval

Status:

Planned

---

### Graph Module

Location:

```text
src/hybrid/graph/
```

Responsibilities:

- Vertex Management
- Edge Management
- Traffic Graph Construction
- Graph Statistics

Status:

Planned

---

### Analytics Module

Location:

```text
src/hybrid/analytics/
```

Responsibilities:

- Traffic Analysis
- Utilization Analysis
- Graph Analysis
- Report Generation

Status:

Planned

---

## Hybrid Integration Layer

Location:

```text
src/hybrid/
```

Responsibilities:

- Integrate MPI Layer
- Integrate Shared Buffer
- Integrate Thread Pool
- Coordinate Data Flow
- Manage End-to-End Processing

Status: Planned

This layer will be implemented after independent completion and validation of the communication and processing prototypes.

# Current Development Status

## Completed

- POSIX Threads Framework
- TCP Socket Framework
- Pthreads + Socket Integration
- MPI Framework
- Multi-DES Framework

## Current Phase

- Group-E Communication Prototype
- Group-F Processing Prototype
- Independent Testing and Validation

## Planned

- Hybrid Integration
- Berkeley DB Integration
- Graph Construction
- Analytics
- Cluster Deployment

# APIs

## Communication Module APIs

### MPI Initialization

```c
int initialize_mpi(int *argc, char ***argv);
```

### MPI Finalization

```c
void finalize_mpi(void);
```

### Traffic Generation

```c
TelecomPacket generate_packet(void);
```

### Packet Serialization

```c
int serialize_packet(TelecomPacket *packet,
                     char *buffer);
```

### Packet Deserialization

```c
int deserialize_packet(char *buffer,
                       TelecomPacket *packet);
```

### Packet Distribution

```c
int distribute_packet(TelecomPacket *packet);
```

### Client Communication

```c
int send_packet(TelecomPacket *packet);
```

### Server Communication

```c
int receive_packet(TelecomPacket *packet);
```

---

## Processing Module APIs

### Queue Initialization

```c
int initialize_queue(void);
```

### Shared Buffer Insert

```c
int enqueue_packet(TelecomPacket *packet);
```

### Shared Buffer Remove

```c
int dequeue_packet(TelecomPacket *packet);
```

### Queue Size

```c
int queue_size(void);
```

### Worker Thread Creation

```c
int create_worker_pool(int thread_count);
```

### Worker Pool Shutdown

```c
void destroy_worker_pool(void);
```

### Queue Destruction

```c
int destroy_queue(void);
```

---

## Storage Module API

### Database Initialization

```c
int initialize_database(void);
```

### Store Packet

```c
int store_packet(TelecomPacket *packet);
```

### Close Database

```c
void close_database(void);
```

---

## Graph Module APIs

### Add Vertex

```c
int add_vertex(const char *node);
```

### Add Edge

```c
int add_edge(const char *source,
             const char *destination);
```

### Update Edge Weight

```c
int update_edge_weight(const char *source,
                       const char *destination);
```

---

## Analytics Module APIs

### Generate Traffic Statistics

```c
void generate_traffic_statistics(void);
```

### Generate Graph Statistics

```c
void generate_graph_statistics(void);
```

### Generate Performance Statistics

```c
void generate_performance_statistics(void);
```

---

## Monitoring Module APIs

### Log Event

```c
void log_event(const char *message);
```

### Update Statistics

```c
void update_statistics(void);
```

### Generate Runtime Report

```c
void generate_runtime_report(void);
```

### Start Timer

```c
void start_timer(void);
```

### Stop Timer

```c
void stop_timer(void);
```

### Print Statistics

```c
void print_statistics(void);
```
