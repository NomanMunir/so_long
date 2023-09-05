/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:50:01 by abashir           #+#    #+#             */
/*   Updated: 2023/08/10 09:58:54 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

void	ft_lstadd_back(t_list **lst, void *content, int fd);
char	*ft_strchr(t_list *list);
char	*ft_strdup(const char *s1);
void	ft_read_file(t_list **lst, int fd);
char	*ft_create_line(t_list *lst, size_t len);
void	ft_extra_line(t_list **lst, int fd, int *flag);
char	*get_next_line(int fd);
void	ft_lstclear(t_list **lst);
size_t	ft_count_ch(t_list *ptr);

#endif