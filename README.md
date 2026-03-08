<p align="center">
  <img src="https://www.especial.gr/wp-content/uploads/2019/03/panepisthmio-dut-attikhs.png" alt="UNIWA" width="150"/>
</p>

<p align="center">
  <strong>UNIVERSITY OF WEST ATTICA</strong><br>
  SCHOOL OF ENGINEERING<br>
  DEPARTMENT OF COMPUTER ENGINEERING AND INFORMATICS
</p>

<p align="center">
  <a href="https://www.uniwa.gr" target="_blank">University of West Attica</a> ·
  <a href="https://ice.uniwa.gr" target="_blank">Department of Computer Engineering and Informatics</a>
</p>

---

<p align="center">
  <strong>Object-Oriented Programming</strong>
</p>

<h1 align="center">
  Babis Poteridis and the Magic Notebook Searching
</h1>

<p align="center">
  <strong>Vasileios Evangelos Athanasiou</strong><br>
  Student ID: 19390005
</p>

<p align="center">
  <a href="https://github.com/Ath21" target="_blank">GitHub</a> ·
  <a href="https://www.linkedin.com/in/vasilis-athanasiou-7036b53a4/" target="_blank">LinkedIn</a>
</p>

<hr/>

<p align="center">
  <strong>Supervision</strong>
</p>

<p align="center">
  Supervisor: Cleo Sgouropoulou, Professor<br>
</p>

<p align="center">
  <a href="https://ice.uniwa.gr/en/emd_person/georgios-meletiou/" target="_blank">UNIWA Profile</a> ·
  <a href="https://www.linkedin.com/in/cleo-sgouropoulou-51683525/" target="_blank">LinkedIn</a>
</p>

<p align="center">
  Co-supervisor: Georgios Meletiou, Laboratory Teaching Staff<br>
</p>

<p align="center">
  <a href="https://ice.uniwa.gr/en/emd_person/georgios-meletiou/" target="_blank">UNIWA Profile</a>
</p>

</hr>

---

<p align="center">
  Athens, July 2022
</p>

---

<p align="center">
  <img src="https://usercontent.static.blocksmithxr.com/nfPtaRrZAeTE9h6EO4kN4TxajUmusqsL..jpg" width="250"/>
</p>

---

# README

## Babis Poteridis and the Magic Notebook Searching

This project is a **C++ terminal-based game** developed for the *Object-Oriented Programming* course at the **University of West Attica**.  

The game features a competition between two students, **Babis Poteridis** and **Loukas Malfoi**, as they navigate a magical labyrinth in search of a teleporting gem.

---

## Table of Contents

| Section | Folder/File | Description |
|------:|-------------|-------------|
| 1 | `INSTALL.md` | Installation and build instructions |
| 2 | `README.md` | Project overview and usage guide |
| 3 | `UML/` | UML design documentation |
| 3.1 | `UML/UML-Class-Maze-Game.png` | UML class diagram of the maze game architecture |
| 4 | `assign/` | Semester project assignment material |
| 4.1 | `assign/Semester-Project-p.1.png` | Assignment description (page 1, English) |
| 4.2 | `assign/Semester-Project-p.2.png` | Assignment description (page 2, English) |
| 4.3 | `assign/Εξαμηνιαία-Εργασία-σελ.1.png` | Assignment description (page 1, Greek) |
| 4.4 | `assign/Εξαμηνιαία-Εργασία-σελ.2.png` | Assignment description (page 2, Greek) |
| 5 | `src/` | Source code of the Maze Game |
| 5.1 | `src/main.cpp` | Entry point of the program |
| 5.2 | `src/Makefile` | Build configuration for compiling the project |
| 5.3 | `src/GameEngine.h` | Game engine class declaration |
| 5.4 | `src/GameEngine.cpp` | Game engine implementation |
| 5.5 | `src/GameObject.h` | Base class for all game objects |
| 5.6 | `src/GameObject.cpp` | Implementation of the base game object |
| 5.7 | `src/Maze.h` | Maze structure and functionality declarations |
| 5.8 | `src/Maze.cpp` | Maze implementation |
| 5.9 | `src/MagicGem.h` | MagicGem class declaration |
| 5.10 | `src/MagicGem.cpp` | MagicGem implementation |
| 5.11 | `src/Poteridis.h` | Poteridis character class declaration |
| 5.12 | `src/Poteridis.cpp` | Poteridis character implementation |
| 5.13 | `src/Malfoi.h` | Malfoi character class declaration |
| 5.14 | `src/Malfoi.cpp` | Malfoi character implementation |
| 5.15 | `src/maps/` | Text files describing different maze maps |
| 5.15.1 | `src/maps/checkerboard.txt` | Checkerboard-style maze layout |
| 5.15.2 | `src/maps/great_divide.txt` | Maze divided into two large regions |
| 5.15.3 | `src/maps/quadrants.txt` | Maze divided into four quadrants |
| 5.15.4 | `src/maps/simple_maze.txt` | Basic maze layout |
| 5.15.5 | `src/maps/snake_pit.txt` | Snake-like maze structure |
| 5.15.6 | `src/maps/spiral_doom.txt` | Spiral-shaped maze layout |
| 5.15.7 | `src/maps/training_pilars.txt` | Maze with pillar obstacles for training |

---

## 1. Game Story

At the **Magical Educational Institute (M.E.I.) of West Attica**, an annual competition is held between the two best students.

This year the competitors are:

- **Babis Poteridis** - represented by the orange character `M`
- **Loukas Malfoi** - represented by the green character `L`

However, the villainous **Professor Gmeles** interferes with the competition. He takes control of Malfoi’s movements and enchants the **Magic Gem** so that it teleports randomly across the maze.

The goal is simple: **reach the gem before your opponent does.**

---

## 2. Class Structure
The project follows an object-oriented design.

### 2.1 GameObject
Abstract base class representing any entity in the game.

### 2.2 Poteridis
Derived class representing the player-controlled character.

### 2.3 Malfoi
Derived class representing the AI-controlled opponent, featuring a simple "smart movement" strategy.

### 2.4 MagicGem
Derived class representing the target object that teleports randomly across the maze.

### 2.5 Maze
Responsible for:
- Loading the map from a file
- Boundary checking
- Rendering the maze grid

### 2.6 GameEngine
Handles:
- Game loop execution
- `ncurses` initialization
- Input handling
- Win and loss conditions

---

## 3. Controls
| Key        | Action                                         |
|------------|------------------------------------------------|
| Arrow Keys | Move Babis Poteridis (Up, Down, Left, Right)  |
| Space      | Stay in place for one turn                     |
| Escape     | Exit the game                                  |
| Enter      | Restart the game after win/loss                |

---

## 4. Map Format

Maps are loaded from `.txt` files using the following symbols:

| Symbol | Meaning                     |
|-------|-----------------------------|
| `*`    | Wall (cannot pass)          |
| `.`     | Corridor (walkable path)    |

### 4.1 Important:
The map perimeter must be completely closed with walls.