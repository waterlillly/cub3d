#include "../../cub3d.h"

int	get_time(t_game *game)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) < 0)
		exit_failure("gettimeofday", game);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

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
	return (game->data.map[y][x] == '1' || game->data.map[y][x] == ' '
		|| game->data.map[y][x] == 'D');
}
