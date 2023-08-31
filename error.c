
#include "so_long.h"

void	error_handling(int error)
{
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
		ft_putstr_fd("Invalid map dimensions", 2);
	if (error == 8)
		ft_putstr_fd("Map contain invalid no. of exit/collectible or start", 2);
	if (error == 9)
		ft_putstr_fd("Player can't reach collectible/exit", 2);
	if (error == 10)
		ft_putstr_fd("File(s) empty", 2);
	exit(1);
}

void	ft_check_file(int argc, char **argv)
{
	char	*buf;

	if (argc != 2)
		error_handling(4);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
		error_handling(5);
	if (open(argv[1], O_RDONLY) < 0 || open(P_PATH, O_RDONLY) < 0 \
	|| open(W_PATH, O_RDONLY) < 0)
		error_handling(6);
	if (open(C_PATH, O_RDONLY) < 0 || open(E_PATH, O_RDONLY) < 0 \
	|| open(S_PATH, O_RDONLY) < 0)
		error_handling(6);
	if (read(open(argv[1], O_RDONLY), &buf, 1) < 1 || \
	read(open(P_PATH, O_RDONLY), &buf, 1) < 1)
		error_handling(10);
	if (read(open(W_PATH, O_RDONLY), &buf, 1) < 1 || \
	read(open(C_PATH, O_RDONLY), &buf, 1) < 1)
		error_handling(10);
	if (read(open(E_PATH, O_RDONLY), &buf, 1) < 1 || \
	read(open(S_PATH, O_RDONLY), &buf, 1) < 1)
		error_handling(10);
}



