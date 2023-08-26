# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abashir <abashir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 15:18:50 by abashir           #+#    #+#              #
#    Updated: 2023/08/26 16:29:43 by abashir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libsolong.a

SRC = 	get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

all:$(NAME)
	cc $(CFLAGS) parsing.c flood_fill.c ft_split.c is_map_valid.c utils.c minilibx/libmlx.a $(NAME) -framework OpenGL -framework AppKit && ./a.out
	
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(BOBJ)
	ar rcs $(NAME) $(BOBJ) $(OBJ) 

clean:
	rm -f $(OBJ) $(BOBJ)
	
fclean: clean
	rm -f $(NAME)

re: fclean all
	
.PHONY: all clean fclaen re