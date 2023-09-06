/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:43:34 by nmunir            #+#    #+#             */
/*   Updated: 2023/09/06 16:09:53 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_collect(t_map *map_data)
{
	int			i;
	int			j;
	int			k;

	i = 0;
	k = 0;
	map_data->c_ar = malloc(sizeof(t_point) * map_data->c);
	if (!map_data->c_ar)
		error_handling_free(6, map_data->array);
	while (i < map_data->size.x)
	{
		j = 0;
		while (j < map_data->size.y)
		{
			if (map_data->array[i][j] == 'C')
				map_data->c_ar[k++] = (t_point){i, j};
			j++;
		}
		i++;
	}
}

void	check_array(t_map *map_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_data->size.x)
	{
		j = 0;
		while (j < map_data->size.y)
		{
			if (map_data->array[i][j] != '0' && map_data->array[i][j] != '1' && \
			map_data->array[i][j] != 'C' && map_data->array[i][j] != 'E' && \
			map_data->array[i][j] != 'P')
				error_handling_free(10, map_data->array);
			j++;
		}
		i++;
	}
}

void	flood_fill(char **tab, t_point cur)
{
	if (tab[cur.x][cur.y] != '0' && tab[cur.x][cur.y] != 'C')
		return ;
	tab[cur.x][cur.y] = 'F';
	flood_fill(tab, (t_point){cur.x - 1, cur.y});
	flood_fill(tab, (t_point){cur.x + 1, cur.y});
	flood_fill(tab, (t_point){cur.x, cur.y - 1});
	flood_fill(tab, (t_point){cur.x, cur.y + 1});
}

void	check_flood(t_map *m, char *av)
{
	int		i;
	t_point	pt;
	char	**flood;
	t_map	map_data;

	i = 0;
	flood = create_array(av, &map_data);
	flood[m->s.x][m->s.y] = '0';
	flood_fill(flood, m->s);
	if (flood[m->e.x - 1][m->e.y] != 'F' && flood[m->e.x + 1][m->e.y] != 'F' && \
	flood[m->e.x][m->e.y + 1] != 'F' && flood[m->e.x][m->e.y - 1] != 'F')
		error_handling_free(7, m->array);
	while (i < m->c)
	{
		pt = m->c_ar[i];
		if (flood[pt.x - 1][pt.y] != 'F' && flood[pt.x + 1][pt.y] != 'F' && \
		flood[pt.x][pt.y + 1] != 'F' && flood[pt.x][pt.y - 1] != 'F')
			error_handling_free(7, m->array);
		i++;
	}
	ft_free_arr(flood);
	free(m->c_ar);
}
