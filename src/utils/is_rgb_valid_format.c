/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rgb_valid_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:36:01 by msimic            #+#    #+#             */
/*   Updated: 2025/01/29 12:36:02 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

bool is_rgb_valid_format(char *str)
{
	int i = 0;
	int count = 0;
	int comma = 0;
	int len = ft_strlen(str);
	while (str[i])
	{
		if (str[i] == ','){
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
