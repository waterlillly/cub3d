/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:35:36 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/02 20:35:37 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	floor_ceiling(t_game *game, int x)
{
	int	i;

	i = game->ray.bot - 1;
	while (++i < WIN_HEIGHT)
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

void	calc_side_dist(t_game *game)
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

void	get_direction(t_game *game)
{
	if (game->ray.side == 0)
	{
		game->ray.texture = game->textures[WEST];
		if (game->ray.dir.x > 0)
			game->ray.texture = game->textures[EAST];
		game->ray.correct_dist = (game->ray.sidedist.x - game->ray.deltadist.x)
			/ game->macro.tile_height;
		game->ray.wall_x = (game->ray.map.y + game->ray.correct_dist
				* game->ray.dir.y) / (double)game->macro.tile_height;
	}
	else
	{
		game->ray.texture = game->textures[NORTH];
		if (game->ray.dir.y > 0)
			game->ray.texture = game->textures[SOUTH];
		game->ray.correct_dist = (game->ray.sidedist.y - game->ray.deltadist.y)
			/ game->macro.tile_height;
		game->ray.wall_x = (game->ray.map.x + game->ray.correct_dist
				* game->ray.dir.x) / (double)game->macro.tile_height;
	}
	game->ray.wall_x -= floor(game->ray.wall_x);
}
