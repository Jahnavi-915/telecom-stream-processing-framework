# MPI Distributed Processing Workflow

Phase 1: Single DES - Single Worker

DES Simulator (Rank 0)
          │
          ▼
Generate Telecom Packet
          │
          ▼
      MPI_Send()
          │
          ▼
      MPI_Recv()
          │
          ▼
 Worker Process (Rank 1)
          │
          ▼
 Process Telecom Packet
          │
          ▼
 Statistics Collection

================================================================

Phase 2: Single DES - Multiple Workers

                 DES Simulator
                   (Rank 0)
                       │
      ┌────────────────┼────────────────┐
      │                │                │
      ▼                ▼                ▼
 Rank 1           Rank 2           Rank 3
 Worker           Worker           Worker
      │                │                │
      ▼                ▼                ▼
Packet Proc.     Packet Proc.     Packet Proc.
      │                │                │
      └────────────────┼────────────────┘
                       ▼
             Statistics Collection

================================================================

Phase 3: Multiple DES - Multiple Workers

 DES-1        DES-2        DES-3
   │            │            │
   └────────────┼────────────┘
                │
                ▼
      MPI Communication Layer
                │
     ┌──────────┼──────────┐
     │          │          │
     ▼          ▼          ▼
 Worker-1   Worker-2   Worker-3
     │          │          │
     ▼          ▼          ▼
 Packet     Packet     Packet
Processing Processing Processing
     │          │          │
     └──────────┼──────────┘
                ▼
      Statistics Collection

================================================================

Future Hybrid MPI + POSIX Threads Architecture

 Multiple DES
       │
       ▼
 MPI Communication Layer
       │
       ▼
 MPI Process
       │
       ▼
 Producer Thread
       │
       ▼
 Shared Buffer
       │
       ▼
 Consumer Thread
       │
       ▼
 Packet Processing
       │
       ▼
 Statistics Collection