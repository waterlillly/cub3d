#include "../cub3d.h"

static void	init_macros(t_game *game)
{
	game->macro.tile_size = (WIN_SIZE * 0.1);
	game->macro.minimap_size = floor(WIN_SIZE * 0.2);
	game->macro.mini_tile_width = (game->macro.minimap_size / game->data.map_width);
	game->macro.mini_tile_height = (game->macro.minimap_size / game->data.map_height);
	game->macro.fov = 60 * (M_PI / 180);
}

int	main(int ac, char **av)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	(void)ac;
	(void)av;
	// initialization_of_vars(&game);
	// args_handler(ac, av, &game);
	// validator(&game, av);
	init_macros(&game);
	init_cub(&game);
	if (mlx_handler(&game) != 0)
		exit_failure("mlx_handler", &game);
	mlx_do_key_autorepeatoff(game.cub.mlx_con);
	mlx_loop(game.cub.mlx_con);
	mlx_do_key_autorepeaton(game.cub.mlx_con);
	return (exit_success(&game));
}
