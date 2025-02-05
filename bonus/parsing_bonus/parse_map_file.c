/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:33:00 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/05 20:12:35 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static bool	valid_split(char **split, int *tex_count, int *col_count,
		t_game *game)
{
	if (!split || !split[0] || !split[1] || split[2])
		return (false);
	if (split[0] && split[1] && is_texture_identifier(split[0]))
	{
		if (!validate_texture_element(split, tex_count, game))
			return (false);
	}
	else if (split[0] && split[1] && is_color_identifier(split[0]))
	{
		if (!validate_color_element(split, col_count, game))
			return (false);
	}
	else
		return (false);
	return (true);
}

static bool	check_rest_map(char *line, t_game *game, bool *empty_line)
{
	if (ft_strchr(line, 'D'))
		game->has_door = true;
	if (is_line_empty(line) && game->data.data)
		*empty_line = true;
	if (is_line_empty(line) && !game->data.data)
		return (true);
	if (!*empty_line && !is_line_empty(line) && is_inside_map(line))
	{
		if (ft_only_white(line))
			return (false);
		return (append_line_to_map(line, game));
	}
	else if (!is_line_empty(line) && !is_inside_map(line)
		&& !*empty_line && game->data.data)
		return (false);
	else if (game->has_door && !game->textures[DOOR].name
		&& !is_line_empty(line))
		return (check_for_door_texture(game, line));
	return (true);
}

static bool	process_line(char *line, t_game *game)
{
	static int		tex_count = 0;
	static int		col_count = 0;
	static bool		empty_line = false;
	char			**split;

	if ((tex_count < 4 || col_count < 2) && !game->data.data)
	{
		if (is_line_empty(line))
			return (true);
		split = split_line_into_words(line);
		if (!split)
			return (false);
		if (!valid_split(split, &tex_count, &col_count, game))
			return (ft_free_2d(split), false);
		return (ft_free_2d(split), true);
	}
	else if (tex_count >= 4 && col_count >= 2)
		return (check_rest_map(line, game, &empty_line));
	return (false);
}

static void	init_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		ft_bzero(&game->textures[i], sizeof(t_image));
		i++;
	}
	game->has_door = false;
	game->valid_door = false;
}

void	parse_file(int fd, t_game *game)
{
	char	*line;

	ft_bzero(&game->data, sizeof(t_data));
	errno = 0;
	init_textures(game);
	while (true)
	{
		line = get_next_line(fd);
		if (errno == ENOMEM)
			(free(line), close(fd), exit_failure("get_next_line", game));
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
	if (game->has_door && !game->valid_door)
		exit_failure("No door texture found", game);
	if (!split_map_into_grid(game))
		exit_failure("split map failed", game);
}
