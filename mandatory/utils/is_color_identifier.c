#include "../cub3d.h"

bool	is_color_identifier(char *trim)
{
	if (ft_strcmp(trim, "F") && ft_strcmp(trim, "C"))
		return (false);
	return (true);
}
