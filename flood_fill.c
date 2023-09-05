/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:42:08 by nmunir            #+#    #+#             */
/*   Updated: 2023/09/05 13:12:15 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.x < 0 || cur.y >= size.y || cur.x >= size.x || \
	(tab[cur.x][cur.y] != to_fill && tab[cur.x][cur.y] != 'C'))
		return ;
	tab[cur.x][cur.y] = 'F';
	flood_fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	flood_fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	flood_fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	flood_fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	check_flood(t_map m, char *av)
{
	int		i;
	t_point	pt;
	char	**f;
	t_map	map_data;

	f = create_array(av, &map_data);
	if (!f)
		error_handling_free(0, m.array);
	i = 0;
	f[m.s.x][m.s.y] = '0';
	flood_fill(f, m.size, m.s, '0');
	if (f[m.e.x - 1][m.e.y] != 'F' && f[m.e.x + 1][m.e.y] != 'F' && \
	f[m.e.x][m.e.y + 1] != 'F' && f[m.e.x][m.e.y - 1] != 'F')
		error_handling_free(9, m.array);
	while (i < m.c)
	{
		pt = m.c_ar[i];
		if (f[pt.x - 1][pt.y] != 'F' && f[pt.x + 1][pt.y] != 'F' && \
		f[pt.x][pt.y + 1] != 'F' && f[pt.x][pt.y - 1] != 'F')
			error_handling_free(9, m.array);
		i++;
	}
	ft_free_arr(f);
	free (m.c_ar);
}

void	create_collect(t_map *map_data, int c)
{
	int			i;
	int			j;
	int			k;
	t_point		*collect;

	i = 0;
	k = 0;
	collect = malloc(sizeof(t_point) * c);
	if (!collect)
		error_handling_free(0, map_data->array);
	while (i < map_data->size.x)
	{
		j = 0;
		while (j < map_data->size.y)
		{
			if (map_data->array[i][j] == 'C')
				collect[k++] = (t_point){i, j};
			j++;
		}
		i++;
	}
	map_data->c_ar = collect;
}
