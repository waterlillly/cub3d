/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_texture_identifier.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:36:44 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/02 20:36:46 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	is_texture_identifier(char *line)
{
	if (ft_strcmp(line, "NO") && ft_strcmp(line, "SO") && ft_strcmp(line, "WE")
		&& ft_strcmp(line, "EA"))
		return (false);
	return (true);
}
