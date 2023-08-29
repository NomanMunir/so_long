/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:12:52 by abashir           #+#    #+#             */
/*   Updated: 2023/08/29 13:23:58 by nmunir           ###   ########.fr       */
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
	char 			**array;
}				t_map;

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
	int		cake;
	int		steps;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	struct s_map	map;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	flood_fill(char **tab, t_point size, t_point cur, char to_fill);
bool	is_map_rect(t_map map);
bool	is_map_closed(t_map map);
size_t	ft_counter(t_map *map_data, char ch);
size_t	check_count(t_map *map_data);
size_t	check_map(t_map *map_data);
size_t	ft_strspn(const char *s, char c);
void	create_collect(t_map *map_data, int c);
int		check_flood(t_map m);
void	ft_print_array(char **array, int row);
char	**create_array(int fd, t_map *m_data);

#endif
