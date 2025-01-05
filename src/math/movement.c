#include "../../cub3d.h"

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->cub.player.p_x + cos(game->cub.player.angle) * game->cub.player.move_speed;
	new_y = game->cub.player.p_y + sin(game->cub.player.angle) * game->cub.player.move_speed;
	if (!is_wall(game, new_x / TILE_SIZE, new_y / TILE_SIZE))
	{
		game->cub.player.p_x = new_x;
		game->cub.player.p_y = new_y;
	}
	// else
	// 	ft_putendl_fd("Error: move_forward", 2);
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->cub.player.p_x - cos(game->cub.player.angle) * game->cub.player.move_speed;
	new_y = game->cub.player.p_y - sin(game->cub.player.angle) * game->cub.player.move_speed;
	if (!is_wall(game, new_x / TILE_SIZE, new_y / TILE_SIZE))
	{
		game->cub.player.p_x = new_x;
		game->cub.player.p_y = new_y;
	}
	// else
	// 	ft_putendl_fd("Error: move_backward", 2);
}
void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->cub.player.p_x + cos(game->cub.player.angle) * game->cub.player.move_speed;
	new_y = game->cub.player.p_x;
	if (!is_wall(game, new_x / TILE_SIZE, new_y / TILE_SIZE))
		game->cub.player.p_x = new_x;
	// else
	// 	ft_putendl_fd("Error: move_forward", 2);
}

void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->cub.player.p_x - cos(game->cub.player.angle) * game->cub.player.move_speed;
	new_y = game->cub.player.p_y;
	if (!is_wall(game, new_x / TILE_SIZE, new_y / TILE_SIZE))
		game->cub.player.p_x = new_x;
	// else
	// 	ft_putendl_fd("Error: move_backward", 2);
}

void	turn_left(t_game *game)
{
	game->cub.player.angle -= game->cub.player.turn_speed;
	// printf("turn left -> angle: %f\n", game->cub.player.angle);
}

void	turn_right(t_game *game)
{
	game->cub.player.angle += game->cub.player.turn_speed;
	// printf("turn right -> angle: %f\n", game->cub.player.angle);
}
