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
    printw("\n");
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
    printw("\n");
}

void draw_board(void)
{
    t_board board;
    int h, w;
    getmaxyx(stdscr, h, w);

    board.w = w / 4 - 1;
    board.h = h / 4 - 1;
    for (int i = 0; i < 4; i++)
    {
        draw_separation(board);
        for(int j = 0; j < board.h - 2; j++)
            draw_line(board);
    }
    draw_separation(board);
}