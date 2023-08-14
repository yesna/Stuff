
#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_error(int i, char *strarg)
{
	write(1, "\nIn error check top\n", 31);
	
	if (!((strarg[i] >= '1' && strarg[i] <= '4') || strarg[i] == ' '))
		return (1);
	if (strarg[i] == ' ' && !(strarg[i - 1] >= '0' && strarg[i - 1] <= '4'))
		return (1);
	if (i >= 33)
		return (1);
	else
	{
		write(1, "\nEndof error check \n", 31);
		return (0);
	}
}

char	*cleanup(char *strarg)
{
	int		i;
	int		j;
	char	*clean;

	i = 0;
	j = 0;
	clean = (char *)malloc(ft_strlen(strarg) + 1);
	if (!clean)
		return NULL;
	write(1, "In Cleanup \n", 27);

	while (strarg[i])
	{
		write(1, "In Cleanup check \n", 27);
		if (ft_error(i, strarg))
		{
			write(1, "Error\n", 6);
			return (NULL);
		}
		if (strarg[i] >= '1' && strarg[i] <= '4')
		{	
			clean[j] = strarg[i];
			j++;
		}
		
		i++;
	}
	clean[j] = '\0';
	return (clean);
}

int	check_first_8(int i, char *strarg)
{
	while (i < 4)
	{
		if (strarg[i] == 4 && strarg[i + 4] == 4)
			return (1);
		if ((strarg[i] + strarg[i + 4]) == 7)
			return (1);
		if (strarg[i] == 3 && strarg[i + 4] == 3)
			return (1);
		if (strarg[i] == 1 && strarg[i + 4] == 1)
			return (1);
		i++;
	}
	return (0);
}

int	check_last_8(int j, char *strarg)
{
	while (j < 12)
	{
		if (strarg[j] == 4 && strarg[j + 4] == 4)
			return (1);
		if ((strarg[j] + strarg[j + 4]) == 7)
			return (1);
		if (strarg[j] == 3 && strarg[j + 4] == 3)
			return (1);
		if (strarg[j] == 1 && strarg[j + 4] == 1)
			return (1);
		j++;
	}
	return (0) ;
}

int	wrong_input(char *strarg)
{
	int	i;
	int	j;
	int	var_error;

	i = 0;
	j = 8;
	var_error = 0;
	write(1, "Before check_first_8\n", 21);
	
	if (check_first_8(i, strarg))
		var_error = 1;
	write(1, "Before check_last_8\n", 21);
	if (check_last_8(j, strarg))
		var_error = 1;
	if (var_error)
	{
		write(1, "Error\n", 6);
	}
	return (0);
}

char	**tab_maker(void)
{
	char	**tab;
/*	int		x;
	int		y;

	x = 0;
	y = 0;*/
//	tab = (char **)malloc(4 * 4);
	tab = (char **)malloc(4 * sizeof(char *));
    tab[0] = (char *)malloc(4);
    tab[1] = (char *)malloc(4);
    tab[2] = (char *)malloc(4);
    tab[3] = (char *)malloc(4);
    tab[0][0] = '0'; tab[0][1] = '0'; tab[0][2] = '0'; tab[0][3] = '0';
    tab[1][0] = '0'; tab[1][1] = '0'; tab[1][2] = '0'; tab[1][3] = '0';
    tab[2][0] = '0'; tab[2][1] = '0'; tab[2][2] = '0'; tab[2][3] = '0';
    tab[3][0] = '0'; tab[3][1] = '0'; tab[3][2] = '0'; tab[3][3] = '0';
/*	if(!tab)
	{
		return (NULL);
	}
	while (y < 4)
	{
		while (x < 4)
		{
			tab[y][x] = '0';
			x++;
		}
		y++;
	}*/
	return (tab);
}

int	ft_check_maxs(char **tab, char *maxs, int x, int y);

int	ft_check_line(char **tab, int y, int nb)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (tab[y][i] == nb)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_column(char **tab, int x, int nb)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (tab[i][x] == nb)
			return (0);
		i++;
	}
	return (1);
}

int	check_possible(char **tab, char *maxs, int *pos, int nb)
{
	int	x;
	int	y;

	x = pos[1];
	y = pos[0];
	if (ft_check_column(tab, x, nb))
	{
		if (ft_check_line(tab, y, nb))
		{
			tab [y][x] = (nb + 48);
			if (ft_check_maxs(tab, maxs, x, y))
			{
				tab[y][x] = '0';
				return (1);
			}
		}
	}	
	tab[y][x] = '0';
	return (0);
}

int	ft_check_south(char **tab, char *maxs, int x)
{
	int	i;
	int	max;
	int	compteur;

	i = 3;
	max = tab[3][x];
	compteur = 1;
	while (i >= 0)
	{
		if (max < tab[i][x])
		{
			compteur++;
			max = tab[i][x];
		}
		i--;
	}
	if (compteur > (maxs[4 + x] - 48))
		return (0);
	return (1);
}

int	ft_check_north(char **tab, char *maxs, int x)
{
	int	i;
	int	max;
	int	compteur;

	i = 0;
	max = tab[0][x];
	compteur = 1;
	while (i < 4)
	{
		if (max < tab[i][x])
		{
			compteur++;
			max = tab[i][x];
		}
		i++;
	}
	if (compteur > (maxs[0 + x] - 48))
		return (0);
	return (1);
}

int	ft_check_east(char **tab, char *maxs, int y)
{
	int	i;
	int	max;
	int	compteur;

	i = 3;
	max = tab[y][3];
	compteur = 1;
	while (i >= 0)
	{
		if (max < tab[y][i])
		{
			compteur++;
			max = tab[y][i];
		}
		i--;
	}
	if (compteur > (maxs[12 + y] - 48))
		return (0);
	return (1);
}

int	ft_check_west(char **tab, char *maxs, int y)
{
	int	i;
	int	max;
	int	compteur;

	i = 0;
	max = tab[y][0];
	compteur = 1;
	while (i < 4)
	{
		if (max < tab[y][i])
		{
			compteur++;
			max = tab[y][i];
		}
		i++;
	}
	if (compteur > (maxs[8 + y] - 48))
		return (0);
	return (1);
}

int	ft_check_maxs(char **tab, char *maxs, int x, int y)
{
	int	north;
	int	south;
	int	west;
	int	east;

	north = ft_check_north (tab, maxs, x);
	south = ft_check_south (tab, maxs, x);
	west = ft_check_west (tab, maxs, y);
	east = ft_check_east (tab, maxs, y);
	if ((north + south + west + east) == 4)
		return (1);
	else
		return (0);
}

int	solve(char **tab, char *clean);

int	backtracker(int *coo, int b, char **tab, char *clean)
{
	int	x;
	int	y;

	x = coo[1];
	y = coo[0];
	while (b < 5)
	{
		if (check_possible(tab, clean, coo, b))
		{
			tab[y][x] = b + '0';
			solve(tab, clean);
			tab[y][x] = '0';
		}
		b++;
	}
	return (0);
}

int	solve(char **tab, char *clean)
{
	int		x;
	int		y;
	int		b;
	int		*coo;

	b = 1;
	x = -1;
	y = -1;
	coo = malloc(2 * 4);
	coo[0] = y;
	coo[1] = x;
	while (++y < 4)
	{
		while (++x < 4)
		{
			if (tab[3][3] != '0')
				return (0);
			if (tab[y][x] == '0')
			{
				backtracker(coo, b, tab, clean);
				return (1);
			}
		}
	}
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_tab_print(char **tab)
{
	int index;

	index = 0;
	while (index < 16)
	{		
		ft_putchar(tab[index / 4][index % 4]);
		if ((index + 1) % 4 == 0)
			ft_putchar('\n');
		else
			ft_putchar(' ');
		index++;
	}
}

int	main(int argc, char **argv)
{
	char **tab;
	char *clean;
	int	i;
	
	clean = cleanup(argv[1]);
	write(1, "After cleanup\n", 14);
	tab = tab_maker();
	write(1, "After tab_maker\n", 16);
	write(1, "Before argc check\n", 18);
	if (argc != 2)
	{
		write(1 ,"Error\n", 6);
		return (0);
	}
	write(1, "Before wrong_input check \n", 27);
	if (wrong_input(clean))
	{
		write(1 ,"Error\n", 6);
		return (0);
	}
	if (solve(tab, clean))
	{
		write(1 ,"Error\n", 6);
		return (0);
	}
	else
	{
		ft_tab_print(tab);
		return (0);
	}
	i = 0;
	while (i < 4)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	free(clean);
}
