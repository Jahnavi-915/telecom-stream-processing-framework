# Group-E Communication Prototype - Validation Checklist

## 1. Basic Communication (The Roads)
- [ ] MPI Client successfully connects to MPI Server
- [ ] One Client can send a packet to One Server
- [ ] Server receives the packet without data corruption

## 2. Queue and Delay (The Traffic Jams)
- [ ] Shared Packet Queue (Bucket) correctly stores incoming packets
- [ ] System handles Delay Injection (simulated network lag) without crashing

## 3. Scalability (Rush Hour)
- [ ] 2 Clients can send packets to One Server simultaneously
- [ ] 4 Clients can send packets to One Server simultaneously
- [ ] 8 Clients can send packets to One Server simultaneously

## 4. Stability (Crash Testing)
- [ ] No packet loss during stress testing
- [ ] System handles forced failures gracefully
