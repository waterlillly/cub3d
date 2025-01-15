#include "../../cub3d.h"

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos.x + game->player.dir.x * game->player.move_speed;
	new_y = game->player.pos.y + game->player.dir.y * game->player.move_speed;
	if (!is_wall(game, new_x, game->player.pos.y))
		game->player.pos.x = new_x;
	if (!is_wall(game, game->player.pos.x, new_y))
		game->player.pos.y = new_y;
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos.x - game->player.dir.x * game->player.move_speed;
	new_y = game->player.pos.y - game->player.dir.y * game->player.move_speed;
	if (!is_wall(game, new_x, game->player.pos.y))
		game->player.pos.x = new_x;
	if (!is_wall(game, game->player.pos.x, new_y))
		game->player.pos.y = new_y;
}

void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos.x + game->player.dir.y * game->player.move_speed;
	new_y = game->player.pos.y - game->player.dir.x * game->player.move_speed;
	if (!is_wall(game, new_x, game->player.pos.y))
		game->player.pos.x = new_x;
	if (!is_wall(game, game->player.pos.x, new_y))
		game->player.pos.y = new_y;
}

void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos.x - game->player.dir.y * game->player.move_speed;
	new_y = game->player.pos.y + game->player.dir.x * game->player.move_speed;
	if (!is_wall(game, new_x, game->player.pos.y))
		game->player.pos.x = new_x;
	if (!is_wall(game, game->player.pos.x, new_y))
		game->player.pos.y = new_y;
}
