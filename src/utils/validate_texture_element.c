#include "../../cub3d.h"

static int	check_texture_and_set_no_so(t_game *game, char **split)
{
	if (!ft_strcmp(split[0], "NO"))
	{
		if (game->textures[NORTH].name)
			return (false);
		game->textures[NORTH].name = ft_strdup(split[1]);
		if (!game->textures[NORTH].name)
			return (false);
	}
	else if (!ft_strcmp(split[0], "SO"))
	{
		if (game->textures[SOUTH].name)
			return (false);
		game->textures[SOUTH].name = ft_strdup(split[1]);
		if (!game->textures[SOUTH].name)
			return (false);
	}
	return (true);
}

static int	check_texture_and_set_ea_we(t_game *game, char **split)
{
	if (!ft_strcmp(split[0], "EA"))
	{
		if (game->textures[EAST].name)
			return (false);
		game->textures[EAST].name = ft_strdup(split[1]);
		if (!game->textures[EAST].name)
			return (false);
	}
	else if (!ft_strcmp(split[0], "WE"))
	{
		if (game->textures[WEST].name)
			return (false);
		game->textures[WEST].name = ft_strdup(split[1]);
		if (!game->textures[WEST].name)
			return (false);
	}
	return (true);
}

bool	validate_texture_element(char **split, int *tex_count, t_game *game)
{
	if (split[1] && access(split[1], R_OK) == 0 && !split[2])
	{
		if (!ft_strnstr_bool(split[1], ".xpm", ft_strlen(split[1]) - 4, 4))
			return (false);
		if ((!ft_strcmp(split[0], "NO") || !ft_strcmp(split[0], "SO"))
			&& check_texture_and_set_no_so(game, split) == false)
			return (false);
		else if ((!ft_strcmp(split[0], "EA") || !ft_strcmp(split[0], "WE"))
			&& check_texture_and_set_ea_we(game, split) == false)
			return (false);
		(*tex_count)++;
		return (true);
	}
	return (false);
}
