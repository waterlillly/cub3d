/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:34:17 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/02 20:34:18 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	initialization_of_vars(t_game *game)
{
	ft_bzero(&game->data, sizeof(t_data));
	ft_bzero(&game->textures, sizeof(t_image) * 5);
	game->data.win_height = WIN_HEIGHT;
	game->data.win_width = WIN_WIDTH;
	game->player.pos.x = -1;
	game->player.pos.y = -1;
}
