/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:02:12 by abashir           #+#    #+#             */
/*   Updated: 2023/09/06 18:40:03 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_end(t_data *data)
{
	if (data->map.c == 0)
	{
		ft_putstr_fd("You have completed the game in ", 2);
		ft_putnbr_fd(data->steps, 2);
		ft_putstr_fd(" steps!\n", 2);
		on_destroy(data);
	}
	else
		ft_putstr_fd("You need to collect all the cakes!\n", 2);
}

void	move(t_data *data, int x, int y)
{
	if (data->map.array[data->map.s.x + y][data->map.s.y + x] != '1')
	{
		if (data->map.array[data->map.s.x + y][data->map.s.y + x] == 'E')
			check_end(data);
		else
		{
			data->map.array[data->map.s.x][data->map.s.y] = '0';
			data->map.s.y += x;
			data->map.s.x += y;
			if (data->map.array[data->map.s.x][data->map.s.y] == 'C')
				data->map.c--;
			data->map.array[data->map.s.x][data->map.s.y] = 'P';
			mlx_clear_window(data->mlx_ptr, data->win_ptr);
			draw_map(data);
			data->steps++;
			ft_putstr_fd("Steps: ", 2);
			ft_putnbr_fd(data->steps, 2);
			ft_putchar_fd('\n', 2);
		}
	}
}
