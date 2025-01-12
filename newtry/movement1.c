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

	new_x = game->player.pos.x + cos(game->player.dir.x) * game->player.move_speed;
	new_y = game->player.pos.y + sin(game->player.dir.y) * game->player.move_speed;
	if (!is_wall(game, new_x, game->player.pos.y))
		game->player.pos.x = new_x;
	if (!is_wall(game, game->player.pos.x, new_y))
		game->player.pos.y = new_y;
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos.x - cos(game->player.dir.x) * game->player.move_speed;
	new_y = game->player.pos.y - sin(game->player.dir.y) * game->player.move_speed;
	if (!is_wall(game, new_x, game->player.pos.y))
		game->player.pos.x = new_x;
	if (!is_wall(game, game->player.pos.x, new_y))
		game->player.pos.y = new_y;
}

void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos.x + sin(game->player.dir.y) * game->player.move_speed;
	new_y = game->player.pos.y - cos(game->player.dir.x) * game->player.move_speed;
	if (!is_wall(game, new_x, game->player.pos.y))
		game->player.pos.x = new_x;
	if (!is_wall(game, game->player.pos.x, new_y))
		game->player.pos.y = new_y;
}

void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos.x - sin(game->player.dir.y) * game->player.move_speed;
	new_y = game->player.pos.y + cos(game->player.dir.x) * game->player.move_speed;
	if (!is_wall(game, new_x, game->player.pos.y))
		game->player.pos.x = new_x;
	if (!is_wall(game, game->player.pos.x, new_y))
		game->player.pos.y = new_y;
}

void	turn_left(t_game *game)
{
	double	angle;

	game->player.dir = normalize(game->player.dir);
	angle = vector_to_angle(game->player.dir) - game->player.turn_speed;
	// game->player.dir = angle_to_vector(angle);
	game->player.dir = normalize(angle_to_vector(angle));
}

void	turn_right(t_game *game)
{
	double	angle;

	game->player.dir = normalize(game->player.dir);
	angle = vector_to_angle(game->player.dir) + game->player.turn_speed;
	// game->player.dir = angle_to_vector(angle);
	game->player.dir = normalize(angle_to_vector(angle));
}
