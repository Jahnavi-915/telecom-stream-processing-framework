# Meeting Notes

## Initial Project Understanding

- Project focuses on telecom stream processing.
- Multiple implementation approaches will be studied.
- Streaming Media Player acts as the initial reference architecture.
- POSIX Threads implementation is the first milestone.
- Socket Programming will be explored after POSIX implementation.
- MPI-based approaches will be investigated in later phases.
- Group-E is responsible for implementation understanding, testing, validation, and comparative analysis.

# Meeting Notes – Project Discussion with Supervisor

**Date:** 24 June 2026

## Discussion Summary

A discussion was held regarding the final direction of the Telecom Stream Processing Framework project based on the supervisor's email and follow-up call.

The objective is no longer limited to individual prototypes (Pthreads, Sockets, MPI, and Multi-DES). The focus has now shifted towards building a complete Hybrid Telecom Stream Processing and Analytics Platform.

---

## Key Requirements Discussed

### 1. Hybrid Distributed Processing Framework

The final system should integrate:

* MPI-based distributed processing
* POSIX Thread-based parallel processing
* Multiple Data Extraction Servers (DES)
* Real-time telecom data processing

The framework should support both:

* Single-machine execution
* Multi-machine cluster deployment

---

### 2. Cluster-Oriented Architecture

The supervisor emphasized designing the framework for cluster environments.

The system should be capable of:

* Running on a single machine during development and testing
* Running across multiple systems connected through a network
* Supporting distributed processing through MPI
* Supporting future scalability

A true Distributed Shared Memory (DSM) implementation is not mandatory. A distributed MPI-based architecture with process-level communication is acceptable and more practical within the project timeline.

---

### 3. Real-Time Telecom Data Processing

The framework should process telecom-like traffic streams whose characteristics resemble real-world telecom traffic.

Possible input sources include:

* Simulated telecom traffic
* Telecom traces
* Network traffic traces
* CSV datasets
* Real-time generated traffic streams

The final model should be demonstrated using realistic workloads.

---

### 4. Storage Layer

Processed telecom data should be stored persistently.

Current decision:

* Berkeley DB will be used as the primary storage mechanism.

The storage layer should support:

* Packet storage
* Metadata storage
* Retrieval of processed records

---

### 5. Graph Construction and Analytics

The supervisor suggested generating communication graphs from processed telecom traffic.

Graph representation may include:

* Vertices representing telecom entities
* Edges representing communication relationships
* Edge weights representing communication volume

Possible analytics:

* Traffic analysis
* Communication pattern analysis
* Node utilization analysis
* Throughput analysis
* Performance analysis

---

### 6. Software Engineering Focus

The project should follow professional software engineering practices.

Requirements include:

* Modular architecture
* Clean code organization
* Maintainable implementation
* Proper comments and documentation
* Defensive programming practices
* Assertions and validation checks
* Clear module boundaries
* Reusable components

The final repository should be understandable and executable by another user using only the provided documentation.

---

### 7. Documentation Expectations

The final repository should contain:

* Architecture documentation
* Design documentation
* Implementation documentation
* User Manual
* Technical Manual
* Testing and Validation Reports
* Performance Reports
* README with execution instructions

A new user should be able to:

1. Read the documentation.
2. Build the project.
3. Execute the framework.
4. Reproduce results.

---

### 8. Testing and Validation

The previously developed testing framework should be reused and extended.

Testing should include:

* Unit Testing
* Module Testing
* Integration Testing
* Functional Testing
* System Testing
* Performance Testing
* Stress Testing
* Scalability Testing
* Cluster Testing
* Validation and Comparative Evaluation

---

### 9. Final Deliverables

The final submission should include:

* Complete source code
* Complete repository structure
* Final report/thesis document
* Presentation slides
* Demonstration-ready implementation
* Testing and validation artifacts

---

## Important Deadlines

### Project Review Submission

**Deadline:** 12 July 2026

Items to be submitted:

* Complete project archive
* Updated repository
* Project report/thesis draft
* Presentation draft
* Supporting documentation

---

### Project Presentation

**Tentative Window:** 13–17 July 2026

Presentation Duration:

* Approximately 20 minutes presentation
* Followed by Q&A session

---

## Immediate Action Items

### Jahnavi

* Finalize Hybrid Architecture
* Lead MPI and integration development
* Coordinate overall implementation
* Manage testing and validation activities

### Sreeja

* Develop Berkeley DB module
* Develop Graph framework
* Develop Analytics framework
* Perform module-level testing

---

## Expected Final Workflow

```text
Traffic Source
      │
      ▼
Multiple DES
      │
      ▼
MPI Communication Layer
      │
      ▼
Shared Buffer
      │
      ▼
Worker Threads
      │
      ▼
Packet Processing
      │
      ▼
Graph Construction
      │
      ▼
Berkeley DB Storage
      │
      ▼
Analytics Engine
      │
      ▼
Reports and Visualization
```

The team will now proceed with implementation of the Hybrid Telecom Stream Processing Framework according to the finalized architecture and roadmap.

# Meeting Notes – Supervisor Email and Follow-up Discussion

**Date:** 25 June 2026

## Discussion Summary

The supervisor clarified the development strategy for both project groups through email and follow-up discussions. The emphasis shifted from developing independent implementations to building reusable prototypes that will later be integrated into a unified Hybrid Telecom Stream Processing Framework.

---

## Key Discussion Points

### 1. Independent Prototype Development

Both project groups should first complete their respective prototypes independently.

**Group-E**

* Develop the communication prototype.
* Implement MPI-based client-server communication.
* Support one-client/one-server communication.
* Extend to multiple MPI clients communicating with one server.
* Develop communication APIs and algorithms.

**Group-F**

* Develop the multithreaded processing prototype.
* Implement shared-memory packet processing using POSIX Threads.
* Generate synthetic telecom traffic.
* Finalize packet processing workflow.

---

### 2. Prototype Validation

Each prototype should be independently tested and validated before integration.

Validation activities include:

* Functional testing
* Unit testing
* Module testing
* Stress testing
* Performance testing
* Failure injection
* Scalability testing

Both groups should also understand the implementation developed by the other group.

---

### 3. Communication Prototype Requirements

The supervisor specified that the communication prototype should support:

* One Client → One Server communication.
* Delay injection at the client or server.
* Continuous packet reception.
* A shared packet queue (bucket) to accumulate incoming packets.
* Multiple MPI clients communicating with a single MPI server.
* Support for future cluster deployment.

---

### 4. Processing Prototype Requirements

The processing prototype should provide:

* Shared-memory packet buffering.
* Producer–Consumer implementation.
* Read/Write lock synchronization.
* Parallel packet processing using worker threads.
* Packet processing statistics.

---

### 5. Hybrid Integration Strategy

Hybrid integration will begin only after:

* Communication prototype completion.
* Processing prototype completion.
* Independent testing and validation.
* Prototype exchange between both groups.

Both teams should exchange:

* Algorithms
* API specifications
* Prototype implementations
* Validation reports

before integrating both systems into the Hybrid framework.

---

## Immediate Action Items

### Group-E

* Complete the communication prototype.
* Implement one-client/one-server communication.
* Extend to multiple MPI clients.
* Implement queue interface and delay injection.
* Prepare communication APIs and documentation.

### Group-F

* Complete the multithreaded processing prototype.
* Finalize packet processing framework.
* Generate synthetic telecom traffic.
* Prepare processing APIs and documentation.

---

## Outcome

Both groups will independently complete and validate their respective prototypes during the current development phase. Hybrid MPI–Pthreads integration, Berkeley DB, graph construction, analytics, and monitoring will begin only after successful prototype exchange and interface finalization.
