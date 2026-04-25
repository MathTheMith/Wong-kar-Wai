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
        {
            game_board[i][j] = 0;
        }
    }

    return game_board;
}

void    update_game_board(int **board)
{
    
}