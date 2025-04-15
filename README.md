# CYB-3053 Project 2: Memory Allocator

**Course**: Operating Systems Concepts (CYB-3053)  
**Term**: Spring 2025  
**Author**: Faizefied393  
**Repository**: https://github.com/Faizefied393/OSProject2_

## Overview

This project implements a custom memory allocator in C, replicating the behavior of `malloc`, `calloc`, `realloc`, and `free`. The allocator manages a free list and dynamically expands the heap using `sbrk()` when necessary. Several memory allocation strategies are supported, including extra credit implementations.

## Features

- `tumalloc(size_t size)`
- `tucalloc(size_t num, size_t size)`
- `turealloc(void *ptr, size_t new_size)`
- `tufree(void *ptr)`
- Free list memory management
- Memory expansion via `sbrk`
- Strategy support:
  - First Fit (default)
  - Best Fit
  - Worst Fit
  - Next Fit

## Project Structure

OSProject2/ ├── include/ │ └── alloc.h ├── src/ │ ├── alloc.c │ └── test.c ├── build/ ├── CMakeLists.txt └── README.md

perl
Copy
Edit

## Setup Instructions (WSL / Ubuntu)

Install dependencies:

```sh
sudo apt update && sudo apt install build-essential cmake git valgrind -y
Clone the repository:

git clone https://github.com/Faizefied393/OSProject2_.git
cd OSProject2_
Build the project:

mkdir build && cd build
cmake ..
make
Run the program:

./cyb3053_project2
Memory Testing
Check for memory leaks with Valgrind:

valgrind --leak-check=full --show-leak-kinds=all ./cyb3053_project2
Expected output:

All heap blocks were freed -- no leaks are possible
Source Highlights
alloc.h
Defines free_block structure

Enumerates strategy types

Declares public allocation functions

alloc.c
Implements memory allocation and deallocation

Supports configurable allocation strategies

Manages the free list

Uses sbrk() to expand the heap

test.c
Demonstrates usage of the custom allocator

Tests each strategy for correctness

Strategy Behavior
Strategy	Description
First Fit	Selects the first block large enough to allocate
Best Fit	Selects the smallest block that fits the request
Worst Fit	Selects the largest available block
Next Fit	Continues searching from the last used block
Strategy is set using:

set_allocation_strategy(BEST_FIT); // Or FIRST_FIT, WORST_FIT, NEXT_FIT
GitHub Configuration
Set up Git and push changes:

git config --global user.name "Your Name"
git config --global user.email "your.email@example.com"
git add .
git commit -m "Final version with strategy support"
git push origin main
Use your GitHub token when prompted.
