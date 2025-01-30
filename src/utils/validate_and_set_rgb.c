#include "../../cub3d.h"

static void	check_color_and_set(int *nbr, int i, t_game *game, int fc);

bool	validate_and_set_rgb(char *split, t_game *game, int fc)
{
	char	**rgb;
	int		nbr[3];
	int		i;

	rgb = ft_split(split, ',');
	if (!rgb)
		return (false);
	if (ft_arrlen(rgb) != 3)
		return (false);
	i = 0;
	while (rgb[i])
	{
		if (ft_strlen(rgb[i]) > 3 || ft_strlen(rgb[i]) <= 0
			|| !only_digits(rgb[i]))
			return (ft_free_2d(rgb), false);
		nbr[i] = ft_atoi(rgb[i]);
		if (nbr[i] < 0 || nbr[i] > 255)
			return (ft_free_2d(rgb), false);
		check_color_and_set(nbr, i, game, fc);
		i++;
	}
	return (ft_free_2d(rgb), true);
}

static void	check_color_and_set(int *nbr, int i, t_game *game, int fc)
{
	if (fc == 0)
	{
		game->data.floor_color[i] = nbr[i];
		if (i == 2)
			game->data.floor_color_set = true;
	}
	else
	{
		game->data.ceiling_color[i] = nbr[i];
		if (i == 2)
			game->data.ceiling_color_set = true;
	}
}
