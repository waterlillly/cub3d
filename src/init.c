#include "../cub3d.h"

static void init_texture(t_texture *texture)
{
    printf("init_texture\n");
    texture->north = NULL;
    texture->south = NULL;
    texture->west = NULL;
    texture->east = NULL;
    texture->floor_color = NULL;
    texture->ceiling_color = NULL;
}

void initialization_of_vars(t_game *game)
{
    printf("initialization_of_vars\n");
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

    //INIT STRUCTS
    init_texture(&game->Itex);
}