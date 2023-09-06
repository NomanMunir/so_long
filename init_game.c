/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:40:14 by abashir           #+#    #+#             */
/*   Updated: 2023/09/06 18:33:05 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	create_image_ptr(void *mlx, char *path)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx, path, &img.h, &img.w);
	return (img);
}

void	create_images(t_data *data)
{
	data->s_img = create_image_ptr(data->mlx_ptr, S_PATH);
	data->c_img = create_image_ptr(data->mlx_ptr, C_PATH);
	data->e_img = create_image_ptr(data->mlx_ptr, E_PATH);
	data->w_img = create_image_ptr(data->mlx_ptr, W_PATH);
	data->p_img = create_image_ptr(data->mlx_ptr, P_PATH);
	if (!data->s_img.img || !data->c_img.img || !data->e_img.img || \
	!data->w_img.img || !data->p_img.img)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		imgs_destroy(data);
		error_handling_free(9, data->map.array);
	}
}

void	put_image(char c, int x, int y, t_data data)
{
	if (c == 'P')
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, \
		data.p_img.img, y * IMAGE_SIZE, x * IMAGE_SIZE);
	else if (c == 'C')
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, \
		data.c_img.img, y * IMAGE_SIZE, x * IMAGE_SIZE);
	else if (c == 'E')
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, \
		data.e_img.img, y * IMAGE_SIZE, x * IMAGE_SIZE);
	else if (c == '1')
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, \
		data.w_img.img, y * IMAGE_SIZE, x * IMAGE_SIZE);
	else if (c == '0')
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, \
		data.s_img.img, y * IMAGE_SIZE, x * IMAGE_SIZE);
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map.array[++i])
	{
		j = -1;
		while (data->map.array[i][++j])
		{
			put_image('0', i, j, *data);
			put_image(data->map.array[i][j], i, j, *data);
		}
	}
}

void	init_game(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		free(data->mlx_ptr);
		error_handling_free(8, data->map.array);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
	data->map.size.y * IMAGE_SIZE, \
	data->map.size.x * IMAGE_SIZE, "so_long");
	if (!data->win_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		error_handling_free(8, data->map.array);
	}
	create_images(data);
	draw_map(data);
}
