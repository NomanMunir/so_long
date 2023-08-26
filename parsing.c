/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:40:58 by abashir           #+#    #+#             */
/*   Updated: 2023/08/26 16:34:00 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_array(int fd, int *row)
{
	char	*line;
	char	*line_sec;
	char	**array;

	line = get_next_line(fd);
	while (line)
	{
		*row = *row + 1;
		line_sec = get_next_line(fd);
		if (line_sec)
			line = ft_strjoin_gnl(line, line_sec);
		else
			break ;
	}
	array = ft_split(line, '\n');
	return (array);
}

int	main(void)
{
	int		fd;
	int		row;
	char	**array;
	t_map	map_data;

	row = 0;
	fd = open("maps/42_map.ber", O_RDONLY);
	array = create_array(fd, &row);
	map_data.size.x = row;
	// ft_print_array(array, row);
	check_map(array, &map_data);

	//printf("row: %d col: %d\n", row, col);
	// for(int i = 0; i < row; i++)
	// 	printf("%s\n", array[i]);
	close(fd);
	return (0);
}