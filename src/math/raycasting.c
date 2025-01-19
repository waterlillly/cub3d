#include "../../cub3d.h"

static void	floor_ceiling(t_game *game, int x)
{
	int	i;

	i = game->ray.bot - 1;
	while (++i < WIN_SIZE)
		put_my_pixel(game, x, i, game->f_color);
	i = -1;
	while (++i < game->ray.top)
		put_my_pixel(game, x, i, game->c_color);
}

static void	calc_delta_dist(t_game *game)
{
	if (game->ray.dir.x == 0)
		game->ray.deltadist.x = 1e30;
	else
		game->ray.deltadist.x = fabs(1.0 / game->ray.dir.x);
	if (game->ray.dir.y == 0)
		game->ray.deltadist.y = 1e30;
	else
		game->ray.deltadist.y = fabs(1.0 / game->ray.dir.y);
}

static void	calc_side_dist(t_game *game)
{
	calc_delta_dist(game);
	if (game->ray.dir.x < 0)
	{
		game->ray.step.x = -1;
		game->ray.sidedist.x = (game->player.pos.x - game->ray.map.x)
			* game->ray.deltadist.x;
	}
	else
	{
		game->ray.step.x = 1;
		game->ray.sidedist.x = (game->ray.map.x + 1.0 - game->player.pos.x)
			* game->ray.deltadist.x;
	}
	if (game->ray.dir.y < 0)
	{
		game->ray.step.y = -1;
		game->ray.sidedist.y = (game->player.pos.y - game->ray.map.y)
			* game->ray.deltadist.y;
	}
	else
	{
		game->ray.step.y = 1;
		game->ray.sidedist.y = (game->ray.map.y + 1.0 - game->player.pos.y)
			* game->ray.deltadist.y;
	}
}

static void	get_direction(t_game *game)
{
	if (game->ray.side == 0)
	{
		game->ray.texture = game->textures[WEST];
		if (game->ray.dir.x > 0)
			game->ray.texture = game->textures[EAST];
		game->ray.correct_dist = (game->ray.sidedist.x - game->ray.deltadist.x) / TILE_SIZE;
		game->ray.wall_x = (game->ray.map.y + game->ray.correct_dist * game->ray.dir.y) / (double)TILE_SIZE;
	}
	else
	{
		game->ray.texture = game->textures[NORTH];
		if (game->ray.dir.y > 0)
			game->ray.texture = game->textures[SOUTH];
		game->ray.correct_dist = (game->ray.sidedist.y - game->ray.deltadist.y) / TILE_SIZE;
		game->ray.wall_x = (game->ray.map.x + game->ray.correct_dist * game->ray.dir.x) / (double)TILE_SIZE;
	}
	game->ray.wall_x -= floor(game->ray.wall_x);
}

static void	calc_wall_height(t_game *game)
{
	game->ray.wall_height = (int)(WIN_SIZE / game->ray.correct_dist);
	game->ray.bot = WIN_SIZE / 2 - game->ray.wall_height / 2;
	if (game->ray.bot < 0)
		game->ray.bot = 0;
	game->ray.top = WIN_SIZE / 2 + game->ray.wall_height / 2;
	if (game->ray.top >= WIN_SIZE)
		game->ray.top = WIN_SIZE - 1;
}

static void	calc_side(t_game *game)
{
	while (true)
	{
		if (game->ray.sidedist.x < game->ray.sidedist.y)
		{
			game->ray.sidedist.x += game->ray.deltadist.x;
			game->ray.map.x += game->ray.step.x;
			game->ray.side = 0;
		}
		else
		{
			game->ray.sidedist.y += game->ray.deltadist.y;
			game->ray.map.y += game->ray.step.y;
			game->ray.side = 1;
		}
		if (is_wall(game, game->ray.map.x, game->ray.map.y))
		{
			get_direction(game);
			calc_wall_height(game);
			break ;
		}
	}
}

static void	cast_ray(t_game *game, int x)
{
	int		y;

	game->ray.tex.x = (int)(game->ray.wall_x * game->ray.texture.width);
	if ((game->ray.side == 0 && game->ray.dir.x > 0) ||
		(game->ray.side == 1 && game->ray.dir.y < 0))
		game->ray.tex.x = game->ray.texture.width - game->ray.tex.x - 1;
	game->ray.s = 1.0 * game->ray.texture.height / game->ray.wall_height;
	game->ray.tex_pos = (game->ray.bot - WIN_SIZE / 2 + game->ray.wall_height / 2) * game->ray.s;
	y = game->ray.bot;
	while (y < game->ray.top)
	{
		game->ray.tex.y = (int)game->ray.tex_pos;
		game->ray.tex_pos += game->ray.s;
		game->ray.color = *(unsigned int *)(game->ray.texture.addr
				+ (game->ray.tex.y * game->ray.texture.len
				+ game->ray.tex.x * (game->ray.texture.bpp / 8)));
		if (game->ray.side == 1)
			game->ray.color = (game->ray.color >> 1) & 8355711;//TODO: wtf
		put_my_pixel(game, x, y, game->ray.color);
		y++;
	}
}

void	raycasting(t_game *game)
{
	int		x;
	double	camera;

	x = 0;
	while (x < WIN_SIZE)
	{
		camera = 2.0 * x / WIN_SIZE - 1;
		game->ray.dir.x = game->player.dir.x + game->plane.x * camera;
		game->ray.dir.y = game->player.dir.y + game->plane.y * camera;
		floor_ceiling(game, x);
		game->ray.map.x = (int)game->player.pos.x;
		game->ray.map.y = (int)game->player.pos.y;
		calc_side_dist(game);
		calc_side(game);
		cast_ray(game, x);
		x++;
	}
}
