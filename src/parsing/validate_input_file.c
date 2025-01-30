/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:39:24 by msimic            #+#    #+#             */
/*   Updated: 2025/01/29 16:39:25 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	validate_input_file(char *file, t_game *game)
{
	int	fd;

	if (!file || ft_strlen(file) <= 0)
		exit_failure("no .cub file found", game);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_failure("unable to open .cub file", game);
	parse_file(fd, game);
	close(fd);
}
