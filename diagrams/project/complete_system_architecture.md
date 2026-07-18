# Complete System Architecture

```text
                   Hybrid Telecom Stream Processing Framework


                        +----------------------+
                        |     MPI Clients      |
                        | (Traffic Generators) |
                        +----------+-----------+
                                   |
                                   |
                                   v
                    +-------------------------------+
                    |      Communication Layer      |
                    |        (MPI Server)           |
                    +---------------+---------------+
                                    |
                                    |
                                    v
                    +-------------------------------+
                    |       Shared Buffer           |
                    |    (Circular Queue - FIFO)    |
                    +---------------+---------------+
                                    |
                                    |
                                    v
                    +-------------------------------+
                    |         Worker Pool           |
                    |      (POSIX Threads)          |
                    +---------------+---------------+
                                    |
                                    |
                                    v
                    +-------------------------------+
                    |      Packet Processor         |
                    +---------------+---------------+
                                    |
                                    |
                                    v
                    +-------------------------------+
                    |        Berkeley DB            |
                    |     Persistent Storage        |
                    +---------------+---------------+
                                    |
                                    |
                                    v
                    +-------------------------------+
                    |        Graph Module           |
                    | Communication Relationships   |
                    +---------------+---------------+
                                    |
                                    |
                                    v
                    +-------------------------------+
                    |      Monitoring Layer         |
                    | Statistics & Performance      |
                    +-------------------------------+
```