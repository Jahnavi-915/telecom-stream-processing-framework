# Hybrid Telecom Stream Processing Framework

A modular, high-performance telecom stream processing framework developed using parallel and distributed computing techniques. The framework demonstrates how telecom traffic generated from multiple Data Extraction Servers (DES) can be communicated, processed, stored, analyzed, and monitored through an integrated hybrid architecture.

The project was developed as part of the MPPLAB Telecom Data Extraction initiative and follows an incremental software engineering approach. Individual implementations of POSIX Threads, TCP Sockets, MPI, and Hybrid Integration were designed, implemented, tested, validated, and documented before being combined into the final hybrid framework.

---

## Project Overview

Modern telecom systems generate massive volumes of streaming traffic that require scalable communication, concurrent processing, efficient storage, and continuous monitoring. This project demonstrates a modular architecture capable of handling these requirements by integrating message passing, multithreading, persistent storage, graph construction, and runtime monitoring into a unified framework.

The implemented hybrid framework consists of the following major components:

- **MPI Communication Layer** for distributed packet exchange
- **POSIX Threads Processing Layer** for concurrent packet processing
- **Berkeley DB Storage Layer** for persistent packet storage
- **Graph Construction Layer** for communication relationship modeling
- **Monitoring Layer** for runtime statistics and performance monitoring

The project emphasizes modular design, maintainability, scalability, and comprehensive documentation while preserving the complete development history of the framework.

---

# Features

## Communication

- MPI Client–Server communication
- Multi-client packet transmission
- TelecomPacket serialization and deserialization
- Configurable traffic generation
- Communication statistics collection

## Processing

- Producer–Consumer architecture
- Shared circular buffer
- POSIX Thread worker pool
- Thread synchronization using mutexes and condition variables
- Concurrent packet processing

## Storage

- Berkeley DB integration
- Persistent telecom packet storage
- Packet retrieval support

## Graph Construction

- Communication graph generation
- Vertex and edge management
- Communication statistics

## Monitoring

- Runtime statistics collection
- Throughput monitoring
- Packet processing statistics
- System performance monitoring

---

# System Architecture

```text
                    Hybrid Telecom Stream Processing Framework

                  +---------------------------+
                  |    Data Extraction        |
                  |        Servers (DES)      |
                  +-------------+-------------+
                                |
                                v
                  +---------------------------+
                  |   Communication Layer     |
                  |          (MPI)            |
                  +-------------+-------------+
                                |
                                v
                  +---------------------------+
                  |    Processing Layer       |
                  | (Shared Buffer + Threads) |
                  +-------------+-------------+
                                |
                                v
                  +---------------------------+
                  |      Berkeley DB          |
                  +-------------+-------------+
                                |
                                v
                  +---------------------------+
                  |      Graph Module         |
                  +-------------+-------------+
                                |
                                v
                  +---------------------------+
                  |    Monitoring Layer       |
                  +---------------------------+
```

The framework follows a layered architecture in which each module performs a well-defined responsibility while remaining independent from the implementation details of other components.

---

# Repository Structure

```text
telecom-stream-processing-framework/
│
├── diagrams/
│   ├── architecture/
│   └── evolution/
│
├── docs/
│   ├── evolution/
│   ├── project/
│   └── workflow/
│
├── logs/
│
├── src/
│   ├── hybrid/
│   ├── integration/
│   ├── mpi/
│   ├── pthreads/
│   └── sockets/
│
├── tests_and_reports/
│   ├── GROUP-E_hybrid/
│   ├── GROUP-E_integration/
│   ├── GROUP-E_mpi/
│   ├── GROUP-E_posix_threads/
│   └── GROUP-E_sockets/
│
├── .gitignore
└── README.md
```

## Repository Organization

| Directory | Description |
|-----------|-------------|
| **src/** | Source code for all project phases and the final hybrid implementation. |
| **docs/** | Architecture, design, implementation, testing, and workflow documentation. |
| **diagrams/** | System architecture and project evolution diagrams. |
| **tests_and_reports/** | Testing artifacts, validation reports, performance reports, and phase-wise project documentation. |
| **logs/** | Development and execution logs generated during implementation and testing. |

---

## Project Evolution

The repository preserves the complete evolution of the project from individual parallel programming concepts to the final hybrid framework.

```text
POSIX Threads
       │
       ▼
TCP Socket Communication
       │
       ▼
Socket + Thread Integration
       │
       ▼
MPI Distributed Communication
       │
       ▼
Hybrid Telecom Stream Processing Framework
```

Each implementation phase was independently designed, implemented, tested, validated, and documented before progressing to the next stage.