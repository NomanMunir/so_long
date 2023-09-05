/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:27:49 by abashir           #+#    #+#             */
/*   Updated: 2023/08/10 11:13:27 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_read_file(t_list **lst, int fd)
{
	int		bytes;
	char	*buff;

	buff = malloc(sizeof(char) * ((long)BUFFER_SIZE + 1));
	if (buff == NULL)
		return ;
	bytes = 0;
	while (!ft_strchr(lst[fd]))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buff[bytes] = '\0';
		ft_lstadd_back(lst, ft_strdup(buff), fd);
		if (lst == NULL)
			break ;
	}
	free(buff);
}

char	*ft_create_line(t_list *ptr, size_t len)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	str = malloc(sizeof(char) *(len + 2));
	if (str == NULL)
		return (NULL);
	while (ptr != NULL)
	{
		i = 0;
		while (ptr->content[i] && ptr->content[i] != '\n')
			str[j++] = ptr->content[i++];
		if (ptr->content[i] == '\n')
			str[j] = '\n';
		ptr = ptr->next;
	}
	str[len + 1] = '\0';
	return (str);
}

void	ft_extra_line(t_list **lst, int fd, int *flag)
{
	char	*extra;
	size_t	len;
	char	*s;

	len = 0;
	extra = NULL;
	if (ft_strchr(lst[fd]))
	{
		s = ft_strchr(lst[fd]);
		while (s[len])
			len++;
	}
	if (len > 1)
		extra = ft_strdup(s + 1);
	ft_lstclear(&lst[fd]);
	if (extra)
		ft_lstadd_back(lst, ft_strdup(extra), fd);
	if ((extra == NULL && len > 1) || (!lst && extra))
		*flag = 1;
	free(extra);
}

char	*get_next_line(int fd)
{
	static t_list	*lst[1024];
	char			*res;
	int				flag;

	flag = 0;
	res = NULL;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || read(fd, res, 0))
	{
		ft_lstclear(&lst[fd]);
		return (NULL);
	}
	ft_read_file(lst, fd);
	if (lst[fd] == NULL)
		return (NULL);
	res = ft_create_line(lst[fd], ft_count_ch(lst[fd]));
	if (res == NULL)
		return (NULL);
	ft_extra_line(lst, fd, &flag);
	if (flag == 1)
		return (NULL);
	return (res);
}

// #include <stdio.h>
// #include <fcntl.h>

// int	main(void)
// {
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	int		fd4;
// 	int		fd5;
// 	char	*str;
// 	int		i;

// 	i = 0;
// 	fd1 = open("text.txt", O_RDONLY);
// 	fd2 = open("text1.txt", O_RDONLY);
// 	fd3 = open("lorem.txt", O_RDONLY);
// 	fd4 = open("alice.txt", O_RDONLY);
// 	fd5 = 42;
// 	int order[] = {fd1, fd2, fd1, fd4, fd3, fd5};

// 	while (i < 6)
// 	{
// 		str = get_next_line(order[i]);
// 		printf("%s", str);
// 		free(str);
// 		i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	close(fd4);
// 	close(fd5);
// }
