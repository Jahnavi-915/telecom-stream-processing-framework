# Producer-Consumer Workflow Diagram

```text
Producer
    |
    | Generate Frame
    v
Acquire Mutex
    |
    v
Buffer Full?
    |
   Yes --------------------+
    |                       |
    v                       |
Wait on not_full            |
    |                       |
    +-----------------------+
    |
   No
    |
    v
Insert Frame
    |
    v
Signal not_empty
    |
    v
Release Mutex
```

```text
Consumer
    |
    v
Acquire Mutex
    |
    v
Buffer Empty?
    |
   Yes --------------------+
    |                       |
    v                       |
Wait on not_empty           |
    |                       |
    +-----------------------+
    |
   No
    |
    v
Remove Frame
    |
    v
Signal not_full
    |
    v
Release Mutex
```
