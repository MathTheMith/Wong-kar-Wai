#include <ncurses.h>
#include "2048.h"


void draw_line(t_board board)
{
    for (int i = 0; i < 4; i++)
    {
        printw("|");
        for (int j = 0; j < board.w - 1; j++)
        {
            if (i == 3 && j == board.w - 2)
                printw("|");
            else
                printw(" ");
        }
    }
}

void draw_separation(t_board board)
{
    for (int i = 0; i < 4; i++)
    {
        printw("+");
        for (int j = 0; j < board.w - 1; j++)
        {
            if (i == 3 && j == board.w - 2)
                printw("+");
            else
                printw("-");
        }
    }
    // printw('')
}

int main()
{
    t_board board;
    int ch;
    int h, w;

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

        getmaxyx(stdscr, h, w);

        board.w = w / 4;
        board.h = h / 4;

        erase();

        draw_separation(board);

        refresh();
    }

    endwin();
    return 0;
}