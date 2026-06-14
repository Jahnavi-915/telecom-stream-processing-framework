# Telecom Stream Processing Framework

## Overview

The Telecom Stream Processing Framework is a parallel and distributed systems project focused on designing, implementing, validating, and evaluating frameworks for real-time telecom data stream processing.

Modern telecommunication infrastructures continuously generate large volumes of traffic data from geographically distributed Data Extraction Servers (DES). Efficient collection, transmission, synchronization, processing, and analysis of these streams are critical for network monitoring, traffic engineering, anomaly detection, and large-scale telecom analytics.

This project investigates multiple processing approaches including POSIX Threads, Socket Programming, MPI, and Hybrid Parallel Processing models.

---

# Project Goals

The primary objectives of this project are:

* Process continuous telecom traffic streams.
* Design scalable stream-processing architectures.
* Evaluate synchronization and communication mechanisms.
* Measure throughput, latency, and resource utilization.
* Compare shared-memory and distributed-processing approaches.
* Develop reusable testing and validation methodologies.

---

# Technologies Used

* C / C++
* POSIX Threads (Pthreads)
* TCP Socket Programming
* MPI (Planned)
* Hybrid MPI + Pthreads (Planned)
* Ubuntu Linux
* GCC
* Git & GitHub

---

# System Architecture

```text
Multiple Data Extraction Servers (DES)
                 │
                 ▼
        Communication Layer
      (Sockets / MPI Frameworks)
                 │
                 ▼
         Stream Processing Layer
      (Pthreads / MPI / Hybrid)
                 │
                 ▼
      Synchronization & Buffering
                 │
                 ▼
         Analytics & Processing
                 │
                 ▼
              Results
```

---

# Implemented Modules

## 1. POSIX Threads Producer–Consumer Prototype

Location:

```text
src/pthreads/
```

Features:

* Producer Thread
* Consumer Thread
* Circular Shared Buffer
* Mutex Synchronization
* Condition Variables
* Execution Time Measurement
* Throughput Measurement
* Average Buffer Occupancy Analysis
* Buffer Utilization Analysis

Workflow:

```text
Producer Thread
       ↓
Shared Buffer
       ↓
Consumer Thread
```

---

## 2. TCP Socket Communication Prototype

Location:

```text
src/sockets/
```

Features:

* TCP Server
* TCP Client
* Packet Transmission
* Packet Reception
* Packet Logging
* Throughput Measurement
* Delivery Statistics

Workflow:

```text
DES Server
      ↓
TCP Socket Connection
      ↓
Client
      ↓
Packet Logging
      ↓
Statistics Collection
```

---

# Build & Run Instructions

## POSIX Threads Module

Navigate to:

```bash
cd src/pthreads
```

Compile:

```bash
gcc stream.c -o stream -lpthread
```

Run:

```bash
./stream
```

---

## Socket Server

Navigate to:

```bash
cd src/sockets
```

Compile:

```bash
gcc server.c -o server
```

Run:

```bash
./server
```

---

## Socket Client

Open another terminal.

Navigate to:

```bash
cd src/sockets
```

Compile:

```bash
gcc client.c -o client
```

Run:

```bash
./client
```

---

# Repository Structure

```text
telecom-stream-processing-framework/
│
├── diagrams/
│   ├── producer_consumer_workflow.md
│   ├── shared_buffer_diagram.md
│   ├── socket_workflow.md
│   ├── system_architecture.md
│   └── testing_workflow.md
│
├── docs/
│   ├── design/
│   ├── progress/
│   ├── project/
│   └── testing/
│
├── logs/
│   └── received_packets.log
│
├── reports/
│   ├── GROUP-E_posix_threads/
│   └── GROUP-E_sockets/
│
├── src/
│   ├── pthreads/
│   ├── sockets/
│   ├── mpi/
│   └── hybrid/
│
├── tests/
│
└── README.md
```

---

# Testing & Validation Framework

A reusable testing and validation framework has been developed to support:

* Internal implementation validation
* Comparative evaluation
* Future MPI validation
* Future Hybrid framework validation

Validation Components:

* Test Plan
* Test Case Catalog
* Validation Checklist
* Observation Templates
* Bug Report Framework
* Performance Analysis Framework

---

# POSIX Threads Validation Results

Executed Test Cases:

* TC-01 Balanced Baseline
* TC-02 Small Buffer
* TC-03 Large Buffer
* TC-04 Fast Producer
* TC-05 Fast Consumer
* TC-06 High Volume
* TC-07 Slow System
* TC-08 Fast System
* TC-09 Maximum Throughput
* TC-10 Producer Burst
* TC-11 Consumer Burst

Results:

✅ No frame loss

✅ No frame duplication

✅ No race conditions

✅ No deadlocks

✅ No crashes

✅ Stable synchronization behavior

Performance Highlight:

* Maximum throughput exceeded **29,000 frames/sec**

---

# Socket Communication Validation Results

Executed Test Cases:

* SC-01 Functional Test
* SC-02 Small Stream Test
* SC-03 Medium Stream Test
* SC-04 High Rate Stream Test
* SC-05 High Throughput Test
* SC-06 Stress Test

Results:

✅ TCP connection established successfully

✅ Packet transmission successful

✅ Packet reception successful

✅ Packet ordering preserved

✅ Packet logging successful

✅ Zero packet loss observed

Performance Highlight:

* Maximum sustained throughput ≈ **904 packets/sec**
* Delivery Success Rate = **100%**

---

# Current Project Status

## Completed

✅ POSIX Threads Producer–Consumer Prototype

✅ Shared Buffer Synchronization Framework

✅ Performance Monitoring Framework

✅ Testing & Validation Framework

✅ TCP Socket Communication Prototype

✅ Packet Logging Framework

✅ Socket Validation Framework

✅ Stress Testing & Performance Analysis

---

## Next Phase

### POSIX Threads + Socket Integration

Target Workflow:

```text
Producer Thread
       ↓
Shared Buffer
       ↓
Sender Thread
       ↓
TCP Socket
       ↓
Client
       ↓
Packet Processing
```

---

## Future Phases

### Phase 3

* MPI-Based Distributed Processing
* Multi-Node Data Distribution
* Distributed Telecom Traffic Processing

### Phase 4

* Hybrid MPI + POSIX Threads Framework
* Distributed Multi-Threaded Processing
* Scalability Evaluation

### Phase 5

* Comparative Performance Analysis
* Benchmarking
* Final Framework Evaluation

---

# Team

| Name          | Institution     | Role        |
| ------------- | --------------- | ----------- |
| Jahnavi Pathi | MNIT Jaipur     | Team Lead   |
| Sreeja        | GNITS Hyderabad | Team Member |

---

# Acknowledgement

This project is being developed as part of the MPPLAB Telecom Data Extraction initiative under the guidance of **Dr. V. C. V. Rao**, focusing on the design, implementation, validation, and evaluation of parallel and distributed approaches for large-scale telecom stream processing.

---

# License

This repository is intended for academic research, experimentation, and educational purposes.
