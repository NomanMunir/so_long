/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:43:34 by nmunir            #+#    #+#             */
/*   Updated: 2023/09/06 16:09:13 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_map_rect(t_map *map)
{
	int	i;

	i = 1;
	while (i < map->size.x)
	{
		if (ft_strlen(map->array[i]) != ft_strlen(map->array[i - 1]))
			error_handling_free(2, map->array);
		i++;
	}
}

void	is_map_closed(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->size.x)
	{
		j = -1;
		if (map->array[i][0] != '1' || map->array[i][map->size.y - 1] != '1')
			error_handling_free(2, map->array);
		if (i == 0 || i == map->size.x - 1)
		{
			while (map->array[i][++j])
			{
				if (map->array[i][j] != '1')
					error_handling_free(2, map->array);
			}
		}
	}
}

int	ft_counter(t_map *map_data, char ch)
{
	int		count;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	count = 0;
	while (i < (map_data)->size.x)
	{
		j = ft_strspn(map_data->array[i], ch);
		if (j != 0)
		{
			k = ft_position(map_data->array[i], ch);
			count += j;
			if (ch == 'E')
				map_data->e = (t_point){i, k};
			if (ch == 'P')
				map_data->s = (t_point){i, k};
		}
		i++;
	}
	if (ch == 'C')
		map_data->c = count;
	return (count);
}

void	check_count(t_map *map_data)
{
	if (!(ft_counter(map_data, 'C') > 0 && \
	ft_counter(map_data, 'E') == 1 && ft_counter(map_data, 'P') == 1))
		error_handling_free(5, map_data->array);
}

void	check_map(t_map *map_data, char *av)
{
	is_map_rect(map_data);
	is_map_closed(map_data);
	check_count(map_data);
	check_array(map_data);
	create_collect(map_data);
	check_flood(map_data, av);
}
