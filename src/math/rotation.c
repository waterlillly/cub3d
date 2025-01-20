#include "../../cub3d.h"

static void	rotate_plane(t_game *game, double angle)
{
	double	old_plane_x;

	old_plane_x = game->plane.x;
	game->plane.x = old_plane_x * cos(angle) - game->plane.y * sin(angle);
	game->plane.y = old_plane_x * sin(angle) + game->plane.y * cos(angle);
}

static void	rotate_dir(t_game *game, double angle)
{
	double	old_dir_x;

	old_dir_x = game->player.dir.x;
	game->player.dir.x = old_dir_x * cos(angle) - game->player.dir.y
		* sin(angle);
	game->player.dir.y = old_dir_x * sin(angle) + game->player.dir.y
		* cos(angle);
}

void	turn_left(t_game *game)
{
	// if (game->control.turn_left_velo < 0.3)
	// 	game->control.turn_left_velo += 0.05;
	printf("turn_left: %f\n", game->control.turn_left_velo);
	rotate_dir(game, -game->control.turn_left_velo);
	rotate_plane(game, -game->control.turn_left_velo);
}

void	turn_right(t_game *game)
{
	// if (game->control.turn_right_velo < 0.3)
	// 	game->control.turn_right_velo += 0.05;
	printf("turn_right: %f\n", game->control.turn_right_velo);
	rotate_dir(game, game->control.turn_right_velo);
	rotate_plane(game, game->control.turn_right_velo);
}
