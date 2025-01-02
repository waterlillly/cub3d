#include "../../cub3d.h"

void	move_forward(t_game *game)//add zoom and rendering
{
	int	new_x;
	int	new_y;

	new_x = -1.0;
	new_y = -1.0;
	// new_x = player->p_x + player->dir_x * player->move_speed;
	// new_y = player->p_y + player->dir_y * player->move_speed;
	new_x = game->cub.player.p_x;
	new_y = game->cub.player.p_y - 1;//game->player.move_speed;
	if (!move_player(game, new_x, new_y))
		ft_putendl_fd("Error: move_forward", 2);
}

void	move_backward(t_game *game)//add zoom and rendering
{
	int	new_x;
	int	new_y;

	new_x = -1.0;
	new_y = -1.0;
	// new_x = player->p_x - player->dir_x * player->move_speed;
	// new_y = player->p_y - player->dir_y * player->move_speed;
	new_x = game->cub.player.p_x;
	new_y = game->cub.player.p_y + 1;//game->player.move_speed;
	if (!move_player(game, new_x, new_y))
		ft_putendl_fd("Error: move_backward", 2);
}

void	move_left(t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = -1.0;
	new_y = -1.0;
	// new_x = player->p_x - player->dir_y * player->move_speed;
	// new_y = player->p_y + player->dir_x * player->move_speed;
	new_x = game->cub.player.p_x - 1;//game->player.move_speed;
	new_y = game->cub.player.p_y;
	if (!move_player(game, new_x, new_y))
		ft_putendl_fd("Error: move_left", 2);
}

void	move_right(t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = -1.0;
	new_y = -1.0;
	// new_x = player->p_x + player->dir_y * player->move_speed;
	// new_y = player->p_y - player->dir_x * player->move_speed;
	new_x = game->cub.player.p_x + 1;//game->player.move_speed;
	new_y = game->cub.player.p_y;
	if (!move_player(game, new_x, new_y))
		ft_putendl_fd("Error: move_right", 2);
}
