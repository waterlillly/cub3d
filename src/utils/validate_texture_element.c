/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_texture_element.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:36:28 by msimic            #+#    #+#             */
/*   Updated: 2025/01/29 16:18:37 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	check_texture_and_set_no_so(t_game *game, char **split);
static int	check_texture_and_set_ea_we(t_game *game, char **split);

bool	validate_texture_element(char **split, int *tex_count, t_game *game)
{
	if (split[1] && access(split[1], R_OK) == 0)
	{
		if (check_texture_and_set_no_so(game, split) == false)
			return (false);
		else if (check_texture_and_set_ea_we(game, split) == false)
			return (false);
		ft_free_2d(split);
		(*tex_count)++;
		return (true);
	}
	return (ft_free_2d(split), false);
}

static int	check_texture_and_set_no_so(t_game *game, char **split)
{
	if (!ft_strcmp(split[0], "NO"))
	{
		if (game->textures[NORTH].name)
			return (ft_free_2d(split), false);
		game->textures[NORTH].name = ft_strdup(split[1]);
		if (!game->textures[NORTH].name)
			return (ft_free_2d(split), false);
	}
	else if (!ft_strcmp(split[0], "SO"))
	{
		if (game->textures[SOUTH].name)
			return (ft_free_2d(split), false);
		game->textures[SOUTH].name = ft_strdup(split[1]);
		if (!game->textures[SOUTH].name)
			return (ft_free_2d(split), false);
	}
	return (true);
}

static int	check_texture_and_set_ea_we(t_game *game, char **split)
{
	if (!ft_strcmp(split[0], "EA"))
	{
		if (game->textures[EAST].name)
			return (ft_free_2d(split), false);
		game->textures[EAST].name = ft_strdup(split[1]);
		if (!game->textures[EAST].name)
			return (ft_free_2d(split), false);
	}
	else if (!ft_strcmp(split[0], "WE"))
	{
		if (game->textures[WEST].name)
			return (ft_free_2d(split), false);
		game->textures[WEST].name = ft_strdup(split[1]);
		if (!game->textures[WEST].name)
			return (ft_free_2d(split), false);
	}
	return (true);
}
