#include "2048.h"

bool is_power_of_two(int n)
{
    return (n > 0 && (n & (n - 1)) == 0);
}

bool check_around(int **tab, int i, int j, int size)
{
    int nb = tab[i][j];
    if (j + 1 < size && tab[i][j + 1] == nb) return true;
    if (j - 1 >= 0   && tab[i][j - 1] == nb) return true;
    if (i + 1 < size && tab[i + 1][j] == nb) return true;
    if (i - 1 >= 0   && tab[i - 1][j] == nb) return true;
    return false;
}

bool check_finish(int **tab, t_board board)
{
    for (int i = 0; i < board.size; i++)
    {
        for (int j = 0; j < board.size; j++)
        {
            if (tab[i][j] == WIN_VALUE)
                return true;
            if (tab[i][j] == 0)
                return false;
            if (check_around(tab, i, j, board.size))
                return false;
        }
    }
    return true;
}

int show_menu(void)
{
    int ch, h, w, cx, cy, bx, by;

    init_pair(20, COLOR_YELLOW, -1);
    init_pair(21, COLOR_RED,    -1);
    init_pair(23, COLOR_CYAN,   -1);

    nodelay(stdscr, FALSE);
    while (1)
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
            nodelay(stdscr, TRUE);
            return -1;
        }
        if (ch >= '2' && ch <= '9')
        {
            nodelay(stdscr, TRUE);
            return ch - '0';
        }
    }
}

int main()
{
    t_board board;
    int ch;

    int **game_board;

    initscr();
    noecho();
    start_color();
    use_default_colors();
    curs_set(0);
    set_escdelay(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    board.size = show_menu();
    if (board.size < 0)
    {
        endwin();
        return 0;
    }

    srand(time(NULL));
    game_board = init_game_board(board.size);
    spawn_rand(game_board, board.size, 2);
    draw_board(board, game_board);
    refresh();
    while (1)
    {
        ch = getch();
        if (ch == 27)
            break;

        if (!check_finish(game_board, board))
        {
            erase();
            update_game_board(game_board, board.size, ch);
            draw_board(board, game_board);
        }
        else
        {
            erase();
            printw("You won!!");
        }
        refresh();
    }
    endwin();
    return 0;
}