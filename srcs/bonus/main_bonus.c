#include "2048.h"

int main(void)
{
    t_board board;
    int ch;
    int result;
    bool continue_game = false;
    
    init_all();
    
    board.size = show_menu();
    if (board.size < 0)
        return clean_exit();
    
    int game_board[board.size][board.size];

    start_new_game(board.size, &game_board);
    board.score = 0;

    while (!should_exit())
    {
        ch = getch();
        if (ch == 27)
        {
            write_score(board.score);
            break;
        }
        int h, w;
        getmaxyx(stdscr, h, w);
        if (h < 19 || w < 38)
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
                write_score(board.score);
                board.score = 0;
                continue_game = false;
                start_new_game(board.size, &game_board);
            }
            else if (choice == 2)
                continue_game = true;
            else
            {
                write_score(board.score);
                break;
            }
        }
        else
        {
            write_score(board.score);
            if (loose_menu(board.score))
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
