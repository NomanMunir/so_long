#include "so_long.h"

bool	is_map_rect(char **array, size_t row)
{
	size_t	i;

	i = 1;
	while (i < row)
	{
		if (ft_strlen(array[i]) != ft_strlen(array[i - 1]))
			return (false);
		i++;
	}
	return (true);
}

bool	is_map_closed(char **array, t_map *map_data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map_data->size.x)
	{
		j = 0;
		if (array[i][0] != '1' || array[i][map_data->size.y - 1] != '1')
			return (0);
		if (i == 0 || i == map_data->size.x - 1)
		{
			while (array[i][j])
			{
				if (array[i][j] != '1')
					return (false);
				j++;
			}
		}
		i++;
	}
	return (true);
}

size_t	ft_counter(char **array, t_map *map_data, char ch)
{
	size_t		count;
	size_t		i;
	size_t		j;

	i = 0;
	count = 0;
	while (i < (map_data)->size.x)
	{
		j = ft_strspn(array[i], ch);
		if (j != 0)
		{
			count++;
			if (ch == 'E')
				(*map_data).e = (t_point){i, j};
			if (ch == 'P')
				(*map_data).s = (t_point){i, j};
		}
		i++;
	}
	if (ch == 'C')
		(*map_data).c =	count;	
	return (count);
}

size_t	check_count(char **array, t_map *map_data)
{
	size_t		e;
	size_t		s;
	size_t		c;
	size_t		i;

	i = 0;
	c = ft_counter(array, map_data, 'C');
	e = ft_counter(array, map_data, 'E');
	s = ft_counter(array, map_data, 'P');
	if (c > 0 && e == 1 && s == 1)
		return (1);
	else
		return (0);
}

size_t	check_map(char **array, t_map *map_data)
{
	printf("row %zu and %zu col\n", map_data->size.x, map_data->size.y);
	is_map_rect(array, map_data->size.x);
	if (map_data->size.y == 0)
	{
		ft_putstr_fd("Error\nThe map is not rectangular", 2);
		return (0);
	}
	if (!is_map_closed(array, map_data))
	{
		ft_putstr_fd("Error\nThe map is not enclosed", 2);
		return (0);
	}
	if (!check_count(array, map_data))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Map contain invalid no. of exit/collectible or start", 2);
		return (0);
	}
	map_data->c_ar = create_collect(array, *map_data, map_data->c);
	if (!check_flood(array, map_data))
	{
		ft_putstr_fd("Error\nPlayer can't reach collectible/exit", 2);
		return (0);
	}
	return (1);
}
