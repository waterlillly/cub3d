#include "../../cub3d.h"

int	err(char *s, t_pars *pars)
{
	if (pars)
	{
		if (pars->colors)
			ft_free_2d(pars->colors);
		if (pars->map)
			ft_free_2d(pars->map);
		if (pars->textures)
			ft_free_2d(pars->textures);
		if (pars->map_line)
		{
			free(pars->map_line);
			pars->map_line = NULL;
		}
	}
	if (s)
	{
		ft_putendl_fd(s, 2);
		exit(1);
	}
	else
		exit(0);
	return (-1);
}

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
