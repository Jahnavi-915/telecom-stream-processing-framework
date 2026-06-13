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

# Future Roadmap

This section will be expanded as the project progresses and new phases, implementation approaches, evaluation criteria, and project milestones are introduced.

