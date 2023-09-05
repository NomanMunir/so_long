/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:43:34 by nmunir            #+#    #+#             */
/*   Updated: 2023/09/05 13:13:10 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_map_rect(t_map map)
{
	int	i;

	i = 1;
	while (i < map.size.x)
	{
		if (ft_strlen(map.array[i]) != ft_strlen(map.array[i - 1]))
			error_handling_free(1, map.array);
		i++;
	}
}

void	is_map_closed(t_map map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map.size.x)
	{
		j = -1;
		if (map.array[i][0] != '1' || map.array[i][map.size.y - 1] != '1')
			error_handling_free(2, map.array);
		if (i == 0 || i == map.size.x - 1)
		{
			while (map.array[i][++j])
			{
				if (map.array[i][j] != '1')
					error_handling_free(2, map.array);
			}
		}
	}
}

int	ft_strc(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if ((char)c == '\0')
		return (i);
	return (0);
}

int	ft_counter(t_map *map_data, char ch)
{
	int		count;
	int		i;
	int		j;
	int		k;

	i = 0;
	count = 0;
	k = 0;
	while (i < (map_data)->size.x)
	{
		j = ft_strspn(map_data->array[i], ch);
		if (j != 0)
		{
			k = ft_strc(map_data->array[i], ch);
			count += j;
			if (ch == 'E')
				(*map_data).e = (t_point){i, k};
			if (ch == 'P')
				(*map_data).s = (t_point){i, k};
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

	c = ft_counter(map_data, 'C');
	e = ft_counter(map_data, 'E');
	s = ft_counter(map_data, 'P');
	if (!(c > 0 && e == 1 && s == 1))
		error_handling_free(8, map_data->array);
}

void	check_map(t_map *map_data, char *av)
{
	is_map_rect(*map_data);
	if (map_data->size.y < 5 || map_data->size.x < 3)
		error_handling_free(7, map_data->array);
	is_map_closed(*map_data);
	check_count(map_data);
	create_collect(map_data, map_data->c);
	check_array(map_data);
	check_flood(*map_data, av);
}
