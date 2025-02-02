/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:35:29 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/02 20:35:30 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
			dest = game->cub.img.addr + (y * game->cub.img.len + x
					* (game->cub.img.bpp / 8));
			*(unsigned int *)dest = game->cub.buffer[y][x];
		}
	}
}
