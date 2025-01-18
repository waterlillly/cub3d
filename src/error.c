#include "../cub3d.h"

void free_array(void **array)
{
	size_t i = 0;

	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	if (array){
		free(array);
		array = NULL;
	}
}

void free_all(t_game *game, char *errMSG)
{if (game->TheMapInfo.map_mem_alloc == true)
		free_array((void **)game->TheMapInfo.map);
	if (game->file_mem_alloc == true)
		free_array((void **)game->file);
	if (game->Itex.north_mem_alloc == true)
		free(game->Itex.north);
	if (game->Itex.south_mem_alloc == true)
		free(game->Itex.south);
	if (game->Itex.west_mem_alloc == true) //change to just if (game->Itex.west) because it's anyways checking if there is a memory allocated
		free(game->Itex.west);
	if (game->Itex.east_mem_alloc == true)
		free(game->Itex.east);
	if (game->Itex.floor_mem_alloc == true)
		free(game->Itex.floor_color);
	if (game->Itex.ceiling_mem_alloc == true)
		free(game->Itex.ceiling_color);
	free(game);
	if (errMSG)
		printf("Error\n%s\n", errMSG);
	exit(1);
}
