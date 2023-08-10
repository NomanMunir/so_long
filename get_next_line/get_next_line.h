/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:26:06 by nmunir            #+#    #+#             */
/*   Updated: 2023/08/10 16:10:38 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# ifndef MAX_FD
#  define MAX_FD 1025
# endif

char	*get_next_line(int fd);
char	*ft_get_remaining_str(int fd, char *rem_str);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char *left_str, char *buff);
size_t	ft_strlen_gnl(char *s);
char	*ft_get_first_line(char *rem_str);
char	*ft_get_new_rem_str(char *rem_str);

#endif
