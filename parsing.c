/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:40:58 by abashir           #+#    #+#             */
/*   Updated: 2023/08/10 16:45:19 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool is_map_rect(int fd)
{
	char 	*line;
	size_t 	line_length;
	line = get_next_line(fd);
	line_length = ft_strlen_gnl(line);
	while (line)
	{
		line = get_next_line(fd);
		if (line && (ft_strlen_gnl(line) != line_length))
		{
			line = get_next_line(fd);
			if (line)
			{
				printf("Non-Rectangular Map");
				return (false);
			}
		}
		free(line);
	}
	return (true);
}

bool is_closed_rect(int fd)
{
	
}

int	main(void)
{
	int fd = open("42_map.ber", O_RDONLY);
	is_map_rect(fd);
	close(fd);
	return (0);
}