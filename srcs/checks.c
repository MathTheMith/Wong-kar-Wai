#include "2048.h"

bool check_around(int **tab, int i, int j, int size)
{
    int nb = tab[i][j];
    if (j + 1 < size && tab[i][j + 1] == nb) return true;
    if (j - 1 >= 0   && tab[i][j - 1] == nb) return true;
    if (i + 1 < size && tab[i + 1][j] == nb) return true;
    if (i - 1 >= 0   && tab[i - 1][j] == nb) return true;
    return false;
}

int check_finish(int **tab, t_board board, bool continue_game)
{
    if (!continue_game)
    {
        for (int i = 0; i < board.size; i++)
            for (int j = 0; j < board.size; j++)
                if (tab[i][j] == WIN_VALUE && is_power_of_two(WIN_VALUE))
                    return 1;
    }

    for (int i = 0; i < board.size; i++)
        for (int j = 0; j < board.size; j++)
            if (tab[i][j] == 0 || check_around(tab, i, j, board.size))
                return 0;

    return 2;
}