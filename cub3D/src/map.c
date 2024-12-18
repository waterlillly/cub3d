#include "../../cub3d.h"

bool	check_player(int *player, t_pars *pars)
{
	int		i;
	int		p;

	if (*player != 1)
		return (err("Error: No player found", pars), false);
	i = 0;
	p = 0;
	while (pars->map[i] && !ft_strchr(pars->map[i], pars->player))
		i++;
	while (pars->map[i][p] && pars->map[i][p] != pars->player)
		p++;
	if (pars->map[i][p - 1] == '0' && pars->map[i][p + 1] == '0'
		&& pars->map[i - 1][p] == '0' && pars->map[i + 1][p] == '0')
		return (true);
	return (false);
}

bool	valid_map(t_pars *pars)
{
	int			i;
	static int	player = 0;
	
	i = 0;
	while (pars->map[i])
	{
		if (i == 0 || i == ft_arrlen(pars->map) - 1)
		{
			if (!check_top_bot(pars->map[i], pars))
				return (false);
		}
		else
		{
			if (!check_sides(pars->map[i], &player, pars, i))
				return (false);
		}
		i++;
	}
	if (!check_player(&player, pars))
		return (false);
	return (true);
}

bool	add_to_map(char *line, t_pars *pars)
{
	char	*temp;

	if (!pars->map_line)
	{
		pars->map_line = ft_strdup(line);
		if (!pars->map_line)
			return (ft_putendl_fd("Error: strdup failed", 2), false);
		return (true);
	}
	temp = ft_strjoin(pars->map_line, line);
	if (!temp)
		return (ft_putendl_fd("Error: strjoin failed", 2), false);
	free(pars->map_line);
	pars->map_line = temp;
	return (true);
}

int	find_max_len(t_pars *pars)
{
	int		i;
	int		j;
	int		len;
	char	*line;

	i = 0;
	len = 0;
	while (pars->map[i])
	{
		j = ft_strlen(pars->map[i]) - 1;
		if (j < 0)
			err("Error: strlen == 0", pars);
		while (pars->map[i][j] && pars->map[i][j] == ' ')
			j--;
		line = ft_substr(pars->map[i], 0, j + 1);
		if (!line)
			err("Error: substr failed", pars);
		free(pars->map[i]);
		pars->map[i] = line;
		if (len < j)
			len = j;
		i++;
	}
	return (len);
}

void	modify_map(t_pars *pars)
{
	int		i;
	char	*line;
	int		len;

	i = -1;
	len = ft_strlen(pars->map_line);
	if (len == 0)
		err("Error: strlen == 0", pars);
	if (pars->map_line && pars->map_line[len - 1] == '\n')
		err("Error: Invalid map", pars);
	pars->map = ft_split(pars->map_line, '\n');
	(free(pars->map_line), pars->map_line = NULL);
	if (!pars->map)
		err("Error: split failed", pars);
	pars->map_len = find_max_len(pars);
	while (pars->map[++i])
	{
		line = ft_calloc(pars->map_len + 1, sizeof(char));
		if (!line)
			err("Error: calloc failed", pars);
		ft_memset(line, ' ', pars->map_len + 1);
		ft_memcpy(line, pars->map[i], ft_strlen(pars->map[i]));
		free(pars->map[i]);
		pars->map[i] = line;
	}
}
