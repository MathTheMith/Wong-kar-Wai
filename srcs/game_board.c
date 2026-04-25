#include "2048.h"


void free_board(int **game_board, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (game_board[i] == NULL)
            break;
        free(game_board[i]);
    }
    free(game_board);
}


int **init_game_board(int size)
{
    int **game_board;

    if (size < 4 || size > 5)
        return NULL;

    game_board = ft_calloc(size, sizeof(int *));
    if (game_board == NULL)
        return NULL;

    for (int i = 0; i < size; i++)
    {
        game_board[i] = ft_calloc(size, sizeof(int));

        if (game_board[i] == NULL)
        {
            free_board(game_board, size);
            return NULL;
        }

        for (int j = 0; j < size; j++)
            game_board[i][j] = 0;
    }

    return game_board;
}


void update_horizontal(int **game_board, int size, int move)
{
    int j_start;
    int last_j;

    j_start = 1;
    if (move == -1)
        j_start = size - 2;
    
    for (int i = 0; i < size; i++)
    {
        for (int j = j_start; 0 <= j && j < size - 1; j += move)
        {
            last_j = j;

            for (int k = j; game_board[i][j] != 0 && 0 < k && k < size; k -= move)
            {
                if (game_board[i][k] == 0)
                {
                    game_board[i][k] = game_board[i][last_j];
                    game_board[i][last_j] = 0;
                    last_j = k;
                }

                else if (game_board[i][k] == game_board[i][last_j])
                {
                    game_board[i][k] *= -2;
                    game_board[i][last_j] = 0;
                    last_j = k;
                }

                else if (game_board[i][k] < 0)
                    break;
            }
        }
    }
}


void    update_game_board(int **game_board, int size, int ch)
{
    if (ch == KEY_LEFT)
        update_horizontal(game_board, size, -1);

    else if (ch == KEY_RIGHT)
        update_horizontal(game_board, size, 1);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (game_board[i][j] < 0)
                game_board[i][j] *= 1;
        }
    }
}