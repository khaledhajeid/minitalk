# Minitalk 📨

[![Language](https://img.shields.io/badge/Language-C-blue)](https://github.com/khaledhajeid)
[![Platform](https://img.shields.io/badge/Platform-Linux-lightgrey)](https://github.com/khaledhajeid)
[![42 Project](https://img.shields.io/badge/42%20Project-Completed-brightgreen)](https://github.com/khaledhajeid)

---

## Overview
`Minitalk` is a **small client-server communication program** built in C using **Unix signals**.  
It was my **first project involving inter-process communication (IPC)** and **signal handling**, marking a significant step in learning **low-level system programming**.

This project taught me how to:
- Send messages between processes using `SIGUSR1` and `SIGUSR2`.  
- Encode and decode messages bit by bit.  
- Handle multiple clients safely and efficiently.  
- Build a **robust communication protocol** without external libraries.  

---

## Features
- ✅ Send and receive text messages between **client** and **server**.  
- ✅ Messages are transmitted using **Unix signals** only.  
- ✅ Works reliably for short and long messages.  
- ✅ Provides **feedback on message delivery**.  

---

## Technologies
- Language: C
- Platform: Linux

## Usage

1. Clone the repository:
```c
git clone https://github.com/khaledhajeid/minitalk.git
cd minitalk
```
2. Build the project using the Makefile:
```c
make
```
This will generate server and client executables.

3. Start the server:
```c
./server
```
4. In a separate terminal, start the client and send a message:
```c
./client <server_pid> "Your message here"
```
5. Clean up object files and executables:
```c
make fclean
```

---

## File Structure
```c
minitalk/
├── client.c
├── server.c
├── minitalk.h
├── Makefile
└── README.md
```

---

## Project Highlights
- My first experience with inter-process communication.
- Learned Unix signals, bitwise operations, and process IDs.
- Developed a small but complete communication protocol from scratch.
- Built a foundation for more complex system-level projects.
