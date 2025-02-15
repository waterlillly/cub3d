/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_line_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:34:37 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/02 20:34:38 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	max_line_len(t_game *game)
{
	size_t	row;

	row = 0;
	game->data.max_column = 0;
	while (game->data.map[row])
	{
		if (ft_strlen(game->data.map[row]) > game->data.max_column)
			game->data.max_column = ft_strlen(game->data.map[row]);
		row++;
	}
}
