#include "../cub3d.h"

void args_handler(int ac, char **av, t_game *game)
{
	printf("args_handler\n");
	int arg_len;
	int fd;

	arg_len = ft_strlen(av[1]);
	if (ac != 2)
		free_all(game, ERROR_ARGS);
	else if (arg_len <= 4)
		free_all(game, INVALID_EXTENSION_CUB);
	else if (!ft_strnstr(&av[1][arg_len - 4], ".cub", 4))
		free_all(game, INVALID_EXTENSION_CUB);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		free_all(game, MAP_FILE_NOT_FOUND);
	close(fd);
}