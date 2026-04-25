#ifndef GAME_2048_H
#define GAME_2048_H

#include <ncurses.h>
#include <stdlib.h>
#include "libft.h"

enum e_const
{
    WIN_VALUE = 2048
};

typedef struct board
{
    int tiles_h;
    int tiles_w;
    int old_tiles_w;
    int old_tilies_h;
} t_board;

void draw_board(int tab[4][4]);
int **init_game_board(int size);
void free_board(int **game_board, int size);
void update_game_board(int **game_board, int size, int ch);
void spawn_rand(int **game_board, int size, int n_rand);

#endif