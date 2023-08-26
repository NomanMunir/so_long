
#include "so_long.h"

int	ft_strl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

void	ft_print_array(char **array, int row)
{
	for (int i = 0; i < row; i++)
		printf("%s\n", array[i]);
}

void	ft_putstr(char *s)
{
	if (s != NULL)
		write(1, s, ft_strl(s));
}
