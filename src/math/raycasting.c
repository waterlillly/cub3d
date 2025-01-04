#include "../../cub3d.h"

static void	put_my_wall(t_game *game, t_raycast *rays)
{
	rays->corrected_distance = rays->distance * cos(rays->ray_angle - game->cub.player.angle);
	rays->wall_height = (TILE_SIZE * WIN_HEIGHT) / rays->corrected_distance;
	rays->start = (WIN_HEIGHT / 2) - (rays->wall_height / 2);
	rays->end = (WIN_HEIGHT / 2) + (rays->wall_height / 2);
	if (rays->side == 0)
		rays->wall_x = game->cub.player.p_y + rays->distance * sin(rays->ray_angle);
	else
		rays->wall_x = game->cub.player.p_x + rays->distance * cos(rays->ray_angle);
	rays->wall_x -= floor(rays->wall_x);//?
	rays->tex[0] = rays->wall_x * (double)game->txt.wall.txt_width;
	if ((rays->side == 0 && cos(rays->ray_angle) > 0) || (rays->side == 1 && sin(rays->ray_angle) < 0))
		rays->tex[0] = game->txt.wall.txt_width - rays->tex[0] - 1;
	rays->step = 1.0 * game->txt.wall.txt_height / rays->wall_height;
	rays->tex_pos = (rays->start - WIN_HEIGHT / 2 + rays->wall_height / 2) * rays->step;
	while (rays->start <= rays->end)
	{
		rays->tex[1] = (int)rays->tex_pos & (game->txt.wall.txt_height - 1);
		rays->tex_pos += rays->step;
		rays->color = game->txt.wall.txt_addr +
		       (rays->tex[1] * game->txt.wall.len + rays->tex[0] * (game->txt.wall.bpp / 8));
		put_my_pixel(game, game->rays.col, rays->start, *(unsigned int *)rays->color);
		rays->start++;
	}
}

static void calculate_side(t_raycast *rays, t_game *game)
{
	double	step[2];

	while (!rays->crash)
	{
		if (rays->side_dist[0] < rays->side_dist[1])
		{
			rays->side_dist[0] += rays->delta_dist[0];
			rays->map[0] += step[0];
			rays->side = 0;
		}
		else
		{
			rays->side_dist[1] += rays->delta_dist[1];
			rays->map[1] += step[1];
			rays->side = 1;
		}
		//rays->crash = (game->map[rays->map[0]][rays->map[1]] == WALL_TILE);
	}
}

static void	cast_ray(t_game *game)
{
	game->rays.corrected_distance = game->rays.distance * cos(game->rays.ray_angle - game->cub.player.angle);
	game->rays.wall_height = (TILE_SIZE * WIN_HEIGHT) / game->rays.corrected_distance;
	game->rays.start = (WIN_HEIGHT / 2) - (game->rays.wall_height / 2);
	game->rays.end = (WIN_HEIGHT / 2) + (game->rays.wall_height / 2);
	calculate_side(&(*game).rays, game);
	put_my_wall(game, &(*game).rays);
	while (game->rays.start <= game->rays.end)
	{
		// put_my_pixel(game, col, start, game->txt.wall.txt_img);
		put_my_pixel(game, game->rays.col, game->rays.start, WALL_COLOR);
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

static bool	test_crash(t_game *game)
{
	game->rays.map[0] = (game->cub.player.p_x + cos(game->rays.ray_angle) * game->rays.distance);
	game->rays.map[1] = (game->cub.player.p_y + sin(game->rays.ray_angle) * game->rays.distance);
	if (is_wall(game, game->rays.map[0] / TILE_SIZE, game->rays.map[1] / TILE_SIZE))
	{
		cast_ray(game);
		return (true);
	}
	return (false);
}

void	raycasting(t_game *game)
{
	game->rays.col = 0;
	game->rays.ray_angle = game->cub.player.angle - (game->cub.player.fov / 2);
	while (game->rays.col < NUM_RAYS)
	{
		game->rays.distance = 0;
		game->rays.crash = false;
		while (!game->rays.crash && game->rays.distance < WIN_WIDTH)
		{
			game->rays.distance += 0.1;
			game->rays.crash = test_crash(game);
		}
		game->rays.ray_angle += game->cub.player.fov / NUM_RAYS;
		game->rays.col++;
	}
}

