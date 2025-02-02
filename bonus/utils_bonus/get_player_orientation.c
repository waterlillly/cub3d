/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_orientation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:34:04 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/02 20:34:08 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	get_player_orientation(char orientation, t_game *game)
{
	if (orientation == 'N')
		game->data.p_orientation = NORTH;
	if (orientation == 'S')
		game->data.p_orientation = SOUTH;
	if (orientation == 'E')
		game->data.p_orientation = EAST;
	if (orientation == 'W')
		game->data.p_orientation = WEST;
}
