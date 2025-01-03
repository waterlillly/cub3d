#include "../cub3d.h"

// void args_handler(int ac, char **av)
// {
// 	int arg_len;

// 	arg_len = ft_strlen(av[1]);
// 	if (ac != 2)
// 		err("Error\nInvalid number of arguments\n", NULL);
// 	else if (arg_len <= 4)
// 		err("Error\nInvalid file name\n", NULL);
// 	else if (!ft_strnstr(&av[1][arg_len - 4], ".cub", 4))
// 		err("Error\nInvalid file extension\n", NULL);
// }

int	main(void)//(int ac, char **av)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	init_cub(&game);
	if (mlx_handler(&game) != 0)
		exit_failure("Error: mlx_handler", &game);
	mlx_loop(game.cub.mlx_con);
	return (0);
}
