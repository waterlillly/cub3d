#include "../cub3d.h"

int	main(void)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	init_cub(&game);
	if (mlx_handler(&game) != 0)
		exit_failure("mlx_handler", &game);
	mlx_do_key_autorepeatoff(game.cub.mlx_con);
	mlx_loop(game.cub.mlx_con);
	mlx_do_key_autorepeaton(game.cub.mlx_con);
	return (exit_success(&game));
}
