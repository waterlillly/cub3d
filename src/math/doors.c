#include "../../cub3d.h"

bool	is_door(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->data.map_width || y < 0 || y >= game->data.map_height)
		return (false);
	if (game->data.map[y][x] == 'D' || game->data.map[y][x] == 'd')
		return (true);
	return (false);
}

bool	is_open(t_game *game, int x, int y)
{
	return (game->data.map[y][x] == 'd');
}

void	toggle_door(t_game *game, int x, int y)
{
	printf("is_door\nx=%d\ny=%d\nblock:%c\n\n\n", x, y, game->data.map[y][x]);
	if (is_door(game, x, y))
	{
		if (game->data.map[y][x] == 'D')
			game->data.map[y][x] = 'd';
		else if (game->data.map[y][x] == 'd')
			game->data.map[y][x] = 'D';
	}
}
