/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:56:12 by thomvan-          #+#    #+#             */
/*   Updated: 2023/08/13 15:20:13 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**tab_maker(void)
{
	char	tab[4][4];
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < 4)
	{
		while (x < 4)
		{
			tab[y][x] = '0';
			x++;
		}
		y++;
	}
	return (tab);
}

char	**backtracker(int *coo, char b, char **tab, char *clean)
{
	int	x;
	int	y;

	x = coo[1];
	y = coo[0];
	while (b < '5')
	{
		coo[0] = y;
		coo[1] = x;
		if (Check_if_possible(tab, clean, coo, b))
		{
			tab[y][x] = b;
			solve(tab, clean);
			tab[y][x] = '0';
		}
		b++;
	}
}

char	**solve(char **tab, char *clean)
{
	int		x;
	int		y;
	char	b;
	int		*coo[2];

	b = '1';
	x = -1;
	y = -1;
	coo[0] = y;
	coo[1] = x;
	while (++y < 4)
	{
		while (++x < 4)
		{
			if (tab[3][3] != '0')
				return (tab);
			if (tab[y][x] == '0')
			{
				backtracker(coo, b, tab, clean);
				return ;
			}
		}
	}
}
