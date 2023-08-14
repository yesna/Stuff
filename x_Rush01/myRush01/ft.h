
#ifndef FT_H
# define FT_H
# include <unistd.h>
# include <stdlib.h>

int		**ft_tab_init(char *str);
int		ft_sol(int **tab, int index);
void	ft_tab_print(int **tab);
int		ft_value_is_valid(int **tab, int index, int value);
int		ft_array_is_valid(int **tab);
int		ft_col_up_check(int **tab, int row);
int		ft_col_down_check(int **tab, int row);
int		ft_row_left_check(int **tab, int line);
int		ft_row_right_check(int **tab, int line);
int		ft_left(int **tab, int index, int value);
int		ft_up(int **tab, int index, int value);
void	ft_putchar(char c);
int		ft_strlen(char *str);
#endif
