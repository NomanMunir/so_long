/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:40:58 by abashir           #+#    #+#             */
/*   Updated: 2023/08/25 20:01:25 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	n_word(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			j++;
		}
	}
	return (j);
}

static int	n_chr(char const *s, char c, int start)
{
	int	i;

	i = 0;
	while (s[start] == c)
		start++;
	while (s[start] != '\0' && s[start] != c)
	{
		start++;
		i++;
	}
	return (i);
}

static int	ft_fill(char const *s, char *res, int i, char c)
{
	int	k;

	k = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		res[k] = s[i];
		k++;
		i++;
	}
	res[k] = '\0';
	i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		n_w;
	int		i;
	int		j;
	char	**res;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	n_w = n_word(s, c);
	res = (char **)malloc(sizeof(char *) * (n_w + 1));
	if (res == NULL)
		return (NULL);
	while (j < n_w)
	{
		res[j] = malloc(sizeof(char) * (n_chr(s, c, i) + 1));
		i = ft_fill(s, res[j], i, c);
		j++;
	}
	res[j] = NULL;
	return (res);
}

int ft_strl(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int is_map_rect(char **array, int row)
{
	int		i = 1;
	while (i < row)
	{
		if (ft_strl(array[i]) != ft_strl(array[i - 1]))
			return (0);
		i++;
	}
	return (1);
}
int is_map_closed(char **array, int row, int col)
{
	int i = 0;
	int j;
	while (i < row)
	{
		j = 0;
		if (array[i][0] != '1' || array[i][col - 1] != '1')
			return (0);
		if (i == 0 || i == row - 1)
		{
			while (array[i][j])
			{
				if (array[i][j] != '1')
					return (0);
				j++;
			}
		}
		i++;
	}
	return (1);
}
int	main(void)
{
	int fd = open("42_map.ber", O_RDONLY);
	char *line;
	line = get_next_line(fd);
	char *line_sec;
	char row = 0;
	int col = 0;
	while (line)
	{
		row++;
		line_sec =  get_next_line(fd);
		if (line_sec)
			line  = ft_strjoin_gnl(line ,line_sec);
		else
			break;
	}	
	char **res = ft_split(line, '\n');
	for (int i = 0; i < row; i++)
		printf("%s\n", res[i]);
	col = ft_strl(res[0]);
	printf("is enclosed %d\n", is_map_closed(res, row, col));
	printf("row: %d col: %d %d", row, col, 	is_map_rect(res, row));
	close(fd);
	return (0);
}