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
│   ├── GROUP-E_posix_threads/
│   └── GROUP-F_validation/
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

---

# Technology Stack

| Category | Technologies |
|----------|--------------|
| Programming Language | C |
| Parallel Programming | POSIX Threads (Pthreads) |
| Distributed Computing | MPI (OpenMPI) |
| Networking | TCP Socket Programming |
| Database | Berkeley DB |
| Synchronization | Mutexes, Condition Variables |
| Data Structures | Circular Queue, Graph |
| Build System | Make |
| Operating System | Ubuntu Linux |
| Version Control | Git & GitHub |

---

# Build Instructions

## Prerequisites

The following software must be installed before building the project.

- GCC Compiler
- GNU Make
- OpenMPI
- Berkeley DB Development Libraries
- POSIX Threads

### Ubuntu Installation

```bash
sudo apt update

sudo apt install build-essential

sudo apt install openmpi-bin libopenmpi-dev

sudo apt install libdb-dev
```

---

## Build Individual Modules

Each implementation phase can be built independently.

### POSIX Threads

```bash
cd src/pthreads
make
```

### TCP Sockets

```bash
cd src/sockets
make
```

### MPI Communication

```bash
cd src/mpi
make
```

---

## Build Hybrid Framework

```bash
cd src/hybrid
make
```

The generated executable will be created inside the hybrid source directory.

---

# Running the Project

Run the hybrid implementation using OpenMPI.

```bash
mpirun -np 2 ./hybrid
```

---

# Packet Processing Workflow

The hybrid framework processes telecom packets through the following pipeline:

```text
Generate Telecom Packet
            │
            ▼
MPI Communication
            │
            ▼
Shared Circular Buffer
            │
            ▼
Worker Thread Pool
            │
            ▼
Packet Processing
            │
            ▼
Berkeley DB Storage
            │
            ▼
Communication Graph
            │
            ▼
Monitoring & Statistics
```

---

# Public API

## Communication Layer

| Function | Description |
|----------|-------------|
| `initialize_server()` | Initializes the MPI server. |
| `initialize_client()` | Initializes the MPI client. |
| `send_packet()` | Sends a telecom packet. |
| `receive_packet()` | Receives a telecom packet. |

---

## Telecom Packet

| Function | Description |
|----------|-------------|
| `initialize_packet()` | Initializes a telecom packet. |
| `clear_packet()` | Clears packet contents. |
| `validate_packet()` | Validates packet integrity. |
| `print_packet()` | Prints packet information. |

---

## Traffic Generation

| Function | Description |
|----------|-------------|
| `generate_packet()` | Generates a telecom packet. |
| `generate_timestamp()` | Generates a packet timestamp. |
| `generate_source()` | Generates the packet source identifier. |
| `generate_destination()` | Generates the packet destination identifier. |
| `generate_traffic_type()` | Generates the telecom traffic type. |
| `generate_payload()` | Generates the packet payload. |

---

## Processing Layer

| Function | Description |
|----------|-------------|
| `buffer_init()` | Initializes the shared circular buffer. |
| `enqueue()` | Inserts packets into the buffer. |
| `dequeue()` | Removes packets from the buffer. |
| `process_telecom_packet()` | Processes telecom packets using worker threads. |

---

## Storage Layer

| Function | Description |
|----------|-------------|
| `db_initialize()` | Initializes Berkeley DB. |
| `db_store_packet()` | Stores a telecom packet. |
| `db_get_packet()` | Retrieves a stored packet. |
| `db_close()` | Closes the database. |

---

## Graph Construction Layer

| Function | Description |
|----------|-------------|
| `initialize_graph()` | Initializes the communication graph. |
| `add_vertex()` | Adds a communication endpoint. |
| `add_edge()` | Creates a communication relationship. |
| `print_graph_statistics()` | Displays graph statistics. |
| `get_top_communication_link()` | Returns the most active communication link. |

---

## Monitoring Layer

| Function | Description |
|----------|-------------|
| `monitoring_initialize()` | Initializes runtime monitoring. |
| `monitoring_get_statistics()` | Retrieves execution statistics. |
| `monitoring_print_dashboard()` | Displays runtime monitoring information. |

---

# Documentation

The repository contains detailed documentation covering the complete software development lifecycle.

| Documentation | Description |
|--------------|-------------|
| Project Documentation | System architecture, module design and implementation details |
| Workflow Documentation | Collaboration workflow, roadmap and meeting notes |
| Evolution Documentation | Development history across all project phases |
| Diagrams | System architecture, deployment and module interaction diagrams |

---

# Testing and Reports

Each implementation phase was independently tested and validated before integration into the final hybrid framework.

The repository includes:

- Functional Testing
- Unit Testing
- Integration Testing
- Performance Evaluation
- Validation Reports
- Scalability Testing
- Communication Testing
- Hybrid System Testing

The final hybrid implementation combines all validated modules into a unified telecom stream processing framework while preserving the complete implementation history.

---

# Team

| Name | Institution | Role |
|------|-------------|------|
| Jahnavi Pathi | MNIT Jaipur | Team Lead |
| Sreeja | GNITS Hyderabad | Team Member |

---

# Future Enhancements

# Future Enhancements

The modular architecture allows the framework to be extended with additional capabilities such as:

- Advanced telecom traffic analytics
- Real-time monitoring dashboard
- Fault tolerance and recovery mechanisms
- Dynamic load balancing
- Distributed cluster deployment
- Cloud-native deployment
- Containerization using Docker
- Web-based visualization of communication graphs

---

# Acknowledgement

This project was developed as part of the **MPPLAB Telecom Data Extraction Initiative** under the guidance of **Dr. V. C. V. Rao**.

The project focuses on scalable parallel and distributed approaches for telecom data extraction, communication, processing, storage, graph construction, and runtime monitoring.

---

# License

This repository is intended for academic, research, and educational purposes.