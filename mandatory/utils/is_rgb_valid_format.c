/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rgb_valid_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:36:41 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/02 20:36:42 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
