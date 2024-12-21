#include "../cub3d.h"

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (game == NULL)
	{
		printf("Malloc failed [init game]\n");
		exit(1);
	}

	args_handler(ac, av);
	mapValidator(game, av[1]);

	free(game);
}
