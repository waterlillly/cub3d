#include "../cub3d1.h"

void	render_mini_player(t_game *game)
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
			put_my_pixel(game, (game->player.pos.x / TILE_SIZE * MINIMAP_SIZE) - MINIMAP_SIZE / 4 + x,
				(game->player.pos.y / TILE_SIZE * MINIMAP_SIZE) - MINIMAP_SIZE / 4 + y, BLUE);
		}
	}
	arrow_x = (game->player.pos.x / TILE_SIZE * MINIMAP_SIZE) + cos(vector_to_angle(game->ray.dir)) * MINIMAP_SIZE;
	arrow_y = (game->player.pos.y / TILE_SIZE * MINIMAP_SIZE) + sin(vector_to_angle(game->ray.dir)) * MINIMAP_SIZE;
	t = 0.0;
	while (t <= 1.0)
	{
		x = floor((game->player.pos.x / TILE_SIZE * MINIMAP_SIZE) + t * (arrow_x - (game->player.pos.x / TILE_SIZE * MINIMAP_SIZE)));
		y = floor((game->player.pos.y / TILE_SIZE * MINIMAP_SIZE) + t * (arrow_y - (game->player.pos.y / TILE_SIZE * MINIMAP_SIZE)));
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
	while (++y < MAP_SIZE)
	{
		x = -1;
		while (++x < MAP_SIZE)
		{
			color = WHITE;
			if (crashed(game, x, y))
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
