#include "../cub3d.h"

char	**modify_line(char *line, t_game *game)
{
	char	*temp;
	char	**res;
	int		len;

	len = ft_strlen(line) - 1;
	if (len < 0)
	{
		(free(line), line = NULL);
		exit_failure("Error: Invalid line", game);
	}
	if (line[len] != '\n')
	{
		(free(line), line = NULL);
		exit_failure("Error: Invalid line", game);
	}
	temp = ft_substr(line, 0, len);
	if (!temp)
	{
		(free(line), line = NULL);
		exit_failure("Error: substr failed", game);
	}
	res = ft_split(temp, ' ');
	(free(temp), temp = NULL);
	if (!res)
		exit_failure("Error: split failed", game);
	return (res);
}

bool	is_empty(char *s)
{
	int	i;
	
	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

bool	check_line(char *line, t_game *game)
{
	static int	tex_count = 0;
	static int	col_count = 0;
	char		**split;

	if ((tex_count < 4 || col_count < 2) && !game->data.map_line)
	{
		if (is_empty(line))
			return (true);
		split = modify_line(line, game);
		if (split[0] && split[1] && is_texture(split[0])
			&& (col_count >= 2 || col_count == 0))
			return (check_texture_element(split, &tex_count, game));
		else if (split[0] && split[1] && is_color(split[0])
			&& (tex_count >= 4 || tex_count == 0))
			return (check_color_element(split, &col_count, game));
		else
			return (false);
	}
	else if (line && is_empty(line) && tex_count >= 4
		&& col_count >= 2 && !game->data.map_line)
		return (true);
	else if (line && !is_empty(line) && tex_count >= 4 && col_count >= 2)
		return (add_to_map(line, game));
	return (false);
}

void	check_file(int fd, t_game *game)
{
	char	*line;

	line = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (!check_line(line, game))
		{
			free(line);
			line = NULL;
			close(fd);
			exit_failure("Error: Invalid file", game);
		}
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
}
