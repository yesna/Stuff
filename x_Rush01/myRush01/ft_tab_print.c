#include "ft.h"

void	ft_tab_print(int **tab)
{
	int	index;

	index = 0;
	while (index < 16)
	{
		ft_putchar(tab[index / 4 + 1][index % 4 + 1] + '0');
		if ((index + 1) % 4 == 0)
			ft_putchar('\n');
		else
			ft_putchar(' ');
		index++;
	}
}
