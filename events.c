
#include "so_long.h"

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	ft_putstr_fd("Window closed\n", 2);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_data *img)
{
	if (keycode == RIGHT)
		move(img, 1, 0);
	else if (keycode == LEFT)
		move(img, -1, 0);
	else if (keycode == UP)
		move(img, 0, 1);
	else if (keycode == DOWN)
		move(img, 0, -1);
	else if (keycode == ESC)
		on_destroy(img);
	return (0);
}

void	ft_event(t_data *img)
{
	img->cake = 0;
	img->steps = 0;
	mlx_hook(img->win_ptr, 2, 1L << 0, key_press, img);
	mlx_hook(img->win_ptr, 17, 0L, on_destroy, img);
	mlx_loop(img->mlx_ptr);
}
