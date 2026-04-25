#ifndef GAME_2048_H
#define GAME_2048_H

#include <ncurses.h>
#include <stdlib.h>
#include "libft.h"

typedef struct board
{
    int h;
    int w;
    int old_w;
    int old_h;
} t_board;

void draw_board(void);

#endif