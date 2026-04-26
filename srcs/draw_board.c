#include "2048.h"

int ft_intlen(int n)
{
    int len = 0;

    if (n == 0)
        return 1;

    if (n < 0)
        len++;

    while (n != 0)
    {
        n /= 10;
        len++;
    }
    return len;
}

void draw_separation(t_board board)
{
    for (int i = 0; i < board.size; i++)
    {
        printw("+");
        for (int j = 0; j < board.tiles_w - 1; j++)
            printw("-");
    }
    printw("+\n");
}

void draw_line(t_board board)
{
    for (int i = 0; i < board.size; i++)
    {
        printw("|");
        for (int j = 0; j < board.tiles_w - 1; j++)
            printw(" ");
    }
    printw("|\n");
}

void set_color(int nb)
{
    static int initialized = 0;

    if (!initialized)
    {
        start_color();
        use_default_colors();

        if (can_change_color())
        {
            init_color(10, 1000, 900, 800); // 2
            init_color(11, 950, 700, 500);  // 4
            init_color(12, 900, 600, 400);  // 8
            init_color(13, 850, 500, 300);  // 16
            init_color(14, 800, 400, 200);  // 32
            init_color(15, 750, 300, 100);  // 64
            init_color(16, 700, 200, 50);   // 128
            init_color(17, 650, 150, 0);    // 256
            init_color(18, 600, 100, 0);    // 512
            init_color(19, 550, 50, 0);     // 1024
            init_color(20, 500, 0, 0);      // 2048

            init_pair(1,  COLOR_BLACK, 10);
            init_pair(2,  COLOR_BLACK, 11);
            init_pair(3,  COLOR_BLACK, 12);
            init_pair(4,  COLOR_BLACK, 13);
            init_pair(5,  COLOR_BLACK, 14);
            init_pair(6,  COLOR_BLACK, 15);
            init_pair(7,  COLOR_BLACK, 16);
            init_pair(8,  COLOR_BLACK, 17);
            init_pair(9,  COLOR_BLACK, 18);
            init_pair(10, COLOR_BLACK, 19);
            init_pair(11, COLOR_BLACK, 20);
        }
        else
        {
            init_pair(1,  COLOR_BLACK, COLOR_WHITE);
            init_pair(2,  COLOR_BLACK, COLOR_YELLOW);
            init_pair(3,  COLOR_BLACK, COLOR_CYAN);
            init_pair(4,  COLOR_BLACK, COLOR_GREEN);
            init_pair(5,  COLOR_BLACK, COLOR_MAGENTA);
            init_pair(6,  COLOR_BLACK, COLOR_RED);
            init_pair(7,  COLOR_BLACK, COLOR_BLUE);
            init_pair(8,  COLOR_BLACK, COLOR_YELLOW);
            init_pair(9,  COLOR_BLACK, COLOR_CYAN);
            init_pair(10, COLOR_BLACK, COLOR_GREEN);
            init_pair(11, COLOR_BLACK, COLOR_RED);
        }

        initialized = 1;
    }

    switch (nb)
    {
        case 2:    attron(COLOR_PAIR(1)); break;
        case 4:    attron(COLOR_PAIR(2)); break;
        case 8:    attron(COLOR_PAIR(3)); break;
        case 16:   attron(COLOR_PAIR(4)); break;
        case 32:   attron(COLOR_PAIR(5)); break;
        case 64:   attron(COLOR_PAIR(6)); break;
        case 128:  attron(COLOR_PAIR(7)); break;
        case 256:  attron(COLOR_PAIR(8)); break;
        case 512:  attron(COLOR_PAIR(9)); break;
        case 1024: attron(COLOR_PAIR(10)); break;
        case 2048: attron(COLOR_PAIR(11)); break;
        default:   attron(COLOR_PAIR(0)); break;
    }
}

void put_numbers(int **tab, t_board board)
{

    for (int i = 0; i < board.size; i++)
    {
        for (int j = 0; j < board.size; j++)
        {
            int y = j * (board.tiles_h - 1);
            int x = i * (board.tiles_w);

            set_color(tab[j][i]);

            for (int k = 1; k < board.tiles_h - 1; k++)
            {
                for (int l = 1; l < board.tiles_w; l++)
                {
                    mvprintw(y + k, x + l, " ");
                }
            }
            standend();
        }
    }
    for (int i = 0; i < board.size; i++)
    {
        for (int j = 0; j < board.size; j++)
        {
            int y = (i * board.tiles_h + board.tiles_h / 2) - i;
            int x = (j * board.tiles_w + board.tiles_w / 2) - (ft_intlen(tab[i][j]) / 2);
            if (tab[i][j] != 0)
            {
                set_color(tab[i][j]);
                mvprintw(y, x, "%d", tab[i][j]);
                standend();
            }
        }
    }
}

void draw_board(t_board board, int **tab)
{
    int h, w;
    getmaxyx(stdscr, h, w);

    board.tiles_w = (w - 2) / board.size;
    board.tiles_h = (h + 2) / board.size;
    for (int i = 0; i < board.size; i++)
    {
        draw_separation(board);
        for(int j = 0; j < board.tiles_h - 2; j++)
            draw_line(board);
    }
    draw_separation(board);
    put_numbers(tab, board);
    
}