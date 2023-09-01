/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:01:26 by nmunir            #+#    #+#             */
/*   Updated: 2023/09/01 10:46:11 by nmunir           ###   ########.fr       */
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
	close(fd);
	check_map(&map_data, argv[1]);
	img.map = map_data;
	draw_map(&img);
	ft_event(&img);
}
