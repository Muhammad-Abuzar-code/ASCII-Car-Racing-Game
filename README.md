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

## Game Mechanics

The game starts with two players racing on the same track while obstacles continuously appear and move toward them.

1. Both players control their cars simultaneously using their respective keyboard controls.
2. Obstacles continuously appear on the track, and players must avoid them to keep racing.
3. When a player collides with an obstacle or the track boundary, that player crashes and can no longer continue.
4. If one player crashes, the other player continues racing.
5. The game ends when **both players have crashed**.
6. At the end of the game, the scores of both players are displayed.
7. If either player's score is higher than their previous high score, the **new high score is saved** for future games.

## Platform

This project uses Windows-specific console functionality and is intended to run on **Windows**.

## Purpose

This project was built to strengthen practical understanding of **C++ programming, game loops, input handling, collision detection, arrays, and file management** through a complete console-based application.
