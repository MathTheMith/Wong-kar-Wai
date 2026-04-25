#include "2048.h"

bool is_power_of_two(int n)
{
    return (n > 0 && (n & (n - 1)) == 0);
}

bool check_finish(int tab[4][4])
{
    bool full = true;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (tab[i][j] == WIN_VALUE && is_power_of_two(WIN_VALUE))
                return true;

            if (tab[i][j] == 0)
                full = false;
        }
    }

    return full;
}


void apply_board(int tab[4][4], int **game_board)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            game_board[i][j] = tab[i][j];
    }
}

void apply_tab(int tab[4][4], int **game_board)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            tab[i][j] = game_board[i][j];
    }
}


int main()
{
    int ch;
    int **game_board;
    int tab[4][4] = {
        {2, 2, 4, 2},
        {0, 0, 2, 0},
        {0, 0, 0, 0},
        {0, 4, 0, 0}
    };

    game_board = init_game_board(4);
    apply_board(tab, game_board);

    initscr();
    noecho();
    curs_set(0);
    set_escdelay(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    while (1)
    {
        ch = getch();
        if (ch == 27)
            break;
        
        erase();

        update_game_board(game_board, 4, ch);
        apply_tab(tab, game_board);

        draw_board(tab);
        if (check_finish(tab))
        {
            erase();
            printw("You won!!");
        }
        refresh();
    }
    endwin();
    return 0;
}