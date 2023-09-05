/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:38:05 by nmunir            #+#    #+#             */
/*   Updated: 2023/09/05 14:03:01 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strspn(const char *s, char c)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

void	ft_print_array(char **array, int row)
{
	for (int i = 0; i < row; i++)
		printf("%s\n", array[i]);
}

void	ft_free_arr(char **p)
{
	int	i;

	i = 0;
	while (p != NULL && p[i])
	{
		free(p[i]);
		i++;
	}
	if (p)
	{
		free(p);
		p = NULL;
	}
}
