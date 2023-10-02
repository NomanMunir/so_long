/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:01:26 by nmunir            #+#    #+#             */
/*   Updated: 2023/09/06 16:41:25 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map_data;
	t_data	data;

	ft_check_files(argc, argv);
	if (!create_array(argv[1], &map_data))
		error_handling(2);
	check_map(&map_data, argv[1]);
	data.map = map_data;
	init_game(&data);
	ft_event(&data);
	return (0);
}
