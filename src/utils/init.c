#include "../../cub3d.h"

void	initialization_of_vars(t_game *game)
{
	ft_bzero(&game->data, sizeof(t_data));
	game->data.win_height = WIN_SIZE;
	game->data.win_width = WIN_SIZE;
	game->data.floor_color_set = false;
	game->data.ceiling_color_set = false;
}
