#include "../cub3d1.h"

int	main(void)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	init_cub(&game);
	if (mlx_handler(&game) != 0)
		exit_failure("Error: mlx_handler", &game);
	mlx_loop(game.cub.mlx_con);
	return (exit_success(&game));
}
