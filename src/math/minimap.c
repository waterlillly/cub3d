#include "../../cub3d.h"

static void	render_mini_player(t_game *game)
{
	int		x;
	int		y;
	int		arrow_x;
	int		arrow_y;
	double	t;

	y = -1;
	while (++y < TILE_SIZE / 2)
	{
		x = -1;
		while (++x < TILE_SIZE / 2)
		{
			put_my_pixel(game, game->cub.player.p_x - TILE_SIZE / 4 + x,
				game->cub.player.p_y - TILE_SIZE / 4 + y, PLAYER_COLOR);
		}
	}
	arrow_x = game->cub.player.p_x + cos(game->cub.player.angle) * TILE_SIZE;
	arrow_y = game->cub.player.p_y + sin(game->cub.player.angle) * TILE_SIZE;
	t = 0.0;
	while (t <= 1.0)
	{
		x = (int)(game->cub.player.p_x + t * (arrow_x - game->cub.player.p_x));
		y = (int)(game->cub.player.p_y + t * (arrow_y - game->cub.player.p_y));
		put_my_pixel(game, x, y, PLAYER_COLOR);
		t += 0.01;
	}
}

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
			while (++py < TILE_SIZE)
			{
				px = -1;
				while (++px < TILE_SIZE)
					put_my_pixel(game, x * TILE_SIZE + px, y * TILE_SIZE + py, color);
			}
		}
	}
	render_mini_player(game);
}
