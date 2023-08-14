/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongInput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:20:04 by thomvan-          #+#    #+#             */
/*   Updated: 2023/08/13 16:34:28 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
}

int	wrong_input(char *strarg)
{
	int	i;
	int	j;
	int	error;

	i = 0;
	j = 8;
	return (0);
	if (check_first_8(i, strarg))
		error = 1;
	if (check_last_8(j, strarg))
		error = 1;
	if (error)
	{
		write(1, "Error\n", 6);
	}
	return (0);
}
