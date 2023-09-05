/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:36:47 by abashir           #+#    #+#             */
/*   Updated: 2023/09/05 15:04:30 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_handling(int error)
{
	printf("Error\n %d", error);
	ft_putstr_fd("Error\n", 2);
	if (error == 1)
		ft_putstr_fd("The map is not rectangular\n", 2);
	if (error == 2)
		ft_putstr_fd("The map is not enclosed\n", 2);
	if (error == 3)
		ft_putstr_fd("Wrong character in map\n", 2);
	if (error == 4)
		ft_putstr_fd("Wrong number of arguments\n", 2);
	if (error == 5)
		ft_putstr_fd("Wrong file extension\n", 2);
	if (error == 6)
		ft_putstr_fd("File(s) not found\n", 2);
	if (error == 7)
		ft_putstr_fd("Invalid map dimensions\n", 2);
	if (error == 8)
		ft_putstr_fd("Map has invalid no. of exit/collectible or start\n", 2);
	if (error == 9)
		ft_putstr_fd("Player can't reach collectible/exit\n", 2);
	if (error == 10)
		ft_putstr_fd("File(s) empty/not found or corrupted\n", 2);
	if (error == 11)
		ft_putstr_fd("Map is not valid\n", 2);
	exit(1);
}

void	error_handling_free(int error, char **map)
{
	ft_free_arr(map);
	error_handling(error);
}

int	open_file(char *path)
{
	int		fd;
	char	*buf;

	fd = open(path, O_RDONLY);
	if (fd < 0 || read(fd, &buf, 1) < 1)
		error_handling(10);
	close(fd);
	return (fd);
}

void	ft_check_file(int argc, char **argv)
{
	if (argc != 2)
		error_handling(4);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
		error_handling(5);
	open_file(argv[1]);
	open_file(P_PATH);
	open_file(E_PATH);
	open_file(C_PATH);
	open_file(W_PATH);
	open_file(S_PATH);
}
