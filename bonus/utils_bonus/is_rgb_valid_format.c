#include "../../cub3d_bonus.h"

bool	is_rgb_valid_format(char *str)
{
	int	i;
	int	count;
	int	comma;
	int	len;

	i = 0;
	count = 0;
	comma = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if (str[i] == ',')
		{
			count++;
			comma = i;
			if (comma == 0 || comma == len - 1)
				return (false);
		}
		i++;
	}
	if (count == 2)
		return (true);
	return (false);
}
