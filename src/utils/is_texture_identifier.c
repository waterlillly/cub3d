/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_texture_identifier.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:36:04 by msimic            #+#    #+#             */
/*   Updated: 2025/01/29 12:36:05 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

bool	is_texture_identifier(char *line)
{
	if (ft_strcmp(line, "NO") && ft_strcmp(line, "SO")
		&& ft_strcmp(line, "WE") && ft_strcmp(line, "EA"))
		return (false);
	return (true);
}