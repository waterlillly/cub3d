#include "../../cub3d.h"

static int	calc_wall(t_game *game)
{
	double	wall_x;

	game->rays.correct_dist = game->rays.dist * cos(game->rays.ray_angle - game->cub.player.angle);
	game->rays.wall_height = (TILE_SIZE * WIN_HEIGHT) / game->rays.correct_dist;
	game->rays.start = (WIN_HEIGHT / 2) - (game->rays.wall_height / 2);
	game->rays.end = (WIN_HEIGHT / 2) + (game->rays.wall_height / 2);
	if (game->rays.start < 0)
		game->rays.start = 0;
	if (game->rays.end >= WIN_HEIGHT)
		game->rays.end = WIN_HEIGHT - 1;
	wall_x = game->cub.player.p_x + game->rays.dist * cos(game->rays.ray_angle);
	if (game->rays.side == 0)
		wall_x = game->cub.player.p_y + game->rays.dist * sin(game->rays.ray_angle);
	wall_x -= floor(wall_x);
	if (game->rays.side == 0)//TODO: write function for setting side!
	{
		game->rays.texture = game->txt.west;
		if (cos(game->rays.ray_angle) > 0)
			game->rays.texture = game->txt.east;
	}
	else
	{
		game->rays.texture = game->txt.north;
		if (sin(game->rays.ray_angle) > 0)
			game->rays.texture = game->txt.south;
	}
	return ((int)(wall_x * game->rays.texture.width));
}

static void	cast_ray(t_game *game, int x)
{
	unsigned char	*color;
	int				tex_x;
	int				tex_y;
	double			step;

	tex_x = calc_wall(game);
	step = 1.0 * game->rays.texture.height / game->rays.wall_height;
	game->rays.tex_pos = (game->rays.start - WIN_HEIGHT / 2 + game->rays.wall_height / 2) * step;
	while (game->rays.start <= game->rays.end)
	{
		tex_y = (int)game->rays.tex_pos % game->rays.texture.height;
		game->rays.tex_pos += step;
		color = (unsigned char *)game->rays.texture.addr +
				(tex_y * game->rays.texture.len) + 
				(tex_x * (game->rays.texture.bpp / 8));
		put_my_pixel(game, x, game->rays.start, *(unsigned int *)color);
		game->rays.start++;
	}
}

bool	is_wall(t_game *game, double new_x, double new_y)
{
	int	x;
	int	y;

	x = (int)new_x;
	y = (int)new_y;
	if (x < 0 || x >= MAP_WIDTH || y < 0 || y >= MAP_HEIGHT)
		return (true);
	return (game->map[y][x] == '1');
}

static bool	test_crash(t_game *game, int x)
{
	int	ray_x;
	int	ray_y;

	ray_x = (game->cub.player.p_x + cos(game->rays.ray_angle) * game->rays.dist);
	ray_y = (game->cub.player.p_y + sin(game->rays.ray_angle) * game->rays.dist);
	if (is_wall(game, ray_x / TILE_SIZE, ray_y / TILE_SIZE))
		return (cast_ray(game, x), true);
	return (false);
}

void	raycasting(t_game *game)
{
	bool	crash;
	int		x;

	x = 0;
	game->rays.ray_angle = game->cub.player.angle - (game->cub.player.fov / 2);
	while (x < NUM_RAYS)
	{
		game->rays.dist = 0;
		crash = false;
		while (!crash && game->rays.dist < WIN_WIDTH)
		{
			game->rays.dist += 0.1;
			crash = test_crash(game, x);
		}
		game->rays.ray_angle += game->cub.player.fov / NUM_RAYS;
		x++;
	}
}
