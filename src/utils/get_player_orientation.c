/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_orientation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:35:49 by msimic            #+#    #+#             */
/*   Updated: 2025/01/29 12:41:31 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

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
