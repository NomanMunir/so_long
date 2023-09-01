# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 15:18:50 by abashir           #+#    #+#              #
#    Updated: 2023/09/01 10:49:58 by nmunir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libsolong.a

SRC = 	get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		create_array.c \
		utils.c \
		is_map_valid.c \
		flood_fill.c \
		error.c \
		events.c \
		move.c \
		
OBJ = $(SRC:.c=.o)
ARC = libft/libft.a minilibx/libmlx.a
CC = cc

CFLAGS = #-Wall -Werror -Wextra
FFLAGS = -framework OpenGL -framework AppKit

all: $(NAME) libft minilibx
	$(CC) main.c $(CFLAGS) $(FFLAGS) $(ARC) $(NAME) -o so_long.out
	./so_long.out "maps/map.ber"

libft:
	cd libft && make

minilibx:
	cd minilibx && make
	
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJ)
	ar rcs $(NAME) $(OBJ) 

clean:
	rm -f -v $(OBJ) libft/*.o minilibx/*.o
	
fclean: clean
	rm -f $(NAME) libft/*.a minilibx/*.a

re: fclean all
	
.PHONY: all clean fclaen re libft minilibx