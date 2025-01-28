#include "../../cub3d.h"

static void	render_mini_arrow(t_game *game)
{
	t_ivec	xy;
	t_ivec	axy;
	double	t;

	axy.x = (game->player.pos.x / game->macro.tile_size * game->macro.mini_tile_width)
		+ game->player.dir.x * game->macro.mini_tile_width;
	axy.y = (game->player.pos.y / game->macro.tile_size * game->macro.mini_tile_height)
		+ game->player.dir.y * game->macro.mini_tile_height;
	t = 0.0;
	while (t <= 1.0)
	{
		xy.x = floor((game->player.pos.x / game->macro.tile_size * game->macro.mini_tile_width) + t
				* (axy.x - (game->player.pos.x / game->macro.tile_size * game->macro.mini_tile_width)));
		xy.y = floor((game->player.pos.y / game->macro.tile_size * game->macro.mini_tile_height) + t
				* (axy.y - (game->player.pos.y / game->macro.tile_size
						* game->macro.mini_tile_height)));
		put_my_pixel(game, xy.x, xy.y, RED);
		t += 0.01;
	}
}

static void	render_mini_player(t_game *game)
{
	t_ivec	xy;

	xy.y = -1;
	while (++xy.y < game->macro.mini_tile_height / 2)
	{
		xy.x = -1;
		while (++xy.x < game->macro.mini_tile_width / 2)
		{
			put_my_pixel(game, (game->player.pos.x / game->macro.tile_size
					* game->macro.mini_tile_width) - game->macro.mini_tile_width / 4 + xy.x,
				(game->player.pos.y / game->macro.tile_size * game->macro.mini_tile_height)
				- game->macro.mini_tile_height / 4 + xy.y, BLUE);
		}
	}
	render_mini_arrow(game);
}

static void	display_minimap(t_game *game, t_ivec xy, int color)
{
	t_ivec	pxy;

	pxy.y = -1;
	while (++pxy.y < game->macro.mini_tile_height)
	{
		pxy.x = -1;
		while (++pxy.x < game->macro.mini_tile_width)
			put_my_pixel(game, xy.x * game->macro.mini_tile_width + pxy.x, xy.y
				* game->macro.mini_tile_height + pxy.y, color);
	}
}

void	render_minimap(t_game *game)
{
	t_ivec	xy;
	// int		nbr;
	int		color;

	xy.y = -1;
	// printf("%d\n", game->data.map_height);
	while (++xy.y < game->data.map_height)
	{
		xy.x = -1;
		// printf("%d\n", game->data.map_width);
		while (++xy.x < game->data.map_width)
		{
			// nbr = is_door(game, xy.x, xy.y);
			color = WHITE;
			if (crashed(game, xy.x, xy.y))
				color = BLACK;
			// else if (nbr >= 0 && !is_open(game, nbr))
			// 	color = RED;
			// else if (nbr >= 0 && is_open(game, nbr))
			// 	color = GREEN;
			display_minimap(game, xy, color);
		}
	}
	render_mini_player(game);
}
