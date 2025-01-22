#include "../cub3d.h"

bool	check_top_bot(char *s, t_game *game)
{
	int	i;

	i = 0;
	if (!s)
		return (false);
	while (s[i] && (s[i] == ' ' || s[i] == '1'))
		i++;
	if (!s[i] && check_top(game) && check_bot(game))
		return (true);
	return (false);
}

bool	check_sides(char *s, int *player, t_game *game, int x)
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
		while (s[i] && valid_symbol(i, player, game, x))
			i--;
		if (i < 0)
			return (true);
	}
	return (false);
}

bool	check_bot(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = ft_arrlen(game->data.map) - 1;
	j = 0;
	while (game->data.map[i][j] && game->data.map[i][j] == ' ')
		j++;
	while (game->data.map[i][j] && !rest_space(game->data.map[i], j))
	{
		if (game->data.map[i][j] == ' ')
		{
			k = i - 1;
			while (game->data.map[k][j] && game->data.map[k][j] == ' ' && game->data.map[k][j] != '1')
				k--;
			if (!game->data.map[k][j] || game->data.map[k][j] != '1')
				return (false);
		}
		j++;
	}
	return (true);
}

bool	check_top(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (game->data.map[i][j] && game->data.map[i][j] == ' ')
		j++;
	while (game->data.map[i][j] && !rest_space(game->data.map[i], j))
	{
		if (game->data.map[i][j] == ' ')
		{
			k = i + 1;
			while (game->data.map[k][j] && game->data.map[k][j] == ' ' && game->data.map[k][j] != '1')
				k++;
			if (!game->data.map[k][j] || game->data.map[k][j] != '1')
				return (false);
		}
		j++;
	}
	return (true);
}

void	transfer_orient(char orientation, t_game *game)
{
	if (orientation == 'N')
		game->data.p_orientation = NORTH;
	if (orientation == 'S')
		game->data.p_orientation = SOUTH;
	if (orientation == 'E')
		game->data.p_orientation = EAST;
	if (orientation == 'W')
		game->data.p_orientation = WEST;
}

bool	valid_symbol(int i, int *player, t_game *game, int x)
{
	if (game->data.map[x][i] == '1')
		return (true);
	else if (game->data.map[x][i] == ' ')
	{
		if ((!game->data.map[x][i + 1] || game->data.map[x][i + 1] == ' '
			|| game->data.map[x][i + 1] == '1') && (!game->data.map[x][i - 1]
			|| game->data.map[x][i - 1] == ' ' || game->data.map[x][i - 1] == '1'))
			return (true);
	}
	else if (game->data.map[x][i] == '0')
	{
		if (game->data.map[x][i + 1] && game->data.map[x][i + 1] != ' '
			&& game->data.map[x][i - 1] && game->data.map[x][i - 1] != ' ')
			return (true);
	}
	else if (*player == 0 && (game->data.map[x][i] == 'N' || game->data.map[x][i] == 'S'
		|| game->data.map[x][i] == 'E' || game->data.map[x][i] == 'W'))
	{
		(*player)++;
		game->data.player_orient = game->data.map[x][i];
		game->player.pos.x = x + 0.5;
		game->player.pos.y = i + 0.5;
		game->data.map[x][i] = '0';
		transfer_orient(game->data.player_orient, game);
		return (true);
	}
	return (false);
}
