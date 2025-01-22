#include "../cub3d.h"

bool	check_player(int *player, t_game *game)
{
	int		i;
	int		p;

	if (*player != 1)
		return (exit_failure("Error: No player found", game), false);
	i = 0;
	p = 0;
	while (game->data.map[i] && !ft_strchr(game->data.map[i], game->data.player_orient))
		i++;
	while (game->data.map[i][p] && game->data.map[i][p] != game->data.player_orient)
		p++;
	if (i > 0 && i < ft_arrlen(game->data.map) - 1 && p > 0 && p < (int)ft_strlen(game->data.map[i]) - 1
		&& (game->data.map[i][p - 1] == '0' || game->data.map[i][p + 1] == '0'
		|| game->data.map[i - 1][p] == '0' || game->data.map[i + 1][p] == '0'))
		return (true);
	return (false);
}

bool	valid_map(t_game *game)
{
	int			i;
	static int	player = 0;
	
	i = 0;
	while (game->data.map[i])
	{
		if (i == 0 || i == ft_arrlen(game->data.map) - 1)
		{
			if (!check_top_bot(game->data.map[i], game))
				return (false);
		}
		else
		{
			if (!check_sides(game->data.map[i], &player, game, i))
				return (false);
		}
		i++;
	}
	if (!check_player(&player, game))
		return (false);
	return (true);
}

bool	add_to_map(char *line, t_game *game)
{
	char	*temp;

	if (!game->data.map_line)
	{
		game->data.map_line = ft_strdup(line);
		if (!game->data.map_line)
			return (exit_failure("strdup failed", game), false);
		return (true);
	}
	temp = ft_strjoin(game->data.map_line, line);
	if (!temp)
		return (exit_failure("strjoin failed", game), false);
	free(game->data.map_line);
	game->data.map_line = temp;
	return (true);
}

int	find_max_len(t_game *game)
{
	int		i;
	int		j;
	int		len;
	char	*line;

	i = 0;
	len = 0;
	while (game->data.map[i])
	{
		j = ft_strlen(game->data.map[i]) - 1;
		if (j < 0)
			exit_failure("strlen == 0", game);
		while (game->data.map[i][j] && game->data.map[i][j] == ' ')
			j--;
		line = ft_substr(game->data.map[i], 0, j + 1);
		if (!line)
			exit_failure("substr failed", game);
		free(game->data.map[i]);
		game->data.map[i] = line;
		if (len < j)
			len = j;
		i++;
	}
	return (len);
}

void	modify_map(t_game *game)
{
	int		i;
	char	*line;
	int		len;

	i = -1;
	len = ft_strlen(game->data.map_line);
	if (len == 0)
		exit_failure("strlen == 0", game);
	if (game->data.map_line && game->data.map_line[len - 1] == '\n')
		exit_failure("Invalid map", game);
	game->data.map = ft_split(game->data.map_line, '\n');
	(free(game->data.map_line), game->data.map_line = NULL);
	if (!game->data.map)
		exit_failure("split failed", game);
	game->data.map_len = find_max_len(game);
	while (game->data.map[++i])
	{
		line = ft_calloc(game->data.map_len + 1, sizeof(char));
		if (!line)
			exit_failure("calloc failed", game);
		ft_memset(line, ' ', game->data.map_len + 1);
		ft_memcpy(line, game->data.map[i], ft_strlen(game->data.map[i]));
		free(game->data.map[i]);
		game->data.map[i] = line;
	}
}
