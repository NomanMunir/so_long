# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 15:18:50 by abashir           #+#    #+#              #
#    Updated: 2023/08/27 15:40:20 by nmunir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libsolong.a

SRC = 	get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		parsing.c \
		utils.c \
		is_map_valid.c \
		flood_fill.c \
		

OBJ = $(SRC:.c=.o)
ARC = libft/libft.a minilibx/libmlx.a
CC = cc

CFLAGS = -Wall -Werror #-Wextra
FFLAGS = -framework OpenGL -framework AppKit

all:$(NAME) libft
	$(CC) main.c $(CFLAGS) $(FFLAGS) $(ARC) $(NAME)
	./a.out
	
libft:
	cd libft && $(make)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJ)
	ar rcs $(NAME) $(OBJ) 

clean:
	rm -f -v $(OBJ) libft/*.o
	
fclean: clean
	rm -f $(NAME) libft/*.a

re: fclean all
	
.PHONY: all clean fclaen re