/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:31:20 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/03 23:46:02 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	is_door(t_game *game, int x, int y)
{
	int	c;

	c = 0;
	if (x < 0 || x >= game->data.map_width || y < 0
		|| y >= game->data.map_height)
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

void	toggle_door(t_game *game, int x, int y)
{
	int	c;

	if (!game->valid_door)
		return ;
	c = is_door(game, x, y);
	if (c >= 0 && !is_open(game, c))
	{
		game->doors[c].open = true;
		game->doors[c].open_time = get_time(game);
	}
}

static void	init_doors(t_game *game)
{
	int		c;
	t_ivec	xy;

	c = 0;
	xy.y = -1;
	while (game->data.map[++xy.y])
	{
		xy.x = -1;
		while (game->data.map[xy.y][++xy.x])
		{
			if (game->data.map[xy.y][xy.x] == 'D')
			{
				game->doors[c].open = false;
				game->doors[c].pos.x = xy.x;
				game->doors[c].pos.y = xy.y;
				game->doors[c].open_time = 0;
				c++;
			}
		}
	}
}

void	parse_doors(t_game *game)
{
	t_ivec	xy;

	if (!game->valid_door)
		return ;
	game->num_doors = 0;
	xy.y = -1;
	while (game->data.map[++xy.y])
	{
		xy.x = -1;
		while (game->data.map[xy.y][++xy.x])
		{
			if (game->data.map[xy.y][xy.x] == 'D')
				game->num_doors++;
		}
	}
	game->doors = ft_calloc(game->num_doors + 1, sizeof(t_doors));
	if (!game->doors)
		exit_failure("ft_calloc", game);
	init_doors(game);
}
