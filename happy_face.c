/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:40:58 by abashir           #+#    #+#             */
/*   Updated: 2023/08/10 13:26:57 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "math.h"
#include <math.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int 	i;

	i  = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 800, "Hello world!");
	img.img = mlx_new_image(mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while (++i < 100)
		my_mlx_pixel_put(&img, 150 + i, 100, 0x00FF0000);
		i = 0;
	while (++i < 100)
		my_mlx_pixel_put(&img, 250, 100 + i, 0x00FF0000);
		i = 0;
	while (++i < 100)
		my_mlx_pixel_put(&img, 250 - i, 200, 0x00FF0000);
		i = 0;
	while (++i < 100)
		my_mlx_pixel_put(&img, 150, 200 - i, 0x00FF0000);
		i = 0;
	while (++i < 100)
		my_mlx_pixel_put(&img, 650 - i, 100, 0x00FF0000);
		i = 0;
	while (++i < 100)
		my_mlx_pixel_put(&img, 550, 100 + i, 0x00FF0000);
		i = 0;
	while (++i < 100)
		my_mlx_pixel_put(&img, 550 + i, 200, 0x00FF0000);
		i = 0;
	while (++i < 100)
		my_mlx_pixel_put(&img, 650, 200 - i, 0x00FF0000);
	i = 0;
	while (++i < 100)
		my_mlx_pixel_put(&img, 400 + i * 0.25, 200 + i * 0.75, 0x00FF0000);
	i = 0;
	while (++i < 100)
		my_mlx_pixel_put(&img, 400 - i * 0.25, 200 + i * 0.75, 0x00FF0000);		
	i = 0;
	while (++i < 100)
		my_mlx_pixel_put(&img, 400 - 25 + i * 0.5, 200 + 75, 0x00FF0000);
	i = 0;
	int r = 150;
	while (++i < 300)
		my_mlx_pixel_put(&img, 250 + i, sqrt(r*r - pow((250 + i - 400), 2)) + 300, 0x00FF0000);
			
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}