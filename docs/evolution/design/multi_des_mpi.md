# Multi-DES MPI Architecture Design

## Overview

The Multi-DES MPI Architecture extends the existing MPI Distributed Processing Module by introducing multiple Data Extraction Servers (DES) that simultaneously generate telecom traffic streams.

The objective is to simulate a realistic telecom environment where multiple geographically distributed DES nodes continuously generate packet streams that must be collected, distributed, and processed by a distributed computing framework.

The architecture uses MPI message passing to coordinate communication between DES processes, a central Master Coordinator, and multiple Worker Processes.

---

# Design Objectives

The Multi-DES architecture is designed to:

* Simulate multiple telecom data sources.
* Support concurrent packet generation.
* Distribute incoming packets across Worker Processes.
* Evaluate distributed processing scalability.
* Measure communication performance.
* Validate load balancing strategies.
* Prepare for future Hybrid MPI + Pthreads integration.

---

# System Architecture

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
        ┌──────────┼──────────┐
        ▼          ▼          ▼
     Worker-1   Worker-2   Worker-3
        │          │          │
        └──────────┼──────────┘
                   ▼
          Statistics Collection
```

---

# Process Roles

## Master Coordinator

MPI Rank:

```text
Rank 0
```

Responsibilities:

* Receive packets from all DES processes.
* Maintain global packet statistics.
* Perform packet distribution.
* Manage Worker Processes.
* Collect performance metrics.
* Coordinate termination.

---

## Data Extraction Servers (DES)

MPI Ranks:

```text
Rank 1 → DES-1
Rank 2 → DES-2
Rank 3 → DES-3
```

Responsibilities:

* Generate telecom packets.
* Assign source information.
* Populate packet payloads.
* Send generated packets to the Master Coordinator.

Each DES acts as an independent telecom data source.

---

## Worker Processes

MPI Ranks:

```text
Rank 4+
```

Responsibilities:

* Receive packets from Master Coordinator.
* Process incoming packets.
* Maintain processing statistics.
* Report execution status.

Workers perform distributed packet processing.

---

# Communication Workflow

## Phase 1 — Packet Generation

Each DES independently generates telecom packets.

Example:

```text
DES-1 → Packet 1
DES-1 → Packet 2

DES-2 → Packet 1
DES-2 → Packet 2

DES-3 → Packet 1
DES-3 → Packet 2
```

---

## Phase 2 — Packet Collection

Generated packets are transmitted to the Master Coordinator.

```text
DES Processes
      ↓
Master Coordinator
```

The Master receives packets from all DES sources.

---

## Phase 3 — Packet Distribution

The Master distributes packets among Worker Processes using Round-Robin scheduling.

Example:

```text
Packet 1 → Worker 1
Packet 2 → Worker 2
Packet 3 → Worker 3
Packet 4 → Worker 4
Packet 5 → Worker 1
```

---

## Phase 4 — Distributed Processing

Worker Processes receive and process assigned packets.

```text
Worker Process
      ↓
Packet Processing
      ↓
Statistics Update
```

---

## Phase 5 — Termination

After all DES processes complete packet generation:

* DES processes notify the Master.
* Master sends termination packets to Workers.
* Workers terminate gracefully.
* Final statistics are displayed.

---

# Telecom Packet Structure

```c
typedef struct
{
    int packet_id;
    int des_id;
    int priority;

    char source[50];
    char destination[50];
    char payload[100];

} TelecomPacket;
```

---

# Packet Metadata

## Packet ID

Unique packet identifier.

Example:

```text
1
2
3
...
```

---

## DES ID

Identifies packet source.

Example:

```text
DES-1
DES-2
DES-3
```

---

## Priority

Packet priority level.

Example:

```text
1 = Normal
2 = High
3 = Critical
```

---

## Payload

Packet content information.

Example:

```text
Telecom Traffic Record
Call Detail Record
Network Event Record
```

---

# Load Balancing Strategy

The Master Coordinator uses Round-Robin packet distribution.

Algorithm:

```text
Worker 1
Worker 2
Worker 3
Worker 4
Repeat
```

Benefits:

* Balanced workload allocation.
* Reduced Worker starvation.
* Simple implementation.
* Predictable distribution behavior.

---

# Statistics Collection

## DES Statistics

Collected per DES:

* Packets Generated
* Generation Rate

---

## Master Statistics

Collected globally:

* Total Packets Received
* Total Packets Distributed
* Execution Time
* Throughput

---

## Worker Statistics

Collected per Worker:

* Packets Processed
* Processing Status

---

## Communication Statistics

* Communication Success Rate
* Packet Loss
* Packet Ordering Verification
* Load Distribution Verification

---

# Example Execution Configuration

```bash
mpirun -np 8 ./multi_des
```

Process Allocation:

```text
Rank 0 → Master

Rank 1 → DES-1
Rank 2 → DES-2
Rank 3 → DES-3

Rank 4 → Worker-1
Rank 5 → Worker-2
Rank 6 → Worker-3
Rank 7 → Worker-4
```

---

# Expected Outcomes

The Multi-DES architecture is expected to demonstrate:

* Concurrent packet generation.
* Distributed packet collection.
* Balanced workload distribution.
* Stable MPI communication.
* High communication success rates.
* Improved scalability compared to the Single-DES model.

---

# Future Extensions

Future enhancements may include:

* Dynamic Worker allocation.
* Adaptive load balancing.
* Distributed statistics aggregation.
* Telecom packet classification.
* Fault tolerance mechanisms.
* Hybrid MPI + POSIX Threads integration.
* Large-scale multi-node deployment.

---

# Conclusion

The Multi-DES MPI Architecture provides a scalable distributed processing model for telecom stream processing by combining multiple packet-generating DES sources with distributed Worker Processes. This architecture serves as the next evolutionary stage of the Telecom Stream Processing Framework and forms the foundation for future large-scale distributed telecom analytics systems.
