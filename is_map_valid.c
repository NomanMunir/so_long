
#include "so_long.h"

int	is_map_rect(char **array, int row)
{
	int	i;

	i = 1;
	while (i < row)
	{
		if (ft_strl(array[i]) != ft_strl(array[i - 1]))
			return (0);
		i++;
	}
	i = ft_strl(array[0]);
	return (i);
}

int	is_map_closed(char **array, t_map *map_data)
{
	int	i;
	int	j;

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
					return (0);
				j++;
			}
		}
		i++;
	}
	return (1);
}

int	ft_counter(char **array, t_map *map_data, char ch)
{
	int		count;
	int		i;
	int		j;

	i = 0;
	count = 0;
	while (i < (map_data)->size.x)
	{
		j = ft_strchr(array[i], ch);
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

int	check_count(char **array, t_map *map_data)
{
	int		e;
	int		s;
	int		c;
	int		i;

	i = 0;
	c = ft_counter(array, map_data, 'C');
	e = ft_counter(array, map_data, 'E');
	s = ft_counter(array, map_data, 'P');
	if (c > 0 && e == 1 && s == 1)
		return (1);
	else
		return (0);
}

int	check_map(char **array, t_map *map_data)
{
	map_data->size.y = is_map_rect(array, map_data->size.x);
	if (map_data->size.y == 0)
	{
		ft_putstr("Error\nThe map is not rectangular");
		return (0);
	}
	if (!is_map_closed(array, map_data))
	{
		ft_putstr("Error\nThe map is not enclosed");
		return (0);
	}
	if (!check_count(array, map_data))
	{
		ft_putstr("Error\n");
		ft_putstr("Map contain invalid no. of exit/collectible or start");
		return (0);
	}
	map_data->c_ar = create_collect(array, *map_data, map_data->c);
	if (!check_flood(array, map_data))
	{
		ft_putstr("Error\nPlayer can't reach collectible/exit");
		return (0);
	}
	return (1);
}
