#include "../../cub3d.h"

int	is_door(t_game *game, int x, int y)
{
	int		c;

	c = 0;
	if (x < 0 || x >= game->data.map_width || y < 0 || y >= game->data.map_height)
		return (-1);
	while (c < game->num_doors)
	{
		if (game->doors[c].pos.x == x && game->doors[c].pos.y == y)
			return (c);
		c++;
	}
	return (-1);
}

bool	is_open(t_game *game, int nbr)
{
	if (nbr == -1)
		return (false);
	return (game->doors[nbr].open);
}

int	get_time(t_game *game)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) < 0)
		exit_failure("gettimeofday", game);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	toggle_door(t_game *game, int x, int y)
{
	int	c;

	c = is_door(game, x, y);
	if (c >= 0 && !is_open(game, c))
	{
		game->doors[c].open = true;
		game->doors[c].open_time = get_time(game);
	}
}
