![Repo Size](https://img.shields.io/github/repo-size/roshhellwett/Numsuko?style=for-the-badge)
![Stars](https://img.shields.io/github/stars/roshhellwett/Numsuko?style=for-the-badge)
![Forks](https://img.shields.io/github/forks/roshhellwett/Numsuko?style=for-the-badge)
![Issues](https://img.shields.io/github/issues/roshhellwett/Numsuko?style=for-the-badge)
![C/C++](https://img.shields.io/badge/Language-C%2FC%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B)

# PROJECT NUMSUKO

Numsuko is a lightweight, command-line number guessing game written in C/C++. It challenges users to guess a randomly-generated number within a strict limit of attempts, offering a highly interactive and engaging experience natively within the terminal environment.

---

## ✨ Key Features

### 🎮 Gameplay Mechanics
* **Dynamic Difficulty Levels:** Choose your challenge: Easy (1-10, 5 chances), Medium (1-20, 10 chances), or Hard (1-100, 10 chances).
* **Randomized Generation:** Uses time-seeded random number generation for a unique, unpredictable experience every session.
* **Interactive Feedback:** Provides real-time "Too High" or "Too Low" hints while tracking your remaining attempts.
* **Infinite Replayability:** Seamless continuous game loop allowing players to instantly replay without restarting the executable.

### ⚡ Core Functionality
* **Lightweight Execution:** Highly optimized CLI utility that runs natively on standard terminals with minimal overhead.
* **Cross-Platform Compatibility:** Pure standard library implementation (`<stdio.h>`, `<stdlib.h>`, `<time.h>`), easily compilable on Linux, Windows, or macOS.

## 🛠️ Prerequisites

To build and run Numsuko, you will need:
* **C/C++ Compiler:** GCC, Clang, or MSVC.
* **Terminal:** Any standard command-line interface or terminal emulator.

## 🚀 Build Instructions

Follow these steps to build Numsuko from source:

```bash
   git clone [https://github.com/roshhellwett/Numsuko.git](https://github.com/roshhellwett/Numsuko.git)
   cd Numsuko
```

---

# 📂 Project Structure
```
Numsuko/
├── .github/workflows/
│   └── cmake-single-platform.yml # CI/CD build configuration
├── Numsuko.exe                   # Pre-compiled Windows executable
├── main.cpp                      # Core game logic and application entry point
├── LICENSE                       # Open source license documentation
├── security.md                   # Security and vulnerability details
└── readme.md                     # Project documentation
```

© 2026 [Zenith Open Source Projects](https://zenithopensourceprojects.vercel.app/). All Rights Reserved.  
Zenith is a Open Source Project Idea's by @roshhellwett
