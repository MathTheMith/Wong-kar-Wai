#include "2048.h"

bool is_power_of_two(int n)
{
    return (n > 0 && (n & (n - 1)) == 0);
}

bool check_finish(int **tab, t_board board)
{
    bool full = true;

    for (int i = 0; i < board.size; i++)
    {
        for (int j = 0; j < board.size; j++)
        {
            if (tab[i][j] == WIN_VALUE && is_power_of_two(WIN_VALUE))
                return true;

            if (tab[i][j] == 0)
                full = false;
        }
    }

    return full;
}


int main()
{
    t_board board;
    int ch;

    initscr();
    noecho();
    start_color();
    use_default_colors();
    curs_set(0);
    set_escdelay(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    while (1)
    {
        erase();
        printw("What size of board would you want ?\n");
        printw("4x4 (click 4)\n");
        printw("5x5 (click 5)\n");

        refresh();

        ch = getch();

        if (ch == '4')
            board.size = 4;
        if (ch == '5')
            board.size = 5;
        if (ch == '4' || ch == '5')
            break;
    }
    int **game_board;
    game_board = init_game_board(board.size);
    spawn_rand(game_board, board.size, 2);
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
            refresh();
        }
        refresh();
    }
    endwin();
    return 0;
}