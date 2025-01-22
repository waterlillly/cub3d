#include "../cub3d.h"

static void mem_aloc_false(t_game *game)
{
    game->TheMapInfo.map_mem_alloc = false;
    game->file_mem_alloc = false;
    game->Itex.north_mem_alloc = false;
    game->Itex.south_mem_alloc = false;
    game->Itex.west_mem_alloc = false;
    game->Itex.east_mem_alloc = false;
}

static void init_texture(t_texture *texture)
{
    texture->north = NULL;
    texture->south = NULL;
    texture->west = NULL;
    texture->east = NULL;
    texture->floor_color = NULL;
    texture->ceiling_color = NULL;
}

static void init_map(t_game *game)
{
    game->TheMapInfo.map = NULL;
    game->TheMapInfo.num_of_rows = 0;
    game->TheMapInfo.max_column = 0;
}

void initialization_of_vars(t_game *game)
{
    game->win_height = WINDOW_HEIGHT;
    game->win_width = WINDOW_WIDTH;
    game->texture_px = NULL;
    game->texture = NULL;
    game->path = NULL;
    game->line_count = 0;
	game->num_of_rows = 0;
	game->num_of_columns = 0;
	game->num_of_player = 0;
	game->num_of_orientations = 0;

    mem_aloc_false(game);

    //INIT STRUCTS
    init_texture(&game->Itex);
    init_map(game);
}