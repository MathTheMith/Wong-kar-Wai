#include "2048.h"

bool check_around(int size, int (*tab)[size][size], int i, int j)
{
    int nb = (*tab)[i][j];
    if (j + 1 < size && (*tab)[i][j + 1] == nb) return true;
    if (j - 1 >= 0   && (*tab)[i][j - 1] == nb) return true;
    if (i + 1 < size && (*tab)[i + 1][j] == nb) return true;
    if (i - 1 >= 0   && (*tab)[i - 1][j] == nb) return true;
    return false;
}

int check_finish(t_board board, int (*tab)[board.size][board.size], bool continue_game)
{
    if (!continue_game)
    {
        for (int i = 0; i < board.size; i++)
            for (int j = 0; j < board.size; j++)
                if ((*tab)[i][j] == (is_power_of_two(WIN_VALUE) ? WIN_VALUE : 2048))
                    return 1;
    }

    for (int i = 0; i < board.size; i++)
        for (int j = 0; j < board.size; j++)
            if ((*tab)[i][j] == 0 || check_around(board.size, tab, i, j))
                return 0;

    return 2;
}