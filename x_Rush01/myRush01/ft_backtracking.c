#include "ft.h"

int	ft_sol(int **tab, int index)
{
	int	value;

	if (index == 16 && ft_array_is_valid(tab))
	{
		return (1);
	}
	if (index < 16)
	{
		value = 1;
		while (value < 5)
		{
			if (ft_value_is_valid(tab, index, value))
			{
				tab[index / 4 + 1][index % 4 + 1] = value;
				if (ft_sol(tab, index + 1))
					return (1);
			}
			value++;
		}
	}
	return (0);
}
