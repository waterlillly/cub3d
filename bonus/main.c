#include "../cub3d_bonus.h"

int	main(int ac, char **av)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	initialization_of_vars(&game);
	args_handler(ac, av, &game);
	validate_game(&game, av);
	init_cub(&game);
	if (mlx_handler(&game) != 0)
		exit_failure("mlx_handler", &game);
	mlx_do_key_autorepeatoff(game.cub.mlx_con);
	mlx_loop(game.cub.mlx_con);
	mlx_do_key_autorepeaton(game.cub.mlx_con);
	return (exit_success(&game));
}
