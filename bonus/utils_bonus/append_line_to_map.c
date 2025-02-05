/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_line_to_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:34:01 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/05 12:42:49 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

bool	is_inside_map(char *line)
{
	int	i;

	i = 0;
	if (!line || ft_only_white(line))
		return (false);
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1'
			&& line[i] != 'D' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'W' && line[i] != 'E')
			return (false);
		i++;
	}
	if (! line[i] || line[i] == '\n')
		return (true);
	return (false);
}

bool	append_line_to_map(char *line, t_game *game)
{
	char	*temp;

	if (!game->data.data)
	{
		game->data.data = ft_strdup(line);
		if (!game->data.data)
			return (false);
		return (true);
	}
	temp = ft_strjoin(game->data.data, line);
	if (!temp)
		return (false);
	free(game->data.data);
	game->data.data = temp;
	return (true);
}
