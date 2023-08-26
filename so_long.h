/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:12:52 by abashir           #+#    #+#             */
/*   Updated: 2023/08/26 16:36:00 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
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
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_map
{
	t_point			size;
	t_point			s;
	t_point			e;
	int				c;
	t_point			*c_ar;
}				t_map;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	flood_fill(char **tab, t_point size, t_point cur, char to_fill);
char	**ft_split(char const *s, char c);
int		is_map_rect(char **array, int row);
int		is_map_closed(char **array, t_map *map_data);
int		ft_counter(char **array, t_map *map_data, char ch);
int		check_count(char **array, t_map *map_data);
int		check_map(char **array, t_map *map_data);
int		ft_strl(char *str);
int		ft_strchr(char *s, char c);
t_point	*create_collect(char **array, t_map map_data, int c);
int		check_flood(char **array, t_map *m);
void	ft_putstr(char *s);

#endif
