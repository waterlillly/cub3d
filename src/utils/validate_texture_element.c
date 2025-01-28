#include "../../cub3d.h"

bool	validate_texture_element(char **split, int *tex_count, t_game *game)
{
	if (split[1] && access(split[1], R_OK) == 0)
	{
		if (!ft_strcmp(split[0], "NO"))
		{
			if (game->textures[NORTH].name)
				return(ft_free_2d(split), false);
			game->textures[NORTH].name = ft_strdup(split[1]);
			if (!game->textures[NORTH].name)
				return(ft_free_2d(split), false);
		}
		else if (!ft_strcmp(split[0], "SO"))
		{
			if (game->textures[SOUTH].name)
				return(ft_free_2d(split), false);
			game->textures[SOUTH].name = ft_strdup(split[1]);
			if (!game->textures[SOUTH].name)
				return(ft_free_2d(split), false);
		}
		else if (!ft_strcmp(split[0], "EA"))
		{
			if (game->textures[EAST].name)
				return(ft_free_2d(split), false);
			game->textures[EAST].name = ft_strdup(split[1]);
			if (!game->textures[EAST].name)
				return(ft_free_2d(split), false);
		}
		else if (!ft_strcmp(split[0], "WE"))
		{
			if (game->textures[WEST].name)
				return(ft_free_2d(split), false);
			game->textures[WEST].name = ft_strdup(split[1]);
			if (!game->textures[WEST].name)
				return(ft_free_2d(split), false);
		}
		ft_free_2d(split);
		(*tex_count)++;
		return (true);
	}
	return (ft_free_2d(split), false);
}
