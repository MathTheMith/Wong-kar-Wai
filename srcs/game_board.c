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

int randint(int range)
{
    return rand() % range;
}

void spawn_rand(int **game_board, int size, int n_rand)
{
    int tab[size * size];
    int range;
    int n;

    for (int k = 0; k < n_rand; k++)
    {
        range = size * size;
        for (int i = 0; i < range; i++)
            tab[i] = 0;

        while (1)
        {
            n = randint(range);
            while (tab[n] == 1 && n < size * size)
                n++;

            if (game_board[n / size][n % size] != 0)
            {
                tab[n] = 1;
                range--;
            }
            else if (randint(100) < 90)
            {
                game_board[n / size][n % size] = 2;
                break;
            }
            else
            {
                game_board[n / size][n % size] = 4;
                break;
            }
            if (range == 0)
                break;
        }
    }
}

void update_horizontal(t_board *board, int **game_board, int size, int move, int *has_moved)
{
    int j_start;
    int last_j;
    j_start = 1;
    if (move == -1)
        j_start = size - 2;
    
    for (int i = 0; i < size; i++)
    {
        for (int j = j_start; 0 <= j && j < size; j += move)
        {
            last_j = j;

            for (int k = j - move; game_board[i][last_j] >= 0 && 0 <= k && k < size; k -= move)
            {
                if (game_board[i][k] == 0)
                {
                    game_board[i][k] = game_board[i][last_j];
                    game_board[i][last_j] = 0;
                    last_j = k;

                    *has_moved = 1;
                }

                else if (game_board[i][k] == game_board[i][last_j])
                {
                    game_board[i][k] *= -2;
                    game_board[i][last_j] = 0;
                    board->score -= game_board[i][k];
                    *has_moved = 1;
                    break;
                }

                else
                    break;
            }
        }
    }
}

void update_vertical(t_board *board, int **game_board, int size, int move, int *has_moved)
{
    int i_start;
    int last_i;

    i_start = 1;
    if (move == -1)
        i_start = size - 2;
    
    for (int j = 0; j < size; j++)
    {
        for (int i = i_start; 0 <= i && i < size; i += move)
        {
            last_i = i;

            for (int k = i - move; game_board[last_i][j] != 0 && 0 <= k && k < size; k -= move)
            {
                if (game_board[k][j] == 0)
                {
                    game_board[k][j] = game_board[last_i][j];
                    game_board[last_i][j] = 0;
                    last_i = k;
                    *has_moved = 1;
                }
                else if (game_board[k][j] == game_board[last_i][j])
                {
                    game_board[k][j] *= -2;
                    game_board[last_i][j] = 0;
                    board->score -= game_board[k][j];
                    *has_moved = 1;
                    break;
                }

                else
                    break;
            }
        }
    }
}

void update_game_board(t_board *board, int **game_board, int size, int ch)
{
    int has_moved;

    has_moved = 0;

    switch (ch)
    {
        case KEY_LEFT:
            update_horizontal(board, game_board, size, 1, &has_moved);
            break;

        case KEY_RIGHT:
            update_horizontal(board, game_board, size, -1, &has_moved);
            break;

        case KEY_UP:
            update_vertical(board, game_board, size, 1, &has_moved);
            break;

        case KEY_DOWN:
            update_vertical(board, game_board, size, -1, &has_moved);
            break;

        default:
            return ;
    }
    if (has_moved)
        spawn_rand(game_board, size, 1);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (game_board[i][j] < 0)
                game_board[i][j] *= -1;
}
