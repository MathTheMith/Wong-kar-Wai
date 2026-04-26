#include "2048.h"

int win_menu(int score)
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
            mvprintw(by,      bx, "+--------------------------------+");
            mvprintw(by + 1,  bx, "|                                |");
            mvprintw(by + 2,  bx, "|   You win!                     |");
            mvprintw(by + 3,  bx, "|                                |");
            mvprintw(by + 4,  bx, "|   Score:                       |");
            mvprintw(by + 5,  bx, "|                                |");
            mvprintw(by + 6,  bx, "|   Press  R      to play again  |");
            mvprintw(by + 7,  bx, "|   Press  C      to continue    |");
            mvprintw(by + 8,  bx, "|   Press  ESC    to quit        |");
            mvprintw(by + 9,  bx, "|                                |");
            mvprintw(by + 10, bx, "+--------------------------------+");
            standend();

            attron(A_BOLD | COLOR_PAIR(20));
            mvprintw(by + 4, bx + 11, "%d", score);
            mvprintw(by + 6, bx + 11, "R");
            mvprintw(by + 7, bx + 11, "C");
            mvprintw(by + 8, bx + 11, "ESC");
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

int loose_menu(int score)
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
            mvprintw(by + 4, bx, "|   Score:                       |");
            mvprintw(by + 5, bx, "|                                |");
            mvprintw(by + 6, bx, "|   Press  R      to play again  |");
            mvprintw(by + 7, bx, "|   Press  ESC    to quit        |");
            mvprintw(by + 8, bx, "|                                |");
            mvprintw(by + 9, bx, "+--------------------------------+");
            standend();

            attron(A_BOLD | COLOR_PAIR(20));
            mvprintw(by + 4, bx + 11, "%d", score);
            standend();
            attron(A_BOLD | COLOR_PAIR(23));
            mvprintw(by + 6, bx + 11, "R");
            mvprintw(by + 7, bx + 11, "ESC");
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
