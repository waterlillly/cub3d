#include "../cub3d1.h"

/* Normalize a vector
	= scaling it to the length of 1 (unit vector) while keeping its direction
	length gets the actual length of the given vector */
t_dvec	normalize(t_dvec vec)
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
	t_dvec	norm;

	norm = normalize(vec);
	result = atan2(norm.y, norm.x);
	return (result);
}

/* Convert angle to vector + normalize it */
t_dvec	angle_to_vector(double angle)
{
	t_dvec	result;

	result.x = cos(angle);
	result.y = sin(angle);
	return (normalize(result));
}

bool	crashed(t_game *game, int x, int y)
{
	if (x < 0 || x >= MAP_SIZE || y < 0 || y >= MAP_SIZE)
		return (true);
	return (game->map[y][x] == '1');
	// return (g_map[y * MAP_SIZE + x] == 1);
}
