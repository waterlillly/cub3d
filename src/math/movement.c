#include "../../cub3d.h"

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
	game->player.dir.x = old_dir_x * cos(angle) - game->player.dir.y * sin(angle);
	game->player.dir.y = old_dir_x * sin(angle) + game->player.dir.y * cos(angle);
}

void	turn_left(t_game *game)
{
	// double	angle;

	rotate_dir(game, -game->player.turn_speed);
	rotate_plane(game, -game->player.turn_speed);
	// angle = vector_to_angle(game->player.dir) - game->player.turn_speed;
	// game->player.dir = angle_to_vector(angle);
	// game->plane.x *= cos(game->player.turn_speed) - game->plane.y * sin(game->player.turn_speed);
	// game->plane.y = game->plane.x * sin(game->player.turn_speed) + game->plane.y * cos(game->player.turn_speed);
}

void	turn_right(t_game *game)
{
	// double	angle;

	rotate_dir(game, game->player.turn_speed);
	rotate_plane(game, game->player.turn_speed);
	// angle = vector_to_angle(game->player.dir) + game->player.turn_speed;
	// game->player.dir = angle_to_vector(angle);
	// game->plane.x *= cos(game->player.turn_speed) - game->plane.y * sin(game->player.turn_speed);
	// game->plane.y = game->plane.x * sin(game->player.turn_speed) + game->plane.y * cos(game->player.turn_speed);
}

/*TODO: look at this
 if (keyDown(SDLK_UP))
    {
      if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
      if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
    }
    //move backwards if no wall behind you
    if (keyDown(SDLK_DOWN))
    {
      if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
      if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
    }
    //rotate to the right
    if (keyDown(SDLK_RIGHT))
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = dirX;
      dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
      dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
      planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
    }
    //rotate to the left
    if (keyDown(SDLK_LEFT))
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = dirX;
      dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
      dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
      planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
    }
  }
}
*/