#include "../cub3d.h"

int	main(int ac, char **av)
{
	printf("main\n");
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (game == NULL)
		ft_error_msg_free_exit(MALLOC_FAILED, game);
	game->map_alloc = 0;

	initialization_of_vars(game);
	args_handler(ac, av, game);
	mapValidator(game, av);

	free(game);
}
