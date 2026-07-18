# Hybrid System Design

## Purpose

This document describes the internal design of the Hybrid Telecom Stream Processing Framework.

---

# Module Overview

## Communication Module

### Description

Responsible for receiving telecom traffic from multiple Data Extraction Servers and distributing packets across processing nodes using MPI.

### Responsibilities

* DES communication
* MPI communication
* Packet distribution
* Cluster communication

### Input 

* Telecom traffic packets

### Output

* Packets forwarded to the Processing Module

---

## Processing Module

### Description

Responsible for buffering, synchronization, and parallel packet processing using POSIX Threads.

### Responsibilities

* Shared buffer management
* Thread management
* Packet processing
* Synchronization

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
- Packet retrieval
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
- Communication analysis
- Traffic analysis

### Input

- Processed telecom packets

### Output

- Traffic graphs
- Graph statistics
- Communication summaries

---

## Monitoring Module

### Description

Responsible for runtime logging, statistics collection, and performance monitoring.

### Responsibilities

- Logging
- Statistics collection
- Execution time measurement
- Throughput measurement
- Performance monitoring

### Input

- Runtime events

### Output

- Logs
- Runtime statistics
- Performance metrics

---

# Data Flow

The Hybrid Telecom Stream Processing Framework follows the data flow shown below.

```text
Real-Time Traffic Source
            │
            ▼
Data Extraction Servers (DES)
            │
            ▼
MPI Communication Layer
            │
            ▼
Shared Buffer
            │
            ▼
Worker Thread Pool
            │
            ▼
Packet Processing Engine
            │
            ▼
Berkeley DB Storage
            │
            ▼
Graph Construction Engine
            │
            ▼
MOnotoring and Graph Statistics
            │
            ▼
        Reports
```

## Step 1: Traffic Ingestion

Traffic is generated as simulated telecom packets by multiple Data Extraction Server (DES) processes.
The traffic is converted into TelecomPacket structures.
---

## Step 2: Data Extraction Servers

Multiple DES processes generate or ingest telecom traffic and forward packets to the MPI communication layer.

---

## Step 3: MPI Communication

MPI processes distribute packets across processing nodes.

Responsibilities:

- Packet reception
- Packet routing
- Packet distribution
- Cluster communication

---

## Step 4: Shared Buffer

Packets received through MPI are inserted into a shared buffer.

Responsibilities:

- Circular packet buffering
- Thread-safe synchronization using POSIX read-write locks
- Temporary packet storage

---

## Step 5: Worker Thread Pool

Consumer threads remove packets from the shared buffer and perform packet processing.

Responsibilities:

- Parallel processing
- Workload distribution
- Packet handling

---

## Step 6: Berkeley DB Storage

Processed telecom packet records are stored persistently in Berkeley DB.

Responsibilities:

- Packet storage
- Packet retrieval
- Database management

---

## Step 7: Graph Construction

Processed packets are converted into graph structures.

Graph Representation:

```text
Source Node ─────► Destination Node
```

Edge weights represent traffic volume.

---

## Step 8: Graph Analytics

The Graph Module analyzes the communication graph and generates:

- Traffic statistics
- Graph statistics
- Performance metrics
- Communication summaries

---

## Step 9: Reporting

The monitoring and graph modules generate:

- Performance summaries
- Validation reports
- Communication summaries
- Graph statistics

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

## Shared Buffer

The Shared Buffer stores TelecomPacket objects before processing.

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

## Performance Statistics Record

Performance statistics are generated during packet processing and graph construction.

Example Metrics:

- Total Packets Processed
- Execution Time
- Throughput
- Graph Statistics
- Communication Statistics
- Most Active Source
- Most Active Destination
- Top Communication Links

---

# Component Mapping

This section identifies reusable components from existing implementations and new modules required for the Hybrid Telecom Stream Processing Framework.

---

## Components Reused from Group-E

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

# APIs

## Communication Module APIs

### Server Initialization

```c
int initialize_server(int *argc, char ***argv);
```

### Client Initialization

```c
int initialize_client(int *argc, char ***argv);
```

### Packet Transmission

```c
int send_packet(const TelecomPacket *packet);
```

### Packet Reception

```c
int receive_packet(TelecomPacket *packet);
```

---

## Processing Module APIs

### Initialize Shared Buffer

```c
int buffer_init(SharedBuffer *buf);
```

### Enqueue Packet

```c
int enqueue(SharedBuffer *buf,
            const TelecomPacket *packet);
```

### Dequeue Packet

```c
int dequeue(SharedBuffer *buf,
            TelecomPacket *out);
```

### Process Telecom Packet

```c
void process_telecom_packet(
    const TelecomPacket *packet,
    int worker_id);
```

---

## Storage Module APIs

### Database Initialization

```c
int db_initialize(const char *db_name);
```

### Store Packet

```c
int db_store_packet(const TelecomPacket *packet);
```

### Retrieve Packet

```c
int db_get_packet(uint32_t packet_id,
                  TelecomPacket *packet);
```

### Close Database

```c
void db_close(void);
```

---

## Graph Module APIs

### Initialize Graph

```c
void initialize_graph(Graph *graph);
```

### Add Vertex

```c
GraphVertex *add_vertex(Graph *graph,
                        const char *node);
```

### Add Edge

```c
void add_edge(Graph *graph,
              const char *source,
              const char *destination);
```

### Print Graph Statistics

```c
void print_graph_statistics(Graph *graph);
```

### Get Top Communication Link

```c
TopCommunicationLink get_top_communication_link(Graph *graph);
```

---

## Monitoring Module APIs

### Initialize Monitoring

```c
void monitoring_initialize(void);
```

### Get Statistics

```c
SystemStatistics *monitoring_get_statistics(void);
```

### Print Monitoring Dashboard

```c
void monitoring_print_dashboard(void);
```