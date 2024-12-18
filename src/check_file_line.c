#include "../cub3d.h"

char	**modify_line(char *line, t_pars *pars)
{
	char	*temp;
	char	**res;
	int		len;

	len = ft_strlen(line) - 1;
	if (len < 0)
	{
		(free(line), line = NULL);
		err("Error: Invalid line", pars);
	}
	if (line[len] != '\n')
	{
		(free(line), line = NULL);
		err("Error: Invalid line", pars);
	}
	temp = ft_substr(line, 0, len);
	if (!temp)
	{
		(free(line), line = NULL);
		err("Error: substr failed", pars);
	}
	res = ft_split(temp, ' ');
	(free(temp), temp = NULL);
	if (!res)
		err("Error: split failed", pars);
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

bool	check_line(char *line, t_pars *pars)
{
	static int	tex_count = 0;
	static int	col_count = 0;
	char		**split;

	if ((tex_count < 4 || col_count < 2) && !pars->map_line)
	{
		if (is_empty(line))
			return (true);
		split = modify_line(line, pars);
		if (split[0] && split[1] && is_texture(split[0]))
			return (check_texture_element(split, &tex_count, pars));
		else if (split[0] && split[1] && is_color(split[0]))
			return (check_color_element(split, &col_count, pars));
		else
			return (false);
	}
	else if (line && is_empty(line) && tex_count >= 4
		&& col_count >= 2 && !pars->map_line)
		return (true);
	else if (line && !is_empty(line) && tex_count >= 4 && col_count >= 2)
		return (add_to_map(line, pars));
	return (false);
}

void	check_file(int fd, t_pars *pars)
{
	char	*line;

	line = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (!check_line(line, pars))
		{
			free(line);
			line = NULL;
			close(fd);
			err("Error: Invalid file", pars);
		}
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
}
