# Module Interaction Diagram

```text
                  Module Interaction Diagram


+---------------------------+
|   Communication Layer     |
|          (MPI)            |
+-------------+-------------+
              |
              | Receives Packets
              |
              v
+---------------------------+
|    Processing Layer       |
| (Shared Buffer + Threads) |
+-------------+-------------+
              |
              | Processes Packets
              |
              v
+---------------------------+
|      Storage Layer        |
|      (Berkeley DB)        |
+-------------+-------------+
              |
              | Reads Stored Data
              |
              v
+---------------------------+
|       Graph Module        |
| Communication Analysis    |
+-------------+-------------+
              |
              | Generates Statistics
              |
              v
+---------------------------+
|    Monitoring Layer       |
| Runtime Performance       |
+---------------------------+
```