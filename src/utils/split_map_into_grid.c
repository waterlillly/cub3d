#include "../../cub3d.h"

bool	split_map_into_grid(t_game *game)
{
	int		i;
	char	**map;

	i = 0;
	game->data.map = ft_split(game->data.data, '\n');
	if (!game->data.map)
		return (false);
	max_line_len(game);
	map = ft_calloc(ft_arrlen(game->data.map) + 1, sizeof(char *));
	if (!map)
		return (false);
	while (game->data.map[i])
	{
		map[i] = ft_calloc(game->data.max_column + 1, sizeof(char));
		if (!map[i])
			return (ft_free_2d(map), false);
		ft_memset(map[i], ' ', game->data.max_column);
		ft_memcpy(map[i], game->data.map[i], ft_strlen(game->data.map[i]));
		i++;
	}
	if (i < ft_arrlen(game->data.map))
		return (ft_free_2d(map), false);
	game->data.num_of_rows = i;
	ft_free_2d(game->data.map);
	game->data.map = map;
	return (true);
}
