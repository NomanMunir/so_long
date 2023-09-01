
#include "so_long.h"

void	put_image(char c, int x, int y, t_data img)
{
	img.img = mlx_xpm_file_to_image(img.mlx_ptr, S_PATH, &img.w, &img.h);
	mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, \
	img.img, y * IMAGE_SIZE, x * IMAGE_SIZE);
	if (c == 'P')
		img.img = mlx_xpm_file_to_image(img.mlx_ptr, P_PATH, &img.w, &img.h);
	else if (c == '1')
		img.img = mlx_xpm_file_to_image(img.mlx_ptr, W_PATH, &img.w, &img.h);
	else if (c == 'C')
		img.img = mlx_xpm_file_to_image(img.mlx_ptr, C_PATH, &img.w, &img.h);
	else if (c == 'E')
		img.img = mlx_xpm_file_to_image(img.mlx_ptr, E_PATH, &img.w, &img.h);
	else
		img.img = mlx_xpm_file_to_image(img.mlx_ptr, S_PATH, &img.w, &img.h);
	if (!img.img)
		error_handling(10);
	mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, \
	img.img, y * IMAGE_SIZE, x * IMAGE_SIZE);
}

void	draw_map(t_data *img)
{
	int	i;
	int	j;

	i = -1;
	img->mlx_ptr = mlx_init();
	if (!img->mlx_ptr)
	{
		free(img->mlx_ptr);
		error_handling(0);
	}
	img->win_ptr = mlx_new_window(img->mlx_ptr, img->map.size.y * IMAGE_SIZE, \
	img->map.size.x * IMAGE_SIZE, "Princess");
	if (!img->win_ptr)
	{
		free(img->win_ptr);
		error_handling(0);
	}
	while (img->map.array[++i])
	{
		j = -1;
		while (img->map.array[i][++j])
			put_image(img->map.array[i][j], i, j, *img);
	}
}

int	check_move(t_data *img, int x, int y)
{
	if (img->map.s.y + x < img->map.size.y \
	&& img->map.s.x + y < img->map.size.x)
	{
		if (img->map.array[img->map.s.x + y][img->map.s.y] != '1' \
		&& img->map.array[img->map.s.x][img->map.s.y + x] != '1')
		{
			return (1);
		}
	}
	return (0);
}

void	check_end(t_data *img, int x, int y)
{
	if (img->map.array[img->map.s.x][img->map.s.y + x] == 'E' \
	|| img->map.array[img->map.s.x + y][img->map.s.y] == 'E')
	{
		if (img->cake == img->map.c)
		{
			ft_putstr_fd("You have completed the game in ", 2);
			ft_putnbr_fd(img->steps, 2);
			ft_putstr_fd(" steps!\n", 2);
			on_destroy(img);
		}
		else
			ft_putstr_fd("You need to collect all the cakes!\n", 2);
	}
}

void	move(t_data *img, int x, int y)
{
	if (check_move(img, x, y))
	{
		check_end(img, x, y);
		if (img->map.array[img->map.s.x][img->map.s.y + x] != 'E' && \
		img->map.array[img->map.s.x + y][img->map.s.y] != 'E')
		{
			put_image('0', img->map.s.x, img->map.s.y, *img);
			img->map.s.y += x;
			img->map.s.x += y;
			put_image('P', img->map.s.x, img->map.s.y, *img);
			img->steps++;
		}
		ft_putstr_fd("Steps: ", 2);
		ft_putnbr_fd(img->steps, 2);
		ft_putchar_fd('\n', 2);
		if (img->map.array[img->map.s.x][img->map.s.y] == 'C')
		{
			img->cake++;
			img->map.array[img->map.s.x][img->map.s.y] = '0';
		}
	}
}
