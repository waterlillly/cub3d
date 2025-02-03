/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_texture_element.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:33:58 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/03 23:41:10 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static int	check_texture_and_set_no_so(t_game *game, char **split)
{
	if (!ft_strcmp(split[0], "NO"))
	{
		if (game->textures[NORTH].name)
			return (false);
		game->textures[NORTH].name = ft_strdup(split[1]);
		if (!game->textures[NORTH].name)
			return (false);
	}
	else if (!ft_strcmp(split[0], "SO"))
	{
		if (game->textures[SOUTH].name)
			return (false);
		game->textures[SOUTH].name = ft_strdup(split[1]);
		if (!game->textures[SOUTH].name)
			return (false);
	}
	return (true);
}

static int	check_texture_and_set_ea_we(t_game *game, char **split)
{
	if (!ft_strcmp(split[0], "EA"))
	{
		if (game->textures[EAST].name)
			return (false);
		game->textures[EAST].name = ft_strdup(split[1]);
		if (!game->textures[EAST].name)
			return (false);
	}
	else if (!ft_strcmp(split[0], "WE"))
	{
		if (game->textures[WEST].name)
			return (false);
		game->textures[WEST].name = ft_strdup(split[1]);
		if (!game->textures[WEST].name)
			return (false);
	}
	return (true);
}

int	check_texture_and_set_do(t_game *game, char **split)
{
	if (split[0] && split[1] && access(split[1], R_OK) == 0 && !split[2])
	{
		if (ft_strlen(split[1]) < 4)
			return (false);
		if (ft_strncmp(split[1] + ft_strlen(split[1]) - 4, ".xpm", 4) != 0)
			return (false);
		if (!ft_strcmp(split[0], "DO"))
		{
			if (game->textures[DOOR].name)
				return (false);
			game->textures[DOOR].name = ft_strdup(split[1]);
			if (!game->textures[DOOR].name)
				return (false);
			return (true);
		}
	}
	return (false);
}

bool	validate_texture_element(char **split, int *tex_count, t_game *game)
{
	if (split[0] && split[1] && access(split[1], R_OK) == 0 && !split[2])
	{
		if (!ft_strnstr_bool(split[1], ".xpm", ft_strlen(split[1]) - 4, 4))
			return (false);
		if ((!ft_strcmp(split[0], "NO") || !ft_strcmp(split[0], "SO"))
			&& check_texture_and_set_no_so(game, split) == false)
			return (false);
		else if ((!ft_strcmp(split[0], "EA") || !ft_strcmp(split[0], "WE"))
			&& check_texture_and_set_ea_we(game, split) == false)
			return (false);
		// else if (!ft_strcmp(split[0], "DO") && check_texture_and_set_do(game,
		// 		split) == false)
		// 	return (false);
		(*tex_count)++;
		return (true);
	}
	return (false);
}
