#ifndef GAME_2048_H
#define GAME_2048_H

#include <ncurses.h>

enum e_const
{
    WIN_VALUE = 2
};

typedef struct board
{
    int tiles_h;
    int tiles_w;
    int old_tiles_w;
    int old_tilies_h;
} t_board;

void draw_board(int tab[4][4]);

#endif