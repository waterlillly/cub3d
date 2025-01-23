#include "../../cub3d.h"

static void init_map(t_game *game)
{
	game->data.map = NULL;
	game->data.num_of_rows = 0;
	game->data.max_column = 0;
}

void initialization_of_vars(t_game *game)
{
	//ft_bzero(&game->data, sizeof(t_data));
	game->data.win_height = WIN_SIZE;
	game->data.win_width = WIN_SIZE;
	game->data.texture_px = NULL;//TODO: line 25 to 35 is basically obsolete if we have line 22 to 24
	game->data.texture = NULL;
	game->data.path = NULL;
	game->data.line_count = 0;
	game->data.num_of_rows = 0;
	game->data.num_of_columns = 0;
	game->data.num_of_player = 0;
	game->data.num_of_orientations = 0;
	init_map(game);
}