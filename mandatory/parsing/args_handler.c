/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:35:52 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/02 20:45:07 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static bool	valid_file(char *s)
{
	if (s[ft_strlen(s) - 5] == '/'
		|| !ft_strcmp(s, ".cub"))
		return (false);
	return (true);
}

void	args_handler(int ac, char **av, t_game *game)
{
	int	arg_len;
	int	fd;

	if (ac != 2 || !av)
		exit_failure(ERROR_ARGS, game);
	arg_len = ft_strlen(av[1]);
	if (arg_len <= 4)
		exit_failure(INVALID_EXTENSION_CUB, game);
	else if (!ft_strnstr(&av[1][arg_len - 4], ".cub", 4))
		exit_failure(INVALID_EXTENSION_CUB, game);
	else if (!valid_file(av[1]))
		exit_failure("Invalid file", game);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit_failure(MAP_FILE_NOT_FOUND, game);
	close(fd);
}
