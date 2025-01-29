/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rgb_valid_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:36:01 by msimic            #+#    #+#             */
/*   Updated: 2025/01/29 15:45:34 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

bool	is_rgb_valid_format(char *str)
{
	int	i;
	int	count;
	int	comma;
	int	len;

	i = 0;
	count = 0;
	comma = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if (str[i] == ',')
		{
			count++;
			comma = i;
			if (comma == 0 || comma == len - 1)
				return (false);
		}
		i++;
	}
	if (count == 2)
		return (true);
	return (false);
}

// if (!rgb_format(res))
// 	return (ft_free_2d(res), NULL);

// static bool rgb_format(char **str)
// {
// 	int i;
// 	int j;

// 	i = -1;
// 	ft_print_array(str);
// 	while (str[++i])
// 	{
// 		if (ft_strchr(str[0], 'C') || ft_strchr(str[0], 'F'))
// 		{
// 			j = -1;
// 			while (str[1][++j])
// 			{
// 				if (!is_rgb_valid_format(str[1]))
// 					return (false);
// 			}
// 		}
// 	}
// 	return (true);
// }