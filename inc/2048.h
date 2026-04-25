#ifndef GAME_2048_H
#define GAME_2048_H

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

# define SAVE_FILE "save.txt"

enum e_const
{
    WIN_VALUE = 2048
};

typedef struct board
{
    int size;
    int tiles_h;
    int tiles_w;
    int old_tiles_w;
    int old_tilies_h;
} t_board;

void draw_board(t_board board, int **tab);
int **init_game_board(int size);
void free_board(int **game_board, int size);
int update_game_board(int **game_board, int size, int ch);
void spawn_rand(int **game_board, int size, int n_rand);
int  show_menu(void);
int  win_menu(void);
int  loose_menu(void);

int load_score(char buffer[256]);
int write_score(int score);

#endif
