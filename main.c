/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:01:26 by nmunir            #+#    #+#             */
/*   Updated: 2023/08/29 16:21:39 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	printf("Window closed\n");
	exit(0);
	return (0);
}
 void    put_image(char c, int x, int y, t_data img)
{
	img.img	= mlx_xpm_file_to_image(img.mlx_ptr, "./assets/sky.xpm", &img.width, &img.height);
	mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.img, y * 42, x * 42);
	if (c == 'P')
		img.img	= mlx_xpm_file_to_image(img.mlx_ptr, "./assets/princess.xpm", &img.width, &img.height);
	else if (c == '1')
		img.img	= mlx_xpm_file_to_image(img.mlx_ptr, "./assets/wall.xpm", &img.width, &img.height);
	else if (c == 'C')
		img.img	= mlx_xpm_file_to_image(img.mlx_ptr, "./assets/cake.xpm", &img.width, &img.height);
	else if (c == 'E')
		img.img	= mlx_xpm_file_to_image(img.mlx_ptr, "./assets/exit.xpm", &img.width, &img.height);
	else
		img.img	= mlx_xpm_file_to_image(img.mlx_ptr, "./assets/sky.xpm", &img.width, &img.height);
	mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.img, y * 42, x * 42);
}

int	render(t_data *img)
{
	int i = -1;
	int j;
	img->mlx_ptr = mlx_init();
	img->win_ptr = mlx_new_window(img->mlx_ptr, img->map.size.y * 42, img->map.size.x * 42, "Princess!!!!!");
	while (img->map.array[++i])
	{
		j = -1;
		while (img->map.array[i][++j])
			put_image(img->map.array[i][j], i, j, *img);
	}
	return (0);
}
static void right(t_data *img)
{
	if (img->map.s.y + 1 < img->map.size.y && img->map.array[img->map.s.x][img->map.s.y + 1] != '1')
	{
		if (img->map.array[img->map.s.x][img->map.s.y + 1] == 'E')
		{
			if (img->cake == img->map.c)
			{
				printf("You have completed the game in %d steps!\n", img->steps);
				on_destroy(img);
			}
			else
				printf("You need to collect all the cupcakes before exiting!\n");
		}
		if (img->map.array[img->map.s.x][img->map.s.y + 1] != 'E')
		{
			put_image('0', img->map.s.x, img->map.s.y++, *img);
			put_image('P', img->map.s.x, img->map.s.y, *img);
			img->steps++;
		}
		printf("Steps: %d\n", img->steps);
		if (img->map.array[img->map.s.x][img->map.s.y] == 'C')
		{
			img->cake++;
			img->map.array[img->map.s.x][img->map.s.y] = '0';
		}
	}
}
static void left(t_data *img)
{
	if (img->map.s.y - 1 < img->map.size.y && img->map.array[img->map.s.x][img->map.s.y - 1] != '1')
	{
		if (img->map.array[img->map.s.x][img->map.s.y - 1] == 'E')
		{
			if (img->cake == img->map.c)
			{
				printf("You have completed the game in %d steps!\n", img->steps);
				on_destroy(img);
			}
			else
				printf("You need to collect all the cupcakes before exiting!\n");
		}
		if (img->map.array[img->map.s.x][img->map.s.y - 1] != 'E')
		{
			put_image('0', img->map.s.x, img->map.s.y--, *img);
			put_image('P', img->map.s.x, img->map.s.y, *img);
			img->steps++;
		}
		printf("Steps: %d\n", img->steps);
		if (img->map.array[img->map.s.x][img->map.s.y] == 'C')
		{
			img->cake++;
			img->map.array[img->map.s.x][img->map.s.y] = '0';
		}
	}
}
static void up(t_data *img)
{
	if (img->map.s.x + 1 < img->map.size.x && img->map.array[img->map.s.x + 1][img->map.s.y] != '1')
	{
		if (img->map.array[img->map.s.x + 1][img->map.s.y] == 'E')
		{
			if (img->cake == img->map.c)
			{
				printf("You have completed the game in %d steps!\n", img->steps);
				on_destroy(img);
			}
			else
				printf("You need to collect all the cupcakes before exiting!\n");
		}
		if (img->map.array[img->map.s.x + 1][img->map.s.y] != 'E')
		{
			put_image('0', img->map.s.x++, img->map.s.y, *img);
			put_image('P', img->map.s.x, img->map.s.y, *img);
			img->steps++;
		}
		printf("Steps: %d\n", img->steps);
		if (img->map.array[img->map.s.x][img->map.s.y] == 'C')
		{
			img->cake++;
			img->map.array[img->map.s.x][img->map.s.y] = '0';
		}
	}
}
static void down(t_data *img)
{
	if (img->map.s.x - 1 < img->map.size.x && img->map.array[img->map.s.x - 1][img->map.s.y] != '1')
	{
		if (img->map.array[img->map.s.x - 1][img->map.s.y] == 'E')
		{
			if (img->cake == img->map.c)
			{
				printf("You have completed the game in %d steps!\n", img->steps);
				on_destroy(img);
			}
			else
				printf("You need to collect all the cupcakes before exiting!\n");
		}
		if (img->map.array[img->map.s.x - 1][img->map.s.y] != 'E')
		{
			put_image('0', img->map.s.x--, img->map.s.y, *img);
			put_image('P', img->map.s.x, img->map.s.y, *img);
			img->steps++;
		}
		printf("Steps: %d\n", img->steps);
		if (img->map.array[img->map.s.x][img->map.s.y] == 'C')
		{
			img->cake++;
			img->map.array[img->map.s.x][img->map.s.y] = '0';
		}
	}
}
int key_press(int keycode, t_data *img) 
{
	if (keycode == 124)
		right(img);
	else if (keycode == 123)
		left(img);
	else if (keycode == 125)
		up(img);
	else if (keycode == 126)
		down(img);
	else if (keycode == 53)
		on_destroy(img);
	return 0;
}
void ft_event(t_data *img)
{
	mlx_hook(img->win_ptr, 2, 1L << 0, key_press, img);
	mlx_hook(img->win_ptr, 17, 0L, on_destroy, img);
	mlx_loop(img->mlx_ptr);
}

int ft_check_file(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\nWrong number of arguments\n", 2);
		return (0);
	}
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
	{
		ft_putstr_fd("Error\nWrong file extension\n", 2);
		return (0);
	}
	return (1);
}
int	main(int argc, char **argv)
{
	int		fd;
	t_map	map_data;
	if (!ft_check_file(argc, argv))
		exit(1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nFile not found\n", 2);
		exit(1);
	}
	create_array(fd, &map_data);
	ft_print_array(map_data.array, map_data.size.x);
	if (check_map(&map_data) == 0)
		exit(1);
	
	t_data	img;
	img.map = map_data;
	render(&img);
	img.cake = 0;
	img.steps = 0;
	ft_event(&img);
}
