/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:02:12 by abashir           #+#    #+#             */
/*   Updated: 2023/09/05 12:39:27 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (img->map.array[img->map.s.x + y][img->map.s.y + x] == 'E')
	{
		if (img->map.c == 0)
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
		if (img->map.array[img->map.s.x + y][img->map.s.y + x] != 'E')
		{
			mlx_clear_window(img->mlx_ptr, img->win_ptr);
			img->map.array[img->map.s.x][img->map.s.y] = '0';
			img->map.s.y += x;
			img->map.s.x += y;
			if (img->map.array[img->map.s.x][img->map.s.y] == 'C')
				img->map.c--;
			img->map.array[img->map.s.x][img->map.s.y] = 'P';
			draw_map(img);
			img->steps++;
		}
		ft_putstr_fd("Steps: ", 2);
		ft_putnbr_fd(img->steps, 2);
		ft_putchar_fd('\n', 2);
	}
}
