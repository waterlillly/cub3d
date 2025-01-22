#include "../cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	initialization_of_vars(&game);
	args_handler(ac, av, &game);
	validator(&game, av);
	init_cub(&game);
	if (mlx_handler(&game) != 0)
		exit_failure("mlx_handler", &game);
	mlx_loop(game.cub.mlx_con);
	return (exit_success(&game));
}

// int	main(int ac, char **av)
// {
// 	t_game	game;
// 	int		i;

// 	ft_bzero(&game, sizeof(t_game));
// 	init_struct(&game);
// 	if (ac == 2 && av[1])
// 	{
// 		check_input_file(av[1], &game);
// 		if (game.data.map)
// 		{
// 			i = -1;
// 			while (game.data.map[++i])
// 				printf("|%s|\n", game.data.map[i]);
// 		}
// 	}
// 	init_cub(&game);
// 	if (mlx_handler(&game) != 0)
// 		exit_failure("mlx_handler", &game);
// 	mlx_loop(game.cub.mlx_con);
// 	return (exit_success(&game));
// }