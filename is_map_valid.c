/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:43:34 by nmunir            #+#    #+#             */
/*   Updated: 2023/08/29 14:15:56 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_map_rect(t_map map)
{
	size_t	i;

	i = 1;
	while (i < map.size.x)
	{
		if (ft_strlen(map.array[i]) != ft_strlen(map.array[i - 1]))
			return (false);
		i++;
	}
	return (true);
}

bool	is_map_closed(t_map map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map.size.x)
	{
		j = 0;
		if (map.array[i][0] != '1' || map.array[i][map.size.y - 1] != '1')
			return (0);
		if (i == 0 || i == map.size.x - 1)
		{
			while (map.array[i][j])
			{
				if (map.array[i][j] != '1')
					return (false);
				j++;
			}
		}
		i++;
	}
	return (true);
}

size_t	ft_counter(t_map *map_data, char ch)
{
	size_t		count;
	size_t		i;
	size_t		j;

	i = 0;
	count = 0;
	while (i < (map_data)->size.x)
	{
		j = ft_strspn(map_data->array[i], ch);
		if (j != 0)
		{
			count += j;
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

size_t	check_count(t_map *map_data)
{
	size_t		e;
	size_t		s;
	size_t		c;
	size_t		i;

	i = 0;
	c = ft_counter(map_data, 'C');
	e = ft_counter(map_data, 'E');
	s = ft_counter(map_data, 'P');
	if (c > 0 && e == 1 && s == 1)
		return (1);
	else
		return (0);
}

size_t	check_map(t_map *map_data)
{
	is_map_rect(*map_data);
	if (map_data->size.y == 0)
	{
		ft_putstr_fd("Error\nThe map is not rectangular", 2);
		return (0);
	}
	if (!is_map_closed(*map_data))
	{
		ft_putstr_fd("Error\nThe map is not enclosed", 2);
		return (0);
	}
	if (!check_count(map_data))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Map contain invalid no. of exit/collectible or start", 2);
		return (0);
	}
	create_collect(map_data, map_data->c);
	if (!check_flood(*map_data))
	{
		ft_putstr_fd("Error\nPlayer can't reach collectible/exit", 2);
		return (0);
	}
	return (1);
}
