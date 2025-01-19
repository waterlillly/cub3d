#include "../../cub3d.h"

static void	render_mini_player(t_game *game)
{
	int		x;
	int		y;
	int		arrow_x;
	int		arrow_y;
	double	t;

	y = -1;
	while (++y < MINI_TILE / 2)
	{
		x = -1;
		while (++x < MINI_TILE / 2)
		{
			put_my_pixel(game, (game->player.pos.x / TILE_SIZE * MINI_TILE)
				- MINI_TILE / 4 + x, (game->player.pos.y / TILE_SIZE
					* MINI_TILE) - MINI_TILE / 4 + y, BLUE);
		}
	}
	arrow_x = (game->player.pos.x / TILE_SIZE * MINI_TILE)
		+ game->player.dir.x * MINI_TILE;
	arrow_y = (game->player.pos.y / TILE_SIZE * MINI_TILE)
		+ game->player.dir.y * MINI_TILE;
	t = 0.0;
	while (t <= 1.0)
	{
		x = floor((game->player.pos.x / TILE_SIZE * MINI_TILE) + t * (arrow_x
					- (game->player.pos.x / TILE_SIZE * MINI_TILE)));
		y = floor((game->player.pos.y / TILE_SIZE * MINI_TILE) + t * (arrow_y
					- (game->player.pos.y / TILE_SIZE * MINI_TILE)));
		put_my_pixel(game, x, y, RED);
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
	while (++y < game->map_size)
	{
		x = -1;
		while (++x < game->map_size)
		{
			color = WHITE;
			if (crashed(game, x, y))
				color = BLACK;
			py = -1;
			while (++py < MINI_TILE)
			{
				px = -1;
				while (++px < MINI_TILE)
					put_my_pixel(game, x * MINI_TILE + px, y * MINI_TILE
						+ py, color);
			}
		}
	}
	render_mini_player(game);
}
