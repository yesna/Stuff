#include "ft.h"

/* int	ft_args_tst(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		return (0);
	if (ft_strlen(argv[1]) != 4 * 8 - 1)
		return (0);
	i = 0;
	while (argv[1][i])
	{
		if (i % 2 == 0 && (argv[1][i] < '1' || argv[1][i] > '4'))
			return (0);
		else if (i % 2 == 1 && argv[1][i] != ' ')
			return (0);
		i++;
	}
	return (1);
} */



int	main(int argc, char **argv)
{
	int	**tab;
	int	i;

	if (!ft_args_tst(argc, argv))
	{
		write(2, "Error\n", 12);
		return (-1);
	}
	tab = ft_tab_init(argv[1]);
	if (!tab)
		return (-1);
	if (ft_sol(tab, 0))
		ft_tab_print(tab);
	else
		write(2, "Error\n", 12);
	i = 0;
	while (i < 6)
		free(tab[i++]);
	free(tab);
	return (0);
}
