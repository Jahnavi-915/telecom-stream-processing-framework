# Communication Layer Performance Report

## Project

Hybrid Telecom Stream Processing Framework

## Module

Communication Layer (MPI)

---

# Objective

Evaluate the communication performance of the MPI communication layer under increasing communication workloads.

---

# Test Environment

| Parameter | Value |
|------------|--------|
| Operating System | Ubuntu Linux |
| Communication Library | OpenMPI |
| Language | C |
| Queue Capacity | 100 |
| Performance Mode | Enabled |
| Packet Logging | Disabled |
| Packet Size | 256 Bytes |

---

# Benchmark Configuration

The performance evaluation was performed using a dedicated performance configuration.

During benchmarking:

- Performance Mode was enabled.
- Packet logging was disabled.
- Each MPI client transmitted 1000 packets to the communication server.
- Packets were processed immediately after reception to eliminate the artificial processing bottleneck introduced during queue stress testing.

---

# Benchmark Results

| MPI Processes | MPI Clients | Packets / MPI Client | Total Packets | Execution Time (s) | Average Time / Packet (ms) | Throughput (Packets/s) |
|---------------:|------------:|---------------------:|--------------:|-------------------:|---------------------------:|-----------------------:|
| 2 | 1 | 1000 | 1000 | 0.003072 | 0.003072 | 325541.29 |
| 3 | 2 | 1000 | 2000 | 0.003146 | 0.001573 | 635749.73 |
| 5 | 4 | 1000 | 4000 | 0.003380 | 0.000845 | 1183602.84 |

---

# Observations

- All benchmark executions completed successfully.
- No packet loss was observed.
- Packets Enqueued matched Packets Dequeued in every experiment.
- Queue occupancy remained at one packet because packets were processed immediately after reception.
- Communication throughput increased with increasing numbers of concurrent MPI clients.
- Execution time remained nearly constant while total packet count increased, resulting in higher aggregate communication throughput.

---

# Comparison with Stress Testing

Unlike the queue stress tests performed during Phase 6, the performance evaluation was executed using Performance Mode.

The communication queue therefore operated without the artificial producer-consumer imbalance introduced during stress testing, allowing the communication performance of the MPI layer to be evaluated independently.

---

# Conclusion

The MPI communication layer demonstrated stable and scalable communication performance under increasing workloads. As the number of concurrent MPI clients increased, overall throughput improved while maintaining reliable packet transmission and reception.

The benchmark results indicate that the communication module scales effectively with multiple concurrent MPI clients while maintaining correct packet transmission and reception.

The communication layer is considered ready for hybrid integration with the POSIX Threads shared buffer.

Within the Hybrid Telecom Stream Processing Framework, each MPI client represents an individual Data Extraction Server (DES) during communication-layer execution.