#include "../../cub3d.h"

// void ft_free_2d(void **array)
// {
// 	size_t i = 0;

// 	while (array[i] != NULL)
// 	{
// 		free(array[i]);
// 		i++;
// 	}
// 	if (array){
// 		free(array);
// 		array = NULL;
// 	}
// }

// void free_all(t_game *game, char *errMSG)
// {
// 	if (game->data.map)
// 		ft_free_2d(game->data.map);
// 	if (game->data.file_data)
// 		ft_free_2d(game->data.file_data);
// 	if (game->textures[NORTH].name)
// 		free(game->textures[NORTH].name);
// 	if (game->textures[SOUTH].name)
// 		free(game->textures[SOUTH].name);
// 	if (game->textures[EAST].name)//change to just if (game->textures[EAST].name) because it's anyways checking if there is a memory allocated
// 		free(game->textures[EAST].name);
// 	if (game->textures[WEST].name)
// 		free(game->textures[WEST].name);
// 	// if (game->textures[].name)
// 	// 	free(game->textures[].name)floor_color);
// 	// if (game->textures[].name)
// 	// 	free(game->textures[].name)ceiling_color);
// 	free(game);
// 	if (errMSG)
// 		printf("Error\n%s\n", errMSG);
// 	exit(1);
// }
