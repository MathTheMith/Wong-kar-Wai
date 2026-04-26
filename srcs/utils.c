#include "2048.h"

volatile __sig_atomic_t g_signal = 0;

static void handler(int sig)
{
    g_signal = sig;
}

void init_all(void)
{
    initscr();
    noecho();
    start_color();
    use_default_colors();
    curs_set(0);
    set_escdelay(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    signal(SIGINT, handler);
    signal(SIGTERM, handler);

    srand(time(NULL));
}

int **start_new_game(int size)
{
    int **board = init_game_board(size);
    spawn_rand(board, size, 2);
    draw_board((t_board){.size = size}, board);
    return board;
}

void reset_game(int ***board, int size)
{
    free_board(*board, size);
    *board = start_new_game(size);
}

int should_exit(void)
{
    return (g_signal != 0);
}

int clean_exit(int **board, int size)
{
    if (board)
        free_board(board, size);
    endwin();
    return 0;
}

bool is_power_of_two(int n)
{
    return (n > 0 && (n & (n - 1)) == 0);
}