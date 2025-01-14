#include "../cub3d1.h"

// void	draw_vertical_line(t_game *game, int x, t_ray *ray)
// {
// 	int	y;

// 	y = ray->bot;
// 	while (y <= ray->top)
// 	{
// 		// put_my_pixel(game, x, y, ray->color);
// 		game->cub.buffer[y][x] = ray->color;
// 		y++;
// 	}
// }

void	put_my_pixel(t_game *game, int x, int y, int color)
{
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
		game->cub.buffer[y][x] = color;
}

void	buffer_to_image(t_game *game)
{
	int		x;
	int		y;
	char	*dest;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			dest = game->cub.img.addr + (y * game->cub.img.len + x * (game->cub.img.bpp / 8));
			*(unsigned int *)dest = game->cub.buffer[y][x];
		}
	}
}

static void	floor_ceiling(t_game *game, int x)
{
	int	i;

	i = game->ray.bot - 1;
	while (++i < WIN_HEIGHT)
		put_my_pixel(game, x, i, GREEN);
	i = -1;
	while (++i < game->ray.top)
		put_my_pixel(game, x, i, BLUE);
}

void	calc_side_dist(t_game *game)
{
	/* calculate deltadist */
	if (game->ray.dir.x == 0)
		game->ray.deltadist.x = 1e30;
	else
		game->ray.deltadist.x = fabs(1.0 / game->ray.dir.x);
	if (game->ray.dir.y == 0)
		game->ray.deltadist.y = 1e30;
	else
		game->ray.deltadist.y = fabs(1.0 / game->ray.dir.y);
	/* calculate sidedist + step */
	if (game->ray.dir.x < 0)
	{
		game->ray.step.x = -1;
		game->ray.sidedist.x = (game->ray.pos.x - game->ray.map.x) * game->ray.deltadist.x;
	}
	else
	{
		game->ray.step.x = 1;
		game->ray.sidedist.x = (game->ray.map.x + 1 - game->ray.pos.x) * game->ray.deltadist.x;
	}
	if (game->ray.dir.y < 0)
	{
		game->ray.step.y = -1;
		game->ray.sidedist.y = (game->ray.pos.y - game->ray.map.y) * game->ray.deltadist.y;
	}
	else
	{
		game->ray.step.y = 1;
		game->ray.sidedist.y = (game->ray.map.y + 1 - game->ray.pos.y) * game->ray.deltadist.y;
	}
}

/* avoid fisheye effect by using the corrected distance based on
	side == 0 -> ray hit vertical wall
	side == 1 -> ray hit horizontal wall */
void	get_direction(t_game *game)
{
	if (game->ray.side == 0)
	{
		game->ray.texture = game->textures[NORTH];
		if (game->ray.dir.x > 0)
			game->ray.texture = game->textures[SOUTH];
		// game->ray.correct_dist = (game->ray.pos.x - game->player.pos.x + (1 - game->ray.step.x) / 2) / game->ray.dir.x;
		game->ray.correct_dist = (game->ray.sidedist.x - game->ray.deltadist.x);
		game->ray.wall_x = game->ray.pos.y + game->ray.correct_dist * game->ray.dir.y;
	}
	else
	{
		game->ray.texture = game->textures[WEST];
		if (game->ray.dir.y > 0)
			game->ray.texture = game->textures[EAST];
		// game->ray.correct_dist = (game->ray.pos.y - game->player.pos.y + (1 - game->ray.step.y) / 2) / game->ray.dir.y;
		game->ray.correct_dist = (game->ray.sidedist.y - game->ray.deltadist.y);
		game->ray.wall_x = game->ray.pos.x + game->ray.correct_dist * game->ray.dir.x;
	}
	game->ray.wall_x -= floor(game->ray.wall_x);
}

void calc_side(t_game *game, int x)
{
	while (true)
	{
		if (game->ray.sidedist.x < game->ray.sidedist.y)
		{
			game->ray.sidedist.x += game->ray.deltadist.x;
			game->ray.map.x += game->ray.step.x;
			// game->ray.pos.x += game->ray.step.x;
			game->ray.side = 0;
		}
		else
		{
			game->ray.sidedist.y += game->ray.deltadist.y;
			game->ray.map.y += game->ray.step.y;
			// game->ray.pos.y += game->ray.step.y;
			game->ray.side = 1;
		}
		// if (is_wall(game, game->ray.pos.x, game->ray.pos.y))
		if (is_wall(game, game->ray.map.x, game->ray.map.y))
		{
			get_direction(game);
			calc_wall(game);
			cast_ray(game, x);
			break ;
		}
	}
}

void calc_wall(t_game *game)
{
	game->ray.wall_height = WIN_HEIGHT / game->ray.correct_dist;
	game->ray.bot = WIN_HEIGHT / 2 - game->ray.wall_height / 2;
	if (game->ray.bot < 0)
		game->ray.bot = 0;
	game->ray.top = WIN_HEIGHT / 2 + game->ray.wall_height / 2;
	if (game->ray.top >= WIN_HEIGHT)
		game->ray.top = WIN_HEIGHT - 1;
}

void	cast_ray(t_game *game, int x)//better texture mapping
{
	int		y;
	int		d;

	game->ray.tex.x = (int)(game->ray.wall_x * (double)game->ray.texture.width);
	if ((game->ray.side == 0 && game->ray.dir.x > 0) || (game->ray.side == 1 && game->ray.dir.y < 0))
		game->ray.tex.x = game->ray.texture.width - game->ray.tex.x - 1;//for correctly mapping and mirroring texture if needed
	y = game->ray.bot;
	while (y < game->ray.top)
	{
		d = (y * 256) - (WIN_HEIGHT * 128) + (game->ray.wall_height * 128);
		game->ray.tex.y = (((d * game->ray.texture.height) / game->ray.wall_height) / 256);
		game->ray.color = *(unsigned int *)(game->ray.texture.addr + 
				(game->ray.tex.y * game->ray.texture.len + game->ray.tex.x * (game->ray.texture.bpp / 8)));
		put_my_pixel(game, x, y, game->ray.color);
		y++;
	}
}

/*TODO: look at this
 for(int x = 0; x < texWidth; x++)
  for(int y = 0; y < texHeight; y++)
  {
    int xorcolor = (x * 256 / texWidth) ^ (y * 256 / texHeight);
    //int xcolor = x * 256 / texWidth;
    int ycolor = y * 256 / texHeight;
    int xycolor = y * 128 / texHeight + x * 128 / texWidth;
    texture[0][texWidth * y + x] = 65536 * 254 * (x != y && x != texWidth - y); //flat red texture with black cross
    texture[1][texWidth * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
    texture[2][texWidth * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
    texture[3][texWidth * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
    texture[4][texWidth * y + x] = 256 * xorcolor; //xor green
    texture[5][texWidth * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
    texture[6][texWidth * y + x] = 65536 * ycolor; //red gradient
    texture[7][texWidth * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
  }
*/

// void	cast_ray(t_game *game, int x)//original texture mapping
// {
// 	int		y;
// 	double	step;

// 	game->ray.tex.x = (int)(game->ray.wall_x * (double)game->ray.texture.width);
// 	if ((game->ray.side == 0 && game->ray.dir.x > 0) || (game->ray.side == 1 && game->ray.dir.y < 0))
// 		game->ray.tex.x = game->ray.texture.width - game->ray.tex.x - 1;//for correctly mapping and mirroring texture if needed
// 	step = 1.0 * game->ray.texture.height / game->ray.wall_height;
// 	game->ray.tex_pos = (game->ray.bot - WIN_HEIGHT / 2 + game->ray.wall_height / 2) * step;
// 	y = game->ray.bot;
// 	while (y < game->ray.top)
// 	{
// 		game->ray.tex.y = (int)game->ray.tex_pos & (game->ray.texture.height - 1);//cast texture to int and protect from overflow
// 		game->ray.tex_pos += step;
// 		game->ray.color = game->ray.texture.addr[game->ray.texture.height * game->ray.tex.y + game->ray.tex.x];
// 		put_my_pixel(game, x, y, game->ray.color);
// 		y++;
// 	}
// }

void raycasting(t_game *game)
{
	int x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		game->camera = 2.0 * x / WIN_WIDTH - 1;
		game->ray.dir.x = game->player.dir.x + game->plane.x * game->camera;
		game->ray.dir.y = game->player.dir.y + game->plane.y * game->camera;
		game->ray.pos = game->player.pos;
		game->ray.map.x = (int)game->ray.pos.x;
		game->ray.map.y = (int)game->ray.pos.y;
		floor_ceiling(game, x);
		calc_side_dist(game);
		calc_side(game, x);;
		// get_direction(game);
		// calc_wall(game);
		// cast_ray(game, x);
		x++;
	}
}

