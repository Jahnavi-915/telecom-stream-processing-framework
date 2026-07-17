# Graph Module Performance Report

## Module

Graph Construction and Analytics

---

# Test Environment

| Parameter | Value |
|-----------|-------|
| Operating System | Ubuntu Linux |
| Programming Language | C |
| Communication Library | OpenMPI |
| Graph Representation | Adjacency List |
| Packets Processed | 25 |
| Number of Towers | 10 |

---

# Graph Construction Performance

Operation

Graph Construction

Time Complexity

O(E)

Memory Complexity

O(V + E)

Status

PASS

---

# Analytics Performance

## Total Communication Volume

Algorithm

Traverse all graph edges.

Time Complexity

O(E)

Memory Complexity

O(1)

Status

PASS

---

## Most Active Source Tower

Algorithm

Traverse every vertex and sum outgoing edge weights.

Time Complexity

O(E)

Memory Complexity

O(1)

Status

PASS

---

## Most Active Destination Tower

Algorithm

Traverse graph for each destination tower.

Time Complexity

O(V × E)

Memory Complexity

O(1)

Status

PASS

---

## Top Communication Link

Algorithm

Single traversal of all graph edges.

Time Complexity

O(E)

Memory Complexity

O(1)

Status

PASS

---

## Out-Degree Analysis

Time Complexity

O(out-degree)

Memory Complexity

O(1)

Status

PASS

---

## In-Degree Analysis

Time Complexity

O(E)

Memory Complexity

O(1)

Status

PASS

---

# Runtime Statistics

Observed Analytics

```
Total Communication Volume : 25 packets

Most Active Source Tower : Tower-4

Most Active Destination Tower : Tower-6

Top Communication Link : Tower-4 -> Tower-7 (2 packets)
```

Observed Degree Analysis

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

---

# Performance Summary

| Component | Status |
|-----------|--------|
| Graph Construction | PASS |
| Communication Volume | PASS |
| Source Analytics | PASS |
| Destination Analytics | PASS |
| Top Communication Link | PASS |
| Degree Analysis | PASS |

---

# Conclusion

The graph module successfully performs graph construction and real-time communication analytics with linear-time traversal algorithms for most operations. The implementation is suitable for integration into the hybrid telecom stream processing framework and provides accurate communication statistics with minimal runtime overhead.