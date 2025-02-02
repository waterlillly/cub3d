/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:30:12 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/02 21:11:44 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	main(int ac, char **av)
{
	t_game	*game;

	game = NULL;
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		exit_failure("calloc failed", game);
	initialization_of_vars(game);
	args_handler(ac, av, game);
	validate_game(game, av);
	init_cub(game);
	if (mlx_handler(game) != 0)
		exit_failure("mlx_handler", game);
	mlx_do_key_autorepeatoff(game->cub.mlx_con);
	mlx_loop(game->cub.mlx_con);
	mlx_do_key_autorepeaton(game->cub.mlx_con);
	return (exit_success(game));
}
