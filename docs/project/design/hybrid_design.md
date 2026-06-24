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
Graph Construction Engine
            │
            ▼
Berkeley DB Storage
            │
            ▼
Analytics Engine
            │
            ▼
Reports & Visualization
```

## Step 1: Traffic Ingestion

Traffic is received from real-time streams, telecom traces, network traces, or CSV datasets.

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

- Packet buffering
- Synchronization
- Temporary storage

---

## Step 5: Worker Thread Pool

Consumer threads remove packets from the shared buffer and perform packet processing.

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

Not Implemented

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

Not Implemented

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

Not Implemented

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

Status:

Not Implemented

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

### Packet Distribution

```c
int distribute_packet(TelecomPacket *packet);
```

---

## Processing Module APIs

### Shared Buffer Insert

```c
int enqueue_packet(TelecomPacket *packet);
```

### Shared Buffer Remove

```c
int dequeue_packet(TelecomPacket *packet);
```

### Worker Thread Creation

```c
int create_worker_pool(int thread_count);
```

---

## Storage Module APIs

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