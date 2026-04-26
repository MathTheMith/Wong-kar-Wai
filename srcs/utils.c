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
    init_pair(20, COLOR_YELLOW, -1);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    signal(SIGINT, handler);
    signal(SIGTERM, handler);

    srand(time(NULL));
}

void start_new_game(int size, int (*game_board)[size][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            (*game_board)[i][j] = 0;
        }
    }
    spawn_rand(size, game_board, 2);
    draw_board((t_board){.size = size}, game_board);
}

int should_exit(void)
{
    return (g_signal != 0);
}

int clean_exit()
{
    endwin();
    return 0;
}

bool is_power_of_two(int n)
{
    return (n > 0 && (n & (n - 1)) == 0);
}

int ft_intlen(int n)
{
    int len = 0;

    if (n == 0)
        return 1;

    if (n < 0)
        len++;

    while (n != 0)
    {
        n /= 10;
        len++;
    }
    return len;
}