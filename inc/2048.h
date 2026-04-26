#ifndef GAME_2048_H
#define GAME_2048_H

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

# define SAVE_FILE "save.txt"
# define BOARD_MAX 9

#include <signal.h>
#include "libft.h"

extern volatile sig_atomic_t g_signal;

enum e_const
{
    WIN_VALUE = 2048
};

typedef struct board
{
    int score;
    int size;
    int tiles_h;
    int tiles_w;
    int old_tiles_w;
    int old_tilies_h;
} t_board;

void draw_board(t_board board, int (*tab)[board.size][board.size]);
void spawn_rand(int size, int (*game_board)[size][size], int n_rand);
void update_game_board(t_board *board, int (*game_board)[board->size][board->size], int ch);
int  show_menu(void);
int  win_menu(int score);
int  loose_menu(int score);
void init_all(void);

void start_new_game(int size, int (*game_board)[size][size]);

int should_exit(void);

int clean_exit();
int check_finish(t_board board, int (*tab)[board.size][board.size], bool continue_game);

bool is_power_of_two(int n);
char *get_ascii(int nb);
int   get_ascii_width(int nb);
int   get_ascii_height(int nb);
void  draw_ascii(int y, int x, int nb);
int   get_ascii_number_width(int nb);
void  draw_ascii_number(int y, int x, int nb);
int ft_intlen(int n);
int load_score(char buffer[256]);
int write_score(int score);

#endif
