/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:35:52 by msimic            #+#    #+#             */
/*   Updated: 2025/01/29 17:13:11 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	initialization_of_vars(t_game *game)
{
	ft_bzero(&game->data, sizeof(t_data));
	game->data.win_height = WIN_SIZE;
	game->data.win_width = WIN_SIZE;
	game->data.floor_color_set = false;
	game->data.ceiling_color_set = false;
}
