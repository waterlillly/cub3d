/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_color_element.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:37:03 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/02 20:37:04 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	validate_color_element(char **split, int *col_count, t_game *game)
{
	if (split && split[0] && split[1] && !split[2])
	{
		if ((!ft_strcmp(split[0], "F")
				&& validate_and_set_rgb(split[1], game, 0))
			|| (!ft_strcmp(split[0], "C")
				&& validate_and_set_rgb(split[1], game, 1)))
		{
			(*col_count)++;
			return (true);
		}
	}
	return (false);
}
