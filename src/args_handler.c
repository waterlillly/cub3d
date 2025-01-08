#include "../cub3d.h"

void args_handler(int ac, char **av, t_game *game)
{
	printf("args_handler\n");
	int arg_len;
	int fd;

	arg_len = ft_strlen(av[1]);
	if (ac != 2)
		ft_error_msg_free_exit(ERROR_ARGS, game);
	else if (arg_len <= 4)
		ft_error_msg_free_exit(INVALID_EXTENSION_CUB, game);
	else if (!ft_strnstr(&av[1][arg_len - 4], ".cub", 4))
		ft_error_msg_free_exit(INVALID_EXTENSION_CUB, game);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error_msg_free_exit(MAP_FILE_NOT_FOUND, game);
	close(fd);
}