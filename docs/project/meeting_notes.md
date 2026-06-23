# Meeting Notes

## Initial Project Understanding

- Project focuses on telecom stream processing.
- Multiple implementation approaches will be studied.
- Streaming Media Player acts as the initial reference architecture.
- POSIX Threads implementation is the first milestone.
- Socket Programming will be explored after POSIX implementation.
- MPI-based approaches will be investigated in later phases.
- Group-E is responsible for implementation understanding, testing, validation, and comparative analysis.


## Week 3 Hybrid Integration Discussion

After reviewing both Group-E and Group-F implementations, the goal of Week 3 is **not to rewrite existing modules** but to integrate both frameworks into a complete Hybrid MPI + POSIX Threads architecture.

### What Group-F Already Provides

Group-F has already implemented:

* Shared Buffer Framework
* Producer–Consumer Synchronization
* Worker Thread Management
* Thread Coordination Logic
* Packet Processing Framework

These components will be reused wherever possible after validation.

---

### What Group-E Already Provides

Group-E has already implemented and validated:

* Socket Communication Framework
* Pthreads + Socket Integration
* MPI Distributed Processing Framework
* Multi-DES Architecture
* Statistics Collection Framework
* Logging Framework
* Testing & Validation Framework

These components provide the communication and monitoring infrastructure for the final system.

---

### How We Plan to Combine Both Frameworks

Current Group-F Workflow:

```text
Producer Threads
       │
       ▼
Shared Buffer
       │
       ▼
Consumer Threads
       │
       ▼
Packet Processing
```

Current Group-E Workflow:

```text
Multiple DES
       │
       ▼
MPI Communication
       │
       ▼
Master Process
       │
       ▼
Worker Processes
```

Hybrid Workflow:

```text
Multiple DES
       │
       ▼
MPI Communication Layer
       │
       ▼
Master Process
       │
       ▼
Group-F Shared Buffer
       │
       ▼
Group-F Worker Threads
       │
       ▼
Packet Processing
       │
       ▼
Group-E Statistics Framework
       │
       ▼
Group-E Logging Framework
```

---

### Practical Integration Approach

The key idea is that MPI communication will replace the Producer Threads.

Instead of:

```c
producer()
{
    packet = generate_packet();
    enqueue(packet);
}
```

the Master Process will receive packets through MPI and directly insert them into the Group-F shared buffer.

```c
while(receiving_packets)
{
    MPI_Recv(&packet,...);
    enqueue(packet);
}
```

This means:

```text
MPI Communication
        =
Producer
```

and the existing Group-F Consumer Threads continue processing packets without major modifications.

---

### Software Engineering Guidelines

The Hybrid framework should follow a clean modular architecture and avoid large monolithic source files.

Proposed structure:

```text
src/hybrid/
│
├── include/
├── mpi/
├── buffer/
├── threads/
├── processing/
├── monitoring/
├── tests/
└── hybrid_main.c
```

Responsibilities should be separated clearly:

* MPI Layer → Communication
* Buffer Layer → Packet Storage
* Thread Layer → Worker Management
* Processing Layer → Packet Processing
* Statistics Layer → Performance Metrics
* Logging Layer → Log Generation

---

### Implementation Ownership

#### Jahnavi

* MPI Communication Layer
* MPI-to-Buffer Integration
* Statistics Framework
* Logging Framework
* Performance Monitoring
* Testing & Validation
* Documentation

#### Sreeja

* Shared Buffer Integration
* Worker Thread Pool
* Packet Processing Integration
* Synchronization Support
* Real-Time Streaming Logic
* Optimization

---

### Week 3 End Goal

Develop a clean, modular, software-engineering-oriented Hybrid framework capable of:

```text
Multiple DES
      │
      ▼
MPI Communication
      │
      ▼
Shared Buffer
      │
      ▼
Thread Pool
      │
      ▼
Packet Processing
      │
      ▼
Statistics & Logging
```

while reusing validated Group-F components and extending them with Group-E's distributed processing infrastructure.
