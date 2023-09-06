/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:40:58 by abashir           #+#    #+#             */
/*   Updated: 2023/09/06 13:31:29 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_row(char *argv)
{
	char	*line;
	int		row;
	int		fd;

	row = 0;
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		row++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (row);
}

char	**fill_array(char *argv, t_map *map)
{
	int		i;
	char	*line;
	char	**array;
	int		fd;

	i = 0;
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n')
			return (ft_free_arr(map->array), free(line), NULL);
		array = ft_split(line, '\n');
		map->array[i] = array[0];
		free(array);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map->array[i] = NULL;
	close(fd);
	return (map->array);
}

char	**create_array(char *argv, t_map *map)
{
	int		i;

	i = 0;
	map->size.x = get_row(argv);
	map->array = malloc(sizeof(char *) * (map->size.x + 1));
	if (!map->array)
		error_handling(6);
	while (i < map->size.x + 1)
		map->array[i++] = NULL;
	if (!fill_array(argv, map))
		return (NULL);
	map->size.y = ft_strlen(map->array[0]);
	return (map->array);
}
