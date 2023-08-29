/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:42:08 by nmunir            #+#    #+#             */
/*   Updated: 2023/08/29 14:28:01 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x || \
	(tab[cur.x][cur.y] != to_fill && tab[cur.x][cur.y] != 'C'))
		return ;
	tab[cur.x][cur.y] = 'F';
	flood_fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	flood_fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	flood_fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	flood_fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

int	check_flood(t_map m)
{
	size_t	i;
	t_point	pt;
	char	**f;
	int		fd;
	t_map	map_data;

	fd = open("maps/42_map.ber", O_RDONLY);
	f = create_array(fd, &map_data);
	i = 0;
	f[m.s.x][m.s.y] = '0';
	flood_fill(f, m.size, m.s, '0');
	if (f[m.e.x - 1][m.e.y] != 'F' && f[m.e.x + 1][m.e.y] != 'F' && \
	f[m.e.x][m.e.y + 1] != 'F' && f[m.e.x][m.e.y - 1] != 'F')
		return (0);
	while (i < m.c)
	{
		pt = m.c_ar[i];
		if (f[pt.x - 1][pt.y] != 'F' && f[pt.x + 1][pt.y] != 'F' && \
		f[pt.x][pt.y + 1] != 'F' && f[pt.x][pt.y - 1] != 'F')
			return (0);
		i++;
	}
	f[m.s.x][m.s.y] = 'P';
	return (1);
}

void	create_collect(t_map *map_data, int c)
{
	size_t		i;
	size_t		j;
	size_t		k;
	t_point		*collect;

	i = 0;
	k = 0;
	collect = malloc(sizeof(t_point) * (c + 1));
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
