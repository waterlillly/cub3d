#include "../../cub3d.h"

/*
	fabs: returns absolute value of a floating point number
	ceil: returns smallest integral value which is not less than argument
	floor: returns largest integral value which is not greater than argument
*/

static void calc_side_dist(t_game *game)
{
	game->rays.delta_dist[0] = fabs(1 / cos(game->rays.ray_angle));
	game->rays.delta_dist[1] = fabs(1 / sin(game->rays.ray_angle));
	game->rays.side_dist[0] = (ceil(game->cub.player.p_x) - game->cub.player.p_x) * game->rays.delta_dist[0];
	if (game->rays.step[0] < 0)
		game->rays.side_dist[0] = (game->cub.player.p_x - floor(game->cub.player.p_x)) * game->rays.delta_dist[0];
	game->rays.side_dist[1] = (ceil(game->cub.player.p_y) - game->cub.player.p_y) * game->rays.delta_dist[1];
	if (game->rays.step[1] < 0)
		game->rays.side_dist[1] = (game->cub.player.p_y - floor(game->cub.player.p_y)) * game->rays.delta_dist[1];
}

static void	calc_side(t_game *game)
{
	game->rays.step[0] = 1;
	if (cos(game->rays.ray_angle) < 0)
		game->rays.step[0] = -1;
	game->rays.step[1] = 1;
	if (sin(game->rays.ray_angle) < 0)
		game->rays.step[1] = -1;
	calc_side_dist(game);
	while (game->map[game->rays.map[0]][game->rays.map[1]] != '1' &&
		game->rays.map[0] > 0 && game->rays.map[1] > 0 &&
		game->rays.map[0] < MAP_WIDTH && game->rays.map[1] < MAP_HEIGHT)
	{
		if (game->rays.side_dist[0] < game->rays.side_dist[1])
		{
			game->rays.side_dist[0] += game->rays.delta_dist[0];
			game->rays.map[0] += game->rays.step[0];
			game->rays.side = 0;
		}
		else
		{
			game->rays.side_dist[1] += game->rays.delta_dist[1];
			game->rays.map[1] += game->rays.step[1];
			game->rays.side = 1;
		}
	}
}

static void	get_direction(t_game *game)
{
	if (game->rays.side == 0)
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
}

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
	calc_side(game);
	wall_x = game->cub.player.p_x + game->rays.dist * cos(game->rays.ray_angle);
	if (game->rays.side == 0)
		wall_x = game->cub.player.p_y + game->rays.dist * sin(game->rays.ray_angle);
	wall_x -= floor(wall_x);
	get_direction(game);
	return ((int)(wall_x * game->rays.texture.width));
}

static void	floor_ceiling(t_game *game, int x)
{
	int	i;

	i = game->rays.end;
	while (i < WIN_HEIGHT)
	{
		put_my_pixel(game, x, i, BLACK);
		i++;
	}
	i = 0;
	while (i < game->rays.start)
	{
		put_my_pixel(game, x, i, DEEPSPACE);
		i++;
	}
}

static void	cast_ray(t_game *game, int x)
{
	unsigned char	*color;
	int				tex_x;
	int				tex_y;
	double			step;
	int				y;

	tex_x = calc_wall(game);
	step = 1.0 * game->rays.texture.height / game->rays.wall_height;
	game->rays.tex_pos = (game->rays.start - WIN_HEIGHT / 2 + game->rays.wall_height / 2) * step;
	y = game->rays.start;
	while (y <= game->rays.end)
	{
		tex_y = (int)game->rays.tex_pos % game->rays.texture.height;
		game->rays.tex_pos += step;
		color = (unsigned char *)game->rays.texture.addr +
				(tex_y * game->rays.texture.len) + 
				(tex_x * (game->rays.texture.bpp / 8));
		put_my_pixel(game, x, y, *(unsigned int *)color);
		y++;
	}
	floor_ceiling(game, x);
}

static bool	test_crash(t_game *game, int x)
{
	double	ray_x;
	double	ray_y;

	ray_x = game->cub.player.p_x + cos(game->rays.ray_angle) * game->rays.dist;
	ray_y = game->cub.player.p_y + sin(game->rays.ray_angle) * game->rays.dist;
	if (is_wall(game, ray_x, ray_y))
		return (cast_ray(game, x), true);
	return (false);
}

void	raycasting(t_game *game)
{
	bool	crash;
	int		x;

	x = 0;
	game->rays.ray_angle = game->cub.player.angle - (game->cub.player.fov / 2);
	while (x < WIN_WIDTH)
	{
		game->rays.dist = 0;
		crash = false;
		while (!crash && game->rays.dist <= WIN_WIDTH)
		{
			game->rays.dist += 0.1;
			crash = test_crash(game, x);
		}
		game->rays.ray_angle += game->cub.player.fov / WIN_WIDTH;
		x++;
	}
}
