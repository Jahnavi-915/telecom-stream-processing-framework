# Pthreads + Socket Integration Workflow

## Overview

This diagram illustrates the integrated telecom packet streaming architecture combining POSIX Threads and TCP Socket Programming.

---

## Workflow

```text
+-------------------+
| Producer Thread   |
+-------------------+
          |
          v
+-------------------+
| Shared Buffer     |
| (Circular Queue)  |
+-------------------+
          |
          v
+-------------------+
| Sender Thread     |
+-------------------+
          |
          v
+-------------------+
| TCP Socket Layer  |
+-------------------+
          |
          v
+-------------------+
| Client            |
+-------------------+
          |
          v
+-------------------+
| Packet Logging    |
+-------------------+
```

---

## Packet Flow

```text
Packet Generated
        ↓
Shared Buffer
        ↓
Sender Thread
        ↓
TCP Transmission
        ↓
Client Reception
        ↓
Packet Logging
```

---

## Purpose

The integration combines:

- Shared-memory processing using POSIX Threads.
- Reliable packet communication using TCP sockets.

This architecture serves as the first complete telecom packet streaming prototype and provides the foundation for future distributed processing models.