/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:12:52 by abashir           #+#    #+#             */
/*   Updated: 2023/09/06 15:25:45 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include "get_next_line/get_next_line.h"

# define P_PATH "./assets/player.xpm"
# define W_PATH "./assets/cloud.xpm"
# define C_PATH "./assets/cake.xpm"
# define E_PATH "./assets/exit.xpm"
# define S_PATH "./assets/sky.xpm"

# define IMAGE_SIZE 42
# define ESC 		53
# define UP 		126
# define DOWN 		125
# define LEFT 		123
# define RIGHT 		124

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_map
{
	t_point			size;
	t_point			s;
	t_point			e;
	int				c;
	t_point			*c_ar;
	char			**array;
}				t_map;

typedef struct s_img
{
	void			*img;
	int				w;
	int				h;	
}				t_img;				

typedef struct s_data {
	void			*mlx_ptr;
	void			*win_ptr;
	int				steps;
	t_img			s_img;
	t_img			e_img;
	t_img			w_img;
	t_img			p_img;
	t_img			c_img;
	struct s_map	map;
}				t_data;

void	ft_check_files(int argc, char **argv);
int		get_row(char *argv);
char	**create_array(char *argv, t_map *game);
char	**fill_array(char *argv, t_map *map);
void	check_map(t_map *map_data, char *av);
void	is_map_rect(t_map *map);
void	is_map_closed(t_map *map);
int		ft_counter(t_map *map_data, char ch);
void	check_count(t_map *map_data);
void	create_collect(t_map *map_data);
void	check_array(t_map *map_data);
void	check_flood(t_map *m, char *av);
void	flood_fill(char **tab, t_point cur);
void	init_game(t_data *img);
void	create_images(t_data *img);
t_img	create_image_ptr(void *mlx, char *path);
void	put_image(char c, int x, int y, t_data img);
void	draw_map(t_data *img);
int		key_press(int keycode, t_data *img);
void	ft_event(t_data *img);
void	move(t_data *img, int x, int y);
int		on_destroy(t_data *data);
void	imgs_destroy(t_data	*img);
void	ft_free_arr(char **p);
int		ft_strspn(const char *s, char c);
int		ft_position(const char *s, int c);
void	ft_print_array(char **array, int row);
void	error_handling(int error);
void	error_handling_free(int error, char **map);

#endif
