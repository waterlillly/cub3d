#include "../../cub3d.h"

bool	is_wall(t_game *game, double new_x, double new_y)
{
	int	x;
	int	y;

	x = (int)new_x;
	y = (int)new_y;
	if (x < 0 || x >= MAP_WIDTH || y < 0 || y >= MAP_HEIGHT)
		return (true);
	return (game->map[y][x] == '1');
}

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->cub.player.p_x + cos(game->cub.player.angle) * game->cub.player.move_speed;
	new_y = game->cub.player.p_y + sin(game->cub.player.angle) * game->cub.player.move_speed;
	if (!is_wall(game, new_x / TILE_SIZE, game->cub.player.p_y / TILE_SIZE))
		game->cub.player.p_x = new_x;
	if (!is_wall(game, game->cub.player.p_x / TILE_SIZE, new_y / TILE_SIZE))
		game->cub.player.p_y = new_y;
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->cub.player.p_x - cos(game->cub.player.angle) * game->cub.player.move_speed;
	new_y = game->cub.player.p_y - sin(game->cub.player.angle) * game->cub.player.move_speed;
	if (!is_wall(game, new_x / TILE_SIZE, game->cub.player.p_y / TILE_SIZE))
		game->cub.player.p_x = new_x;
	if (!is_wall(game, game->cub.player.p_x / TILE_SIZE, new_y / TILE_SIZE))
		game->cub.player.p_y = new_y;
}

void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->cub.player.p_x + sin(game->cub.player.angle) * game->cub.player.move_speed;
	new_y = game->cub.player.p_y - cos(game->cub.player.angle) * game->cub.player.move_speed;
	if (!is_wall(game, new_x / TILE_SIZE, game->cub.player.p_y / TILE_SIZE))
		game->cub.player.p_x = new_x;
	if (!is_wall(game, game->cub.player.p_x / TILE_SIZE, new_y / TILE_SIZE))
		game->cub.player.p_y = new_y;
}

void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->cub.player.p_x - sin(game->cub.player.angle) * game->cub.player.move_speed;
	new_y = game->cub.player.p_y + cos(game->cub.player.angle) * game->cub.player.move_speed;
	if (!is_wall(game, new_x / TILE_SIZE, game->cub.player.p_y / TILE_SIZE))
		game->cub.player.p_x = new_x;
	if (!is_wall(game, game->cub.player.p_x / TILE_SIZE, new_y / TILE_SIZE))
		game->cub.player.p_y = new_y;
}

void	turn_left(t_game *game)
{
	game->cub.player.angle -= game->cub.player.turn_speed;
	if (game->cub.player.angle < 0)
		game->cub.player.angle += 2 * M_PI;
}

void	turn_right(t_game *game)
{
	game->cub.player.angle += game->cub.player.turn_speed;
	if (game->cub.player.angle >= 2 * M_PI)
		game->cub.player.angle -= 2 * M_PI;
}
