#include "../../cub3d.h"

void	init_player(t_game *game)
{
	game->cub.player.p_x = MAP_WIDTH / 2;
	game->cub.player.p_y = MAP_HEIGHT /2;
	game->cub.player.dir_x = 0;
	game->cub.player.dir_y = 0;
	game->cub.player.move_speed = 1;
}

bool	is_wall(t_game *game, int x, int y)
{
	if (x < 0 || x >= MAP_WIDTH || y < 0 || y >= MAP_HEIGHT)
		return (false);
	return (game->map[y][x] == '1');
}

bool	move_player(t_game *game, int new_x, int new_y)
{
	if (!is_wall(game, new_x, game->cub.player.p_y))
		game->cub.player.p_x = new_x;
	else
		return (false);
	if (!is_wall(game, game->cub.player.p_x, new_y))
		game->cub.player.p_y = new_y;
	else
		return (false);
	return (true);
}
