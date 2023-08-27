/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:01:26 by nmunir            #+#    #+#             */
/*   Updated: 2023/08/27 15:47:41 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define KEY_ESC 53 // Key code for the ESC key

int close_window(void *param) {
    (void)param; // Suppress unused parameter warning
    printf("Window is closing...\n");
    exit(0);
}

int key_press(int keycode, void *param) {
    (void)param; // Suppress unused parameter warning

    if (keycode == KEY_ESC) {
        printf("ESC key pressed. Exiting...\n");
        exit(0);
    }

    printf("Key with code %d pressed.\n", keycode);
    return 0;
}

int	main(void)
{

	void *mlx;
    void *window;

    mlx = mlx_init();
    if (!mlx) {
        fprintf(stderr, "Error initializing MiniLibX\n");
        return 1;
    }

    window = mlx_new_window(mlx, 800, 600, "Keyboard Events Example");
    if (!window) {
        fprintf(stderr, "Error creating window\n");
        return 1;
    }

    mlx_hook(window, 2, 1L << 0, key_press, mlx);
    mlx_hook(window, 17, 1L << 17, close_window, mlx);

    mlx_loop(mlx);

	// int		fd;
	// int		row;
	// char	**array;
	// t_map	map_data;

	// row = 0;
	// fd = open("maps/42_map.ber", O_RDONLY);
	// array = create_array(fd, &row);
	// map_data.size.x = row;

	
	// check_map(array, &map_data);
	
	// // ft_print_array(array, row);
	// //printf("row: %d col: %d\n", row, col);
	// // for(int i = 0; i < row; i++)
	// // 	printf("%s\n", array[i]);
	// close(fd);
	return (0);
}