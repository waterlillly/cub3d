#include "../../cub3d.h"

void	render_minimap(t_game *game)
{
	int	x;
	int	y;
	int	color;
	int	px;
	int	py;

	y = -1;
	while (++y < MAP_HEIGHT)
	{
		x = -1;
		while (++x < MAP_WIDTH)
		{
			color = CEILING_COLOR;
			if (game->map[y][x] == '1')
				color = FLOOR_COLOR;
			py = -1;
			while (++py < (TILE_SIZE / 4))
			{
				px = -1;
				while (++px < (TILE_SIZE / 4))
					put_my_pixel(game, x * (TILE_SIZE / 4) + px,
						y * (TILE_SIZE / 4) + py, color);
			}
		}
	}
	put_my_pixel(game, game->cub.player.p_x / TILE_SIZE * (TILE_SIZE / 4),
		game->cub.player.p_y / TILE_SIZE * (TILE_SIZE / 4), PLAYER_COLOR);
}
