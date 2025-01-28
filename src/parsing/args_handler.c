#include "../../cub3d.h"

void args_handler(int ac, char **av, t_game *game)
{
	int arg_len;
	int fd;

	arg_len = ft_strlen(av[1]);
	if (ac != 2)
		exit_failure(ERROR_ARGS, game);
	else if (arg_len <= 4)
		exit_failure(INVALID_EXTENSION_CUB, game);
	else if (!ft_strnstr(&av[1][arg_len - 4], ".cub", 4))
		exit_failure(INVALID_EXTENSION_CUB, game);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit_failure(MAP_FILE_NOT_FOUND, game);
	close(fd);
}