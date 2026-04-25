#include "2048.h"

void draw_separation(t_board board)
{
    for (int i = 0; i < 4; i++)
    {
        printw("+");
        for (int j = 0; j < board.tiles_w - 1; j++)
        {
            if (i == 3 && j == board.tiles_w - 2)
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
        for (int j = 0; j < board.tiles_w - 1; j++)
        {
            if (i == 3 && j == board.tiles_w - 2)
                printw("|");
            else
                printw(" ");
        }
    }
    printw("\n");
}

void put_numbers(int tab[4][4], t_board board)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int y = (i * board.tiles_h + board.tiles_h / 2) - i;
            int x = j * board.tiles_w + board.tiles_w / 2;
            if (tab[i][j] != 0)
                mvprintw(y, x, "%d", tab[i][j]);
        }
    }
}

void draw_board(int tab[4][4])
{
    t_board board;
    int h, w;
    getmaxyx(stdscr, h, w);

    board.tiles_w = w / 4 - 1;
    board.tiles_h = h / 4 - 1;
    for (int i = 0; i < 4; i++)
    {
        draw_separation(board);
        for(int j = 0; j < board.tiles_h - 2; j++)
            draw_line(board);
    }
    draw_separation(board);
    put_numbers(tab, board);
}