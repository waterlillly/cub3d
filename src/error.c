#include "../cub3d.h"

void free_array(void **array)
{
	printf("free_array\n");
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
{
	printf("free_all\n");
	//CHECK
	printf("True: %d False: %d\n", true, false);
	printf("map alloc: %d\n", game->TheMapInfo.map_mem_alloc);
	printf("file alloc: %d\n", game->file_mem_alloc);
	printf("north alloc: %d\n", game->Itex.north_mem_alloc);
	printf("south alloc: %d\n", game->Itex.south_mem_alloc);
	printf("west alloc: %d\n", game->Itex.west_mem_alloc);
	printf("east alloc: %d\n", game->Itex.east_mem_alloc);
	printf("floor alloc: %d\n", game->Itex.floor_mem_alloc);
	printf("ceiling alloc: %d\n", game->Itex.ceiling_mem_alloc);
	//*********************************************************************
	
	if (game->TheMapInfo.map_mem_alloc == true)
		free_array((void **)game->TheMapInfo.map);
	if (game->file_mem_alloc == true)
		free_array((void **)game->file);
	if (game->Itex.north_mem_alloc == true)
		free(game->Itex.north);
	if (game->Itex.south_mem_alloc == true)
		free(game->Itex.south);
	if (game->Itex.west_mem_alloc == true)
		free(game->Itex.west);
	if (game->Itex.east_mem_alloc == true)
		free(game->Itex.east);
	if (game->Itex.floor_mem_alloc == true)
		free(game->Itex.floor_color);
	if (game->Itex.ceiling_mem_alloc == true)
		free(game->Itex.ceiling_color);
	free(game);
	printf("Error\n%s\n", errMSG);
	exit(1);
}
