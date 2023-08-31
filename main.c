/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:01:26 by nmunir            #+#    #+#             */
/*   Updated: 2023/08/31 18:55:00 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map_data;
	t_data	img;

	ft_check_file(argc, argv);
	fd = open(argv[1], O_RDONLY);
	create_array(fd, &map_data);
	ft_print_array(map_data.array, map_data.size.x);
	close(fd);
	check_map(&map_data, argv[1]);
	img.map = map_data;
	draw_map(&img);
	ft_event(&img);
}
