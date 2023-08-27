/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:40:58 by abashir           #+#    #+#             */
/*   Updated: 2023/08/27 14:58:43 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_array(int fd, int *row)
{
	const char	*line;
	const char	*line_sec;
	char		**array;

	line = get_next_line(fd);
	while (line)
	{
		*row = *row + 1;
		line_sec = get_next_line(fd);
		if (line_sec)
			line = ft_strjoin(line, line_sec);
		else
			break ;
	}
	array = ft_split(line, '\n');
	return (array);
}
