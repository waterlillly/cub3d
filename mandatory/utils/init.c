#include "../cub3d.h"

void	initialization_of_vars(t_game *game)
{
	ft_bzero(&game->data, sizeof(t_data));
	ft_bzero(&game->textures, sizeof(t_image) * 5);
	game->data.win_height = WIN_HEIGHT;
	game->data.win_width = WIN_WIDTH;
	game->player.pos.x = -1;
	game->player.pos.y = -1;
}
