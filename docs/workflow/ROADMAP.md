# Project Roadmap

This document tracks the planned milestones, study objectives, implementation goals, testing activities, and development phases of the Telecom Stream Processing Framework project.

The roadmap is iterative and will be updated throughout the project as new requirements, approaches, implementation strategies, and project phases are introduced.

---

# Week 1

## Overall Objective

Build a strong understanding of the POSIX Threads based Streaming Media Player architecture, implement a prototype, develop testing and validation methodologies, and establish a foundation for Socket Programming based communication models.

**Note:** MPI is not a primary focus during this week. Only a conceptual understanding of MPI and its role in distributed systems is required at this stage.

---

# Day 1 — Concept Study & Architecture Understanding (Both Team Members)

## Goal

By the end of Day 1, both team members should understand the complete workflow and all concepts required for implementation, testing, validation, and future project phases.

---

## 1. Understand the Complete Workflow

Study and understand:

```text
Streaming Source
      ↓
Producer Thread
      ↓
Shared Buffer
      ↓
Consumer Thread
      ↓
Output
```

Understand:

* Role of each component
* Data flow through the system
* Stream processing lifecycle
* Mapping of streaming concepts to telecom packet processing

---

## 2. POSIX Threads (Pthreads)

Study:

* Thread Lifecycle
* pthread_create()
* pthread_join()
* pthread_exit()
* Thread Synchronization
* Shared Memory Model
* Critical Sections

Understand:

* Why threads are used
* Benefits of multithreading
* Shared memory communication
* Race conditions
* Thread coordination

---

## 3. Producer–Consumer Model (In Depth)

Study:

* Producer
* Consumer
* Shared Buffer
* Bounded Buffer

Understand:

* Producer faster than consumer
* Consumer faster than producer
* Buffer full condition
* Buffer empty condition
* Blocking mechanisms
* Waiting mechanisms

---

## 4. Synchronization Concepts

Study:

* Mutexes
* Condition Variables
* Read–Write Locks

Understand:

* Why synchronization is necessary
* Race conditions
* Deadlocks
* Starvation
* Lock contention

---

## 5. Testing & Validation Concepts

Study:

* Functional Testing
* Stress Testing
* Performance Testing

Understand:

* What should be tested
* How bugs are identified
* How bottlenecks are identified
* Throughput
* Latency
* Buffer utilization

---

## 6. Streaming Media Player Architecture

Understand:

* Frame generation
* Frame buffering
* Frame consumption
* Continuous data streams

Study why the streaming media player architecture is being used as a reference model for telecom packet processing.

---

## 7. Socket Programming (Conceptual Overview)

Do not study implementation details yet.

Understand:

* What is a Client?
* What is a Server?
* Why sockets are used
* Data transfer between systems
* DES to Client communication model

Basic workflow:

```text
DES Server
      ↓
Socket Connection
      ↓
Client Receiver
```

---

## 8. MPI (Conceptual Overview)

Do not study MPI programming.

Understand:

* What MPI is
* Why MPI exists
* Shared Memory vs Message Passing
* Why MPI is useful for distributed systems

No implementation required.

---

## Day 1 Deliverables

Both team members should be able to explain:

1. Producer–Consumer Architecture
2. Shared Buffer Workflow
3. Synchronization Mechanisms
4. Streaming Media Player Architecture
5. Testing & Validation Strategy
6. Socket Programming Fundamentals
7. MPI Fundamentals

---

# Day 2-3 — POSIX Thread Model Implementation

## Team Member 1 (Jahnavi)

### Focus Areas

* Overall Architecture
* Frame/Data Structure Design
* Shared Buffer Design
* Statistics Design
* Documentation

### Tasks

* Define Frame structure
* Define Buffer workflow
* Define logging structure
* Document data flow
* Maintain implementation documentation

---

## Team Member 2 (Sreeja)

### Focus Areas

* POSIX Thread Implementation

### Tasks

* Producer Thread
* Consumer Thread
* Shared Queue
* Mutex Integration
* Condition Variables
* Synchronization logic

---

## Joint Goal

Implement:

```text
Producer
     ↓
Shared Buffer
     ↓
Consumer
```

using POSIX Threads.

---

# Day 4-5 — Testing, Validation & Analysis

## Team Member 1 (Jahnavi)

### Focus Areas

Testing Strategy and Validation Framework

### Tasks

* Create Test Cases
* Create Validation Checklist
* Create Observation Templates
* Define Performance Metrics

### Test Scenarios

* Small Buffer
* Large Buffer
* Fast Producer
* Slow Producer
* Fast Consumer
* Slow Consumer
* Large Number of Frames
* Multiple Consumers

---

## Team Member 2 (Sreeja)

### Focus Areas

Execution and Data Collection

### Tasks

Collect:

* Frames Produced
* Frames Consumed
* Execution Time
* Throughput
* Buffer Occupancy
* Waiting Time

---

## Joint Goal

Prepare:

* Bug Report
* Bottleneck Analysis
* Validation Report
* Performance Observations

These artifacts will later be used to test and evaluate Group-F's implementation.

---

# Day 6 — Socket Programming Study & Prototype Design

## Team Member 1 (Jahnavi)

### Study

* Client–Server Workflow
* TCP Communication Flow
* DES Architecture

### Design

* Packet Structure
* Data Flow Diagram
* Communication Workflow

---

## Team Member 2 (Sreeja)

### Study

* socket()
* bind()
* listen()
* accept()
* connect()
* send()
* recv()

### Design

* Basic Client–Server Architecture
* Server Workflow
* Client Workflow

---

## Joint Goal

Understand how a Data Extraction Server (DES) can be modeled using Socket Programming.

---

# Day 7 — Socket Programming Prototype

## Team Member 1 (Jahnavi)

### Implement

Client

Tasks:

* Connect to Server
* Receive Data
* Display Data
* Log Received Packets

---

## Team Member 2 (Sreeja)

### Implement

Server

Tasks:

* Generate Data
* Send Data
* Manage Client Connection

---

## Joint Goal

Build:

```text
Server
    ↓
Socket Connection
    ↓
Client
```

prototype.

---

# End of Week Deliverables

1. POSIX Thread Streaming Model
2. Producer–Consumer Implementation
3. Testing & Validation Framework
4. Validation Report Template
5. Socket Programming Prototype
6. Performance Observation Notes
7. Readiness to Review and Evaluate Group-F's Implementation

---

# Week 2

## Overall Objective

Integrate the POSIX Threads Producer–Consumer architecture with the Socket Programming communication model to create an end-to-end telecom packet streaming prototype. In parallel, develop a foundational MPI communication prototype, establish testing and validation methodologies for both implementations, and prepare the project for future Multi-DES and Hybrid processing architectures.

---

# Day 1 — Pthreads + Socket Integration Design

## Team Member 1 (Jahnavi)

### Focus Areas

* Integration Architecture
* Telecom Packet Design
* Workflow Documentation
* Statistics Design

### Tasks

* Design integrated architecture
* Define telecom packet structure
* Design packet lifecycle
* Design statistics collection framework
* Create integration workflow diagrams

---

## Team Member 2 (Sreeja)

### Focus Areas

* Integration Planning
* Existing Module Analysis

### Tasks

* Review Producer–Consumer implementation
* Review Socket Programming implementation
* Analyze integration requirements
* Identify modifications required for Sender Thread implementation

---

## Joint Goal

Design:

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
```

---

# Day 2 — Pthreads + Socket Integration Implementation

## Team Member 1 (Jahnavi)

### Focus Areas

* Integration Review
* Documentation
* Statistics Framework

### Tasks

* Review integration workflow
* Maintain implementation documentation
* Verify packet lifecycle implementation
* Finalize integration metrics

---

## Team Member 2 (Sreeja)

### Focus Areas

* Integration Implementation

### Tasks

* Replace Consumer Thread with Sender Thread
* Connect Shared Buffer with Socket communication
* Implement packet transmission workflow
* Implement end-to-end packet streaming
* Integrate statistics collection

---

## Joint Goal

Implement:

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
```

---

# Day 3 — Integration Testing, Validation & Analysis

## Team Member 1 (Jahnavi)

### Focus Areas

Testing Framework and Validation

### Tasks

* Create integration test cases
* Create validation checklist
* Define performance metrics
* Prepare observation templates

### Test Scenarios

* Small Packet Streams
* Large Packet Streams
* High Packet Rate
* Low Packet Rate
* Stress Testing
* Throughput Testing

---

## Team Member 2 (Sreeja)

### Focus Areas

Execution and Data Collection

### Tasks

Collect:

* Packets Generated
* Packets Buffered
* Packets Sent
* Packets Received
* Execution Time
* Throughput
* Packet Loss Statistics

---

## Joint Goal

Prepare:

* Integration Validation Report
* Integration Observation Report
* Integration Test Results
* Performance Analysis Report

---

# Day 4 — MPI Study & Prototype Design

## Team Member 1 (Jahnavi)

### Study

* MPI Architecture
* Distributed Memory Model
* Process Communication Workflow
* MPI Execution Model

### Design

* MPI Workflow Diagram
* MPI Communication Design
* MPI Validation Strategy

---

## Team Member 2 (Sreeja)

### Study

* MPI_Init()
* MPI_Finalize()
* MPI_Comm_rank()
* MPI_Comm_size()
* MPI_Send()
* MPI_Recv()

### Design

* Basic MPI Communication Architecture
* Process Communication Workflow

---

## Joint Goal

Understand and design:

```text
Process 0
      ↓
MPI_Send
      ↓
Process 1
      ↓
MPI_Recv
```

---

# Day 5 — MPI Prototype Implementation

## Team Member 1 (Jahnavi)

### Focus Areas

* Documentation
* Statistics Design
* Validation Planning

### Tasks

* Define MPI metrics
* Document MPI workflow
* Prepare testing framework

---

## Team Member 2 (Sreeja)

### Focus Areas

* MPI Implementation

### Tasks

* Implement MPI Hello World
* Implement MPI_Send()
* Implement MPI_Recv()
* Implement message exchange prototype
* Add basic statistics collection

---

## Joint Goal

Implement:

```text
Process 0
      ↓
MPI_Send
      ↓
Process 1
      ↓
MPI_Recv
```

---

# Day 6 — MPI Testing, Validation & Analysis

## Team Member 1 (Jahnavi)

### Focus Areas

Testing Framework and Validation

### Tasks

* Create MPI test cases
* Create MPI validation checklist
* Prepare observation templates
* Define performance metrics

---

## Team Member 2 (Sreeja)

### Focus Areas

Execution and Data Collection

### Tasks

Collect:

* Messages Sent
* Messages Received
* Execution Time
* Communication Statistics
* Throughput Metrics

---

## Joint Goal

Prepare:

* MPI Validation Report
* MPI Observation Report
* MPI Test Results
* Performance Analysis Report

---

# Day 7 — Documentation & Week Closure

## Team Member 1 (Jahnavi)

### Tasks

* Update Architecture Documentation
* Update Implementation Documentation
* Update Progress Log
* Update README
* Prepare Week 2 Progress Report

---

## Team Member 2 (Sreeja)

### Tasks

* Review implementation artifacts
* Review testing artifacts
* Organize source code and reports
* Verify repository structure

---

## Joint Goal

Finalize:

* Integrated Pthreads + Socket Prototype
* MPI Communication Prototype
* Validation Reports
* Performance Reports
* Week 2 Documentation

---

# End of Week Deliverables

1. Integrated Pthreads + Socket Streaming Prototype
2. Sender Thread Based Communication Architecture
3. Integration Validation Report
4. Integration Performance Analysis
5. MPI Communication Prototype
6. MPI Validation Report
7. MPI Performance Analysis
8. Updated Architecture and Implementation Documentation

---

# Week Roadmap – Group-E Communication Prototype

## Week Objective

Develop and validate the Group-E Communication Prototype based on Sir's implementation roadmap.

This phase focuses on:

- One Client → One Server communication
- Delay Injection and Queue (Bucket) validation
- Multiple Client → One Server communication
- Communication testing and validation
- Validation of Group-F Processing Prototype

Hybrid integration will begin only after both prototypes are independently completed and validated.

---

# Existing Implementations

The following implementations are already completed and documented under `docs/evolution/` and should be reused wherever applicable:

- POSIX Threads Producer–Consumer Framework
- TCP Socket Communication
- Pthreads + Socket Integration
- MPI Communication
- Multi-DES MPI Framework

The objective of this phase is to extend these implementations into a reusable Hybrid Communication Prototype.

---

# Work Distribution

## Jahnavi

### Communication Prototype Development

Responsibilities

- Review MPI and Multi-DES implementations
- Finalize TelecomPacket structure
- Finalize communication algorithm
- Implement Traffic Generator
- Implement MPI Client
- Implement MPI Server
- Implement Queue Interface
- Implement Packet Serialization
- Implement Communication Statistics
- Implement Delay Injection
- Implement Multiple Client support
- Prepare API documentation
- Review implementation

Deliverables

- Communication Prototype
- Communication Algorithm
- API Documentation
- Performance Results

---

## Sreeja

### Testing & Validation

Responsibilities

### Test Group-E Communication Prototype

- Unit Testing
- Module Testing
- Functional Testing
- Delay Injection Testing
- Stress Testing
- Failure Injection
- Scalability Testing
- Regression Testing
- Performance Testing

### Validate Group-F Prototype

- Review architecture
- Execute prototype
- Validate outputs
- Validate queue behaviour
- Validate synchronization
- Record observations
- Prepare validation report

Deliverables

- Test Cases
- Test Reports
- Validation Reports
- Performance Reports
- Group-F Validation Report

---

# Daily Plan

## Day 1 — One Client → One Server Design

### Jahnavi

- Review previous MPI implementation.
- Freeze TelecomPacket structure.
- Finalize communication algorithm.
- Set up communication framework.
- Prepare Traffic Generator design.

### Sreeja

- Study Group-F implementation.
- Prepare communication testing framework.
- Design unit and functional test cases.
- Prepare validation checklist.

Deliverable

- Communication design completed.
- Testing framework ready.

---

## Day 2 — One Client → One Server Prototype

### Jahnavi

Implement:

- Traffic Generator
- MPI Client
- MPI Server
- Packet Serialization
- One Client → One Server communication

### Sreeja

Execute:

- Unit Testing
- Functional Testing
- Communication Validation

Deliverable

Working One Client → One Server prototype.

---

## Day 3 — Queue & Delay Injection

### Jahnavi

Implement:

- Shared Packet Queue (Bucket)
- Queue Interface
- Client Delay Injection
- Server Delay Injection
- Communication Statistics

### Sreeja

Execute:

- Queue Validation
- Delay Injection Testing
- Throughput Testing
- Packet Loss Testing

Deliverable

Queue validation and communication statistics.

---

## Day 4 — Multiple Client Prototype

### Jahnavi

Extend communication to:

- 2 Clients → One Server
- 4 Clients → One Server
- 8 Clients → One Server

Implement:

- Round-Robin communication
- Multi-client communication handling

### Sreeja

Execute:

- Functional Testing
- Stress Testing
- Scalability Testing
- Multi-client Validation

Deliverable

Validated Multiple Client → One Server prototype.

---

## Day 5 — Group-F Prototype Validation

### Jahnavi

- Review communication prototype.
- Resolve communication issues.
- Improve logging.
- Improve error handling.
- Update documentation.

### Sreeja

Validate Group-F prototype.

Activities

- Execute prototype.
- Validate queue behaviour.
- Validate synchronization.
- Verify outputs.
- Record observations.
- Prepare validation report.

Deliverable

Validated Group-F Processing Prototype.

---

## Day 6 — Communication Testing & Prototype Freeze

### Jahnavi

- Resolve testing issues.
- Finalize communication prototype.
- Freeze APIs.
- Finalize communication algorithm.

### Sreeja

Execute:

- Regression Testing
- Performance Testing
- Validation Review

Deliverable

Communication Prototype ready for exchange.

---

## Day 7 — Documentation & Prototype Exchange

### Jahnavi

Prepare:

- Communication Prototype
- Communication Algorithm
- API Documentation
- Updated Documentation

### Sreeja

Prepare:

- Test Reports
- Validation Reports
- Performance Reports
- Group-F Evaluation Report

Joint Activities

- Review both prototypes.
- Exchange algorithms.
- Freeze interfaces.
- Prepare Hybrid integration plan.

Deliverable

Communication Prototype completed and validated.

---

# End-of-Week Deliverables

## Group-E

- One Client → One Server Prototype
- Multiple Client → One Server Prototype
- Delay Injection Framework
- Shared Packet Queue
- Communication Algorithm
- API Documentation
- Test Reports
- Performance Results

## Group-F

- Processing Prototype (Validated)

---

# Next Week

- Group-F validates the Group-E Communication Prototype.
- Both groups exchange algorithms and APIs.
- Finalize the Hybrid communication-processing interface.
- Integrate the Communication and Processing prototypes.
- Perform end-to-end Hybrid testing.
- Begin Berkeley DB, Graph Construction, Analytics, and Monitoring after successful Hybrid integration.