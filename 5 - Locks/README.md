# Lab 5

[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://raw.githubusercontent.com/nextseto/Operating-Systems-Experiments/master/LICENSE)

**Part 1:** Write a piece of code to experiment with the Producer-Consumer theory for locking and synchronization.

**Part 2:** Write a piece of code to experiment with semaphores.

**Part 3:** An interesting way of calculating pi is to use a technique known as Monte Carlo, which involves randomization.

Create several threads, each of which generates random points and determines if the points fall within the circle. The program need to satisfy following two conditions.

- Each thread will have to update the global count of all points that fall within the circle.

- Protect against race conditions on updates to the shared global variable by some synchronization method.

# How to Run

#### Option 1: macOS

1. Clone the source: `https://github.com/nextseto/Operating-Systems-Experiments.git`
2. Go into the directory: `cd Operating-Systems-Experiments/5 - Locks/`
3. Open `Lab5.xcodeproj` with Xcode

#### Option 2: Linux

1. Clone the source: `https://github.com/nextseto/Operating-Systems-Experiments.git`
2. Go into the directory: `cd Operating-Systems-Experiments/5 - Locks/Lab5`
3. Compile: `make`
4. Run: `./lab5_<num>` 