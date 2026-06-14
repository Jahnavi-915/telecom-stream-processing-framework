# Socket Prototype Observation Report

## Objective

To implement and evaluate a TCP-based Data Extraction Server (DES) and Client communication model for telecom stream processing. The objective was to establish reliable communication, transmit packet streams, collect performance statistics, and validate packet delivery.

## System Configuration

* Operating System: Ubuntu Linux
* Programming Language: C
* Communication Model: Client–Server
* Protocol: TCP
* Port Number: 8080
* Communication Medium: Localhost (127.0.0.1)

## Packet Structure

```c
typedef struct
{
    int packet_id;
    char payload[100];
} Packet;
```

## Experimental Setup

* Number of Packets Sent: 10
* Number of Packets Received: 10
* Packet Generation Interval: 1 second
* Transmission Mode: Continuous Packet Stream
* Communication Type: Reliable TCP Communication

## Server-Side Performance Results

| Metric             | Value            |
| ------------------ | ---------------- |
| Total Packets Sent | 10               |
| Execution Time     | 10.002772 sec    |
| Send Throughput    | 1.00 packets/sec |

### Server Throughput Calculation

Throughput = Total Packets Sent / Execution Time

= 10 / 10.002772

≈ 1.00 packets/sec

## Client-Side Performance Results

| Metric                 | Value            |
| ---------------------- | ---------------- |
| Total Packets Received | 10               |
| Execution Time         | 9.002475 sec     |
| Receive Throughput     | 1.11 packets/sec |

### Client Throughput Calculation

Throughput = Total Packets Received / Execution Time

= 10 / 9.002475

≈ 1.11 packets/sec

## Packet Delivery Statistics

| Metric                | Value |
| --------------------- | ----- |
| Packets Sent          | 10    |
| Packets Received      | 10    |
| Packet Loss           | 0     |
| Delivery Success Rate | 100%  |

### Packet Loss Calculation

Packet Loss = Packets Sent − Packets Received

= 10 − 10

= 0

### Delivery Success Rate

Success Rate = (Packets Received / Packets Sent) × 100

= (10 / 10) × 100

= 100%

## Observations

1. A TCP connection was successfully established between the server and client.
2. The server generated and transmitted a stream of 10 packets.
3. The client successfully received all transmitted packets.
4. No packet loss was observed during communication.
5. Packets were received in the correct order from Packet 1 to Packet 10.
6. Packet logging functionality worked correctly and all received packets were stored in the log file.
7. TCP ensured reliable and ordered packet delivery.
8. The server achieved a sustained transmission throughput of approximately 1.00 packet/sec.
9. The client achieved a reception throughput of approximately 1.11 packets/sec.
10. The experiment successfully simulated a basic telecom packet-streaming workflow.

## Discussion

The implementation demonstrates a simplified telecom stream-processing architecture consisting of a Data Extraction Server (DES), TCP communication channel, and a packet-receiving client. The experiment validates reliable packet transmission, packet logging, packet ordering, and performance measurement. The collected metrics provide a baseline for future enhancements involving multithreading, shared buffers, producer-consumer architectures, and distributed stream processing.

## Conclusion

A TCP-based socket communication prototype was successfully designed and implemented. The server transmitted 10 packets, and the client received all 10 packets with zero packet loss. Reliable communication, packet logging, throughput measurement, and performance monitoring were successfully demonstrated. This prototype serves as a foundation for future development of the Telecom Stream Processing Framework involving POSIX threads, producer-consumer models, and scalable telecom packet-processing systems.
