#include "../cub3d_bonus.h"

bool	is_texture_identifier(char *line)
{
	if (ft_strcmp(line, "NO") && ft_strcmp(line, "SO")
		&& ft_strcmp(line, "WE") && ft_strcmp(line, "EA")
		&& ft_strcmp(line, "DO"))
		return (false);
	return (true);
}
