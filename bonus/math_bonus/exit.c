/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:32:23 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/03 23:17:03 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	free_all(t_game *game)
{
	if (game->data.map)
		ft_free_2d(game->data.map);
	if (game->data.data)
		free(game->data.data);
	if (game->data.file_data)
		ft_free_2d(game->data.file_data);
	if (game->textures[NORTH].name)
		free(game->textures[NORTH].name);
	if (game->textures[SOUTH].name)
		free(game->textures[SOUTH].name);
	if (game->textures[EAST].name)
		free(game->textures[EAST].name);
	if (game->textures[WEST].name)
		free(game->textures[WEST].name);
}

static void	destroy_mlx(t_game *game)
{
	if (game && game->cub.mlx_con && game->textures[EAST].img)
		mlx_destroy_image(game->cub.mlx_con, game->textures[EAST].img);
	if (game && game->cub.mlx_con && game->textures[WEST].img)
		mlx_destroy_image(game->cub.mlx_con, game->textures[WEST].img);
	if (game && game->cub.mlx_con && game->textures[NORTH].img)
		mlx_destroy_image(game->cub.mlx_con, game->textures[NORTH].img);
	if (game && game->cub.mlx_con && game->textures[SOUTH].img)
		mlx_destroy_image(game->cub.mlx_con, game->textures[SOUTH].img);
	if (game && game->cub.mlx_con && game->cub.img.img)
		mlx_destroy_image(game->cub.mlx_con, game->cub.img.img);
	if (game && game->cub.mlx_con && game->cub.mlx_win)
		mlx_destroy_window(game->cub.mlx_con, game->cub.mlx_win);
	if (game && game->cub.mlx_con)
	{
		mlx_destroy_display(game->cub.mlx_con);
		free(game->cub.mlx_con);
	}
}

static void	free_data(t_game *game)
{
	if (!game)
		return ;
	if (game->doors)
		free(game->doors);
	if (game->textures[DOOR].name)
	{
		free(game->textures[DOOR].name);
		if (game && game->cub.mlx_con && game->textures[DOOR].img)
			mlx_destroy_image(game->cub.mlx_con, game->textures[DOOR].img);
	}
	free_all(game);
	destroy_mlx(game);
}

void	exit_failure(char *s, t_game *game)
{
	if (!game)
		exit(EXIT_FAILURE);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(s, STDERR_FILENO);
	get_next_line(-1);
	if (game->cub.mlx_win)
		mlx_do_key_autorepeaton(game->cub.mlx_con);
	free_data(game);
	if (game)
	{
		free(game);
		game = NULL;
	}
	exit(EXIT_FAILURE);
}

int	exit_success(t_game *game)
{
	if (!game)
		exit(EXIT_FAILURE);
	if (game && game->cub.mlx_win)
		mlx_do_key_autorepeaton(game->cub.mlx_con);
	free_data(game);
	if (game)
	{
		free(game);
		game = NULL;
	}
	exit(EXIT_SUCCESS);
}
