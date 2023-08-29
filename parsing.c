/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:40:58 by abashir           #+#    #+#             */
/*   Updated: 2023/08/29 16:21:22 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


char	**create_array(int fd, t_map *m_data)
{
	const char	*line;
	const char	*line_sec;
	char		**array;
	size_t		row;

	row = 0;
	line = get_next_line(fd);
	
	while (line)
	{
		row++;
		line_sec = get_next_line(fd);
		if (line_sec)
			line = ft_strjoin(line, line_sec);
		else
			break ;
	}
	array = ft_split(line, '\n');
	m_data->size.x = row;
	m_data->size.y = ft_strlen(array[0]);
	m_data->array = array;
	return (array);
}
