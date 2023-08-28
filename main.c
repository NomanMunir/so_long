/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:01:26 by nmunir            #+#    #+#             */
/*   Updated: 2023/08/28 12:47:59 by nmunir           ###   ########.fr       */
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

int main() {
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
    return 0;
}
	// int		fd;
	// char	**array;
	// t_map	map_data;

	// fd = open("maps/42_map.ber", O_RDONLY);
	// array = create_array(fd, &map_data);


	// check_map(array, &map_data);
	// ft_print_array(array, map_data.size.x);
    
	//  printf("row: %d col: %d\n", row, col);
	// close(fd);
// 	return (0);
// }