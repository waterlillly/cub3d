#include "../../cub3d.h"

static int	color(int *color)
{
	return ((color[0] << 16) | (color[1] << 8) | color[2]);
}

void	get_colors(t_game *game)
{
	game->c_color = color(game->data.ceiling_color);
	game->f_color = color(game->data.floor_color);
}

void	check_texture(t_game *game, int i)
{
	if (game->textures[i].width != game->textures[i].height)
		exit_failure("Textures have to have the same width and height", game);
	if (game->textures[i].bpp != 32)
		exit_failure("Texture format not supported (must be 32bpp)", game);
}

bool	is_wall(t_game *game, double new_x, double new_y)
{
	int	x;
	int	y;
	int	nbr;

	x = floor(new_x);
	y = floor(new_y);
	if (x < 0 || x >= game->data.map_width || y < 0
		|| y >= game->data.map_height)
		return (true);
	nbr = is_door(game, x, y);
	if (nbr >= 0 && is_open(game, nbr))
		return (false);
	return (game->data.map[y][x] == '1' || game->data.map[y][x] == 'D');
}

void	check_doors(t_game *game)
{
	int	time;
	int	c;

	c = 0;
	time = get_time(game);
	if (time == -1)
		exit_failure("get time", game);
	time += 5;
	while (c < game->num_doors)
	{
		if (game->doors[c].open == true && game->doors[c].open_time
			+ 5000 <= time && is_door(game, (int)game->player.pos.x,
				(int)game->player.pos.y) == -1)
		{
			game->doors[c].open = false;
			game->doors[c].open_time = 0;
		}
		c++;
	}
}
