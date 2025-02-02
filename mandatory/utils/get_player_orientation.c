/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_orientation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:36:27 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/02 20:36:28 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
