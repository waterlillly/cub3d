/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_and_set_rgb.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:36:22 by msimic            #+#    #+#             */
/*   Updated: 2025/01/29 12:36:23 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

bool	validate_and_set_rgb(char *split, t_game *game, int fc)
{
	char	**rgb;
	int		nbr[3];
	int		i;

	rgb = ft_split(split, ',');
	if (!rgb)
		return (false);
	if (ft_arrlen(rgb) != 3)
		return (false);
	i = 0;
	while (rgb[i])
	{
		if (ft_strlen(rgb[i]) > 3 || ft_strlen(rgb[i]) <= 0
			|| !only_digits(rgb[i]))
			return (ft_free_2d(rgb), false);
		nbr[i] = ft_atoi(rgb[i]);
		if (nbr[i] < 0 || nbr[i] > 255)
			return (ft_free_2d(rgb), false);
		if (fc == 0)
		{
			game->data.floor_color[i] = nbr[i];
			if (i == 2)
				game->data.floor_color_set = true;
		}
		else
		{
			game->data.ceiling_color[i] = nbr[i];
			if (i == 2)
				game->data.ceiling_color_set = true;
		}
		i++;
	}
	return (ft_free_2d(rgb), true);
}