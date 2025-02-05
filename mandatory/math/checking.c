/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:35:06 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/02 20:35:07 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

	x = floor(new_x / (game->macro.tile_width));
	y = floor(new_y / (game->macro.tile_height));
	if (x < 0 || x >= game->data.map_width || y < 0
		|| y >= game->data.map_height)
		return (true);
	return (game->data.map[y][x] == '1');
}
