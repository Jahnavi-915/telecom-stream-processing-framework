# Processing Hybrid Performance Report

## 1. Overview

This report summarizes the performance evaluation of the Processing Layer.

The evaluation measures:

- Execution Time
- Average Processing Time
- Throughput
- Queue Utilization

---

## 2. Performance Results

### Test 1

| Parameter | Value |
|-----------|-------|
| Clients | 1 |
| Packets | 10 |
| Execution Time | 0.000071 seconds |
| Average Time/Packet | 0.007053 ms |
| Throughput | 141783.64 packets/sec |
| Maximum Queue Size | 10 |

---

### Test 2

| Parameter | Value |
|-----------|-------|
| Clients | 1 |
| Packets | 100 |
| Execution Time | 0.001793 seconds |
| Average Time/Packet | 0.017928 ms |
| Throughput | 55778.48 packets/sec |
| Maximum Queue Size | 94 |

---

### Test 3

| Parameter | Value |
|-----------|-------|
| Clients | 4 |
| Packets/Client | 100 |
| Total Packets | 400 |
| Execution Time | 0.007037 seconds |
| Average Time/Packet | 0.017592 ms |
| Throughput | 56844.29 packets/sec |
| Maximum Queue Size | 100 |

---

## 3. Observations

- The worker pool successfully processed packets under varying workloads.
- Queue utilization increased as packet load increased.
- The shared buffer reached full utilization during the highest workload without packet loss.
- Throughput remained stable under concurrent execution.
- All packets were processed successfully.

---

## 4. Conclusion

The processing layer demonstrates efficient concurrent packet processing using POSIX Threads. The implementation maintained data integrity, queue consistency, and high throughput during all evaluation scenarios.