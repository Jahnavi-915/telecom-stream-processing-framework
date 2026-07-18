# Test Results Report

**Project:** Multi-Threaded Telecom Data Extraction System

**Group:** Group-F

**Language:** C (POSIX Threads)

**Operating System:** Ubuntu Linux

**Compiler:** GCC

---

# Objective

The objective of testing was to verify the correct functioning of the telecom data extraction system.

The following modules were tested individually and as an integrated application.

- Shared Buffer
- Producer Module
- Consumer Module
- Integrated Media Player

---

# Build Verification

The project was compiled successfully using the Makefile.

Commands executed

```bash
make clean
make
```

Executables generated

- build/test_buffer
- build/test_producer
- build/test_consumer
- build/test_integration
- build/media_player

Compilation completed successfully without errors.

---

# Test 1 – Shared Buffer

Command

```bash
./build/test_buffer
```

## Results

| Test | Status |
|------|--------|
| Buffer Initialization | PASS |
| Enqueue Operation | PASS |
| Dequeue Operation | PASS |
| FIFO Validation | PASS |
| Buffer Full Condition | PASS |
| Buffer Empty Condition | PASS |
| Buffer Destroy | PASS |

### Observation

- Shared buffer initialized correctly.
- FIFO ordering maintained.
- Buffer correctly handled FULL condition.
- Buffer correctly handled EMPTY condition.
- Buffer shutdown completed successfully.

Final Result

```
ALL TESTS PASSED
```

---

# Test 2 – Producer Module

Command

```bash
./build/test_producer 4 20
```

## Configuration

| Parameter | Value |
|-----------|-------|
| Producers | 4 |
| Packets Per Producer | 20 |
| Total Packets Generated | 80 |
| Buffer Size | 20 |

### Observation

- Four producer threads executed concurrently.
- Packets were successfully enqueued.
- Buffer full condition was handled correctly.
- Additional packets were safely dropped after the buffer became full.
- No synchronization issues were observed.

Final Result

```
Expected in buffer : 20
Actual in buffer   : 20
Status             : PASS
```

---

# Test 3 – Consumer Module

Command

```bash
./build/test_consumer 4 20
```

## Configuration

| Parameter | Value |
|-----------|-------|
| Consumers | 4 |
| Packets | 20 |
| Buffer Size | 20 |

### Observation

- Consumer threads started successfully.
- Packets were dequeued correctly.
- Packet payloads were processed correctly.
- Consumers terminated gracefully after producer completion.

Final Result

```
Consumers            : 4
Packets Requested    : 20
Packets Inserted     : 20
Remaining In Buffer  : 0
Status               : PASS
```

---

# Test 4 – Integration Test

Command

```bash
./build/media_player 4 4 20
```

## Configuration

| Parameter | Value |
|-----------|-------|
| Producers | 4 |
| Consumers | 4 |
| Packets Per Producer | 20 |
| Total Packets | 80 |

### Observation

- Producers generated packets successfully.
- Consumers processed packets concurrently.
- Shared buffer synchronized correctly.
- No deadlocks occurred.
- All packets were consumed.

Final Result

```
Total Produced       : 80
Total Consumed       : 80
Remaining In Buffer  : 0
Status               : PASS
```

---

# Overall Summary

| Module | Result |
|---------|--------|
| Shared Buffer | PASS |
| Producer | PASS |
| Consumer | PASS |
| Integration | PASS |

All module tests completed successfully.