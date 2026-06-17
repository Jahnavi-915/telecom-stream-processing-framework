# Git Workflow and Branch Strategy 

# **WEEK-1**

## Repository Branch Structure

```text
main
│
└── development
     │
     ├── feature/pthreads
     │
     └── feature/sockets
```

### Branch Purpose

#### main

Contains:

* Stable milestones
* Validated implementations
* Completed weekly deliverables
* Documentation ready for review

Only stable work should be merged into this branch.

---

#### development

Contains:

* Current week's integrated work
* Documentation updates
* Planning and architecture changes

Acts as the central working branch.

---

#### feature/pthreads

Contains:

* POSIX Threads implementation
* Producer-Consumer implementation
* Synchronization implementation
* Testing related to POSIX Threads

---

#### feature/sockets

Contains:

* Socket Programming implementation
* Client-Server prototype
* Communication workflow experiments

---

# Initial Setup

## Step 1

Repository already contains:

```text
main
```

---

## Step 2

Jahnavi creates development branch:

```bash
git checkout -b development
git push -u origin development
```

---

## Step 3

Sreeja gets the branch:

```bash
git fetch
git checkout development
```

Now both team members can work on:

```text
development
```

---

# Daily Workflow (Both Team Members)

## Before Starting Work

Always synchronize your repository.

```bash
git checkout <current-branch>
git pull origin <current-branch>
```

Example:

```bash
git checkout development
git pull origin development
```

This ensures you have the latest changes.

---

## During Work

* Work only on assigned tasks.
* Commit frequently.
* Avoid modifying the same implementation files simultaneously.
* For shared documents, update only your designated sections whenever possible.

---

## Before Ending Work

Check changes:

```bash
git status
```

Add changes:

```bash
git add .
```

Commit:

```bash
git commit -m "Meaningful description of work"
```

Examples:

```bash
git commit -m "Add Day 1 study notes"
git commit -m "Implement producer thread"
git commit -m "Add socket client prototype"
```

Push:

```bash
git push origin <current-branch>
```

---

## If Push Fails

Git may display:

```text
Updates were rejected because the remote contains work that you do not have locally.
```

This means someone else pushed first.

Run:

```bash
git pull origin <current-branch>
```

Resolve conflicts if any appear.

Then:

```bash
git push origin <current-branch>
```

---

# Day-wise Branch Usage

## Day 1

### Branch

development

### Created By

Jahnavi

### Team Members

* Jahnavi
* Sreeja

### Activities

* Concept Study
* Architecture Understanding
* Documentation Updates
* Project Planning

---

## Day 2

### Create POSIX Branch

Jahnavi creates:

```bash
git checkout development
git checkout -b feature/pthreads
git push -u origin feature/pthreads
```

---

### Sreeja gets the branch

```bash
git fetch
git checkout feature/pthreads
```

Now both work on:

```text
feature/pthreads
```

---

## Day 2 - Day 5

### Working Branch

feature/pthreads

### Team Members

* Jahnavi
* Sreeja

### Activities

* POSIX Threads Implementation
* Producer-Consumer Model
* Synchronization
* Testing Preparation
* Validation Framework Design

---

## End of Day 5

Merge POSIX work into development.

Jahnavi:

```bash
git checkout development
git pull origin development
git merge feature/pthreads
git push origin development
```

---

## Day 6

### Create Socket Branch

Jahnavi creates:

```bash
git checkout development
git checkout -b feature/sockets
git push -u origin feature/sockets
```

---

### Sreeja gets the branch

```bash
git fetch
git checkout feature/sockets
```

Now both work on:

```text
feature/sockets
```

---

## Day 6 - Day 7

### Working Branch

feature/sockets

### Team Members

* Jahnavi
* Sreeja

### Activities

* Socket Programming Study
* Client-Server Prototype
* Communication Design
* Packet Transfer Prototype

---

## End of Day 7

Merge socket work into development.

Jahnavi:

```bash
git checkout development
git pull origin development
git merge feature/sockets
git push origin development
```

---

# End of Week Integration

After:

* POSIX Threads Prototype
* Testing & Validation Framework
* Socket Programming Prototype
* Documentation Updates

Jahnavi merges development into main:

```bash
git checkout main
git pull origin main
git merge development
git push origin main
```

This becomes the official Week 1 milestone.

---

# File Ownership Guidelines

## Primarily Maintained by Jahnavi

* README.md
* docs/roadmap.md
* docs/architecture.md
* docs/test_plan.md

---

## Primarily Maintained by Sreeja

* src/pthreads/*
* src/sockets/*

---

## Shared Files

* docs/progress_log.md

For shared files, each team member should update only their designated sections whenever possible.

---

# Important Rules

1. Pull before starting work.
2. Push after completing work.
3. Use meaningful commit messages.
4. Do not work directly on main.
5. Do not delete another team member's changes.
6. If a conflict occurs, communicate before resolving it.
7. Keep documentation updated along with implementation.


# Git Workflow and Branch Strategy

# WEEK-2

## Repository Branch Structure

```text
main
│
└── development
     │
     ├── feature/integration
     │
     └── feature/mpi
```

### Branch Purpose

#### main

Contains:

* Stable weekly milestones
* Validated implementations
* Approved documentation
* Completed deliverables

Only stable and tested work should be merged into this branch.

---

#### development

Contains:

* Current week's integrated work
* Documentation updates
* Testing artifacts
* Architecture updates
* Weekly deliverables before final release

Acts as the central working branch.

---

#### feature/integration

Contains:

* Pthreads + Socket integration
* Sender Thread implementation
* End-to-end packet streaming workflow
* Integration testing and validation

---

#### feature/mpi

Contains:

* MPI communication prototype
* MPI experiments
* MPI testing and validation
* MPI workflow documentation

---

# Initial Setup

## Step 1

Ensure development branch is up to date.

```bash
git checkout development
git pull origin development
```

---

## Step 2

Jahnavi creates Integration branch:

```bash
git checkout development
git checkout -b feature/integration
git push -u origin feature/integration
```

---

## Step 3

Sreeja gets the branch:

```bash
git fetch
git checkout feature/integration
```

---

# Daily Workflow (Both Team Members)

## Before Starting Work

Always synchronize your repository.

```bash
git checkout <current-branch>
git pull origin <current-branch>
```

Example:

```bash
git checkout feature/integration
git pull origin feature/integration
```

---

## During Work

* Work only on assigned tasks.
* Commit frequently.
* Avoid modifying the same implementation files simultaneously.
* Update documentation together with implementation.

---

## Before Ending Work

Check changes:

```bash
git status
```

Add changes:

```bash
git add .
```

Commit:

```bash
git commit -m "Meaningful description of work"
```

Examples:

```bash
git commit -m "Design integration architecture"
git commit -m "Implement sender thread"
git commit -m "Add integration validation report"
git commit -m "Implement MPI send receive prototype"
```

Push:

```bash
git push origin <current-branch>
```

---

## If Push Fails

Run:

```bash
git pull origin <current-branch>
```

Resolve conflicts.

Then:

```bash
git push origin <current-branch>
```

---

# Day-wise Branch Usage

## Day 1

### Branch

feature/integration

### Team Members

* Jahnavi
* Sreeja

### Activities

* Integration Architecture Design
* Telecom Packet Design
* Workflow Documentation
* Sender Thread Design

---

## Day 2

### Branch

feature/integration

### Team Members

* Jahnavi
* Sreeja

### Activities

* Pthreads + Socket Integration Implementation
* Sender Thread Development
* Packet Streaming Workflow
* Statistics Collection

---

## Day 3

### Branch

feature/integration

### Team Members

* Jahnavi
* Sreeja

### Activities

* Integration Testing
* Validation
* Observation Reports
* Performance Analysis

---

## End of Day 3

Merge Integration work into development.

Jahnavi:

```bash
git checkout development
git pull origin development
git merge feature/integration
git push origin development
```

---

## Day 4

### Create MPI Branch

Jahnavi creates:

```bash
git checkout development
git checkout -b feature/mpi
git push -u origin feature/mpi
```

---

### Sreeja gets the branch

```bash
git fetch
git checkout feature/mpi
```

Now both work on:

```text
feature/mpi
```

---

## Day 4 - Day 6

### Working Branch

feature/mpi

### Team Members

* Jahnavi
* Sreeja

### Activities

* MPI Study
* MPI Architecture Design
* MPI Prototype Development
* MPI Testing
* MPI Validation

---

## End of Day 6

Merge MPI work into development.

Jahnavi:

```bash
git checkout development
git pull origin development
git merge feature/mpi
git push origin development
```

---

## Day 7

### Branch

development

### Team Members

* Jahnavi
* Sreeja

### Activities

* Documentation Updates
* Progress Log Updates
* README Updates
* Week 2 Report Preparation
* Repository Review

---

# End of Week Integration

After:

* Pthreads + Socket Integration
* Integration Testing & Validation
* MPI Communication Prototype
* MPI Validation Reports
* Documentation Updates

Jahnavi merges development into main:

```bash
git checkout main
git pull origin main
git merge development
git push origin main
```

This becomes the official Week 2 milestone.

---

# File Ownership Guidelines

## Primarily Maintained by Jahnavi

* README.md
* docs/project/architecture.md
* docs/project/implementation_details.md
* docs/project/ROADMAP.md
* docs/testing/*
* reports/*

---

## Primarily Maintained by Sreeja

* src/pthreads/*
* src/sockets/*
* src/mpi/*

---

## Shared Files

* docs/progress/progress_log.md

For shared files, each team member should update only their designated sections whenever possible.

---

# Important Rules

1. Pull before starting work.
2. Push after completing work.
3. Use meaningful commit messages.
4. Do not work directly on main.
5. Do not delete another team member's changes.
6. Resolve conflicts through communication.
7. Keep documentation synchronized with implementation.
8. Complete testing and validation before merging into development.

