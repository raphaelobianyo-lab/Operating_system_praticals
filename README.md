# Operating Systems Practical Sessions (CSC 308)

This repository contains C implementations of practical sessions on process synchronization and inter-process communication in Linux.

## Contents

### Practical Session 1: Mutex Lock Demonstration
**Objective:**
Demonstrate mutual exclusion using POSIX pthread mutex locks.

**Concepts Covered**
- pthread_mutex_init()
- pthread_mutex_lock()
- pthread_mutex_unlock()
- pthread_mutex_destroy()
- Race conditions
- Mutual exclusion

**File**
- `mutex_demo.c`

---

### Practical Session 2: Producer–Consumer Simulation
**Objective:**
Implement the Producer–Consumer problem using POSIX semaphores.

**Concepts Covered**
- Circular buffer
- Producer and Consumer threads
- sem_init()
- sem_wait()
- sem_post()
- sem_destroy()
- Thread synchronization

**File**
- `producer_consumer.c`

---

### Practical Session 3: Semaphore Implementation
**Objective:**
Protect a shared resource using POSIX semaphores and compare it with mutex locks.

**Concepts Covered**
- Binary semaphores
- Counting semaphores
- Resource synchronization
- Shared counter protection

**File**
- `semaphore_counter.c`

---

### Practical Session 4: Shared Memory Programming
**Objective:**
Implement Inter-Process Communication (IPC) using shared memory.

**Concepts Covered**
- shmget()
- shmat()
- shmdt()
- shmctl()
- fork()
- Parent-child communication
- Shared memory cleanup

**File**
- `shared_memory_program.c`

---

## Compilation

Compile each program individually.

### Mutex Demonstration

```bash
gcc mutex_demo.c -o mutex_demo -pthread
```

### Producer–Consumer

```bash
gcc producer_consumer.c -o producer_consumer -pthread
```

### Semaphore Counter

```bash
gcc semaphore_counter.c -o semaphore_counter -pthread
```

### Shared Memory Program

```bash
gcc shared_memory_program.c -o shared_memory_program
```

---

## Running the Programs

```bash
./mutex_demo
```

```bash
./producer_consumer
```

```bash
./semaphore_counter
```

```bash
./shared_memory_program
```

---

## Expected Learning Outcomes

After completing these practical sessions, students should be able to:

- Understand race conditions in concurrent programming.
- Use mutexes to protect critical sections.
- Synchronize threads using POSIX semaphores.
- Implement the Producer–Consumer problem.
- Compare mutexes and semaphores.
- Implement Inter-Process Communication (IPC) using shared memory.
- Properly create and destroy synchronization primitives and shared memory segments.

---

## Requirements

- Linux Operating System
- GCC Compiler
- POSIX Threads (`pthread`)
- POSIX Semaphores
- System V Shared Memory

---

## Author

**Raphael Obianyo**

Course: **CSC 308 – Operating Systems**
