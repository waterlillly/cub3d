#include "../../cub3d.h"

static void	cast_ray(t_game *game, int col, double distance, double ray_angle)
{
	double	corrected_distance;
	int		wall_height;
	int		start;
	int		end;

	corrected_distance = distance * cos(ray_angle - game->cub.player.angle);
	wall_height = (TILE_SIZE * WIN_HEIGHT) / corrected_distance;
	start = (WIN_HEIGHT / 2) - (wall_height / 2);
	end = (WIN_HEIGHT / 2) + (wall_height / 2);
	while (start <= end)
	{
		put_my_pixel(game, col, start, WALL_COLOR);
		start++;
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

static bool	test_crash(t_game *game, int col, double distance, double ray_angle)
{
	int	map_x;
	int	map_y;

	map_x = (game->cub.player.p_x + cos(ray_angle) * distance);
	map_y = (game->cub.player.p_y + sin(ray_angle) * distance);
	if (is_wall(game, map_x / TILE_SIZE, map_y / TILE_SIZE))
	{
		cast_ray(game, col, distance, ray_angle);
		return (true);
	}
	return (false);
}

void	raycasting(t_game *game)
{
	double	ray_angle;
	int		col;
	double	distance;
	bool	crash;

	col = 0;
	ray_angle = game->cub.player.angle - (game->cub.player.fov / 2);
	while (col < NUM_RAYS)
	{
		distance = 0;
		crash = false;
		while (!crash && distance < WIN_WIDTH)
		{
			distance += 0.1;
			crash = test_crash(game, col, distance, ray_angle);
		}
		ray_angle += game->cub.player.fov / NUM_RAYS;
		col++;
	}
}

