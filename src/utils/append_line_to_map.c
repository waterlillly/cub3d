/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_line_to_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:35:02 by msimic            #+#    #+#             */
/*   Updated: 2025/01/29 12:35:19 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

bool	append_line_to_map(char *line, t_game *game)
{
	char	*temp;

	if (!game->data.data)
	{
		game->data.data = ft_strdup(line);
		if (!game->data.data)
			return (ft_putendl_fd("Error: strdup failed", 2), false);
		return (true);
	}
	temp = ft_strjoin(game->data.data, line);
	if (!temp)
		return (ft_putendl_fd("Error: strjoin failed", 2), false);
	free(game->data.data);
	game->data.data = temp;
	return (true);
}
