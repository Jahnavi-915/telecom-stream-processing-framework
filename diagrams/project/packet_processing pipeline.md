# Packet Processing Pipeline

```text
                   Telecom Packet Processing Pipeline


     +-------------------------+
     |  Packet Generated       |
     |      (MPI Client)       |
     +------------+------------+
                  |
                  v
     +-------------------------+
     |    Packet Received      |
     |     (MPI Server)        |
     +------------+------------+
                  |
                  v
     +-------------------------+
     |   Packet Validation     |
     +------------+------------+
                  |
                  v
     +-------------------------+
     | Enqueue into Shared     |
     |      Buffer Queue       |
     +------------+------------+
                  |
                  v
     +-------------------------+
     | Worker Thread Dequeues  |
     |        Packet           |
     +------------+------------+
                  |
                  v
     +-------------------------+
     | Packet Processing       |
     | (Header & Payload)      |
     +------------+------------+
                  |
                  v
     +-------------------------+
     | Store in Berkeley DB    |
     +------------+------------+
                  |
                  v
     +-------------------------+
     | Update Communication    |
     |        Graph            |
     +------------+------------+
                  |
                  v
     +-------------------------+
     | Update Runtime          |
     | Statistics              |
     +------------+------------+
                  |
                  v
     +-------------------------+
     | Processing Complete     |
     +-------------------------+
```