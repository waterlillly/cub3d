#include "../../cub3d.h"

/*
	fabs: returns absolute value of a floating point number
	ceil: returns smallest integral value which is not less than argument
	floor: returns largest integral value which is not greater than argument
*/

static void	normalize_angle(t_game *game)
{
	if (game->rays.ray_angle < 0)
	{
		while (game->rays.ray_angle < 0)
			game->rays.ray_angle += (2 * M_PI);
	}
	else if (game->rays.ray_angle > (2 * M_PI))
	{
		while (game->rays.ray_angle > (2 * M_PI))
			game->rays.ray_angle -= (2 * M_PI);
	}
}

static void calc_side_dist(t_game *game)
{
	normalize_angle(game);
	game->rays.delta_dist[0] = fabs(1 / game->rays.ray_dir[0]);
	game->rays.delta_dist[1] = fabs(1 / game->rays.ray_dir[1]);

	if (game->rays.ray_dir[0] < 0)
	{
		game->rays.step[0] = -1;
		game->rays.side_dist[0] = (game->cub.player.p_x - game->rays.map[0]) * game->rays.delta_dist[0];
	}
	else
	{
		game->rays.step[0] = 1;
		game->rays.side_dist[0] = (game->rays.map[0] + 1.0 - game->cub.player.p_x) * game->rays.delta_dist[0];
	}

	if (game->rays.ray_dir[1] < 0)
	{
		game->rays.step[1] = -1;
		game->rays.side_dist[1] = (game->cub.player.p_y - game->rays.map[1]) * game->rays.delta_dist[1];
	}
	else
	{
		game->rays.step[1] = 1;
		game->rays.side_dist[1] = (game->rays.map[1] + 1.0 - game->cub.player.p_y) * game->rays.delta_dist[1];
	}
	// game->rays.side_dist[0] = (ceil(game->cub.player.p_x) - game->cub.player.p_x) * game->rays.delta_dist[0];
	// if (game->rays.step[0] < 0)
	// 	game->rays.side_dist[0] = (game->cub.player.p_x - floor(game->cub.player.p_x)) * game->rays.delta_dist[0];
	// game->rays.side_dist[1] = (ceil(game->cub.player.p_y) - game->cub.player.p_y) * game->rays.delta_dist[1];
	// if (game->rays.step[1] < 0)
	// 	game->rays.side_dist[1] = (game->cub.player.p_y - floor(game->cub.player.p_y)) * game->rays.delta_dist[1];
}

static void	get_direction(t_game *game)
{
	if (game->rays.side == 0)
	{
		game->rays.texture = game->txts[WEST];
		if (game->rays.ray_dir[0] > 0)
			game->rays.texture = game->txts[EAST];
	}
	else
	{
		game->rays.texture = game->txts[NORTH];
		if (game->rays.ray_dir[1] > 0)
			game->rays.texture = game->txts[SOUTH];
	}
}

static void	calc_side(t_game *game)
{
	calc_side_dist(game);
	while (game->map[game->rays.map[0]][game->rays.map[1]] != '1')
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
	get_direction(game);
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
	wall_x = game->cub.player.p_x + game->rays.dist * game->rays.ray_dir[0];
	if (game->rays.side == 0)
		wall_x = game->cub.player.p_y + game->rays.dist * game->rays.ray_dir[1];
	wall_x -= floor(wall_x);
	return ((int)floor(wall_x * game->rays.texture.width));
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
	// if ((game->rays.side == 0 && game->rays.ray_dir[0] > 0) ||
	// 	(game->rays.side == 1 && game->rays.ray_dir[1] < 0))
	// 		tex_x = game->rays.texture.width - tex_x - 1;
	// tex_x = (int)(tex_x * game->rays.texture.width / 4) % game->rays.texture.width;
	step = 1.0 * game->rays.texture.height / game->rays.wall_height;
	game->rays.tex_pos = (game->rays.start - WIN_HEIGHT / 2 + game->rays.wall_height / 2) * step;
	y = game->rays.start;
	while (y < game->rays.end)
	{
		// game->rays.tex_pos = y * game->rays.texture.len - (WIN_HEIGHT * TILE_SIZE) * game->rays.texture.len / 2 + game->rays.wall_height * game->rays.texture.len / 2;
		// tex_y = ((game->rays.tex_pos * game->rays.texture.height) / game->rays.wall_height) / game->rays.texture.len;
		// tex_y = (int)game->rays.tex_pos & (game->rays.texture.height - 1);
		tex_y = (int)game->rays.tex_pos % game->rays.texture.height;
		// tex_y = (int)(tex_y * game->rays.texture.height / 4) % game->rays.texture.height;
		color = (unsigned char *)game->rays.texture.addr +
				(tex_y * game->rays.texture.len + tex_x * (game->rays.texture.bpp / 8));
		put_my_pixel(game, x, y, *(unsigned int *)color);
		game->rays.tex_pos += step;
		y++;
	}
	floor_ceiling(game, x);
}

static bool	test_crash(t_game *game, int x)
{
	game->rays.ray_dir[0] = game->cub.player.p_x + cos(game->rays.ray_angle) * game->rays.dist;
	game->rays.ray_dir[1] = game->cub.player.p_y + sin(game->rays.ray_angle) * game->rays.dist;
	if (is_wall(game, game->rays.ray_dir[0], game->rays.ray_dir[1]))
		return (cast_ray(game, x), true);
	return (false);
}

void	raycasting(t_game *game)
{
	bool	crash;
	int		x;

	x = 0;
	ft_bzero(&game->rays, sizeof(t_raycast));
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
