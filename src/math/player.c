#include "../../cub3d.h"

void	init_player(t_game *game)
{
	t_player	player;

	ft_bzero(&player, sizeof(t_player));
	game->player = &player;
	game->player->p_x = 3.0;
	game->player->p_y = 7.0;
	game->player->dir_x = 0.0;
	game->player->dir_y = 0.0;
	game->player->move_speed = 1.2;
}

bool is_walkable(char **map, int x, int y)
{
	return (map[y][x] == '0');
}

int	move_player(t_game *game, int key)
{
	float	new_x;
	float	new_y;

	if (key == XK_Escape)
		return (exit_success(game));
	if (key == XK_Up)
	{
		new_x = game->player->p_x + game->player->dir_x * game->player->move_speed;
		new_y = game->player->p_y + game->player->dir_y * game->player->move_speed;
	}
	else if (key == XK_Down)
	{
		new_x = game->player->p_x - game->player->dir_x * game->player->move_speed;
		new_y = game->player->p_y - game->player->dir_y * game->player->move_speed;
	}
	else if (key == XK_Left)
	{
		new_x = game->player->p_x - game->player->dir_y * game->player->move_speed;
		new_y = game->player->p_y + game->player->dir_x * game->player->move_speed;
	}
	else if (key == XK_Right)
	{
		new_x = game->player->p_x + game->player->dir_y * game->player->move_speed;
		new_y = game->player->p_y - game->player->dir_x * game->player->move_speed;
	}
	else
		return (1);
	if (is_walkable(game->map, (int)new_x, (int)game->player->p_y))
		game->player->p_x = new_x;
	if (is_walkable(game->map, (int)game->player->p_x, (int)new_y))
		game->player->p_y = new_y;
	return (0);
}
