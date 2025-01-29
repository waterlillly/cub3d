/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_color_element.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:36:25 by msimic            #+#    #+#             */
/*   Updated: 2025/01/29 16:08:58 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

bool	validate_color_element(char **split, int *col_count, t_game *game)
{
	if (split[1])
	{
		if ((ft_strcmp(split[0], "F")
				&& validate_and_set_rgb(split[1], game, 0))
			|| (ft_strcmp(split[0], "C")
				&& validate_and_set_rgb(split[1], game, 1)))
		{
			(*col_count)++;
			return (true);
		}
	}
	ft_free_2d(split);
	return (false);
}
