#include "ft.h"

/* ft_putchar est defini dans libft.c (ainsi que ft_strlen) */
/* le fichier ft.h reprend toutes les fonctions utilisée    */
/* dans les  *.c                                            */

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
