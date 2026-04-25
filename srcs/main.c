#include "2048.h"

int main()
{
    int ch;

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
        draw_board();
        refresh();
    }

    endwin();
    return 0;
}