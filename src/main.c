#include "../cub3d.h"

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (game == NULL)
		ft_error_msg_free_exit(MALLOC_FAILED, game);
	game->map_alloc = 0;

	args_handler(ac, av, game);
	get_map(game, av[1]);
	initialization_of_vars(game);

	free(game);
}
