/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:12:52 by abashir           #+#    #+#             */
/*   Updated: 2023/08/28 12:18:11 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "libft/libft.h"
# include <unistd.h>
# include <math.h>
# include "minilibx/mlx.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	size_t	bits_per_pixel;
	size_t	line_length;
	size_t	endian;
}				t_data;

typedef struct s_point
{
	size_t		x;
	size_t		y;
}				t_point;

typedef struct s_map
{
	t_point			size;
	t_point			s;
	t_point			e;
	size_t			c;
	t_point			*c_ar;
}				t_map;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	flood_fill(char **tab, t_point size, t_point cur, char to_fill);
bool	is_map_rect(char **array, size_t row);
bool	is_map_closed(char **array, t_map *map_data);
size_t	ft_counter(char **array, t_map *map_data, char ch);
size_t	check_count(char **array, t_map *map_data);
size_t	check_map(char **array, t_map *map_data);
size_t	ft_strspn(const char *s, char c);
t_point	*create_collect(char **array, t_map map_data, int c);
int		check_flood(char **array, t_map *m);
void	ft_print_array(char **array, int row);
char	**create_array(int fd, t_map *m_data);

#endif
