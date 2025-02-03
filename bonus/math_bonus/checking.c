/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:31:13 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/03 23:52:04 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static int	color(int *color)
{
	return ((color[0] << 16) | (color[1] << 8) | color[2]);
}

void	get_colors(t_game *game)
{
	game->c_color = color(game->data.ceiling_color);
	game->f_color = color(game->data.floor_color);
}

void	check_texture(t_game *game, int i)
{
	if (game->textures[i].width != game->textures[i].height)
		exit_failure("Textures have to have the same width and height", game);
	if (game->textures[i].bpp != 32)
		exit_failure("Texture format not supported (must be 32bpp)", game);
}

bool	is_wall(t_game *game, double new_x, double new_y)
{
	int	x;
	int	y;
	int	nbr;

	x = floor(new_x / (game->macro.tile_width));
	y = floor(new_y / (game->macro.tile_height));
	if (x < 0 || x >= game->data.map_width || y < 0
		|| y >= game->data.map_height)
		return (true);
	if (!game->valid_door && game->data.map[y][x] == 'D')
		return (false);
	nbr = is_door(game, x, y);
	if (nbr >= 0 && is_open(game, nbr))
		return (false);
	return (game->data.map[y][x] == '1' || game->data.map[y][x] == 'D');
}

void	check_doors(t_game *game)
{
	int	time;
	int	c;

	c = 0;
	if (!game->valid_door)
		return ;
	time = get_time(game);
	if (time == -1)
		exit_failure("get time", game);
	while (c < game->num_doors)
	{
		if (game->doors[c].open == true && game->doors[c].open_time
			+ 5000 <= time && is_door(game, (int)game->player.pos.x
				/ game->macro.tile_width, (int)game->player.pos.y
				/ game->macro.tile_height) == -1)
		{
			game->doors[c].open = false;
			game->doors[c].open_time = 0;
		}
		c++;
	}
}
