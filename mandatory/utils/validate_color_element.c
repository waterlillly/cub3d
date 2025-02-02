#include "../cub3d.h"

bool	validate_color_element(char **split, int *col_count, t_game *game)
{
	if (split && split[0] && split[1] && !split[2])
	{
		if ((!ft_strcmp(split[0], "F")
				&& validate_and_set_rgb(split[1], game, 0))
			|| (!ft_strcmp(split[0], "C")
				&& validate_and_set_rgb(split[1], game, 1)))
		{
			(*col_count)++;
			return (true);
		}
	}
	return (false);
}
