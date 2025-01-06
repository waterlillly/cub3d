#include "../../cub3d.h"

static void	render_mini_player(t_game *game)
{
	int		x;
	int		y;
	int		arrow_x;
	int		arrow_y;
	double	t;

	y = -1;
	while (++y < MINIMAP_SIZE / 2)
	{
		x = -1;
		while (++x < MINIMAP_SIZE / 2)
		{
			put_my_pixel(game, (game->cub.player.p_x / TILE_SIZE * MINIMAP_SIZE) - MINIMAP_SIZE / 4 + x,
				(game->cub.player.p_y / TILE_SIZE * MINIMAP_SIZE) - MINIMAP_SIZE / 4 + y, BLUE);
		}
	}
	arrow_x = (game->cub.player.p_x / TILE_SIZE * MINIMAP_SIZE) + cos(game->cub.player.angle) * MINIMAP_SIZE;
	arrow_y = (game->cub.player.p_y / TILE_SIZE * MINIMAP_SIZE) + sin(game->cub.player.angle) * MINIMAP_SIZE;
	t = 0.0;
	while (t <= 1.0)
	{
		x = floor((game->cub.player.p_x / TILE_SIZE * MINIMAP_SIZE) + t * (arrow_x - (game->cub.player.p_x / TILE_SIZE * MINIMAP_SIZE)));
		y = floor((game->cub.player.p_y / TILE_SIZE * MINIMAP_SIZE) + t * (arrow_y - (game->cub.player.p_y / TILE_SIZE * MINIMAP_SIZE)));
		put_my_pixel(game, x, y, BLUE);
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
			color = WHITE;
			if (game->map[y][x] == '1')
				color = BLACK;
			py = -1;
			while (++py < MINIMAP_SIZE)
			{
				px = -1;
				while (++px < MINIMAP_SIZE)
					put_my_pixel(game, x * MINIMAP_SIZE + px, y * MINIMAP_SIZE + py, color);
			}
		}
	}
	render_mini_player(game);
}
