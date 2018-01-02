# Lab 4

[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://raw.githubusercontent.com/nextseto/Operating-Systems-Experiments/master/LICENSE)

**Part 1:** Write a multithreaded program that calculates various statistical values for a list of numbers. This program will be passed a series of numbers on the command line and will then create three separate worker threads. One thread will determine the average of the numbers, the second will determine the maximum value, and the third will determine the minimum value. 

For example, suppose your program is passed the integers: 90 81 78 95 79 72 85 

The program will report:

- The average value is 82 
- The minimum value is 72 
- The maximum value is 95

**Part 2:** An interesting way of calculating pi is to use a technique known as Monte Carlo, which involves randomization.

Write a multi-threaded version of this algorithm that creates a separate thread to generate a number of random points. The thread will count the number of points that occur within the circle and store that result in a global variable. When this thread has exited, the parent thread will calculate and output the estimated value of pi.

# How to Run

#### Option 1: macOS

1. Clone the source: `https://github.com/nextseto/Operating-Systems-Experiments.git`
2. Go into the directory: `cd Operating-Systems-Experiments/4 - Multithreading/`
3. Open `Lab4.xcodeproj` with Xcode

#### Option 2: Linux

1. Clone the source: `https://github.com/nextseto/Operating-Systems-Experiments.git`
2. Go into the directory: `cd Operating-Systems-Experiments/4 - Multithreading/Lab4`
3. Compile: `make`
4. Run: `./lab4_<num>` 