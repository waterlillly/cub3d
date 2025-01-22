#include "../../cub3d.h"

// static void init_texture(t_texture *texture)
// {
//     texture->north = NULL;
//     texture->south = NULL;
//     texture->west = NULL;
//     texture->east = NULL;
//     texture->floor_color = NULL;
//     texture->ceiling_color = NULL;
// }

static void init_map(t_game *game)
{
	game->data.map = NULL;
	game->data.num_of_rows = 0;
	game->data.max_column = 0;
}

void initialization_of_vars(t_game *game)
{
	game->data.win_height = WIN_SIZE;
	game->data.win_width = WIN_SIZE;
	game->data.texture_px = NULL;
	game->data.texture = NULL;
	game->data.path = NULL;
	game->data.line_count = 0;
	game->data.num_of_rows = 0;
	game->data.num_of_columns = 0;
	game->data.num_of_player = 0;
	game->data.num_of_orientations = 0;
	//INIT STRUCTS
	// init_texture(&game->Itex);
	init_map(game);
}