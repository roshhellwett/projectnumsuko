# Numsuko 🎲

[![License](https://img.shields.io/badge/License-Apache--2.0-blue.svg)](LICENSE)
![Platform](https://img.shields.io/badge/Platform-Linux-lightgrey)
![Status](https://img.shields.io/badge/Status-Active-success)
![Contributions](https://img.shields.io/badge/Contributions-Welcome-brightgreen)
![GitHub stars](https://img.shields.io/github/stars/roshhellwett/Numsuko?style=social)

**Numsuko** is a simple command-line number guessing game written in C.  
It challenges the user to guess a randomly-generated number within a limited number of attempts, offering a fun interactive experience in a terminal environment.

---

## 🎮 Features
- CLI-based number guessing game  
- Random number generation each time you play  
- Limited attempts to make the game exciting  
- Clear print-out of guesses, remaining tries, and success/fail messages  
- Lightweight and portable — runs on standard terminals  

---
The files are organized so that the `main.c` handles logic flow, while `game.c`/`game.h` contain the game functions.

---

## 🚀 Getting Started
### Prerequisites
You’ll need a C compiler (e.g., `gcc`) and a terminal (Linux or compatible).

### Build & Run
```bash
git clone https://github.com/roshhellwett/Numsuko.git
cd Numsuko
gcc main.c game.c -o numsuko   # adjust filenames if different
./numsuko

```

---

© 2026 [Zenith Open Source Projects](https://zenithprojects.up.railway.app/). All Rights Reserved.  
Zenith is a Open Source Project Idea's by @roshhellwett

---
