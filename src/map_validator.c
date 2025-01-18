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
	get_whole_file(game, av[1]);
	file_data(game, game->file); // check if failing, and if so, free everything or make all void and free everything in the func
	//later free somewhere else
	free_array((void **)game->file);
	free(game->Itex.north);
	free(game->Itex.south);
	free(game->Itex.west);
	free(game->Itex.east);
	free(game->Itex.floor_color);
	free(game->Itex.ceiling_color);

	// free the map in the loop and then free the map after the loop once
	int i = 0;
	while (game->TheMapInfo.map[i])
	{
		free(game->TheMapInfo.map[i]);
		i++;
	}
	free(game->TheMapInfo.map);
	//***************************************

}