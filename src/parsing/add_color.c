#include "../../cub3d.h"

static bool	is_number(char **rgb)
{
	int		j;
	int		k;
	bool	is_number;

	k = 0;
	j = 0;
	is_number = false;
	while (rgb[j])
	{
		while (rgb[j][k])
		{
			if (ft_isdigit(rgb[j][k]) == 1)
				is_number = true;
			k++;
		}
		if (is_number == false)
			break ;
		k = 0;
		j++;
	}
	return (is_number);
}

static void	convert_to_int_array(t_game *game, char **rgb, int *rgb_int)
{
	int		i;
	bool	is_num;

	i = 0;
	is_num = is_number(rgb);
	while (rgb[i])
	{
		rgb_int[i] = ft_atoi(rgb[i]);
		if ((rgb_int[i] < 0 || rgb_int[i] > 255) || is_num == false)
		{
			ft_free_2d(rgb);
			exit_failure("wrong rgb values", game);
		}
		printf("%d\n", rgb_int[i]);
		i++;
	}
	ft_free_2d(rgb);
}

static void	get_rgb(t_game *game, int *rgb_color, char *line)
{
	char	**rgb;
	char	*s;

	s = ft_strtrim(line, "\n");
	if (!s)
		exit_failure("ft_strtrim", game);
	rgb = ft_split(line, ',');
	if (ft_arrlen(rgb) != 3)
	{
		ft_free_2d(rgb);
		exit_failure("wrong rgb", game);
	}
	convert_to_int_array(game, rgb, rgb_color);
}

int	add_color(t_game *game, char *line, int column)
{
	if (line[column + 1] && ascii_print(line[column + 1]))
		return (ERR);
	if (line[column] == 'F')
		get_rgb(game, game->data.floor_color, line + column + 1);
	else if (line[column] == 'C')
		get_rgb(game, game->data.ceiling_color, line + column + 1);
	else
		return (ERR);
	return (SUCC);
}