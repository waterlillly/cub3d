#include "../../cub3d.h"

static void	render_mini_arrow(t_game *game)
{
	t_ivec	xy;
	t_ivec	axy;
	double	t;

	axy.x = (game->player.pos.x / TILE_SIZE * MINI_TILE_WIDTH)
		+ game->player.dir.x * MINI_TILE_WIDTH;
	axy.y = (game->player.pos.y / TILE_SIZE * MINI_TILE_HEIGHT)
		+ game->player.dir.y * MINI_TILE_HEIGHT;
	t = 0.0;
	while (t <= 1.0)
	{
		xy.x = floor((game->player.pos.x / TILE_SIZE * MINI_TILE_WIDTH) + t
				* (axy.x - (game->player.pos.x / TILE_SIZE * MINI_TILE_WIDTH)));
		xy.y = floor((game->player.pos.y / TILE_SIZE * MINI_TILE_HEIGHT) + t
				* (axy.y - (game->player.pos.y / TILE_SIZE
						* MINI_TILE_HEIGHT)));
		put_my_pixel(game, xy.x, xy.y, RED);
		t += 0.01;
	}
}

static void	render_mini_player(t_game *game)
{
	t_ivec	xy;

	xy.y = -1;
	while (++xy.y < MINI_TILE_HEIGHT / 2)
	{
		xy.x = -1;
		while (++xy.x < MINI_TILE_WIDTH / 2)
		{
			put_my_pixel(game, (game->player.pos.x / TILE_SIZE
					* MINI_TILE_WIDTH) - MINI_TILE_WIDTH / 4 + xy.x,
				(game->player.pos.y / TILE_SIZE * MINI_TILE_HEIGHT)
				- MINI_TILE_HEIGHT / 4 + xy.y, BLUE);
		}
	}
	render_mini_arrow(game);
}

void	render_minimap(t_game *game)
{
	t_ivec	xy;
	t_ivec	pxy;
	int		color;

	xy.y = -1;
	while (++xy.y < game->map_height)
	{
		xy.x = -1;
		while (++xy.x < game->map_width)
		{
			color = WHITE;
			if (crashed(game, xy.x, xy.y))
				color = BLACK;
			pxy.y = -1;
			while (++pxy.y < MINI_TILE_HEIGHT)
			{
				pxy.x = -1;
				while (++pxy.x < MINI_TILE_WIDTH)
					put_my_pixel(game, xy.x * MINI_TILE_WIDTH + pxy.x, xy.y
						* MINI_TILE_HEIGHT + pxy.y, color);
			}
		}
	}
	render_mini_player(game);
}
