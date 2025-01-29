/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_line_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:36:08 by msimic            #+#    #+#             */
/*   Updated: 2025/01/29 12:36:09 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void max_line_len(t_game *game)
{
	size_t row;

	row = 0;
	game->data.max_column = 0;
	while(game->data.map[row])
	{
		if (ft_strlen(game->data.map[row]) > game->data.max_column)
			game->data.max_column = ft_strlen(game->data.map[row]);
		row++;
	}
}