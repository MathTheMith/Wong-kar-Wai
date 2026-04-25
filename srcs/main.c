#include "2048.h"

bool is_power_of_two(int n)
{
    return (n > 0 && (n & (n - 1)) == 0);
}

bool check_around(int **tab, int i, int j, int size)
{
    int nb = tab[i][j];
    if (j + 1 < size && tab[i][j + 1] == nb) return true;
    if (j - 1 >= 0   && tab[i][j - 1] == nb) return true;
    if (i + 1 < size && tab[i + 1][j] == nb) return true;
    if (i - 1 >= 0   && tab[i - 1][j] == nb) return true;
    return false;
}

int check_finish(int **tab, t_board board)
{
    for (int i = 0; i < board.size; i++)
        for (int j = 0; j < board.size; j++)
            if (tab[i][j] == WIN_VALUE)
                return 1;

    for (int i = 0; i < board.size; i++)
        for (int j = 0; j < board.size; j++)
            if (tab[i][j] == 0 || check_around(tab, i, j, board.size))
                return 0;

    return 2;
}

int main()
{
    t_board board;
    int ch;

    int **game_board;

    initscr();
    noecho();
    start_color();
    use_default_colors();
    curs_set(0);
    set_escdelay(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    board.size = show_menu();
    if (board.size < 0)
    {
        endwin();
        return 0;
    }
    int result;
    srand(time(NULL));
    game_board = init_game_board(board.size);
    spawn_rand(game_board, board.size, 2);
    draw_board(board, game_board);
    refresh();
    while (1)
    {
        ch = getch();
        if (ch == 27)
            break;
        result = check_finish(game_board, board);
        if (result == 0)
        {
            erase();
            update_game_board(game_board, board.size, ch);
            draw_board(board, game_board);
        }
        else if (result == 1)
        {
            win_menu();
            break;
        }
        else
        {
            loose_menu();
            break;
        }
        refresh();
    }
    endwin();
    return 0;
}