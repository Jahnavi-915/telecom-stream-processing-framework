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

# Week 3 Roadmap – Hybrid Telecom Stream Processing Framework

## Objective

Develop a production-quality Hybrid Telecom Stream Processing Framework capable of operating on both a single machine and a distributed cluster environment.

The framework will integrate:

* MPI-based distributed communication
* POSIX Thread-based parallel processing
* Berkeley DB storage
* Graph construction and analytics
* Monitoring and performance analysis
* Existing testing and validation framework

The final system should be modular, maintainable, well-documented, thoroughly tested, and deployment-ready.

---

# Team Responsibilities

## Jahnavi (Team Lead & Integration Owner)

### Primary Responsibilities

* Hybrid framework architecture
* MPI integration
* Multi-DES integration
* Shared buffer integration
* Thread pool integration
* Monitoring framework
* Build system
* End-to-end integration
* Testing coordination
* Performance evaluation
* Final documentation integration
* Repository management
* Presentation preparation

### Owned Modules

```text
src/hybrid/
├── hybrid_main.c
├── mpi/
├── processing/
├── monitoring/
└── Makefile
```

### Testing Ownership

* MPI unit testing
* Shared buffer unit testing
* Thread pool unit testing
* Integration testing
* System testing
* Performance testing
* Stress testing
* Scalability testing
* Cluster testing
* Final validation

---

## Sreeja

### Primary Responsibilities

* Berkeley DB integration
* Graph framework
* Analytics framework
* Module-level testing
* Module documentation

### Owned Modules

```text
src/hybrid/
├── database/
├── graph/
└── analytics/
```

### Testing Ownership

* Database unit testing
* Graph unit testing
* Analytics unit testing
* Functional testing support
* Module validation

---

# Day 1 – Architecture Freeze & Project Setup

## Jahnavi

* Finalize Hybrid Architecture
* Finalize Hybrid Design
* Create Hybrid source structure
* Review Group-F implementation
* Identify reusable APIs
* Define integration strategy
* Create implementation roadmap

## Sreeja

* Study Berkeley DB APIs
* Study graph representations
* Study analytics requirements
* Prepare module design

### Deliverables

* Hybrid architecture finalized
* Hybrid design finalized
* Hybrid source structure created
* Integration strategy documented

---

# Day 2 – Core Framework Setup

## Jahnavi

### Implementation

* Create TelecomPacket structure
* Create configuration framework
* Integrate Group-F shared buffer
* Refactor shared buffer APIs

### Unit Testing

* Buffer initialization
* Buffer enqueue
* Buffer dequeue
* Buffer overflow handling
* Buffer underflow handling

## Sreeja

### Implementation

* Design Berkeley DB schema
* Create database module skeleton
* Implement database initialization

### Unit Testing

* Database initialization

### Deliverables

```text
TelecomPacket
Shared Buffer
Database Skeleton
```

---

# Day 3 – MPI Integration

## Jahnavi

### Implementation

* Integrate MPI framework
* Integrate Multi-DES framework
* Connect MPI to shared buffer

```text
MPI
 ↓
Shared Buffer
```

### Unit Testing

* MPI initialization
* Packet send
* Packet receive
* Packet distribution
* Multi-DES communication

## Sreeja

### Implementation

* Packet storage APIs
* Packet retrieval APIs

### Unit Testing

* Packet insertion
* Packet retrieval

### Deliverables

```text
MPI → Shared Buffer
```

working successfully

---

# Day 4 – Thread Integration

## Jahnavi

### Implementation

* Integrate worker thread pool
* Integrate packet processing
* Connect threads to shared buffer

```text
MPI
 ↓
Buffer
 ↓
Threads
```

### Unit Testing

* Thread creation
* Synchronization
* Packet processing
* Multi-thread execution

## Sreeja

### Implementation

* Graph data structures
* Vertex management

### Unit Testing

* Vertex creation
* Vertex lookup

### Deliverables

```text
MPI → Buffer → Threads
```

working successfully

---

# Day 5 – Monitoring & Graph Framework

## Jahnavi

### Implementation

* Logger framework
* Statistics framework
* Throughput measurement
* Runtime monitoring

### Unit Testing

* Logging
* Statistics updates
* Throughput calculations

## Sreeja

### Implementation

* Edge management
* Graph construction
* Graph statistics

### Unit Testing

* Edge creation
* Edge updates
* Graph statistics

### Deliverables

* Monitoring framework operational
* Graph framework operational

---

# Day 6 – Database Integration

## Jahnavi

### Implementation

Integrate:

```text
MPI
 ↓
Buffer
 ↓
Threads
 ↓
Database
```

### Integration Testing

* Data flow validation
* Packet consistency validation

## Sreeja

### Implementation

* Complete Berkeley DB integration
* Complete graph framework
* Begin analytics framework

### Unit Testing

* Database consistency testing

### Deliverables

```text
MPI → Buffer → Threads → Database
```

working successfully

---

# Day 7 – Analytics Integration & Integration Testing

## Jahnavi

### Integration Testing

Validate:

```text
MPI
 ↓
Buffer
 ↓
Threads
```

Check:

* Packet flow correctness
* Synchronization correctness
* No packet loss
* No deadlocks
* No race conditions

## Sreeja

### Implementation

* Traffic analytics
* Graph analytics
* Performance analytics

### Unit Testing

* Analytics calculations
* Statistics generation

### Deliverables

```text
MPI
 ↓
Buffer
 ↓
Threads
 ↓
Database
 ↓
Graph
 ↓
Analytics
```

pipeline operational

---

# Day 8 – Functional Testing & System Testing

Using Existing Testing Framework:

* Test Plan
* Test Case Catalog
* Validation Checklist
* Observation Templates

## Both

### Functional Testing

Validate:

* Packet ingestion
* Packet processing
* Database storage
* Graph generation
* Analytics generation

### System Testing

Validate:

* Single-machine deployment
* Multi-DES deployment
* End-to-end execution

### Deliverables

* Functional testing completed
* System testing completed

---

# Day 9 – Performance, Stress & Scalability Testing

Using Existing Performance Framework.

## Both

### Performance Testing

Measure:

* Throughput
* Execution time
* Worker utilization
* Database performance

### Stress Testing

Execute:

```text
10,000 packets
50,000 packets
100,000 packets
```

Measure:

* Stability
* Resource usage
* Packet loss

### Scalability Testing

Evaluate:

```text
1 Worker
2 Workers
4 Workers
8 Workers
```

and

```text
1 DES
2 DES
4 DES
```

### Deliverables

* Performance results
* Stress testing results
* Scalability analysis

---

# Day 10 – Cluster Testing, Validation & Finalization

## Both

### Cluster Testing

Validate:

* Multi-node MPI execution
* Distributed processing
* Data consistency
* Cluster communication

### Validation

Generate:

* Validation Report
* Performance Report
* Test Results
* Observations

### Documentation

* README update
* Technical Manual
* User Manual
* Final Report
* PPT

### Repository Cleanup

* Remove unused files
* Remove debug code
* Add comments
* Verify build instructions

### Deliverables

* Final Hybrid Framework
* Final Documentation
* Final Reports
* Final Presentation
* Submission-Ready Repository

---

# Testing Strategy

The project will follow the previously developed testing framework and execute:

1. Unit Testing
2. Module Testing
3. Integration Testing
4. Functional Testing
5. System Testing
6. Performance Testing
7. Stress Testing
8. Scalability Testing
9. Cluster Testing
10. Validation & Comparative Evaluation

All testing results will be documented using the existing testing and validation framework developed during Weeks 1 and 2.

