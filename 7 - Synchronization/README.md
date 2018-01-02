# Lab 7

[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://raw.githubusercontent.com/nextseto/Operating-Systems-Experiments/master/LICENSE)

A single-lane bridge connects the two Vermont villages of North Turnbridge and South Turnbridge. Farmers in the two villages use this bridge to deliver their produce to the neighboring town.

- The bridge can become deadlocked if a northbound and a southbound farmer get on the bridge at the same time. (Vermont farmers are stubborn and are unable to back up.)

- Using semaphores and/or mutex locks, design an algorithm in pseudocode that prevents deadlock. Initially, do not be concerned about starvation (the situation in which northbound farmers prevent southbound farmers from using the bridge, or vice versa).

**Part 1:** Make a pthread sample implementation of the scenario above that demonstrates the starvation situation

**Part 2:** Implement the pseudocode using POSIX synchronization. In particular, represent northbound and southbound farmers as separate threads. Once a farmer is on the bridge, the associated thread will sleep for a random period of time, representing traveling across the bridge. Design your program so that you can create several threads representing the northbound and southbound farmers.

# How to Run

#### Option 1: macOS

1. Clone the source: `https://github.com/nextseto/Operating-Systems-Experiments.git`
2. Go into the directory: `cd Operating-Systems-Experiments/7 - Synchronization/`
3. Open `Lab7.xcodeproj` with Xcode
 
#### Option 2: Linux

1. Clone the source: `https://github.com/nextseto/Operating-Systems-Experiments.git`
2. Go into the directory: `cd Operating-Systems-Experiments/7 - Synchronization/Lab7`
3. Compile: `make`
4. Run: `./lab7_<num>` 