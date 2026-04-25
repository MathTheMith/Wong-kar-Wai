#include <ncurses.h>
#include "2048.h"

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

int main()
{
    t_board board;
    int ch;
    int h, w;
    
    initscr();            // init ncurses
    noecho();             // pas d'echo clavier
    curs_set(0);          // cache curseur
    set_escdelay(0);      // ESC instantané
    keypad(stdscr, TRUE); // touches spéciales
    nodelay(stdscr, TRUE);

    
    getmaxyx(stdscr, h, w);

    board.old_h = h;
    board.old_w = w;

    while (1)
    {
        ch = getch();

        if (ch == 27)
            break;

        getmaxyx(stdscr, h, w);

        if (board.old_h != h || board.old_w != w)
        {
            erase();
            board.old_h = h;
            board.old_w = w;
        }
        // for(int i = 0; i < 4; i++)
        // {
        draw_separation(board);

        // }
        erase();
        board.w = w / 4;
        board.h = h / 4;

        refresh();
    }
    endwin();
    return 0;
}