/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_possible.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:39:04 by cmathot           #+#    #+#             */
/*   Updated: 2023/08/13 14:16:29 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
