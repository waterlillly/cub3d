/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_and_set_rgb.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:33:38 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/02 20:33:39 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static int	only_digit_and_len(char **rgb, int i)
{
	if (ft_strlen(rgb[i]) > 3)
		return (0);
	if (only_digits(rgb[i]) == false)
		return (0);
	return (1);
}

static bool	check_for_correct_values(int nbr)
{
	if (nbr < 0 || nbr > 255)
		return (false);
	return (true);
}

static bool	check_for_comma(char *split)
{
	int	i;
	int	comma_count;
	int	comma_position;

	i = 0;
	comma_count = 0;
	comma_position = -1;
	while (split[i])
	{
		if (split[i] == ',')
		{
			comma_count++;
			comma_position = i;
		}
		i++;
	}
	if (comma_count != 2)
		return (false);
	if (comma_position == 0 || comma_position == i - 1)
		return (false);
	return (true);
}

static void	check_color_and_set(int *nbr, int i, t_game *game, int fc)
{
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
}

bool	validate_and_set_rgb(char *split, t_game *game, int fc)
{
	char	**rgb;
	int		nbr[3];
	int		i;

	if (check_for_comma(split) == false)
		return (false);
	rgb = ft_split(split, ',');
	if (!rgb)
		return (false);
	if (ft_arrlen(rgb) != 3)
		return (ft_free_2d(rgb), false);
	i = -1;
	while (rgb[++i])
	{
		if (only_digit_and_len(rgb, i) == 0)
			return (ft_free_2d(rgb), false);
		nbr[i] = ft_atoi(rgb[i]);
		if (check_for_correct_values(nbr[i]) == false)
			return (ft_free_2d(rgb), false);
		check_color_and_set(nbr, i, game, fc);
	}
	if (i != 3 || rgb[i] != NULL)
		return (ft_free_2d(rgb), false);
	return (ft_free_2d(rgb), true);
}
