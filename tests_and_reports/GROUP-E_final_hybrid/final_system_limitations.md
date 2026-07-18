# System Limitations and Future Work

## 1. Current Limitations

Although the Hybrid Telecom Stream Processing Framework successfully integrates MPI communication, POSIX Threads, Berkeley DB, Graph Analytics, and System Monitoring, the current implementation has the following limitations.

### 1.1 Fixed Shared Buffer Capacity

The shared circular buffer has a fixed capacity of **100 packets**. While this is sufficient for the current implementation and testing, it may become a bottleneck under extremely high traffic rates.

**Future Work**

- Implement a dynamically resizable shared buffer.
- Introduce adaptive flow control to handle burst traffic more efficiently.

---

### 1.2 Fixed Worker Thread Pool

The number of worker threads is fixed during system initialization. The framework does not dynamically adjust the worker pool based on workload or processor utilization.

**Future Work**

- Implement adaptive thread pool management.
- Automatically increase or decrease worker threads according to system load.

---

### 1.3 Synthetic Telecom Traffic

The framework currently processes **simulated telecom packets** generated for testing and evaluation. Real telecom traffic characteristics such as varying packet sizes, burst arrivals, and network delays are not considered.

**Future Work**

- Integrate real telecom traffic traces.
- Support live packet capture from network interfaces.

---

### 1.4 Console-Based Monitoring

System statistics and monitoring information are displayed through a command-line interface. The framework does not currently provide graphical visualization of runtime statistics.

**Future Work**

- Develop a web-based monitoring dashboard.
- Provide real-time visualization of throughput, packet processing, and graph analytics.

---

### 1.5 Single-Machine Evaluation

The framework has been designed using MPI and supports multiple Data Extraction Servers. However, experimental evaluation was performed on a **single machine** using multiple MPI processes.

**Future Work**

- Deploy the framework across multiple physical machines.
- Evaluate scalability in distributed cluster environments.

---

### 1.6 Basic Graph Analytics

The current graph analytics module provides communication volume, node degrees, most active source, most active destination, and top communication links. More advanced graph analysis techniques are not included.

**Future Work**

- Community detection.
- Shortest path analysis.
- Centrality measures.
- Temporal communication analysis.
- Traffic anomaly detection.

---

## 2. Future Enhancements

The Hybrid Telecom Stream Processing Framework can be further enhanced by incorporating the following features:

- Distributed deployment across multiple computing nodes.
- Dynamic load balancing between worker threads.
- Web-based monitoring and visualization dashboard.
- Persistent graph storage using graph databases.
- Machine Learning-based traffic prediction and anomaly detection.
- Secure communication using encryption and authentication.
- Configuration management through external configuration files.
- Comprehensive automated testing and benchmarking framework.

---

## 3. Conclusion

The current implementation successfully achieves the project objectives by integrating MPI communication, POSIX Thread-based parallel processing, Berkeley DB storage, graph construction, graph analytics, and system monitoring into a unified hybrid framework. The identified limitations primarily relate to scalability, deployment environment, and advanced analytical capabilities, providing clear directions for future enhancements.