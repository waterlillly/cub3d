#include "../../cub3d.h"

bool	process_line(char *line, t_game *game)
{
	static int	tex_count = 0;
	static int	col_count = 0;
	char		**split;

	if ((tex_count < 4 || col_count < 2) && !game->data.data)
	{
		if (is_line_empty(line))
			return (true);
		split = split_line_into_words(line, game);
		if (split[0] && split[1] && is_texture_identifier(split[0]) && !split[2])
			return (validate_texture_element(split, &tex_count, game));
		else if (split[0] && split[1] && is_color_identifier(split[0]) && !split[2])
			return (validate_color_element(split, &col_count, game));
		else{
			ft_free_2d(split);
			return (false);
		}
	}
	else if (line && is_line_empty(line) && tex_count >= 4
		&& col_count >= 2 && !game->data.data)
		return (true);
	else if (line && !is_line_empty(line) && tex_count >= 4 && col_count >= 2)
		return (append_line_to_map(line, game));
	return (false);
}

void	parse_file(int fd, t_game *game)
{
	char	*line;

	line = NULL;
	line = get_next_line(fd);
	ft_bzero(&game->data, sizeof(t_data));
	game->data.floor_color_set = false;//TODO: add into init instead of here
	game->data.ceiling_color_set = false;
	while (line)
	{
		if (!process_line(line, game))
		{
			free(line);
			line = NULL;
			close(fd);
			exit_failure("Invalid file", game);
		}
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	split_map_into_grid(game);
}
