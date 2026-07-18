# Graph Module Test Results

## Module

Graph Construction and Analytics

---

## Objective

Validate graph construction and graph analytics for the Hybrid Telecom Stream Processing Framework.

---

## Test Environment

| Parameter | Value |
|-----------|-------|
| Operating System | Ubuntu Linux |
| Programming Language | C |
| Communication Library | OpenMPI |
| Database | Berkeley DB |
| Graph Representation | Adjacency List |
| Number of Towers | 10 |
| Packets Processed | 25 |

---

# Test Case 1 : Graph Construction

### Objective

Verify that graph vertices and edges are created correctly while processing telecom packets.

### Expected Result

- Vertices created automatically.
- Duplicate vertices are not created.
- Duplicate communication links increment edge weight.

### Result

PASS

---

# Test Case 2 : Total Communication Volume

### Objective

Verify that total communication volume equals the total processed packets.

### Expected Result

25 packets

### Observed Result

```
Total Communication Volume : 25 packets
```

### Status

PASS

---

# Test Case 3 : Most Active Source Tower

### Objective

Identify the tower generating the highest outgoing communication.

### Expected Result

Tower with maximum outgoing traffic.

### Observed Result

```
Most Active Source Tower : Tower-4
```

### Status

PASS

---

# Test Case 4 : Most Active Destination Tower

### Objective

Identify the tower receiving the highest incoming communication.

### Expected Result

Tower with maximum incoming traffic.

### Observed Result

```
Most Active Destination Tower : Tower-6
```

### Status

PASS

---

# Test Case 5 : Top Communication Link

### Objective

Identify the communication link with the highest packet count.

### Expected Result

Highest weighted graph edge.

### Observed Result

```
Top Communication Link : Tower-4 -> Tower-7 (2 packets)
```

### Status

PASS

---

# Test Case 6 : Node Degree Analysis

### Objective

Validate incoming and outgoing degree calculation for every tower.

### Observed Result

```
Tower-6     Out: 2  In: 5
Tower-8     Out: 2  In: 2
Tower-5     Out: 3  In: 2
Tower-4     Out: 3  In: 1
Tower-3     Out: 3  In: 0
Tower-9     Out: 1  In: 4
Tower-7     Out: 3  In: 3
Tower-1     Out: 2  In: 3
Tower-2     Out: 2  In: 1
Tower-10    Out: 2  In: 2
```

### Expected Result

Correct in-degree and out-degree for all graph vertices.

### Status

PASS

---

# Overall Result

All graph construction and analytics tests completed successfully.

Implemented Features:

- Graph Construction
- Total Communication Volume
- Most Active Source Tower
- Most Active Destination Tower
- Top Communication Link
- In-Degree Analysis
- Out-Degree Analysis

Overall Status

PASS