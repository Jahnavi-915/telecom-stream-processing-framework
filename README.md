# Communication Layer for a Hybrid Telecom Stream Processing Framework

## Overview

The Telecom Stream Processing Framework is a parallel and distributed systems project focused on the design, implementation, testing, validation, and performance evaluation of scalable telecom communication architectures.

This project presents the implementation of the Communication Layer for a Hybrid Telecom Stream Processing Framework. The implemented communication subsystem establishes the distributed communication foundation required for reliable telecom packet exchange between multiple Data Extraction Servers (DES) using MPI.

The Communication Layer includes TelecomPacket design, traffic generation, MPI client-server communication, packet serialization and deserialization, communication queue management, multi-client communication, performance monitoring, and comprehensive testing and validation.

The project follows an incremental software engineering methodology, where the communication subsystem has been independently designed, implemented, tested, validated, and documented. Although only the Communication Layer was implemented in this project, the proposed Hybrid Telecom Stream Processing Framework architecture can be extended to incorporate packet processing, persistent storage, graph analytics, and monitoring components.

---

## Implementation Progress

The project was developed using an incremental software engineering methodology. Each implementation phase was independently designed, implemented, tested, validated, documented, and evaluated before progressing to the next phase. This repository represents the final project deliverable, documenting the implementation and evaluation of the Communication Layer for the Hybrid Telecom Stream Processing Framework.

---

# Project Objectives

* Design a modular communication framework for telecom stream processing.
* Implement distributed packet communication using MPI.
* Support communication from multiple Data Extraction Servers (DES).
* Implement TelecomPacket serialization and deserialization.
* Develop reliable packet transmission and reception mechanisms.
* Evaluate throughput, latency, scalability, and communication performance.
* Validate communication correctness under multiple client configurations.
* Follow professional software engineering practices through modular implementation, testing, documentation, and version control.

---

# Final System Architecture

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
Note: The above diagram illustrates the complete target architecture of the proposed Hybrid Telecom Stream Processing Framework. The scope of this project is limited to the implementation, testing, validation, and performance evaluation of the MPI-based Communication Layer.

---

# Deployment Models

## Single Machine Deployment

The framework can execute on a single machine for:

* Development
* Testing
* Validation
* Performance Evaluation

```text
DES
 ↓
MPI
 ↓
Shared Buffer
 ↓
Worker Threads
 ↓
Database
 ↓
Analytics
```

---

## Cluster Deployment

The framework is designed to support execution across multiple machines connected through a network.

```text
DES Nodes
      ↓
MPI Cluster
      ↓
Hybrid Processing Nodes
      ↓
Storage Layer
      ↓
Analytics Layer
```

Features:

* Distributed execution
* Parallel processing
* Scalable architecture
* Cluster-ready deployment

---

# Core Components

## Communication Layer - Implemented

Responsibilities:

* MPI Communication
* Multi-client MPI Communication
* Packet Distribution
* Distributed Coordination

---

## Processing Layer - Proposed Extension

Responsibilities:

* Shared Buffer Management
* Worker Thread Management
* Synchronization
* Packet Processing

---

## Storage Layer - Proposed Extension

---

## Graph Construction Layer - Proposed Extension

---

## Analytics Layer - Proposed EXtension

---

## Monitoring Layer - Proposed Extension


These modules are part of the proposed Hybrid Framework architecture and are presented as possible extensions beyond the scope of this implementation.

---

# System Input

Supported input sources include:

* Real-time telecom traffic
* Telecom traffic traces
* Network traffic traces
* CSV datasets
* Simulated telecom streams

Example packet attributes:

```text
Packet ID
Timestamp
Source
Destination
Priority
Traffic Type
Payload
```

---

# System Output

The framework generates:

### Processed Packet Records

Processed telecom packet information.

### Performance Reports

Execution statistics and performance metrics.

### Validation Reports

Testing and verification artifacts.

---

# Technologies Used

* C
* POSIX Threads (Pthreads)
* MPI
* TCP Socket Programming
* Ubuntu Linux
* GCC
* Git
* GitHub

---

# Project Evolution

The project has evolved through multiple implementation phases, with each phase focusing on a specific parallel or distributed computing concept.

Every phase was independently implemented, tested, validated, documented, and evaluated before progressing to the next stage.

Detailed implementation history, design evolution, testing artifacts, validation reports, and performance analysis are available under the `docs/evolution/` directory(Phase 1 to Phase 5).

## Phase 1 – POSIX Threads Producer–Consumer Framework

Implemented a multithreaded producer–consumer architecture using POSIX Threads. This phase focused on shared memory communication, synchronization mechanisms, shared buffers, mutexes, condition variables, and runtime statistics collection.

**Key Outcomes:**

* Shared Buffer Implementation
* Producer–Consumer Synchronization
* Thread Management
* Performance Monitoring

---

## Phase 2 – TCP Socket Communication Framework

Implemented a client–server communication model using TCP sockets to enable packet transmission between distributed components.

**Key Outcomes:**

* TCP Client and Server
* Packet Transmission
* Packet Reception
* Communication Validation

---

## Phase 3 – Pthreads and Socket Integration Framework

Combined thread-based processing with socket communication to create a complete packet generation, transmission, and reception pipeline.

**Key Outcomes:**

* End-to-End Packet Flow
* Producer–Sender Architecture
* Receiver–Consumer Architecture
* Integrated Performance Evaluation

---

## Phase 4 – MPI Distributed Processing Framework

Introduced process-level parallelism using MPI. Implemented a distributed master–worker architecture for packet distribution and processing.

**Key Outcomes:**

* MPI Communication
* Distributed Packet Distribution
* Master–Worker Processing Model
* Distributed Statistics Collection

---

## Phase 5 – Multi-DES MPI Framework

Extended the MPI framework to support multiple Data Extraction Servers (DES), enabling concurrent packet generation and distributed processing from multiple traffic sources.

**Key Outcomes:**

* Multiple DES Sources
* Distributed Load Distribution
* Scalability Evaluation
* Multi-Source Traffic Processing

---

## Phase 6 – Hybrid Telecom Stream Processing Framework (Current Project)

Phase 6 focused on the design, implementation, testing, validation, and performance evaluation of the Communication Layer for the Hybrid Telecom Stream Processing Framework.

The implemented Communication Layer includes:

- TelecomPacket Design
- Traffic Generator
- MPI Client
- MPI Server
- Packet Serialization and Deserialization
- Queue Interface
- Multi-client MPI Communication
- Communication Statistics
- Performance Evaluation
- Testing and Validation

The Processing Layer, Storage Layer, Graph Construction Layer, Analytics Layer, and Monitoring Layer are presented as architectural extensions and were not implemented within the scope of this project.
---

# Repository Structure

```text
telecom-stream-processing-framework/
│
├── diagrams/
│
├── docs/
│   ├── evolution/
│   │   ├── design/
│   │   └── testing/
│   │
│   ├── progress/
│   │   ├── evolution_progress_log.md
│   │   └── hybrid_progress_log.md
│   │
│   ├── project/
│   │   ├── design/
│   │   └── testing/
│   │
│   └── workflow/
│
├── logs/
│
├── reports/
│   ├── GROUP-E_hybrid/
│   ├── GROUP-E_integration/
│   ├── GROUP-E_mpi/
│   ├── GROUP-E_posix_threads/
│   └── GROUP-E_sockets/
│
├── src/
│   ├── hybrid/
│   ├── integration/
│   ├── mpi/
│   ├── pthreads/
│   └── sockets/
│
├── tests/
│
├── .gitignore
└── README.md
```

---

# Hybrid Framework Structure

```text
src/hybrid/
│
├── include/
├── mpi/
├── processing/     (Reserved for Extension)
├── database/       (Reserved for Extension)
├── graph/          (Reserved for Extension)
├── analytics/      (Reserved for Extension)
├── monitoring/     (Reserved for Extension)
│
├── Makefile
└── hybrid_main.c
```

This repository contains the complete implementation, testing, validation, performance evaluation, and documentation of the Communication Layer for the Hybrid Telecom Stream Processing Framework. The remaining architectural components are included only as part of the proposed system design and are not implemented within the scope of this project.

### Module Responsibilities

| Module | Status | Responsibility |
|---------|--------|----------------|
| **include** | ✅ Implemented | Common data structures, configuration files, APIs, constants, and shared definitions used across the Communication Layer. |
| **mpi** | ✅ Implemented | Traffic generation, MPI client-server communication, TelecomPacket transmission, packet serialization and deserialization, queue interface, multi-client MPI communication, communication statistics, and performance monitoring. |
| **processing** | Proposed Extension | Shared buffer management, thread synchronization, worker thread management, and packet processing for hybrid execution. |
| **database** | Proposed Extension | Berkeley DB integration, persistent packet storage, and metadata management. |
| **graph** | Proposed Extension | Communication graph construction, vertex and edge management, and graph statistics generation. |
| **analytics** | Proposed Extension | Traffic analysis, communication pattern analysis, performance evaluation, and report generation. |
| **monitoring** | Proposed Extension | Runtime logging, statistics collection, throughput monitoring, and system performance visualization. |
| **hybrid_main** | ✅ Implemented | Framework initialization, Communication Layer orchestration, configuration management, and application execution control. |

---

# Testing & Validation Framework

The project includes a reusable testing and validation framework.

Testing activities include:

* Unit Testing
* Module Testing
* Integration Testing
* Functional Testing
* System Testing
* Performance Testing
* Stress Testing
* Scalability Testing
* Cluster Testing
* Validation & Comparative Evaluation

Testing artifacts include:

* Test Plans
* Test Case Catalogs
* Validation Checklists
* Observation Templates
* Validation Reports
* Performance Reports

---

# Build Instructions

```bash
cd src/hybrid

make clean
make
```
---

# Run Instructions

### Single Client

```bash
mpirun -np 2 ./hybrid
```

### Two Clients

```bash
mpirun -np 3 ./hybrid
```

### Four Clients

```bash
mpirun -np 5 ./hybrid
```

---

# Current Status

## Completed

- POSIX Threads Producer–Consumer Framework
- TCP Socket Communication Framework
- Pthreads + Socket Integration Framework
- MPI Distributed Processing Framework
- Multi-DES MPI Framework
- Hybrid Communication Layer
- Architecture, Design, and Implementation Documentation
- Communication Testing & Validation
- Communication Performance Evaluation

## Proposed Extensions

- POSIX Threads Processing Layer
- Berkeley DB Storage
- Graph Construction
- Analytics
- Monitoring
---

# Current Milestone

The Communication Layer of the Hybrid Telecom Stream Processing Framework has been successfully implemented, tested, validated, and documented.

Current capabilities include:

- MPI-based communication
- TelecomPacket serialization/deserialization
- Multi-client communication
- Queue validation
- Queue stress testing
- Communication performance benchmarking

This project concludes with the successful implementation, testing, validation, and performance evaluation of the Communication Layer. The remaining components shown in the proposed Hybrid Telecom Stream Processing Framework architecture represent potential extensions and are outside the scope of this project.

---

# Team

| Name          | Institution     | Role        |
| ------------- | --------------- | ----------- |
| Jahnavi Pathi | MNIT Jaipur     | Team Lead   |
| Sreeja        | GNITS Hyderabad | Team Member |

---

# Acknowledgement

This project is being developed as part of the MPPLAB Telecom Data Extraction initiative under the guidance of **Dr. V. C. V. Rao**.

The project focuses on scalable parallel and distributed approaches for telecom data extraction, processing, storage, analytics, and evaluation.

---

# License

This repository is intended for academic, research, and educational purposes.
