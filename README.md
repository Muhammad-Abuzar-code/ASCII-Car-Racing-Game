# ASCII Car Racing Game 🏎️

A **2-player console-based racing game** developed in C++ with simultaneous player controls, real-time rendering, collision detection, and persistent high-score tracking.

## Features

* **2-Player Gameplay** — Both players can control their cars simultaneously.
* **Real-Time Game Loop** — Continuously processes input, updates the game state, and renders the board.
* **Non-Blocking Input** — Players can control their cars without pausing the game.
* **Collision Detection** — Detects collisions with boundaries and obstacles in real time.
* **Independent Player States** — When one player crashes, the other can continue playing until both players crash.
* **Persistent High Scores** — Scores are stored using C++ file handling and remain available between game sessions.
* **Console Rendering** — Uses Windows Console API functionality for real-time screen updates with minimal flickering.

## Controls

| Player   | Controls        |
| -------- | --------------- |
| Player 1 | `A` `D` |
| Player 2 | `J` `L`     |

## Technologies & Concepts

* **Language:** C++
* Object-Oriented Programming
* Functions and modular program design
* Multi-dimensional arrays
* Non-blocking keyboard input
* Game loop architecture
* Collision detection
* File I/O using `fstream`
* Windows Console Based Game

## How It Works

The game continuously runs a game loop that:

1. Processes player input.
2. Updates player positions.
3. Generates and updates obstacles.
4. Checks for collisions.
5. Updates player states and scores.
6. Renders the updated game board.

The game continues until both players have crashed.

## Platform

This project uses Windows-specific console functionality and is intended to run on **Windows**.

## Purpose

This project was built to strengthen practical understanding of **C++ programming, game loops, input handling, collision detection, arrays, and file management** through a complete console-based application.
