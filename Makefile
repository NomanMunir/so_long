# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abashir <abashir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 15:18:50 by abashir           #+#    #+#              #
#    Updated: 2023/08/10 15:23:24 by abashir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libsolong.a

get_next_line_src = "get_next_line/"

SRC = 	get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		parsing.c \
		

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

all:$(NAME)
	cc $(CFLAGS) parsing.c minilibx/libmlx.a $(NAME) -framework OpenGL -framework AppKit
	./a.out
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