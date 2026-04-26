#include "2048.h"

int show_menu(void)
{
    int ch, h, w, cx, cy, bx, by;

    init_pair(20, COLOR_YELLOW, -1);
    init_pair(21, COLOR_RED,    -1);
    init_pair(23, COLOR_CYAN,   -1);

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
            mvprintw(by,     bx, "+--------------------------------+");
            mvprintw(by + 1, bx, "|                                |");
            mvprintw(by + 2, bx, "|   Select your board size:      |");
            mvprintw(by + 3, bx, "|                                |");
            mvprintw(by + 4, bx, "|   Press  2 - 9   to start      |");
            mvprintw(by + 5, bx, "|   Press  ESC     to quit       |");
            mvprintw(by + 6, bx, "|                                |");
            mvprintw(by + 7, bx, "+--------------------------------+");
            standend();

            attron(A_BOLD | COLOR_PAIR(21));
            mvprintw(by + 4, bx + 11, "2 - 9");
            mvprintw(by + 5, bx + 11, "ESC");
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

int win_menu(void)
{
    int ch, h, w, cx, cy, bx, by;

    init_pair(20, COLOR_YELLOW, -1);
    init_pair(22, COLOR_GREEN,  -1);

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
            mvprintw(cy - 8, cx - 9, "#   #  #####  #   #");
            mvprintw(cy - 7, cx - 9, "#   #    #    ##  #");
            mvprintw(cy - 6, cx - 9, "# # #    #    # # #");
            mvprintw(cy - 5, cx - 9, "## ##    #    #  ##");
            mvprintw(cy - 4, cx - 9, "#   #  #####  #   #");
            standend();

            attron(A_DIM);
            mvprintw(cy - 2, cx - 17, "You reached ! Congratulations!");
            standend();
        }
        else
            by -= 5;

        if (w > 35)
        {
            attron(COLOR_PAIR(22));
            mvprintw(by,     bx, "+--------------------------------+");
            mvprintw(by + 1, bx, "|                                |");
            mvprintw(by + 2, bx, "|   You win!                     |");
            mvprintw(by + 3, bx, "|                                |");
            mvprintw(by + 4, bx, "|   Press  R      to play again  |");
            mvprintw(by + 5, bx, "|   Press  C      to continue    |");
            mvprintw(by + 6, bx, "|   Press  ESC    to quit        |");
            mvprintw(by + 7, bx, "|                                |");
            mvprintw(by + 8, bx, "+--------------------------------+");
            standend();

            attron(A_BOLD | COLOR_PAIR(20));
            mvprintw(by + 4, bx + 11, "R");
            mvprintw(by + 5, bx + 11, "C");
            mvprintw(by + 6, bx + 11, "ESC");
            standend();
        }
        else
        {
            attron(COLOR_PAIR(22));
            mvprintw(by + 2, cx - 4, "You win!");
            mvprintw(by + 4, cx - 6, "R  to play again");
            standend();
        }
        refresh();

        ch = getch();
        if (ch == 27)
        {
            wtimeout(stdscr, 0);
            return 0;
        }
        else if (ch == 'c' || ch == 'C')
        {
            wtimeout(stdscr, 0);
            return 2;
        }
        else if (ch == 'r' || ch == 'R')
        {
            wtimeout(stdscr, 0);
            return 1;
        }
    }
    return -1;
}

int loose_menu(void)
{
    int ch, h, w, cx, cy, bx, by;

    init_pair(21, COLOR_RED,  -1);
    init_pair(23, COLOR_CYAN, -1);

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
            attron(A_BOLD | COLOR_PAIR(21));
            mvprintw(cy - 8, cx - 9, "#    ###  ###  ###");
            mvprintw(cy - 7, cx - 9, "#    # #  #    #  ");
            mvprintw(cy - 6, cx - 9, "#    # #  ###  ###");
            mvprintw(cy - 5, cx - 9, "#    # #    #  #  ");
            mvprintw(cy - 4, cx - 9, "###  ###  ###  ###");
            standend();

            attron(A_DIM);
            mvprintw(cy - 2, cx - 12, "No more moves available.");
            standend();
        }
        else
            by -= 5;

        if (w > 35)
        {
            attron(COLOR_PAIR(21));
            mvprintw(by,     bx, "+--------------------------------+");
            mvprintw(by + 1, bx, "|                                |");
            mvprintw(by + 2, bx, "|   Game over...                 |");
            mvprintw(by + 3, bx, "|                                |");
            mvprintw(by + 4, bx, "|   Press  R      to play again  |");
            mvprintw(by + 5, bx, "|   Press  ESC    to quit        |");
            mvprintw(by + 6, bx, "|                                |");
            mvprintw(by + 7, bx, "+--------------------------------+");
            standend();

            attron(A_BOLD | COLOR_PAIR(23));
            mvprintw(by + 4, bx + 11, "R");
            mvprintw(by + 5, bx + 11, "ESC");
            standend();
        }
        else
        {
            attron(COLOR_PAIR(21));
            mvprintw(by + 2, cx - 5, "Game over");
            mvprintw(by + 4, cx - 6, "R  to play again");
            standend();
        }
        refresh();

        ch = getch();
        if (ch == 27)
        {
            wtimeout(stdscr, 0);
            return 0;
        }
        if (ch == 'r' || ch == 'R')
        {
            wtimeout(stdscr, 0);
            return 1;
        }
    }
    return -1;
}
