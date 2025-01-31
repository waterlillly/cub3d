#include "../../cub3d.h"

bool	is_line_empty(char *s)
{
	if (s && s[0] == '\n')
		return (true);
	return (false);
}
