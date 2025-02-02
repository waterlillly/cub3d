/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:36:10 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/02 20:46:08 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	validate_game(t_game *game, char **av)
{
	if (!av)
		exit_failure("no av", game);
	validate_input_file(av[1], game);
	is_valid_map(game);
}
