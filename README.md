# Telecom Stream Processing Framework

## Overview

The Telecom Stream Processing Framework is a parallel and distributed systems project focused on the design, implementation, testing, validation, and evaluation of scalable telecom data processing architectures.

The project aims to develop a Hybrid Telecom Stream Processing Framework capable of processing telecom traffic streams in real time while supporting both single-machine and cluster-based deployment environments.

The framework integrates:

* MPI-based distributed processing
* POSIX Thread-based parallel processing
* Berkeley DB persistent storage
* Graph construction and analytics
* Monitoring and performance evaluation
* Comprehensive testing and validation

The final objective is to build a modular, scalable, and maintainable telecom data processing platform that can ingest, process, store, analyze, and visualize telecom traffic streams.

---

## Implementation Progress

The project is being developed incrementally.

Each major subsystem is independently:

- Designed
- Implemented
- Tested
- Validated
- Documented

before being integrated into the complete Hybrid Telecom Stream Processing Framework.

The Communication Layer has been completed and serves as the foundation for subsequent hybrid integration.

---

# Project Objectives

* Process telecom traffic streams in real time.
* Support both single-machine and distributed cluster deployments.
* Integrate process-level and thread-level parallelism.
* Store processed telecom data using Berkeley DB.
* Construct communication graphs from telecom traffic.
* Generate traffic and performance analytics.
* Evaluate throughput, scalability, latency, and resource utilization.
* Follow professional software engineering practices.
* Develop reusable testing and validation methodologies.
* Provide comprehensive documentation and deployment support.

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

## Communication Layer

Responsibilities:

* MPI Communication
* Multi-DES Communication
* Packet Distribution
* Distributed Coordination

---

## Processing Layer

Responsibilities:

* Shared Buffer Management
* Worker Thread Management
* Synchronization
* Packet Processing

---

## Storage Layer

Responsibilities:

* Berkeley DB Integration
* Packet Storage
* Metadata Storage
* Persistent Data Management

---

## Graph Construction Layer

Responsibilities:

* Vertex Management
* Edge Management
* Communication Graph Generation
* Graph Statistics

---

## Analytics Layer

Responsibilities:

* Traffic Analysis
* Communication Pattern Analysis
* Graph Analytics
* Performance Evaluation

---

## Monitoring Layer

Responsibilities:

* Runtime Logging
* Statistics Collection
* Throughput Measurement
* Performance Monitoring

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

### Berkeley DB Records

Persistent packet and metadata storage.

### Traffic Graphs

Communication graphs representing traffic relationships.

### Analytics Reports

Traffic and communication analysis.

### Performance Reports

Execution statistics and performance metrics.

### Validation Reports

Testing and verification artifacts.

---

# Technologies Used

* C
* POSIX Threads (Pthreads)
* MPI
* Berkeley DB
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

The Hybrid Telecom Stream Processing Framework integrates the concepts, components, and lessons learned from all previous phases into a unified end-to-end telecom data processing platform.

This phase serves as the primary project deliverable and represents the culmination of the project's evolution from individual parallel and distributed computing prototypes to a complete telecom stream processing framework.

The Hybrid Telecom Stream Processing Framework currently includes a fully implemented Communication Layer consisting of MPI-based packet communication, multi-client support, communication validation, queue stress testing, and performance evaluation. The next development milestone is the integration of the completed Communication Layer with the POSIX Threads processing framework, followed by Berkeley DB storage, graph construction, analytics, and monitoring.

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
├── processing/
├── database/
├── graph/
├── analytics/
├── monitoring/
│
├── Makefile
└── hybrid_main.c
```

### Module Responsibilities

| Module | Responsibility |
|---------|----------------|
| include | Common data structures, configuration files, APIs, and shared definitions |
| mpi | MPI communication, packet transmission, serialization, traffic generation, queue management, and Multi-DES communication |
| processing | Shared buffer management, thread synchronization, and packet processing |
| database | Berkeley DB integration and persistent packet storage |
| graph | Telecom graph construction, vertex and edge management, and graph statistics |
| analytics | Traffic analysis, graph analytics, performance evaluation, and report generation |
| monitoring | Runtime logging, statistics collection, and performance monitoring |
| hybrid_main | Overall system initialization, module orchestration, and application lifecycle management |

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

## In Progress

- Hybrid Integration (MPI + POSIX Threads Shared Buffer)
- Berkeley DB Storage Layer
- Graph Construction Layer
- Analytics Layer
- Monitoring Layer
- End-to-End Hybrid Validation

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

The next development milestone is the integration of the Communication Layer with the POSIX Threads Shared Buffer developed by Group-F.

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
