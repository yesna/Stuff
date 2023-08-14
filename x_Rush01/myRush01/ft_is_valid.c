#include "ft.h"

int	ft_left(int **tab, int index, int value)
{
	while (index % 4 != 0)
	{
		index--;
		if (tab[index / 4 + 1][index % 4 + 1] == value)
			return (0);
	}
	return (1);
}

int	ft_up(int **tab, int index, int value)
{
	while (index / 4 != 0)
	{
		index -= 4;
		if (tab[index / 4 + 1][index % 4 + 1] == value)
			return (0);
	}
	return (1);
}

int	ft_value_is_valid(int **tab, int index, int value)
{
	if (!ft_up(tab, index, value) || !ft_left(tab, index, value))
	{
		return (0);
	}
	return (1);
}

int	ft_array_is_valid(int **tab)
{
	int	i;

	i = 1;
	while (i < 5)
	{
		if (!ft_col_up_check(tab, i) || !ft_col_down_check(tab, i)
			|| !ft_row_left_check(tab, i) || !ft_row_right_check(tab, i))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
