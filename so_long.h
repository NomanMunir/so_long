/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:12:52 by abashir           #+#    #+#             */
/*   Updated: 2023/08/31 18:25:49 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "libft/libft.h"
# include <unistd.h>
# include "minilibx/mlx.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>

# define IMAGE_SIZE 42
# define P_PATH "./assets/princess.xpm"
# define W_PATH "./assets/wall.xpm"
# define C_PATH "./assets/cake.xpm"
# define E_PATH "./assets/exit.xpm"
# define S_PATH "./assets/sky.xpm"
# define ESC 53
# define UP 125
# define DOWN 126
# define LEFT 123
# define RIGHT 124

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
	char			**array;
}				t_map;

typedef struct s_data {
	void			*mlx_ptr;
	void			*win_ptr;
	int				h;
	int				w;
	int				cake;
	int				steps;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	struct s_map	map;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	flood_fill(char **tab, t_point size, t_point cur, char to_fill);
void	is_map_rect(t_map map);
void	is_map_closed(t_map map);
size_t	ft_counter(t_map *map_data, char ch);
void	check_count(t_map *map_data);
void	check_map(t_map *map_data, char *av);
size_t	ft_strspn(const char *s, char c);
void	create_collect(t_map *map_data, int c);
void	check_flood(t_map m, char *av);
void	ft_print_array(char **array, int row);
char	**create_array(int fd, t_map *m_data);
void	error_handling(int error);
void	check_array(t_map *map_data);
void	ft_check_file(int argc, char **argv);
int		key_press(int keycode, t_data *img);
void	ft_event(t_data *img);
int		on_destroy(t_data *data);
void	draw_map(t_data *img);
void	put_image(char c, int x, int y, t_data img);
void	move(t_data *img, int x, int y);

#endif
