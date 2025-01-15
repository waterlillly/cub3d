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

/* Convert vector to angle + normalize it */
double	vector_to_angle(t_dvec vec)
{
	double	result;
	t_dvec	n;

	n = norm(vec);
	result = atan2(n.y, n.x);
	return (result);
}

/* Convert angle to vector + normalize it */
t_dvec	angle_to_vector(double angle)
{
	t_dvec	result;

	result.x = cos(angle);
	result.y = sin(angle);
	return (norm(result));
}

bool	crashed(t_game *game, double x1, double y1)
{
	int	x;
	int	y;

	x = x1;
	y = y1;
	if (x < 0 || x >= MAP_SIZE || y < 0 || y >= MAP_SIZE)
		return (true);
	return (game->map[y][x] == '1');
}
