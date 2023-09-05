/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:40:58 by abashir           #+#    #+#             */
/*   Updated: 2023/09/05 14:37:47 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_array(t_map *map_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_data->size.x)
	{
		j = 0;
		while (j < map_data->size.y)
		{
			if (map_data->array[i][j] != '0' && map_data->array[i][j] != '1' && \
			map_data->array[i][j] != 'C' && map_data->array[i][j] != 'E' && \
			map_data->array[i][j] != 'P')
				error_handling_free(3, map_data->array);
			j++;
		}
		i++;
	}
}

// char	*get_valid_line(int fd)
// {
// 	char	*line;

// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		line = ft_strtrim(line, " \t\v\f\r\n");
// 		if (line[0] == '\0')
// 			line = get_next_line(fd);
// 		else
// 		{
// 			line = ft_strjoin(line, "\n");
// 			return (line);
// 		}
// 	}
// 	return (NULL);
// }

// char	**create_array(int fd, t_map *m_data)
// {
// 	const char	*line;
// 	const char	*line_sec;
// 	char		**array;
// 	size_t		row;

// 	row = 1;
// 	line = get_valid_line(fd);
// 	line_sec = get_valid_line(fd);
// 	while (line && line_sec)
// 	{
// 		row++;
// 		line = ft_strjoin(line, line_sec);
// 		line_sec = get_valid_line(fd);
// 	}
// 	array = ft_split(line, '\n');
// 	m_data->size.x = row;
// 	m_data->size.y = ft_strlen(array[0]);
// 	m_data->array = array;
// 	return (array);
// }

int		get_row(char *argv)
{
	char	*line;
	int		row;
	int fd = open(argv, O_RDONLY);
	row = 0;
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

int	str_compare_fn(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	**create_array(char *argv, t_map *game)
{
	char	*line;
	int		row;
	int		i;
	int		j;
	char 	**array;
	int		fd;

	i = 0;
	j = 0;
	row = get_row(argv);

	fd = open(argv, O_RDONLY);
	game->size.x = row;
	game->array = malloc(sizeof(char *) * (game->size.x + 1));
	while (j < row + 1)
		game->array[j++] = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (str_compare_fn("\n", line) == 0)
			return (ft_free_arr(game->array), free(line), NULL);
		array = ft_split(line, '\n');
		game->array[i] = array[0];
		free(array);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	game->array[i] = NULL;
	close(fd);
	game->size.y = ft_strlen(game->array[0]);
	return (game->array);
}
