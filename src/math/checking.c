#include "../../cub3d.h"

void	check_texture(t_game *game, int i)
{
	if (game->textures[i].width != game->textures[i].height)
	{
		ft_putstr_fd(game->textures[i].name, 2);
		exit_failure(" does not have the same width and height", game);
	}
	if (game->textures[i].bpp != 32)
		exit_failure("Error: Texture format not supported (must be 32bpp)",
			game);
}

bool	is_wall(t_game *game, double new_x, double new_y)
{
	int	x;
	int	y;

	x = floor(new_x / (TILE_SIZE));
	y = floor(new_y / (TILE_SIZE));
	if (x < 0 || x >= MAP_SIZE || y < 0 || y >= MAP_SIZE)
		return (true);
	return (game->map[y][x] == '1');
}
