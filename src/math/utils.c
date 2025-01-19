#include "../../cub3d.h"

/* Normalize a vector
	= scaling it to the length of 1 (unit vector) while keeping its direction
	length gets the actual length of the given vector */
t_dvec	norm(t_dvec vec)
{
	double	length;
	t_dvec	result;

	length = sqrt(vec.x * vec.x + vec.y * vec.y);
	result.x = vec.x / length;
	result.y = vec.y / length;
	return (result);
}

bool	crashed(t_game *game, double x1, double y1)
{
	int	x;
	int	y;

	x = x1;
	y = y1;
	if (x < 0 || x >= game->map_size || y < 0 || y >= game->map_size)
		return (true);
	return (game->map[y][x] == '1');
}
