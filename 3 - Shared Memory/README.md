# Lab 3

[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://raw.githubusercontent.com/nextseto/Operating-Systems-Experiments/master/LICENSE)

The Collatz conjecture concerns what happens when we take any positive integer n and apply the following algorithm: n = (n/2) if n is even; n = (3*n+1) if n is odd. The conjecture states that when this algorithm is continually applied, all positive integers will eventually reach 1. 

For example, if n = 35, the sequence is 35, 106, 53, 160, 80, 40, 20, 10, 5, 16, 8, 4, 2, 1

Write a C program using the fork() system call that generates this sequence in the child process. The starting number will be provided from the command line. For example, if 8 is passed as a parameter on the command line, the child process will output 8, 4, 2, 1. Have the parent invoke the wait() call to wait for the child process to complete before exiting the program. Perform necessary error checking to ensure that a positive integer is passed on the command line.

# How to Run

#### Option 1: macOS

1. Clone the source: `https://github.com/nextseto/Operating-Systems-Experiments.git`
2. Go into the directory: `cd Operating-Systems-Experiments/3 - Shared Memory/`
3. Open `Lab3.xcodeproj` with Xcode

#### Option 2: Linux

1. Clone the source: `https://github.com/nextseto/Operating-Systems-Experiments.git`
2. Go into the directory: `cd Operating-Systems-Experiments/3 - Shared Memory/Lab3`
3. Compile: `make`
4. Run: `./lab3` 