#include "2048.h"
#include <stdlib.h>

void get_top3(int top[3])
{
    char    buf[256];
    char    *p;
    int     score;

    top[0] = top[1] = top[2] = 0;
    if (load_score(buf))
        return ;
    p = buf;
    while (*p)
    {
        score = atoi(p);
        if (score > top[0])
        {
            top[2] = top[1];
            top[1] = top[0];
            top[0] = score;
        }
        else if (score > top[1])
        {
            top[2] = top[1];
            top[1] = score;
        }
        else if (score > top[2])
            top[2] = score;
        while (*p && *p != '\n')
            p++;
        if (*p == '\n')
            p++;
    }
}

int show_menu(void)
{
    int ch, h, w, cx, cy, bx, by;
    int top[3];

    init_pair(20, COLOR_YELLOW, -1);
    init_pair(21, COLOR_RED,    -1);
    init_pair(23, COLOR_CYAN,   -1);

    get_top3(top);
    wtimeout(stdscr, 100);
    flushinp();
    while (g_signal == 0)
    {
        erase();
        getmaxyx(stdscr, h, w);
        cx = w / 2;
        cy = h / 2;
        bx = cx - 17;
        by = cy;
        if (h > 20)
        {
            attron(A_BOLD | COLOR_PAIR(20));
            mvprintw(cy - 8, cx - 9, "##   ###  # #  ###");
            mvprintw(cy - 7, cx - 9, "  #  # #  # #  # #");
            mvprintw(cy - 6, cx - 9, " ##  # #  ###  ###");
            mvprintw(cy - 5, cx - 9, "#    # #    #  # #");
            mvprintw(cy - 4, cx - 9, "###  ###    #  ###");
            standend();
            attron(A_DIM);
            mvprintw(cy - 2, cx - 14, "Combine tiles and reach 2048!");
            standend();
        }
        else
            by -= 5;
        if (w > 35)
        {
            attron(COLOR_PAIR(23));
            mvprintw(by,      bx, "+--------------------------------+");
            mvprintw(by + 1,  bx, "|                                |");
            mvprintw(by + 2,  bx, "|   Select your board size:      |");
            mvprintw(by + 3,  bx, "|                                |");
            mvprintw(by + 4,  bx, "|   Press  2 - 9   to start      |");
            mvprintw(by + 5,  bx, "|   Press  ESC     to quit       |");
            mvprintw(by + 6,  bx, "|                                |");
            mvprintw(by + 7,  bx, "|   Best scores:                 |");
            mvprintw(by + 8,  bx, "|   1.                           |");
            mvprintw(by + 9,  bx, "|   2.                           |");
            mvprintw(by + 10, bx, "|   3.                           |");
            mvprintw(by + 11, bx, "|                                |");
            mvprintw(by + 12, bx, "+--------------------------------+");
            standend();

            attron(A_BOLD | COLOR_PAIR(21));
            mvprintw(by + 4, bx + 11, "2 - 9");
            mvprintw(by + 5, bx + 11, "ESC");
            standend();

            attron(A_BOLD | COLOR_PAIR(20));
            mvprintw(by + 8,  bx + 7, "%d", top[0]);
            mvprintw(by + 9,  bx + 7, "%d", top[1]);
            mvprintw(by + 10, bx + 7, "%d", top[2]);
            standend();
        }
        else
        {
            attron(COLOR_PAIR(23));
            mvprintw(by + 4, cx - 5, "Press  2 - 9");
            mvprintw(by + 5, cx - 3, "to start");
            standend();
        }
        refresh();

        ch = getch();
        if (ch == 27)
        {
            wtimeout(stdscr, 0);
            return -1;
        }
        if (ch >= '2' && ch <= '9')
        {
            wtimeout(stdscr, 0);
            return ch - '0';
        }
    }
    return -1;
}
