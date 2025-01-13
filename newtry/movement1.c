#include "../cub3d1.h"

bool	is_wall(t_game *game, double new_x, double new_y)
{
	int	x;
	int	y;

	x = floor(new_x / (TILE_SIZE));
	y = floor(new_y / (TILE_SIZE));
	if (x < 0 || x >= MAP_SIZE || y < 0 || y >= MAP_SIZE)
		return (true);
	return (game->map[y][x] == '1');
}

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

// static void	rotate_plane(t_game *game, double angle)
// {
// 	double	old_plane_x;

// 	old_plane_x = game->plane.x;
// 	game->plane.x = old_plane_x * cos(angle) - game->plane.y * sin(angle);
// 	game->plane.y = old_plane_x * sin(angle) + game->plane.y * cos(angle);
// }

void	turn_left(t_game *game)
{
	double	angle;

	angle = vector_to_angle(game->player.dir) - game->player.turn_speed;
	game->player.dir = angle_to_vector(angle);
	// rotate_plane(game, -game->player.turn_speed);
	game->plane.x *= cos(game->player.turn_speed) - game->plane.y * sin(game->player.turn_speed);
	game->plane.y = game->plane.x * sin(game->player.turn_speed) + game->plane.y * cos(game->player.turn_speed);
}

void	turn_right(t_game *game)
{
	double	angle;

	angle = vector_to_angle(game->player.dir) + game->player.turn_speed;
	game->player.dir = angle_to_vector(angle);
	// rotate_plane(game, game->player.turn_speed);
	game->plane.x *= cos(game->player.turn_speed) - game->plane.y * sin(game->player.turn_speed);
	game->plane.y = game->plane.x * sin(game->player.turn_speed) + game->plane.y * cos(game->player.turn_speed);
}
