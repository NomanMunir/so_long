/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:01:26 by nmunir            #+#    #+#             */
/*   Updated: 2023/08/28 19:07:30 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define KEY_ESC 53
// int on_destroy(t_var *data)
// {
// 	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// 	mlx_destroy_display(data->mlx_ptr);
// 	free(data->mlx_ptr);
// 	exit(0);
// 	return (0);
// }
 
int key_press(int keycode, t_data *img) {

    if (keycode == 124)
        {

        }
    printf("Key pressed: %d\n", keycode);
    return 0;
}

void    put_image(char c, int x, int y, t_data img)
{
	int		img_width;
	int		img_height;

    if (c == 'P')
        img.img	= mlx_xpm_file_to_image(img.mlx_ptr, "./assets/princess.xpm", &img_width, &img_height);
    else if (c == '1')
        img.img	= mlx_xpm_file_to_image(img.mlx_ptr, "./assets/wall.xpm", &img_width, &img_height);
    else if (c == 'C')
        img.img	= mlx_xpm_file_to_image(img.mlx_ptr, "./assets/cake.xpm", &img_width, &img_height);
    else if (c == 'E')
        img.img	= mlx_xpm_file_to_image(img.mlx_ptr, "./assets/exit.xpm", &img_width, &img_height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	&img.endian);
	mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.img, y * 42, x * 42);    
}
int	main(void)
{
    int		fd;
	char	**array;
	t_map	map_data;

	fd = open("maps/42_map.ber", O_RDONLY);
	array = create_array(fd, &map_data);
	check_map(array, &map_data);
	ft_print_array(array, map_data.size.x);
    
	t_data	img;
	int		img_width;
	int		img_height;
    int i = 0;
    int j = 0;
    img.mlx_ptr = mlx_init();
    img.win_ptr = mlx_new_window(img.mlx_ptr, map_data.size.y * 42, map_data.size.x * 42, "Hello world!");
    while (array[i])
    {
        j = 0;
        while (array[i][j])
        {
            img.img	= mlx_xpm_file_to_image(img.mlx_ptr, "./assets/sky.xpm", &img_width, &img_height);
	        img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	        &img.endian);
	        mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.img, j * 42, i * 42);
            put_image(array[i][j], i, j, img);
            j++;
        }
        i++;        
    }
    img.s = map_data.s;
    mlx_hook(img.win_ptr, 2, 1L << 0, key_press, &img);
	mlx_loop(img.mlx_ptr);
}

	// int		fd;
	// char	**array;
	// t_map	map_data;

	// fd = open("maps/42_map.ber", O_RDONLY);
	// array = create_array(fd, &map_data);


	// check_map(array, &map_data);
    
	//  printf("row: %d col: %d\n", row, col);
	// close(fd);
// 	return (0);
// }