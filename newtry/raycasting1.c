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

void	calc_side_dist(t_ray *ray)
{
	/* calculate deltadist */
	ray->deltadist.x = fabs(ray->dir.x);
	if (ray->deltadist.x < 1e-20)
		ray->deltadist.x = 1e30;
	else
		ray->deltadist.x = fabs(1.0 / ray->dir.x);
	ray->deltadist.y = fabs(ray->dir.y);
	if (ray->deltadist.y < 1e-20)
		ray->deltadist.y = 1e30;
	else
		ray->deltadist.y = fabs(1.0 / ray->dir.y);
	/* calculate sidedist + step */
	ray->step.x = 1;
	ray->sidedist.x = (ceil(ray->pos.x) - ray->pos.x) * ray->deltadist.x;
	// ray->sidedist.x = ray->deltadist.x * ((int)ray->pos.x + 1.0 - ray->pos.x);
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->sidedist.x = (ray->pos.x - floor(ray->pos.x)) * ray->deltadist.x;
		// ray->sidedist.x = ray->deltadist.x * (ray->pos.x - (int)ray->pos.x);
	}
	ray->step.y = 1;
	ray->sidedist.y = (ceil(ray->pos.y) - ray->pos.y) * ray->deltadist.y;
	// ray->sidedist.y = ray->deltadist.y * ((int)ray->pos.y + 1.0 - ray->pos.y);
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->sidedist.y = (ray->pos.y - floor(ray->pos.y)) * ray->deltadist.y;
		// ray->sidedist.y = ray->deltadist.y * (ray->pos.y - (int)ray->pos.y);
	}
}

void	get_direction(t_ray *ray, t_game *game)
{
	if (ray->side == 0)
	{
		ray->texture = game->textures[WEST];
		if (ray->dir.x > 0)
			ray->texture = game->textures[EAST];
	}
	else
	{
		ray->texture = game->textures[NORTH];
		if (ray->dir.y > 0)
			ray->texture = game->textures[SOUTH];
	}
	/* avoid fisheye effect by using the corrected distance based on
		side == 0 -> ray hit vertical wall
		side == 1 -> ray hit horizontal wall */
	if (ray->side == 0)
	{
		ray->correct_dist = (ray->pos.x - game->player.pos.x + (1 - ray->step.x) / 2) / ray->dir.x;
		// ray->correct_dist = (ray->sidedist.x - ray->deltadist.x);
		ray->wall_x = ray->pos.y + ray->correct_dist * ray->dir.y;
	}
	else
	{
		ray->correct_dist = (ray->pos.y - game->player.pos.y + (1 - ray->step.y) / 2) / ray->dir.y;
		// ray->correct_dist = (ray->sidedist.y - ray->deltadist.y);
		ray->wall_x = ray->pos.x + ray->correct_dist * ray->dir.x;
	}
	ray->wall_x -= floor(ray->wall_x);
}

void calc_side(t_game *game, t_ray *ray)
{
	while (true)
	{
		if (ray->sidedist.x < ray->sidedist.y)
		{
			ray->sidedist.x += ray->deltadist.x;
			ray->pos.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist.y += ray->deltadist.y;
			ray->pos.y += ray->step.y;
			ray->side = 1;
		}
		// if (is_wall(game, ray->pos.x, ray->pos.y))
		if (crashed(game, ray->pos.x, ray->pos.y))
			break ;
	}
}

void calc_wall(t_ray *ray)
{
	ray->wall_height = WIN_HEIGHT / ray->correct_dist;
	ray->bot = WIN_HEIGHT / 2 - ray->wall_height / 2;
	if (ray->bot < 0)
		ray->bot = 0;
	ray->top = WIN_HEIGHT / 2 + ray->wall_height / 2;
	if (ray->top >= WIN_HEIGHT)
		ray->top = WIN_HEIGHT - 1;
}

void	cast_ray(t_game *game, t_ray *ray, int x)
{
	int		y;
	int		d;

	ray->tex.x = (int)(ray->wall_x * ray->texture.width);
	if ((ray->side == 0 && ray->dir.x > 0) || (ray->side == 1 && ray->dir.y < 0))
		ray->tex.x = ray->texture.width - ray->tex.x - 1;
	y = ray->bot;
	while (y < ray->top)
	{
		d = (y * 256) - (WIN_HEIGHT * 128) + (ray->wall_height * 128);
		ray->tex.y = ((d * ray->texture.height) / ray->wall_height) / 256;
		ray->color = *(unsigned int *)(ray->texture.addr + 
				(ray->tex.y * ray->texture.len + ray->tex.x * (ray->texture.bpp / 8)));
		put_my_pixel(game, x, y, ray->color);
		y++;
	}
}

void raycasting(t_game *game)
{
	int x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		game->ray.camera = 2.0 * x / WIN_WIDTH - 1;
		game->ray.dir.x = game->player.dir.x + game->player.plane.x * game->ray.camera;
		game->ray.dir.y = game->player.dir.y + game->player.plane.y * game->ray.camera;
		game->ray.pos = game->player.pos;
		calc_side_dist(&game->ray);
		calc_side(game, &game->ray);
		get_direction(&game->ray, game);
		calc_wall(&game->ray);
		floor_ceiling(game, x);
		cast_ray(game, &game->ray, x);
		x++;
	}
}

