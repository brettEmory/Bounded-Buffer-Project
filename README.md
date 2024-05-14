# Bounded Buffer and Producer-Consumer Problem

## Project Overview

This project involves implementing a bounded buffer and using it to solve the producer-consumer problem in C. The project focuses on creating a multi-threaded environment with proper synchronization using condition variables or semaphores.

## Features

- **Bounded Buffer Implementation:** A buffer with a fixed size that supports push and pop operations.
- **Synchronization:** Ensures safe access to the buffer when used by multiple threads.
- **Producer and Consumer Threads:** Demonstrates the producer-consumer problem with multiple threads.

## File Structure

- **bounded_buffer.h:** Header file defining the functionalities of the bounded buffer.
- **bounded_buffer.c:** Implementation of the bounded buffer functions.
- **main.c:** Creates producer and consumer threads to test the bounded buffer.
- **Makefile:** The makefile to compile the programs.
- **CSE2431.Lab4.pdf:** The lab assignment document providing detailed instructions and requirements.

## Setup and Installation

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/yourusername/bounded-buffer-producer-consumer.git
