/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:36:12 by msimic            #+#    #+#             */
/*   Updated: 2025/01/29 17:13:18 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static bool	process_line(char *line, t_game *game);
static bool	validate_and_process_split(char **split, int *tex_count,
				int *col_count, t_game *game);

void	parse_file(int fd, t_game *game)
{
	char	*line;

	ft_bzero(&game->data, sizeof(t_data));
	errno = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (errno == ENOMEM)
			exit_failure("Invalid file", game);
		if (!line)
			break ;
		if (!process_line(line, game))
		{
			free(line);
			close(fd);
			exit_failure("Invalid file", game);
		}
		free(line);
	}
	close(fd);
	if (!game->data.data)
		exit_failure("empty file", game);
	if (!split_map_into_grid(game))
		exit_failure("split map failed", game);
	// ft_print_array(game->data.map);
}

static bool	validate_and_process_split(char **split, int *tex_count,
int *col_count, t_game *game)
{
	if (split[0] && split[1] && is_texture_identifier(split[0])
		&& !split[2])
	{
		if (!validate_texture_element(split, tex_count, game))
			return (ft_free_2d(split), false);
	}
	else if (split[0] && split[1] && is_color_identifier(split[0])
		&& !split[2])
	{
		if (!validate_color_element(split, col_count, game))
			return (ft_free_2d(split), false);
	}
	else
	{
		ft_free_2d(split);
		return (false);
	}
	return (true);
}

static bool	process_line(char *line, t_game *game)
{
	static int	tex_count = 0;
	static int	col_count = 0;
	char		**split;

	if ((tex_count < 4 || col_count < 2) && !game->data.data)
	{
		if (is_line_empty(line))
			return (true);
		split = NULL;
		split = split_line_into_words(line);
		if (!split)
			return (false);
		if (validate_and_process_split(split, &tex_count,
				&col_count, game) == false)
			return (false);
	}
	else if (line && is_line_empty(line) && tex_count >= 4
		&& col_count >= 2 && !game->data.data)
		return (true);
	else if (line && !is_line_empty(line) && tex_count >= 4 && col_count >= 2)
		return (append_line_to_map(line, game));
	return (true);
}
