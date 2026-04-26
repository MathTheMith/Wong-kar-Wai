#include "2048.h"

void set_color(int nb);

void draw_separation(t_board board, t_sep_pos pos)
{
    chtype left, mid, right;

    if (pos == SEP_TOP)        { left = ACS_ULCORNER; mid = ACS_TTEE; right = ACS_URCORNER; }
    else if (pos == SEP_BOT)   { left = ACS_LLCORNER; mid = ACS_BTEE; right = ACS_LRCORNER; }
    else                       { left = ACS_LTEE;     mid = ACS_PLUS; right = ACS_RTEE;     }

    for (int i = 0; i < board.size; i++)
    {
        addch(i == 0 ? left : mid);
        for (int j = 0; j < board.tiles_w - 1; j++)
            addch(ACS_HLINE);
    }
    addch(right);
    addch('\n');
}

void draw_line(t_board board)
{
    for (int i = 0; i < board.size; i++)
    {
        addch(ACS_VLINE);
        for (int j = 0; j < board.tiles_w - 1; j++)
            addch(' ');
    }
    addch(ACS_VLINE);
    addch('\n');
}

void put_colors(t_board board, int (*tab)[board.size][board.size])
{
    for (int i = 0; i < board.size; i++)
    {
        for (int j = 0; j < board.size; j++)
        {
            int y = j * (board.tiles_h - 1);
            int x = i * (board.tiles_w);

            set_color((*tab)[j][i]);
            for (int k = 1; k < board.tiles_h - 1; k++)
                for (int l = 1; l < board.tiles_w; l++)
                    mvprintw(y + k, x + l, " ");
            standend();
        }
    }
}

void put_numbers(t_board board, int (*tab)[board.size][board.size])
{
    for (int i = 0; i < board.size; i++)
    {
        for (int j = 0; j < board.size; j++)
        {
            int y = (i * board.tiles_h + board.tiles_h / 2) - i;
            int x = (j * board.tiles_w + board.tiles_w / 2) - (ft_intlen((*tab)[i][j]) / 2);
            if ((*tab)[i][j] != 0)
            {
                set_color((*tab)[i][j]);
                mvprintw(y, x, "%d", (*tab)[i][j]);
                standend();
            }
        }
    }
}

void draw_board(t_board board, int (*tab)[board.size][board.size])
{
    int h, w;
    getmaxyx(stdscr, h, w);

    int max_tw = (w - 2) / board.size;
    int max_th = (h - 1) / board.size + 1;

    int tiles_h = max_th;
    int tiles_w = 2 * (tiles_h - 1);

    if (tiles_w > max_tw)
    {
        tiles_w = max_tw;
        tiles_h = tiles_w / 2 + 1;
    }

    if (tiles_h < 3) return ;
    if (tiles_w < 3) return ;

    board.tiles_w = tiles_w;
    board.tiles_h = tiles_h;

    for (int i = 0; i < board.size; i++)
    {
        draw_separation(board, i == 0 ? SEP_TOP : SEP_MID);
        for (int j = 0; j < board.tiles_h - 2; j++)
            draw_line(board);
    }
    draw_separation(board, SEP_BOT);
    put_colors(board, tab);
    put_numbers(board, tab);
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
            init_color(10, 1000, 900, 800);
            init_color(11, 950,  700, 500);
            init_color(12, 900,  600, 400);
            init_color(13, 850,  500, 300);
            init_color(14, 800,  400, 200);
            init_color(15, 750,  300, 100);
            init_color(16, 700,  200, 50);
            init_color(17, 650,  150, 0);
            init_color(18, 600,  100, 0);
            init_color(19, 550,  50,  0);
            init_color(20, 500,  0,   0);

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
        case 2:    attron(COLOR_PAIR(1));  break;
        case 4:    attron(COLOR_PAIR(2));  break;
        case 8:    attron(COLOR_PAIR(3));  break;
        case 16:   attron(COLOR_PAIR(4));  break;
        case 32:   attron(COLOR_PAIR(5));  break;
        case 64:   attron(COLOR_PAIR(6));  break;
        case 128:  attron(COLOR_PAIR(7));  break;
        case 256:  attron(COLOR_PAIR(8));  break;
        case 512:  attron(COLOR_PAIR(9));  break;
        case 1024: attron(COLOR_PAIR(10)); break;
        case 2048: attron(COLOR_PAIR(11)); break;
        default:   attron(COLOR_PAIR(0));  break;
    }
}
