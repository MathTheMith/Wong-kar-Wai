# 🎮 Wong-kar-Wai

> A terminal implementation of 2048, built in C with ncurses — a 42 weekend rush.

![Language](https://img.shields.io/badge/language-C-blue)
![School](https://img.shields.io/badge/school-42-black)
![Status](https://img.shields.io/badge/status-finished-brightgreen)

---

## Description

A faithful terminal clone of 2048: tile merging, random spawns, score tracking, win (2048 tile)
and lose (no move left) states, with an ncurses UI that redraws the board and reacts to terminal
resizes. Progress is written to `save.txt`.

## Build & run

```sh
make
./wong-kar-wai
```

Arrow keys to slide the board, `Esc` to quit.

## Structure

```
inc/2048.h        board struct, function prototypes
srcs/main.c        game loop, resize handling, exit conditions
srcs/game_board.c  spawning, move/merge logic
srcs/draw_board.c  ncurses rendering
srcs/end_menus.c   win/lose menus
srcs/checks.c      input validation, board state checks
srcs/libft/        hand-written libc replacements used throughout
```
