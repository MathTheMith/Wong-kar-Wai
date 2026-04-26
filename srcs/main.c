#include "2048.h"

int main(void)
{
    t_board board;
    int ch;
    int result;
    int game_board[4][4];
    bool continue_game = false;

    init_all();

    board.size = 4;
    board.score = 0;

    start_new_game(board.size, &game_board);

    while (!should_exit())
    {
        ch = getch();
        if (ch == 27)
            break;
        int h, w;
        getmaxyx(stdscr, h, w);
        if (h < 9 || w < 24)
        {
            erase();
            continue;
        }
        result = check_finish(board, &game_board, continue_game);
        if (result == 0)
        {
            erase();
            update_game_board(&board, &game_board, ch);
            draw_board(board, &game_board);
            attron(A_BOLD | COLOR_PAIR(20));
            mvprintw(0, 0, "Score: %d ", board.score);
            standend();
        }
        else if (result == 1)
        {
            int choice = win_menu(board.score);
            if (choice == 1)
            {
                board.score = 0;
                continue_game = false;
                start_new_game(board.size, &game_board);
            }
            else if (choice == 2)
                continue_game = true;
            else
                break;
        }
        else
        {
            if (loose_menu(board.score) == 1)
            {
                board.score = 0;
                start_new_game(board.size, &game_board);
            }
            else
                break;
        }

        refresh();
    }

    return clean_exit();
}
