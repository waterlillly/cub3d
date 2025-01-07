#include "../cub3d.h"

static void init_texture(t_texture *texture)
{
    texture->north = NULL;
    texture->south = NULL;
    texture->west = NULL;
    texture->east = NULL;
}

void initialization_of_vars(t_game *game)
{
    game->win_height = WINDOW_HEIGHT;
    game->win_width = WINDOW_WIDTH;
    game->map = NULL;
    game->texture_px = NULL;
    game->texture = NULL;
    game->path = NULL;
    game->line_count = 0;
	game->map_alloc = 0;
	game->num_of_rows = 0;
	game->num_of_columns = 0;
	game->num_of_player = 0;
	game->num_of_orientations = 0;
    init_texture(&game->texture_info);
}