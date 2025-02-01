#include "../../cub3d_bonus.h"

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
	int	y;

	game->ray.tex.x = game->ray.texture.width - (int)(game->ray.wall_x
			* game->ray.texture.width);
	if (game->ray.tex.x == game->ray.texture.width)
		game->ray.tex.x = game->ray.texture.width - game->ray.tex.x;
	else if ((game->ray.side == 0 && game->ray.dir.x > 0) || (game->ray.side == 1
			&& game->ray.dir.y < 0))
		game->ray.tex.x = game->ray.texture.width - game->ray.tex.x - 1;
	game->ray.s = 1.0 * game->ray.texture.height / game->ray.wall_height;
	game->ray.tex_pos = (game->ray.bot - WIN_SIZE / 2 + game->ray.wall_height
			/ 2) * game->ray.s;
	y = game->ray.bot;
	while (y < game->ray.top)
	{
		game->ray.tex.y = (int)game->ray.tex_pos;
		game->ray.tex_pos += game->ray.s;
		game->ray.color = *(unsigned int *)(game->ray.texture.addr
				+ (game->ray.tex.y * game->ray.texture.len + game->ray.tex.x
					* (game->ray.texture.bpp / 8)));
		if (game->ray.side == 1)
			game->ray.color = (game->ray.color >> 1) & 8355711;
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
