
#include "so_long.h"

void	flood_fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x || \
	tab[cur.x][cur.y] != to_fill)
		return ;
	tab[cur.x][cur.y] = 'F';
	flood_fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	flood_fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	flood_fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	flood_fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

int	check_flood(char **array, t_map *m)
{
	char	**f;
	size_t	i;
	t_point	pt;

	i = 0;
	f = array;
	f[m->s.x][m->s.y] = '0';
	flood_fill(f, m->size, m->s, '0');
	if (f[m->e.x - 1][m->e.y] != 'F' && f[m->e.x + 1][m->e.y] != 'F')
		if (f[m->e.x][m->e.y + 1] != 'F' && f[m->e.x][m->e.y - 1] != 'F')
			return (0);
	while (i < m->c - 1)
	{
		pt = m->c_ar[i];
		if (f[pt.x - 1][pt.y] != 'F' && f[pt.x + 1][pt.y] != 'F')
			if (f[pt.x][pt.y + 1] != 'F' && f[pt.x][pt.y - 1] != 'F')
				return (0);
		i++;
	}
	return (1);

}

t_point	*create_collect(char **array, t_map map_data, int c)
{
	size_t		i;
	size_t		j;
	size_t		k;
	t_point		*collect;

	i = 0;
	k = 0;
	collect = malloc(sizeof(t_point) * (c + 1));
	while (i < (map_data).size.x)
	{
		j = ft_strspn(array[i], 'C');
		if (j != 0)
			collect[k++] = (t_point){i, j};
		i++;
	}
	return (collect);
}
