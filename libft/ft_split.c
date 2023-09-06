/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:47:38 by abashir           #+#    #+#             */
/*   Updated: 2023/07/19 10:54:58 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
