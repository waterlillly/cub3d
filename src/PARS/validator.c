#include "../../cub3d.h"

void validator(t_game *game, char **av)
{
	get_whole_file(game, av[1]);
	file_data(game, game->file);
	valid_map(game);

	free_all(game, NULL);
}