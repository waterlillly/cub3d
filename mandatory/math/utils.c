#include "../cub3d.h"

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
	if (x < 0 || x >= game->data.map_width || y < 0
		|| y >= game->data.map_height)
		return (true);
	return (game->data.map[y][x] == '1' || game->data.map[y][x] == ' ');
}
