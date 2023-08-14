#include "ft.h"

int ft_row_up_check(int **tab, int row)
{
    int j;
    int max;
    int count;

    max = 0;
    j = 1;
    count = tab[0][row];
    while (j < 9)
    {
        if (tab[j][row] > max)
        {
            max = tab[j][row];
            count--;
        }
        j++;
    }
    if (count != 0)
        return (0);
    return (1);
}

int ft_row_down_check(int **tab, int row)
{
    int j;
    int max;
    int count;

    max = 0;
    j = 8;
    count = tab[8][row];
    while (j > 1)
    {
        if (tab[j][row] > max)
        {
            max = tab[j][row];
            count--;
        }
        j--;
    }
    if (count != 0)
        return (0);
    return (1);
}

int ft_line_left_check(int **tab, int line)
{
    int j;
    int max;
    int count;

    max = 0;
    j = 1;
    count = tab[line][0];
    while (j < 9)
    {
        if (tab[line][j] > max)
        {
            max = tab[line][j];
            count--;
        }
        j++;
    }
    if (count != 0)
        return (0);
    return (1);
}

int ft_line_right_check(int **tab, int line)
{
    int j;
    int max;
    int count;

    max = 0;
    j = 8;
    count = tab[line][8];
    while (j > 1)
    {
        if (tab[line][j] > max)
        {
            max = tab[line][j];
            count--;
        }
        j--;
    }
    if (count != 0)
        return (0);
    return (1);
}