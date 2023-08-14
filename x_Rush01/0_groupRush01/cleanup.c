/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:20:39 by thomvan-          #+#    #+#             */
/*   Updated: 2023/08/13 16:19:41 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	error(int i, char *strarg)
{
	if (!((strarg[i] >= 49 && strarg[i] <= 52) || strarg[i] == 32))
		return (1);
	if (strarg[i] == ' ' && !(strarg[i - 1] >= 49 && strarg[i - 1] <= 52))
		return (1);
	if (i >= 33)
		return (1);
	else
		return (0);
}

char	*cleanup(char *strarg)
{
	int		i;
	int		j;
	char	clean[16];

	i = 0;
	j = 0;
	while (strarg[i])
	{
		if (error(i, strarg))
		{
			write(1, "Error\n", 6);
			return ;
		}
		if (strarg[i] >= 49 && strarg[i] <= 52)
		{	
			clean[j] = strarg[i];
			j++;
		}
		i++;
	}
	return (clean);
}
