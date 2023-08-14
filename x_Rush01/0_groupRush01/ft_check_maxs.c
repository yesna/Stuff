/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_maxs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:42:24 by cmathot           #+#    #+#             */
/*   Updated: 2023/08/13 14:18:14 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
