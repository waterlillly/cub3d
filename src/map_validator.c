#include "../cub3d.h"

/*
NO, SO, WE, EA: Paths to wall textures.

F: Floor color in RGB format.
C: Ceiling color in RGB format.

- The map is represented using the letters 0 (empty space) and 1 (wall),
and the spawn point with the orientation N, S, E or W. The map must be
surrounded by walls.
*/

void mapValidator(t_game *game, char **av)
{

	printf("mapValidator\n");
	get_map(game, av[1]);
	file_data(game, game->file);
	//later free somewhere else
	free_array((void **)game->file);
	free(game->Itex.north);
	free(game->Itex.south);
	free(game->Itex.west);
	free(game->Itex.east);
}