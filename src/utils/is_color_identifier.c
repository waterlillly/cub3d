/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_color_identifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:35:56 by msimic            #+#    #+#             */
/*   Updated: 2025/01/29 12:43:01 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

bool	is_color_identifier(char *trim)
{
	if (ft_strcmp(trim, "F") && ft_strcmp(trim, "C"))
		return (false);
	return (true);
}
