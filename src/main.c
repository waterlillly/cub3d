#include "../cub3d.h"

int	main(int ac, char **av)
{
	printf("main\n");
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (game == NULL)
		free_all(game, MALLOC_FAILED);
	initialization_of_vars(game);
	args_handler(ac, av, game);
	validator(game, av);

	free(game);
}
