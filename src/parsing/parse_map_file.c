#include "../../cub3d.h"

bool	append_line_to_map(char *line, t_game *game)
{
	char	*temp;

	if (!game->data.data)
	{
		game->data.data = ft_strdup(line);
		if (!game->data.data)
			return (ft_putendl_fd("Error: strdup failed", 2), false);
		return (true);
	}
	temp = ft_strjoin(game->data.data, line);
	if (!temp)
		return (ft_putendl_fd("Error: strjoin failed", 2), false);
	free(game->data.data);
	game->data.data = temp;
	return (true);
}

bool	validate_and_set_rgb(char *split, t_game *game, int fc)
{
	char	**rgb;
	int		nbr[3];
	int		i;

	rgb = ft_split(split, ',');
	if (!rgb)
		return (false);
	if (ft_arrlen(rgb) != 3)
		return (false);
	i = 0;
	while (rgb[i])
	{
		if (ft_strlen(rgb[i]) > 3 || ft_strlen(rgb[i]) <= 0
			|| !only_digits(rgb[i]))
			return (ft_free_2d(rgb), false);
		nbr[i] = ft_atoi(rgb[i]);
		if (nbr[i] < 0 || nbr[i] > 255)
			return (ft_free_2d(rgb), false);
		if (fc == 0)
		{
			game->data.floor_color[i] = nbr[i];
			if (i == 2)
				game->data.floor_color_set = true;
		}
		else
		{
			game->data.ceiling_color[i] = nbr[i];
			if (i == 2)
				game->data.ceiling_color_set = true;
		}
		i++;
	}
	return (ft_free_2d(rgb), true);
}

bool	validate_color_element(char **split, int *col_count, t_game *game)
{
	if (split[1])
	{
		if ((ft_strcmp(split[0], "F") && validate_and_set_rgb(split[1], game, 0))
			|| (ft_strcmp(split[0], "C") && validate_and_set_rgb(split[1], game, 1)))
		{
			(*col_count)++;
			return (true);
		}
	}
	return (false);
}		

bool	validate_texture_element(char **split, int *tex_count, t_game *game)
{
	if (split[1] && access(split[1], F_OK) == 0)
	{
		if (!ft_strcmp(split[0], "NO"))
		{
			if (game->textures[NORTH].name)
				return(ft_free_2d(split), false);//exit_failure("Duplicate north texture", game));
			game->textures[NORTH].name = ft_strdup(split[1]);
			if (!game->textures[NORTH].name)
				return(ft_free_2d(split), false);//exit_failure("strdup", game));
		}
		else if (!ft_strcmp(split[0], "SO"))
		{
			if (game->textures[SOUTH].name)
				return(ft_free_2d(split), false);//exit_failure("Duplicate south texture", game));
			game->textures[SOUTH].name = ft_strdup(split[1]);
			if (!game->textures[SOUTH].name)
				return(ft_free_2d(split), false);//exit_failure("strdup", game));
		}
		else if (!ft_strcmp(split[0], "EA"))
		{
			if (game->textures[EAST].name)
				return(ft_free_2d(split), false);//exit_failure("Duplicate east texture", game));
			game->textures[EAST].name = ft_strdup(split[1]);
			if (!game->textures[EAST].name)
				return(ft_free_2d(split), false);//exit_failure("strdup", game));
		}
		else if (!ft_strcmp(split[0], "WE"))
		{
			if (game->textures[WEST].name)
				return(ft_free_2d(split), false);//exit_failure("Duplicate west texture", game));
			game->textures[WEST].name = ft_strdup(split[1]);
			if (!game->textures[WEST].name)
				return(ft_free_2d(split), false);//exit_failure("strdup", game));
		}
		ft_free_2d(split);
		(*tex_count)++;
		return (true);
	}
	return (false);
}

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
		if (split[0] && split[1] && is_texture_identifier(split[0]))
			return (validate_texture_element(split, &tex_count, game));
		else if (split[0] && split[1] && is_color_identifier(split[0]))
			return (validate_color_element(split, &col_count, game));
		else
			return (false);
	}
	else if (line && is_line_empty(line) && tex_count >= 4
		&& col_count >= 2 && !game->data.data)
		return (true);
	else if (line && !is_line_empty(line) && tex_count >= 4 && col_count >= 2)
		return (append_line_to_map(line, game));
	return (false);
}

static void	split_map_into_grid(t_game *game)
{
	int		i;
	char	**map;

	i = 0;
	map = NULL;
	game->data.map = ft_split(game->data.data, '\n');
	if (!game->data.map)
		exit_failure("split failed", game);
	max_line_len(game);
	map = ft_calloc(ft_arrlen(game->data.map) + 1, sizeof(char *));
	if (!map)
		exit_failure("calloc failed", game);
	while (game->data.map[i])
	{
		map[i] = ft_calloc(game->data.max_column + 1, sizeof(char));
		if (!map)
			exit_failure("calloc failed", game);
		ft_memset(map[i], ' ', game->data.max_column);
		ft_memcpy(map[i], game->data.map[i], ft_strlen(game->data.map[i]));
		i++;
	}
	ft_free_2d(game->data.map);
	game->data.map = map;
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
	if (game->data.map)
		ft_print_array(game->data.map);
}
