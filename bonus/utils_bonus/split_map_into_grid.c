/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_map_into_grid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:34:50 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/02 20:34:51 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static bool	memory_set(t_game *game, char **map, int i)
{
	map[i] = ft_calloc(game->data.max_column + 1, sizeof(char));
	if (!map[i])
		return (false);
	ft_memset(map[i], ' ', game->data.max_column);
	ft_memcpy(map[i], game->data.map[i], ft_strlen(game->data.map[i]));
	return (true);
}

bool	split_map_into_grid(t_game *game)
{
	int		i;
	char	**map;

	i = -1;
	if (!game->data.data)
		return (false);
	game->data.map = ft_split(game->data.data, '\n');
	if (!game->data.map)
		return (false);
	max_line_len(game);
	map = ft_calloc(ft_arrlen(game->data.map) + 1, sizeof(char *));
	if (!map)
		return (false);
	while (game->data.map[++i])
	{
		if (!memory_set(game, map, i))
			return (ft_free_2d(map), false);
	}
	if (i < ft_arrlen(game->data.map))
		return (ft_free_2d(map), false);
	game->data.num_of_rows = i;
	ft_free_2d(game->data.map);
	game->data.map = map;
	return (true);
}
