#include "../../cub3d.h"

bool	is_door(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map_width || y < 0 || y >= game->map_height)
		return (false);
	if (game->map[y][x] == 'D' || game->map[y][x] == 'd')
		return (true);
	return (false);
}

bool	is_open(t_game *game, int x, int y)
{
	return (game->map[y][x] == 'd');
}

void	toggle_door(t_game *game, int x, int y)
{
	if (is_door(game, x, y))
	{
		if (game->map[y][x] == 'D')
			game->map[y][x] = 'd';
		else if (game->map[y][x] == 'd')
			game->map[y][x] = 'D';
	}
}
