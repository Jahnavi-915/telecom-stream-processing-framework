# Multi-DES MPI Workflow Diagram

## Multi-DES Distributed Processing Architecture

```text
                    ┌─────────────┐
                    │   DES-1     │
                    │  (Rank 1)   │
                    └──────┬──────┘
                           │
                           │ MPI_Send()
                           │
                    ┌──────▼──────┐
                    │             │
                    │             │
                    │             │
┌─────────────┐     │   MASTER    │     ┌─────────────┐
│   DES-2     │────►│ COORDINATOR │◄────│   DES-3     │
│  (Rank 2)   │     │  (Rank 0)   │     │  (Rank 3)   │
└─────────────┘     │             │     └─────────────┘
                    │             │
                    │             │
                    └──────┬──────┘
                           │
                           │ Round-Robin
                           │ Distribution
                           │
      ┌────────────────────┼────────────────────┐
      │                    │                    │
      ▼                    ▼                    ▼

┌─────────────┐    ┌─────────────┐    ┌─────────────┐
│  Worker-1   │    │  Worker-2   │    │  Worker-3   │
│  (Rank 4)   │    │  (Rank 5)   │    │  (Rank 6)   │
└──────┬──────┘    └──────┬──────┘    └──────┬──────┘
       │                  │                  │
       │ Packet           │ Packet           │ Packet
       │ Processing       │ Processing       │ Processing
       │                  │                  │
       ▼                  ▼                  ▼

                ┌─────────────────┐
                │   Statistics    │
                │   Collection    │
                └─────────────────┘
```

---

## Process Allocation Example

```text
Rank 0  → Master Coordinator

Rank 1  → DES-1
Rank 2  → DES-2
Rank 3  → DES-3

Rank 4  → Worker-1
Rank 5  → Worker-2
Rank 6  → Worker-3
Rank 7  → Worker-4
```

---

## Packet Flow

```text
DES-1 Packet
       │
       ▼
Master Coordinator
       │
       ▼
Worker Process
       │
       ▼
Packet Processing

---------------------------------

DES-2 Packet
       │
       ▼
Master Coordinator
       │
       ▼
Worker Process
       │
       ▼
Packet Processing

---------------------------------

DES-3 Packet
       │
       ▼
Master Coordinator
       │
       ▼
Worker Process
       │
       ▼
Packet Processing
```

---

## Load Balancing Strategy

```text
Packet 1  → Worker 1
Packet 2  → Worker 2
Packet 3  → Worker 3
Packet 4  → Worker 4
Packet 5  → Worker 1
Packet 6  → Worker 2
Packet 7  → Worker 3
Packet 8  → Worker 4
...
```

The Master Coordinator distributes packets using a Round-Robin scheduling policy to ensure balanced workload allocation among Worker Processes.

---

## Processing Workflow

```text
DES Processes
       │
       ▼
Generate Telecom Packets
       │
       ▼
Send to Master Coordinator
       │
       ▼
Round-Robin Distribution
       │
       ▼
Worker Processing
       │
       ▼
Statistics Collection
       │
       ▼
Execution Summary
```
