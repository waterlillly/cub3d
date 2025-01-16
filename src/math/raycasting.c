#include "../../cub3d.h"

static void	floor_ceiling(t_game *game, int x)
{
	int	i;

	i = game->ray.bot;
	while (i < WIN_HEIGHT)
	{
		put_my_pixel(game, x, i, game->f_color);
		i++;
	}
	i = 0;
	while (i < game->ray.top)
	{
		put_my_pixel(game, x, i, game->c_color);
		i++;
	}
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
		game->ray.sidedist.x = (game->ray.pos.x - game->ray.map.x)
			* game->ray.deltadist.x;
	}
	else
	{
		game->ray.step.x = 1;
		game->ray.sidedist.x = (game->ray.map.x + 1 - game->ray.pos.x)
			* game->ray.deltadist.x;
	}
	if (game->ray.dir.y < 0)
	{
		game->ray.step.y = -1;
		game->ray.sidedist.y = (game->ray.pos.y - game->ray.map.y)
			* game->ray.deltadist.y;
	}
	else
	{
		game->ray.step.y = 1;
		game->ray.sidedist.y = (game->ray.map.y + 1 - game->ray.pos.y)
			* game->ray.deltadist.y;
	}
}

static void	get_direction(t_game *game)
{
	if (game->ray.side == 0)
	{
		game->ray.texture = game->textures[NORTH];
		if (game->ray.dir.x > 0)
			game->ray.texture = game->textures[SOUTH];
		game->ray.correct_dist = (game->ray.sidedist.x - game->ray.deltadist.x)
			/ TILE_SIZE;
		game->ray.wall_x = game->ray.pos.y + game->ray.correct_dist
			* game->ray.dir.y;
	}
	else
	{
		game->ray.texture = game->textures[WEST];
		if (game->ray.dir.y > 0)
			game->ray.texture = game->textures[EAST];
		game->ray.correct_dist = (game->ray.sidedist.y - game->ray.deltadist.y)
			/ TILE_SIZE;
		game->ray.wall_x = game->ray.pos.x + game->ray.correct_dist
			* game->ray.dir.x;
	}
	game->ray.wall_x -= floor(game->ray.wall_x);
}

static void	calc_wall(t_game *game)
{
	game->ray.wall_height = (int)WIN_HEIGHT / game->ray.correct_dist;
	game->ray.bot = WIN_HEIGHT / 2 - game->ray.wall_height / 2;
	if (game->ray.bot < 0)
		game->ray.bot = 0;
	game->ray.top = WIN_HEIGHT / 2 + game->ray.wall_height / 2;
	if (game->ray.top >= WIN_HEIGHT)
		game->ray.top = WIN_HEIGHT - 1;
}

static void	cast_ray(t_game *game, int x)
{
	int		y;
	double	step;

	game->ray.tex.x = (int)(game->ray.wall_x * game->ray.texture.width);
	if ((game->ray.side == 0 && game->ray.dir.x > 0) ||
		(game->ray.side == 1 && game->ray.dir.y < 0))
		game->ray.tex.x = game->ray.texture.width - game->ray.tex.x - 1;
	step = 1.0 * game->ray.texture.height / game->ray.wall_height;
	game->ray.tex_pos = (game->ray.bot - WIN_HEIGHT / 2 + game->ray.wall_height / 2) * step;
	y = game->ray.bot;
	while (y < game->ray.top)
	{
		game->ray.tex.y = (int)game->ray.tex_pos;
		if (game->ray.tex.y < 0)
			game->ray.tex.y += game->ray.texture.height;
		else if (game->ray.tex.y >= game->ray.texture.height)
			game->ray.tex.y %= game->ray.texture.height;
		game->ray.tex_pos += step;
		game->ray.color = *(unsigned int *)(game->ray.texture.addr
				+ (game->ray.tex.y * game->ray.texture.len + game->ray.tex.x
					* (game->ray.texture.bpp / 8)));
		if (game->ray.side == 1)
			game->ray.color = (game->ray.color >> 1) & 8355711;//TODO: wtf
		put_my_pixel(game, x, y, game->ray.color);
		y++;
	}
}

static void	calc_side(t_game *game, int x)
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
			calc_wall(game);
			cast_ray(game, x);
			break ;
		}
	}
}

void	raycasting(t_game *game)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		game->camera = 2.0 * x / WIN_WIDTH - 1;
		game->ray.dir.x = game->player.dir.x + game->plane.x * game->camera;
		game->ray.dir.y = game->player.dir.y + game->plane.y * game->camera;
		game->ray.pos = game->player.pos;
		game->ray.map.x = (int)game->player.pos.x;
		game->ray.map.y = (int)game->player.pos.y;
		floor_ceiling(game, x);
		calc_side_dist(game);
		calc_side(game, x);
		x++;
	}
}
