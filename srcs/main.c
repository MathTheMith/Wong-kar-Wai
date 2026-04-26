#include "2048.h"

int main(void)
{
    t_board board;
    int **game_board;
    int ch;
    int result;
    bool continue_game = false;

    init_all();

    board.size = show_menu();
    if (board.size < 0)
        return clean_exit(NULL, 0);

    game_board = start_new_game(board.size);

    while (!should_exit())
    {
        ch = getch();
        if (ch == 27)
            break;

        result = check_finish(game_board, board, continue_game);

        if (result == 0)
        {
            erase();
            update_game_board(game_board, board.size, ch);
            draw_board(board, game_board);
        }
        else if (result == 1)
        {
            int choice = win_menu();

            if (choice == 1)
                reset_game(&game_board, board.size);
            else if (choice == 2)
                continue_game = true;
            else
                break;
        }
        else
        {
            if (loose_menu())
                reset_game(&game_board, board.size);
            else
                break;
        }

        refresh();
    }

    return clean_exit(game_board, board.size);
}