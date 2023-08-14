#include "ft.h"

int	ft_col_up_check(int **tab, int col)
{
	int	j;
	int	max;
	int	count;

	max = 0;
	j = 1;
	count = tab[0][col];
	while (j < 5)
	{
		if (tab[j][col] > max)
		{
			max = tab[j][col];
			count--;
		}
		j++;
	}
	if (count != 0)
		return (0);
	return (1);
}

int	ft_col_down_check(int **tab, int col)
{
	int	j;
	int	max;
	int	count;

	max = 0;
	j = 4;
	count = tab[5][col];
	while (j > 0)
	{
		if (tab[j][col] > max)
		{
			max = tab[j][col];
			count--;
		}
		j--;
	}
	if (count != 0)
		return (0);
	return (1);
}

int	ft_row_left_check(int **tab, int row)
{
	int	j;
	int	max;
	int	count;

	max = 0;
	j = 1;
	count = tab[row][0];
	while (j < 5)
	{
		if (tab[row][j] > max)
		{
			max = tab[row][j];
			count--;
		}
		j++;
	}
	if (count != 0)
		return (0);
	return (1);
}

int	ft_row_right_check(int **tab, int row)
{
	int	j;
	int	max;
	int	count;

	max = 0;
	j = 4;
	count = tab[row][5];
	while (j > 0)
	{
		if (tab[row][j] > max)
		{
			max = tab[row][j];
			count--;
		}
		j--;
	}
	if (count != 0)
		return (0);
	return (1);
}
