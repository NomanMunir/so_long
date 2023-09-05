/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:01:26 by nmunir            #+#    #+#             */
/*   Updated: 2023/09/05 14:42:13 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map_data;
	t_data	img;

	ft_check_file(argc, argv);
	create_array(argv[1], &map_data);
	if (create_array(argv[1], &map_data) == NULL)
		error_handling(11);
	check_map(&map_data, argv[1]);
	ft_print_array(map_data.array, map_data.size.x);
	img.map = map_data;
	init_game(&img);
	ft_event(&img);
}
