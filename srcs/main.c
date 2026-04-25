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

int main()
{
    t_board board;
    int ch;
    int tab[4][4] = {
        {1, 0, 2, 0},
        {0, 0, 204, 0},
        {0, 0, 0, 4},
        {0, 7, 0, 8}
    };
    board.size = 4;
    initscr();
    noecho();
    start_color();
    use_default_colors();
    curs_set(0);
    set_escdelay(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    // while (1)
    // {
    //     erase();
    //     printw("What size of board would you want ?\n");
    //     printw("4x4 (click 4)\n");
    //     printw("5x5 (click 5)\n");

    //     refresh();

    //     ch = getch();

    //     if (ch == '4')
    //         board.size = 4;
    //     if (ch == '5')
    //         board.size = 5;
    //     if (ch == '4' || ch == '5')
    //         break;
    // }
    while (1)
    {
        ch = getch();
        if (ch == 27)
            break;
        
        erase();
        draw_board(board, tab);
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