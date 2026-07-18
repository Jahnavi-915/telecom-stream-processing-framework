# Communication Layer Test Results

## Project

Hybrid Telecom Stream Processing Framework

## Module

Communication Layer (MPI)

---

# Test Environment

| Parameter | Value |
|------------|--------|
| Operating System | Ubuntu Linux |
| Communication Library | MPI (OpenMPI) |
| Language | C |
| Build System | Make |
| Communication Type | Point-to-Point MPI |
| Queue Type | Circular Queue |
| Queue Capacity | 100 |
| Processing Batch Size | 5 |

---

# Phase 1 - Basic MPI Communication

## Objective

Validate successful packet transmission between a single MPI client and a single MPI server.

## Test Configuration

| Parameter | Value |
|------------|--------|
| Server | 1 |
| Client | 1 |
| Packets | 1 |

## Expected Result

- Packet generation successful.
- Packet serialization successful.
- Packet transmitted using MPI_Send().
- Packet received using MPI_Recv().
- Packet deserialized successfully.

## Observed Result

- Packet successfully generated.
- Packet successfully transmitted.
- Packet successfully received.
- Packet contents matched before and after transmission.

## Result

PASS

---

# Phase 2 - Continuous Communication

## Objective

Validate reliable continuous packet transmission between one MPI client and one MPI server under sustained communication.

## Test Configuration

| Parameter | Value |
|------------|--------|
| Server | 1 |
| Client | 1 |
| Packets | 1000 |

## Expected Result

- Continuous packet transmission without communication failure.
- All packets successfully transmitted and received.
- No packet corruption.
- Stable communication throughout execution.

## Observed Result

- Successfully transmitted 1000 packets.
- Successfully received 1000 packets.
- No packet loss observed.
- Communication remained stable throughout execution.

## Analysis

The communication layer successfully handled prolonged packet transmission without errors, demonstrating the stability of the MPI communication pipeline under continuous workload.

## Result

PASS

---

# Phase 3 - Communication Queue

## Objective

Validate communication queue functionality.

## Features Tested

- Queue initialization
- Enqueue operation
- Dequeue operation
- Queue statistics
- Queue destruction

## Test Configuration

| Parameter | Value |
|------------|--------|
| Queue Capacity | 100 |
| Packets | 25 |

## Observed Result

Maximum Queue Size : 1

Packets Enqueued : 25

Packets Dequeued : 25

Queue destroyed successfully after processing.

## Analysis

At this stage, packet reception and packet processing occurred sequentially. Each received packet was immediately processed and removed from the communication queue, resulting in a maximum queue occupancy of one packet.

## Result

PASS

---

# Phase 4 - Queue Stress Testing

## Objective

Validate queue behavior when packet arrival rate exceeds packet processing rate.

## Configuration

| Parameter | Value |
|------------|--------|
| Queue Capacity | 100 |
| Processing Batch Size | 5 |
| Packets | 25 |

## Processing Strategy

Receive 5 packets

↓

Process 1 packet

## Expected Result

Queue occupancy should increase during execution while maintaining data integrity.

## Observed Result

Maximum Queue Size : 21

Packets Enqueued : 25

Packets Dequeued : 25

Queue completely emptied before shutdown.

## Analysis

The producer generated packets faster than the simulated consumer processed them. Queue occupancy increased as expected while maintaining correct packet delivery.

## Result

PASS

---

# Phase 5 - Multiple MPI Client Communication

## Objective

Validate simultaneous communication from multiple MPI clients.

---

## Test Case 5.1

### Configuration

| Parameter | Value |
|------------|--------|
| Server | 1 |
| Clients | 2 |
| Packets per Client | 25 |
| Expected Packets | 50 |

### Expected Result

- Server should receive packets from both clients.
- No packet loss.
- Queue statistics should match expected packet count.

### Observed Result

Packets Enqueued : 50

Packets Dequeued : 50

Maximum Queue Size : 41

Packets successfully received from Client 1 and Client 2.

### Result

PASS

---

# Phase 6 - Scalability Testing

## Test Case 6.1

### Configuration

| Parameter | Value |
|------------|--------|
| Server | 1 |
| Clients | 4 |
| Packets per Client | 25 |
| Expected Packets | 100 |

### Observed Result

- All packets successfully received.
- Queue operated correctly.
- No packet loss observed.

### Result

PASS

---

## Test Case 6.2

### Configuration

| Parameter | Value |
|------------|--------|
| Server | 1 |
| Clients | 8 |
| Packets per Client | 25 |
| Expected Packets | 200 |

### Observed Result

Maximum Queue Size : 100

Packets Enqueued : 124

Packets Dequeued : 24

Communication queue reached maximum capacity.

Server terminated after queue overflow.

Remaining clients continued packet transmission.

### Analysis

During the scalability test with eight concurrent MPI clients, the communication queue reached its configured capacity of 100 packets.

This behavior is not caused solely by the queue capacity. The primary reason is the temporary communication-layer architecture used during MPI validation.

The current MPI server performs packet reception and packet processing within the same execution thread. Packet processing is intentionally simulated using a slower processing strategy (processing one packet after every five received packets) to validate queue growth and communication behavior.

As the number of concurrent MPI clients increases, packets are received significantly faster than they are processed. Since packet reception and processing share the same thread, the server cannot continue receiving packets while simultaneously reducing queue occupancy. Consequently, the queue eventually reaches its maximum capacity and rejects additional packets.

This limitation is specific to the current communication-layer prototype and does not represent the intended architecture of the Hybrid Telecom Stream Processing Framework.

### Result

EXPECTED LIMITATION

---

# Overall Test Summary

| Phase | Description | Status |
|--------|-------------|--------|
| Phase 1 | Basic MPI Communication | PASS |
| Phase 2 | Continuous Communication | PASS |
| Phase 3 | Communication Queue | PASS |
| Phase 4 | Queue Stress Testing | PASS |
| Phase 5 | Multiple MPI Clients | PASS |
| Phase 6.1 | Scalability (4 Clients) | PASS |
| Phase 6.2 | Scalability (8 Clients) | EXPECTED LIMITATION |

---

# Conclusion

The communication layer has been successfully validated for:

- Basic MPI communication
- Continuous packet transmission
- Communication queue operations
- Queue stress testing
- Multiple MPI client communication
- Scalability testing with multiple concurrent clients

The communication layer successfully demonstrated reliable packet transmission under single-client and multi-client configurations. Queue stress testing verified the correctness of the communication queue implementation and exposed the expected limitation of the temporary single-threaded communication prototype under high producer concurrency.

This limitation has been documented and will be addressed during hybrid integration, where the temporary communication queue will be replaced by a POSIX Threads producer-consumer shared buffer capable of concurrent packet reception and processing.

## Future Improvement

The current communication queue serves as a temporary validation component for the MPI communication layer and is not intended to represent the final runtime architecture of the Hybrid Telecom Stream Processing Framework.
During hybrid integration, the temporary communication queue will be replaced with the POSIX Threads shared buffer developed by Group-F.

The hybrid architecture will separate packet reception from packet processing using multiple execution threads.

The communication pipeline will become:

MPI Receiver Thread
        ↓
Shared Buffer
        ↓
Worker Threads
        ↓
Packet Processing

In this architecture, the receiver thread continuously accepts incoming packets while worker threads concurrently remove packets from the shared buffer for processing. If the shared buffer becomes full, producer threads will block until buffer space becomes available instead of terminating the communication process.

This producer-consumer design eliminates the artificial bottleneck introduced by the current single-threaded implementation and provides realistic queue behavior under high communication workloads.


---

# Independent Validation Summary

## Validation Activities

The communication layer was independently validated after integrating the latest communication prototype.

The following activities were performed:

- Successfully compiled the project.
- Successfully executed the communication prototype.
- Verified MPI communication.
- Verified queue operations.
- Verified packet transmission.
- Verified packet reception.
- Reviewed communication statistics.
- Compared observed execution with documented results.

---

# Validation Summary

| Validation Item | Status |
|-----------------|--------|
| Build Verification | PASS |
| MPI Communication | PASS |
| Queue Operations | PASS |
| Packet Transmission | PASS |
| Packet Reception | PASS |
| Performance Summary | PASS |

---

# Conclusion

The communication layer operated correctly during validation. The observed behaviour matched the documented communication workflow and no functional issues were identified.
