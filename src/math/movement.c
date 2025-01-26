#include "../../cub3d.h"

void	move_forward(t_game *game)
{
	double			new_x;
	double			new_y;

	if (game->control.forward_velo < game->player.move_speed)
		game->control.forward_velo += 0.5;
	// printf("forward: %f\n", game->control.forward_velo);
	new_x = game->player.pos.x + game->player.dir.x
		* game->control.forward_velo;
	new_y = game->player.pos.y + game->player.dir.y
		* game->control.forward_velo;
	if (!is_wall(game, new_x, game->player.pos.y))
		game->player.pos.x = new_x;
	if (!is_wall(game, game->player.pos.x, new_y))
		game->player.pos.y = new_y;
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	
	if (game->control.backward_velo < game->player.move_speed)
		game->control.backward_velo += 0.5;
	// printf("backward: %f\n", game->control.backward_velo);
	new_x = game->player.pos.x - game->player.dir.x
		* game->control.backward_velo;
	new_y = game->player.pos.y - game->player.dir.y
		* game->control.backward_velo;
	if (!is_wall(game, new_x, game->player.pos.y))
		game->player.pos.x = new_x;
	if (!is_wall(game, game->player.pos.x, new_y))
		game->player.pos.y = new_y;
}

void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	if (game->control.left_velo < game->player.move_speed)
		game->control.left_velo += 0.5;
	// printf("left: %f\n", game->control.left_velo);
	new_x = game->player.pos.x + game->player.dir.y * game->control.left_velo;
	new_y = game->player.pos.y - game->player.dir.x * game->control.left_velo;
	if (!is_wall(game, new_x, game->player.pos.y))
		game->player.pos.x = new_x;
	if (!is_wall(game, game->player.pos.x, new_y))
		game->player.pos.y = new_y;
}

void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	if (game->control.right_velo < game->player.move_speed)
		game->control.right_velo += 0.5;
	// printf("right: %f\n", game->control.right_velo);
	new_x = game->player.pos.x - game->player.dir.y * game->control.right_velo;
	new_y = game->player.pos.y + game->player.dir.x * game->control.right_velo;
	if (!is_wall(game, new_x, game->player.pos.y))
		game->player.pos.x = new_x;
	if (!is_wall(game, game->player.pos.x, new_y))
		game->player.pos.y = new_y;
}
