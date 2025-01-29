/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:22:37 by msimic            #+#    #+#             */
/*   Updated: 2025/01/29 16:43:41 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	validate_row_and_column(t_game *game);
static void	validate_element(t_game *game);
static void	validate_player(t_game *game);

void	is_valid_map(t_game *game)
{
	validate_border(game);
	validate_row_and_column(game);
	validate_element(game);
	validate_player(game);
}

static void	validate_row_and_column(t_game *game)
{
	if (game->data.map == NULL)
		exit_failure("Map missing", game);
	if (game->data.num_of_rows < 3)
		exit_failure("Map is too small", game);
	else
		game->data.map_height = game->data.num_of_rows;
	if (game->data.max_column < 3)
		exit_failure("Map is too small", game);
	else
		game->data.map_width = game->data.max_column;
}

static void	validate_element(t_game *game)
{
	int	row;
	int	column;

	row = -1;
	while (game->data.map[++row])
	{
		column = -1;
		while (game->data.map[row][++column])
		{
			if (!ft_strchr(" 01NSEW", game->data.map[row][column]))
				exit_failure("Invalid character in map", game);
			if (ft_strchr("NSEW", game->data.map[row][column]))
			{
				get_player_orientation(game->data.map[row][column], game);
				game->player.pos.x = row;
				game->player.pos.y = column;
			}
		}
	}
}

static void	validate_player(t_game *game)
{
	int	players;
	int	row;
	int	column;

	players = 0;
	row = -1;
	while (game->data.map[++row])
	{
		column = -1;
		while (game->data.map[row][++column])
		{
			if (ft_strchr("NSEW", game->data.map[row][column]))
				players++;
		}
	}
	if (players != 1)
		exit_failure("Player missing or too many players", game);
}
