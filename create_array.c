/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:40:58 by abashir           #+#    #+#             */
/*   Updated: 2023/08/31 19:10:26 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_array(t_map *map_data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map_data->size.x)
	{
		j = 0;
		while (j < map_data->size.y)
		{
			if (map_data->array[i][j] != '0' && map_data->array[i][j] != '1' && \
			map_data->array[i][j] != 'C' && map_data->array[i][j] != 'E' && \
			map_data->array[i][j] != 'P')
				error_handling(3);
			j++;
		}
		i++;
	}
}

char	*get_valid_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		line = ft_strtrim(line, " \t\v\f\r\n");
		if (line[0] == '\0')
			line = get_next_line(fd);
		else
		{
			line = ft_strjoin(line, "\n");
			return (line);
		}
	}
	return (NULL);
}

char	**create_array(int fd, t_map *m_data)
{
	const char	*line;
	const char	*line_sec;
	char		**array;
	size_t		row;

	row = 1;
	line = get_valid_line(fd);
	line_sec = get_valid_line(fd);
	while (line && line_sec)
	{
		row++;
		line = ft_strjoin(line, line_sec);
		line_sec = get_valid_line(fd);
	}
	array = ft_split(line, '\n');
	m_data->size.x = row;
	m_data->size.y = ft_strlen(array[0]);
	m_data->array = array;
	return (array);
}
