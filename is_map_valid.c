/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:43:34 by nmunir            #+#    #+#             */
/*   Updated: 2023/08/31 18:31:07 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_map_rect(t_map map)
{
	size_t	i;

	i = 1;
	while (i < map.size.x)
	{
		printf("%zu\n", i);
		printf("%zu\n", ft_strlen(map.array[i]));
		printf("%zu\n", ft_strlen(map.array[i - 1]));
		if (ft_strlen(map.array[i]) != ft_strlen(map.array[i - 1]))
			error_handling(1);
		i++;
	}
}

void	is_map_closed(t_map map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map.size.x)
	{
		j = 0;
		if (map.array[i][0] != '1' || map.array[i][map.size.y - 1] != '1')
			error_handling(2);
		if (i == 0 || i == map.size.x - 1)
		{
			while (map.array[i][j])
			{
				if (map.array[i][j] != '1')
					error_handling(2);
				j++;
			}
		}
		i++;
	}
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
		(*map_data).c = count;
	return (count);
}

void	check_count(t_map *map_data)
{
	size_t		e;
	size_t		s;
	size_t		c;
	size_t		i;

	i = 0;
	c = ft_counter(map_data, 'C');
	e = ft_counter(map_data, 'E');
	s = ft_counter(map_data, 'P');
	if (!(c > 0 && e == 1 && s == 1))
		error_handling(8);
}

void	check_map(t_map *map_data, char *av)
{
	is_map_rect(*map_data);
	if (map_data->size.y < 5 || map_data->size.x < 3)
		error_handling(7);
	is_map_closed(*map_data);
	check_count(map_data);
	create_collect(map_data, map_data->c);
	check_flood(*map_data, av);
	check_array(map_data);
}
