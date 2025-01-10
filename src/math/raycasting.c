#include "../../cub3d.h"

void	put_my_pixel(t_game *game, int x, int y, int color)
{
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
		game->cub.buffer[y][x] = color;
}

void	buffer_to_image(t_game *game)
{
	int		x;
	int		y;
	char	*dest;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			dest = game->cub.img.addr + (y * game->cub.img.len + x * (game->cub.img.bpp / 8));
			*(unsigned int *)dest = game->cub.buffer[y][x];
		}
	}
}

static void	floor_ceiling(t_game *game, int x)
{
	int	i;

	i = game->rays.end - 1;
	while (++i < WIN_HEIGHT)
		put_my_pixel(game, x, i, BLACK);
	i = -1;
	while (++i < game->rays.start)
		put_my_pixel(game, x, i, DEEPSPACE);
}

static void calc_side_dist(t_game *game)
{
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
	game->rays.wall_x = game->cub.player.p_x + game->rays.dist * game->rays.ray_dir[0];
	if (game->rays.side == 0)
		game->rays.wall_x = game->cub.player.p_y + game->rays.dist * game->rays.ray_dir[1];
	game->rays.wall_x -= floor(game->rays.wall_x);
	game->rays.tex[0] = game->rays.wall_x * game->rays.texture.width;
}

static void	calc_side(t_game *game)
{
	while (true)
	{
		if (game->rays.delta_dist[0] < game->rays.delta_dist[1])
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
		if (is_wall(game, game->rays.map[0], game->rays.map[1]))
			break ;
	}
}

static void	calc_wall(t_game *game)
{
	normalize_angle(game->rays.ray_angle);
	normalize_angle(game->cub.player.angle);
	game->rays.correct_dist = game->rays.dist * cos(game->rays.ray_angle - game->cub.player.angle);
	game->rays.wall_height = (TILE_SIZE * WIN_HEIGHT) / game->rays.correct_dist;
	game->rays.start = (WIN_HEIGHT / 2) - (game->rays.wall_height / 2);
	game->rays.end = (WIN_HEIGHT / 2) + (game->rays.wall_height / 2);
	if (game->rays.start < 0)
		game->rays.start = 0;
	if (game->rays.end >= WIN_HEIGHT)
		game->rays.end = WIN_HEIGHT - 1;
}

static void	cast_ray(t_game *game, int x)
{
	unsigned char	*color;
	int				y;
	
	game->rays.s = 1.0 * game->rays.texture.height / game->rays.wall_height;
	game->rays.tex_pos = (game->rays.start - WIN_HEIGHT / 2 + game->rays.wall_height / 2) * game->rays.s;
	y = game->rays.start;
	while (y < game->rays.end)
	{
		game->rays.tex[1] = (int)game->rays.tex_pos % game->rays.texture.height;
		game->rays.tex[0] %= game->rays.texture.width;
		color = (unsigned char *)game->rays.texture.addr +
				(game->rays.tex[1] * game->rays.texture.len + game->rays.tex[0] * (game->rays.texture.bpp / 8));
		put_my_pixel(game, x, y, *(unsigned int *)color);
		game->rays.tex_pos += game->rays.s;
		y++;
	}
}

static bool	test_crash(t_game *game)
{
	game->rays.ray_dir[0] = game->cub.player.p_x + cos(game->rays.ray_angle) * game->rays.dist;
	game->rays.ray_dir[1] = game->cub.player.p_y + sin(game->rays.ray_angle) * game->rays.dist;
	if (is_wall(game, game->rays.ray_dir[0], game->rays.ray_dir[1]))
		return (true);
	return (false);
}

void	raycasting(t_game *game)
{
	int	x;

	x = -1;
	normalize_angle(game->cub.player.angle);
	game->rays.ray_angle = game->cub.player.angle - (FOV / 2);
	normalize_angle(game->rays.ray_angle);
	while (++x < WIN_WIDTH)
	{
		game->rays.dist = 0;
		while (game->rays.dist < WIN_WIDTH)
		{
			game->rays.dist += 0.1;
			if (test_crash(game) == true)
				break ;
		}
		calc_wall(game);
		floor_ceiling(game, x);
		calc_side_dist(game);
		calc_side(game);
		get_direction(game);
		cast_ray(game, x);
		game->rays.ray_angle += FOV / WIN_WIDTH;
		normalize_angle(game->rays.ray_angle);
	}
	buffer_to_image(game);
}
