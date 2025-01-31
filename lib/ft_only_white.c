#include "libft.h"

static int	ft_is_white(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (true);
	return (false);
}

bool	ft_only_white(char *line)
{
	int		i;
	bool	white;

	i = 0;
	white = true;
	while (line && line[i])
	{
		if (!ft_is_white(line[i]))
			white = false;
		i++;
	}
	return (white);
}
