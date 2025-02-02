/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_texture_identifier.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:34:34 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/02 20:34:35 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

bool	is_texture_identifier(char *line)
{
	if (ft_strcmp(line, "NO") && ft_strcmp(line, "SO") && ft_strcmp(line, "WE")
		&& ft_strcmp(line, "EA") && ft_strcmp(line, "DO"))
		return (false);
	return (true);
}
