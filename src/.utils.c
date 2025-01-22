#include "../cub3d.h"

bool	rest_space(char *s, int start)
{
	while (s[start] && s[start] == ' ')
		start++;
	if (!s[start])
		return (true);
	return (false);
}

bool	check_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] && line[i] == '\n')
		return (true);
	return (false);
}

bool	only_digits(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
			return (false);
	}
	return (true);
}
