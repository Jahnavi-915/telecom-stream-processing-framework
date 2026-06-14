# Test Case Catalog

## Purpose

This document defines the standard test cases used to validate Producer-Consumer implementations developed as part of the Telecom Stream Processing Framework project.

The same test suite can be reused to evaluate:

* Internal POSIX Threads implementations
* External team implementations
* Socket Programming prototypes
* MPI implementations
* Hybrid MPI + POSIX Threads models

---

# Functional and Validation Test Cases

## TC-01 Balanced Baseline

### Objective

Validate baseline producer-consumer functionality under balanced operating conditions.

### Configuration

* Buffer Size: 5
* Frames Generated: 20
* Producer Delay: 100 ms
* Consumer Delay: 100 ms

### Expected Result

* All frames produced
* All frames consumed
* Correct synchronization
* Stable execution

---

## TC-02 Small Buffer

### Objective

Evaluate implementation behavior under limited buffer capacity.

### Configuration

* Buffer Size: 2
* Frames Generated: 20
* Producer Delay: 100 ms
* Consumer Delay: 100 ms

### Expected Result

* Increased buffer utilization
* Possible waiting events
* Stable synchronization

---

## TC-03 Large Buffer

### Objective

Evaluate implementation behavior with increased buffer capacity.

### Configuration

* Buffer Size: 10
* Frames Generated: 20
* Producer Delay: 100 ms
* Consumer Delay: 100 ms

### Expected Result

* Reduced buffer utilization
* Minimal waiting events
* Stable execution

---

## TC-04 Fast Producer

### Objective

Evaluate synchronization when the producer operates faster than the consumer.

### Configuration

* Buffer Size: 5
* Frames Generated: 20
* Producer Delay: 50 ms
* Consumer Delay: 100 ms

### Expected Result

* Increased Buffer Full Events
* Higher buffer utilization
* No buffer overflow

---

## TC-05 Fast Consumer

### Objective

Evaluate synchronization when the consumer operates faster than the producer.

### Configuration

* Buffer Size: 5
* Frames Generated: 20
* Producer Delay: 100 ms
* Consumer Delay: 50 ms

### Expected Result

* Increased Buffer Empty Events
* Lower buffer occupancy
* Stable execution

---

## TC-06 High Volume

### Objective

Evaluate implementation stability under increased workload.

### Configuration

* Buffer Size: 5
* Frames Generated: 100
* Producer Delay: 100 ms
* Consumer Delay: 100 ms

### Expected Result

* Successful processing of all frames
* Stable synchronization
* No deadlocks or crashes

---

# Extended Performance Test Cases

## TC-07 Slow System

### Objective

Evaluate behavior under low-speed operating conditions.

### Configuration

* Buffer Size: 5
* Frames Generated: 20
* Producer Delay: 500 ms
* Consumer Delay: 500 ms

### Expected Result

* Increased execution time
* Reduced throughput
* Stable synchronization

---

## TC-08 Fast System

### Objective

Evaluate behavior under high-speed operating conditions.

### Configuration

* Buffer Size: 5
* Frames Generated: 20
* Producer Delay: 10 ms
* Consumer Delay: 10 ms

### Expected Result

* Reduced execution time
* Increased throughput
* Stable synchronization

---

## TC-09 Maximum Throughput

### Objective

Measure maximum processing capability without artificial delays.

### Configuration

* Buffer Size: 5
* Frames Generated: 10000
* Producer Delay: 0 ms
* Consumer Delay: 0 ms

### Expected Result

* Maximum throughput
* High synchronization activity
* Stable execution under heavy contention

---

## TC-10 Producer Burst

### Objective

Evaluate behavior when the producer significantly outpaces the consumer.

### Configuration

* Buffer Size: 5
* Frames Generated: 20
* Producer Delay: 0 ms
* Consumer Delay: 100 ms

### Expected Result

* Increased Buffer Full Events
* High buffer utilization
* Producer blocking

---

## TC-11 Consumer Burst

### Objective

Evaluate behavior when the consumer significantly outpaces the producer.

### Configuration

* Buffer Size: 5
* Frames Generated: 20
* Producer Delay: 100 ms
* Consumer Delay: 0 ms

### Expected Result

* Increased Buffer Empty Events
* Low buffer occupancy
* Consumer waiting

---

# Pass Criteria

A test case is considered successful if:

* Compilation succeeds
* Execution completes successfully
* Frames Produced = Frames Consumed
* No frame loss occurs
* No frame duplication occurs
* No deadlocks occur
* No crashes occur
* Synchronization behaves as expected
* Reported statistics are valid and consistent with the test configuration

---

# Socket Communication Test Cases

The following test cases were developed to validate the TCP-based Socket Communication module.

## SC-01 Functional Test

### Objective

Validate basic client-server communication and packet transmission.

### Configuration

* Packets Sent: 10
* Packet Delay: 1 second

### Expected Result

* Successful connection establishment
* Packets Sent = Packets Received
* Packet Loss = 0
* Stable execution

---

## SC-02 Small Stream Test

### Objective

Validate communication for a small packet stream.

### Configuration

* Packets Sent: 3
* Packet Delay: 1 second

### Expected Result

* Successful packet delivery
* Packet Loss = 0
* Stable communication

---

## SC-03 Medium Stream Test

### Objective

Validate communication stability for a longer packet stream.

### Configuration

* Packets Sent: 50
* Packet Delay: 1 second

### Expected Result

* Successful packet delivery
* Packet Loss = 0
* Stable throughput

---

## SC-04 High Rate Stream Test

### Objective

Evaluate communication under increased packet transmission rates.

### Configuration

* Packets Sent: 50
* Packet Delay: 0.1 second

### Expected Result

* Increased throughput
* Packet Loss = 0
* Stable communication

---

## SC-05 High Throughput Test

### Objective

Measure communication performance under aggressive packet generation.

### Configuration

* Packets Sent: 50
* Packet Delay: 0.001 second

### Expected Result

* High throughput
* Stable packet delivery
* No packet loss

---

## SC-06 Stress Test

### Objective

Validate stability under heavy communication workload.

### Configuration

* Packets Sent: 1000
* Packet Delay: 0.001 second

### Expected Result

* Successful transmission of all packets
* Packet Loss = 0
* Stable execution under stress conditions

---

# Socket Module Pass Criteria

A socket communication test is considered successful if:

* Server starts successfully.
* Client connects successfully.
* Packets Sent = Packets Received.
* Packet Loss = 0.
* Packet ordering is preserved.
* Logging completes successfully.
* Throughput is successfully calculated.
* Execution completes without crashes.
* Communication remains stable throughout the test.
