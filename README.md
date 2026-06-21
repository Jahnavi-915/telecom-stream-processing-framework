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
* MPI Distributed Processing
* Multi-DES MPI Processing
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
## 3. Pthreads + Socket Integration Prototype

Location:

```text
src/hybrid/pthreads_socket_integration/
```

Features:

* Producer Thread
* Shared Circular Buffer
* Sender Thread
* TCP Server
* TCP Client
* Telecom Packet Structure
* Packet Logging
* Performance Monitoring
* Throughput Measurement
* Delivery Success Rate Measurement

Workflow:

```text
Producer Thread
       ↓
Shared Buffer
       ↓
Sender Thread
       ↓
TCP Socket
       ↓
Client Receiver
       ↓
Packet Logging
       ↓
Statistics Collection
```
## 4. MPI Distributed Processing Module

Location:

```text
src/mpi/
```

Features:

* MPI Master Process
* MPI Worker Processes
* Telecom Packet Structure
* MPI_Send Communication
* MPI_Recv Communication
* Round-Robin Packet Distribution
* Distributed Packet Processing
* Communication Success Rate Measurement
* Throughput Measurement
* Performance Monitoring

Workflow:

```text
Master Process (DES)
         ↓
MPI Communication Layer
         ↓
Worker Processes
         ↓
Distributed Packet Processing
         ↓
Statistics Collection
```
## 5. Multi-DES MPI Distributed Processing Module

Location:

```text
src/mpi/
```

Features:

* Multiple Data Extraction Servers (DES)
* MPI Master Process
* MPI Worker Processes
* Telecom Packet Structure
* DES-to-Master Communication
* Master-to-Worker Communication
* Round-Robin Packet Distribution
* Packet Logging
* Distributed Statistics Collection
* Worker Load Analysis
* Throughput Measurement
* Communication Success Rate Measurement

Workflow:

```text
DES-1 ─┐
DES-2 ─┼──► Master Process
DES-3 ─┘
              │
              ▼
        Worker Processes
              │
              ▼
      Distributed Processing
              │
              ▼
       Statistics Collection
```

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
## Pthreads + Socket Integration Server

Navigate to:

```bash
cd src/hybrid/pthreads_socket_integration
```

Compile:

```bash
gcc server.c -o server -lpthread
```

Run:

```bash
./server
```

---

## Pthreads + Socket Integration Client

Open another terminal.

Navigate to:

```bash
cd src/hybrid/pthreads_socket_integration
```

Compile:

```bash
gcc client.c -o client
```

Run:

```bash
./client
```
## MPI Distributed Processing Module

Navigate to:

```bash
cd src/mpi
```

Compile:

```bash
mpicc mpi_stream.c -o mpi_stream
```

Run (2 Processes):

```bash
mpirun -np 2 ./mpi_stream
```

Run (4 Processes):

```bash
mpirun -np 4 ./mpi_stream
```

Run (8 Processes):

```bash
mpirun -np 8 ./mpi_stream
```
## Multi-DES MPI Module

Navigate to:

```bash
cd src/mpi
```

Compile:

```bash
mpicc multi_des.c -o multi_des
```

Run:

```bash
mpirun -np 12 ./multi_des
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
│   ├── multi_des_packets.log
│   └── single_des_packets.log
|
├── reports/
│   ├── GROUP-E_posix_threads/
│   ├── GROUP-E_sockets/
│   ├── GROUP-E_integration/
│   └── GROUP-E_mpi/
│       ├── multi-des/
│       └── single-des/
|
├── src/
│   ├── pthreads/
│   ├── sockets/
|   ├── integration/
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
* MPI validation
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

# Pthreads + Socket Integration Validation Results

Executed Test Cases:

* IC-01 Functional Test
* IC-02 Small Stream Test
* IC-03 Medium Stream Test
* IC-04 High Rate Stream Test
* IC-05 High Throughput Test
* IC-06 Stress Test

Results:

✅ Producer–Sender synchronization successful

✅ TCP communication successful

✅ Packet transmission successful

✅ Packet reception successful

✅ Packet ordering preserved

✅ Packet logging successful

✅ Zero packet loss observed

✅ No race conditions observed

✅ No deadlocks observed

Performance Highlights:

* Maximum Send Throughput ≈ 927 packets/sec
* Maximum Receive Throughput ≈ 927 packets/sec
* Total Packets Sent = 10,000
* Total Packets Received = 10,000
* Delivery Success Rate = 100%

# MPI Distributed Processing Validation Results

Executed Test Cases:

* MC-01 Functional Test
* MC-02 Multiple Worker Test
* MC-03 Medium Workload Test
* MC-04 High Workload Test
* MC-05 High Throughput Test
* MC-06 Stress Test

Results:

✅ MPI communication successful

✅ Master–Worker coordination verified

✅ Round-Robin packet distribution verified

✅ Balanced workload allocation verified

✅ Packet ordering preserved

✅ Zero packet loss observed

✅ Stable distributed execution confirmed

Performance Highlights:

* Maximum Packets Tested = 10,000
* Maximum Processes Tested = 8
* Maximum Workers Tested = 7
* Peak Throughput ≈ 507,614 packets/sec
* Communication Success Rate = 100%

# Multi-DES MPI Validation Results

Executed Test Cases:

* MD-01 Functional Test
* MD-02 Single Worker Test
* MD-03 Multiple Worker Test
* MD-04 Load Balancing Test
* MD-05 High Workload Test
* MD-06 Scalability Test
* MD-07 Stress Test

Results:

✅ Multi-DES communication successful

✅ DES-to-Master communication verified

✅ Master-to-Worker communication verified

✅ Load balancing verified

✅ Worker utilization verified

✅ Zero packet loss observed

✅ Stable distributed execution confirmed

Performance Highlights:

* Maximum Total Packets Tested = 30,000
* Maximum Workers Tested = 8
* Maximum Processes Tested = 12
* Peak Throughput ≈ 1,188,683 packets/sec
* Communication Success Rate = 100%

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

✅ Pthreads + Socket Integration Prototype

✅ Integration Performance Monitoring Framework

✅ Integration Testing & Validation Framework

✅ MPI Distributed Processing Module

✅ Master–Worker Communication Framework

✅ Round-Robin Packet Distribution

✅ MPI Testing & Validation Framework

✅ Distributed Performance Monitoring

✅ MPI Stress Testing & Analysis

✅ Multi-DES MPI Distributed Processing Framework

✅ DES-to-Master Communication Framework

✅ Master-to-Worker Communication Framework

✅ Packet Logging Framework

✅ Load Balancing Framework

✅ Multi-DES Testing & Validation Framework

✅ Multi-DES Stress Testing & Analysis

---

## Future Phases

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
