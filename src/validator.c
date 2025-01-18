#include "../cub3d.h"

/*
NO, SO, WE, EA: Paths to wall textures.

F: Floor color in RGB format.
C: Ceiling color in RGB format.

- The map is represented using the letters 0 (empty space) and 1 (wall),
and the spawn point with the orientation N, S, E or W. The map must be
surrounded by walls.
*/

void validator(t_game *game, char **av)
{

	printf("mapValidator\n");
	get_whole_file(game, av[1]);
	file_data(game, game->file); // check if failing, and if so, free everything or make all void and free everything in the func
	valid_map(game);

	free_all(game, NULL);
}