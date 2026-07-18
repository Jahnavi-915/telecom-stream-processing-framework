# Socket Communication Workflow Diagram

## Overview

This diagram illustrates the workflow of the TCP-based Socket Communication Prototype implemented for the Telecom Stream Processing Framework project.

The prototype simulates communication between a Data Extraction Server (DES) and a receiving client using TCP sockets.

---

## High-Level Architecture

```text
+----------------------+
|   DES Server         |
| (Packet Generator)   |
+----------+-----------+
           |
           | TCP Connection
           v
+----------------------+
|      Client          |
| (Packet Receiver)    |
+----------+-----------+
           |
           v
+----------------------+
|   Packet Logging     |
+----------+-----------+
           |
           v
+----------------------+
| Statistics & Metrics |
+----------------------+
```

---

## Communication Workflow

```text
Server Start
      |
      v
Create Socket
      |
      v
Bind To Port
      |
      v
Listen For Client
      |
      v
Accept Connection
      |
      v
Generate Packet
      |
      v
Send Packet
      |
      v
=========================
 TCP Socket Connection
=========================
      |
      v
Receive Packet
      |
      v
Log Packet
      |
      v
Update Statistics
      |
      v
Display Results
```

---

## Packet Processing Flow

```text
Packet Creation
      |
      v
Packet Transmission
      |
      v
Packet Reception
      |
      v
Packet Logging
      |
      v
Statistics Collection
      |
      v
Validation & Analysis
```

---

## Server Responsibilities

### TCP Server

* Create Socket
* Bind Socket
* Listen For Connections
* Accept Client Connection
* Generate Packets
* Send Packets
* Calculate Statistics
* Close Connection

---

## Client Responsibilities

### TCP Client

* Create Socket
* Connect To Server
* Receive Packets
* Log Packet Information
* Calculate Statistics
* Close Connection

---

## Statistics Collection

### Server Side

* Total Packets Sent
* Execution Time
* Send Throughput

### Client Side

* Total Packets Received
* Execution Time
* Receive Throughput

### Communication Metrics

* Packet Loss
* Delivery Success Rate
* Packet Ordering Verification

---

## Future Integration Architecture

The socket communication module will be integrated with the POSIX Threads Producer-Consumer architecture.

```text
Producer Thread
       |
       v
Shared Buffer
       |
       v
Sender Thread
       |
       v
TCP Socket
       |
       v
Client
       |
       v
Packet Processing
```

This architecture will form the foundation of the Telecom Stream Processing Framework.
