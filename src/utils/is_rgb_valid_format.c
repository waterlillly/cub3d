#include "../../cub3d.h"

void is_rgb_valid_format(char *str, t_game *game)
{
	int i = 0;
	int count = 0;
	int comma = 0;
	int len = ft_strlen(str);
	while (str[i])
	{
		if (str[i] == ','){
			count++;
			comma = i;
			if (comma == 0 || comma == len - 1)
				exit_failure("Invalid RGB format", game);
		}
		i++;
	}
	if (count != 2)
		exit_failure("Invalid RGB format", game);
}