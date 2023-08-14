#include "ft.h"

void	ft_borders_init(int **tab, char *str)
{
	int	index_str;
	int	index_tab;

	index_str = 0;
	index_tab = 1;
	while (index_str < 31)
	{
		if (index_str < 7)
			tab[0][index_tab] = str[index_str] - '0';
		else if (index_str < 15)
			tab[5][index_tab] = str[index_str] - '0';
		else if (index_str < 23)
			tab[index_tab][0] = str[index_str] - '0';
		else if (index_str < 31)
			tab[index_tab][5] = str[index_str] - '0';
		index_tab++;
		if (index_tab % 5 == 0)
			index_tab = 1;
		index_str += 2;
	}
}

int	**ft_tab_init(char *str)
{
	int	index;
	int	**tab;
	int	i;

	tab = malloc(6 * sizeof(int *));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < 6)
	{
		tab[i] = malloc(6 * sizeof(int));
		if (!tab)
			return (NULL);
		i++;
	}
	index = 0;
	while (index < 36)
	{
		tab[index / 6][index % 6] = 0;
		index++;
	}
	ft_borders_init(tab, str);
	return (tab);
}
