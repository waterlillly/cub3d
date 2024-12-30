#include "../../cub3d.h"

void	move_forward(t_game *game, char **map)//add zoom and rendering
{
	float	new_x;
	float	new_y;

	new_x = -1.0;
	new_y = -1.0;
	// new_x = player->p_x + player->dir_x * player->move_speed;
	// new_y = player->p_y + player->dir_y * player->move_speed;
	new_x = game->player->p_x;
	new_y = game->player->p_y + game->cub->bg_height;
	move_player(game->player, map, new_x, new_y);
}

void	move_backward(t_game *game, char **map)//add zoom and rendering
{
	float	new_x;
	float	new_y;

	new_x = -1.0;
	new_y = -1.0;
	// new_x = player->p_x - player->dir_x * player->move_speed;
	// new_y = player->p_y - player->dir_y * player->move_speed;
	new_x = game->player->p_x;
	new_y = game->player->p_y - game->cub->bg_height;
	move_player(game->player, map, new_x, new_y);
}

void	move_left(t_game *game, char **map)
{
	float	new_x;
	float	new_y;

	new_x = -1.0;
	new_y = -1.0;
	// new_x = player->p_x - player->dir_y * player->move_speed;
	// new_y = player->p_y + player->dir_x * player->move_speed;
	new_x = game->player->p_x - game->cub->bg_width;
	new_y = game->player->p_y;
	move_player(game->player, map, new_x, new_y);
}

void	move_right(t_game *game, char **map)
{
	float	new_x;
	float	new_y;

	new_x = -1.0;
	new_y = -1.0;
	// new_x = player->p_x + player->dir_y * player->move_speed;
	// new_y = player->p_y - player->dir_x * player->move_speed;
	new_x = game->player->p_x + game->cub->bg_width;
	new_y = game->player->p_y;
	move_player(game->player, map, new_x, new_y);
}
