#include "../cub3d.h"

bool	check_top_bot(char *s, t_pars *pars)
{
	int	i;

	i = 0;
	if (!s)
		return (false);
	while (s[i] && (s[i] == ' ' || s[i] == '1'))
		i++;
	if (!s[i] && check_top(pars) && check_bot(pars))
		return (true);
	return (false);
}

bool	check_sides(char *s, int *player, t_pars *pars, int x)
{
	int	i;

	i = 0;
	if (!s)
		return (false);
	while (s[i] && s[i] == ' ')
		i++;
	if (s[i] && s[i] != '1')
		return (false);
	i = (int)ft_strlen(s) - 1;
	if (i < 0)
		return (false);
	while (s[i] && s[i] == ' ')
		i--;
	if (s[i] && s[i] == '1')
	{
		while (s[i] && valid_symbol(i, player, pars, x))
			i--;
		if (i < 0)
			return (true);
	}
	return (false);
}

bool	check_bot(t_pars *pars)
{
	int	i;
	int	j;
	int	k;

	i = ft_arrlen(pars->map) - 1;
	j = 0;
	while (pars->map[i][j] && pars->map[i][j] == ' ')
		j++;
	while (pars->map[i][j] && !rest_space(pars->map[i], j))
	{
		if (pars->map[i][j] == ' ')
		{
			k = i - 1;
			while (pars->map[k][j] && pars->map[k][j] == ' ' && pars->map[k][j] != '1')
				k--;
			if (!pars->map[k][j] || pars->map[k][j] != '1')
				return (false);
		}
		j++;
	}
	return (true);
}

bool	check_top(t_pars *pars)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (pars->map[i][j] && pars->map[i][j] == ' ')
		j++;
	while (pars->map[i][j] && !rest_space(pars->map[i], j))
	{
		if (pars->map[i][j] == ' ')
		{
			k = i + 1;
			while (pars->map[k][j] && pars->map[k][j] == ' ' && pars->map[k][j] != '1')
				k++;
			if (!pars->map[k][j] || pars->map[k][j] != '1')
				return (false);
		}
		j++;
	}
	return (true);
}

bool	valid_symbol(int i, int *player, t_pars *pars, int x)
{
	if (pars->map[x][i] == '1')
		return (true);
	else if (pars->map[x][i] == ' ')
	{
		if ((!pars->map[x][i + 1] || pars->map[x][i + 1] == ' '
			|| pars->map[x][i + 1] == '1') && (!pars->map[x][i - 1]
			|| pars->map[x][i - 1] == ' ' || pars->map[x][i - 1] == '1'))
			return (true);
	}
	else if (pars->map[x][i] == '0')
	{
		if (pars->map[x][i + 1] && pars->map[x][i + 1] != ' '
			&& pars->map[x][i - 1] && pars->map[x][i - 1] != ' ')
			return (true);
	}
	else if (*player == 0 && (pars->map[x][i] == 'N' || pars->map[x][i] == 'S'
		|| pars->map[x][i] == 'E' || pars->map[x][i] == 'W'))
	{
		(*player)++;
		pars->player = pars->map[x][i];
		return (true);
	}
	return (false);
}
