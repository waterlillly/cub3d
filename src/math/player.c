#include "../../cub3d.h"

void	init_player(t_game *game)
{
	t_player	player;

	ft_bzero(&player, sizeof(t_player));
	game->player = &player;
	game->player->p_x = 0.0;
	game->player->p_y = 0.0;
	game->player->dir_x = 0.0;
	game->player->dir_y = 0.0;
	game->player->move_speed = 1.2;
}

bool is_walkable(char **map, int x, int y)
{
	return (map[y][x] == '0');
}

void	move_player(t_player *player, char **map, float new_x, float new_y)
{
	if (new_x >= 0 && is_walkable(map, (int)new_x, (int)player->p_y))
		player->p_x = new_x;
	if (new_y >= 0 && is_walkable(map, (int)player->p_x, (int)new_y))
		player->p_y = new_y;
}
