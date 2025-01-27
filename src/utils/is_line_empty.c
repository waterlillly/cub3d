#include "../../cub3d.h"

bool	is_line_empty(char *s)
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