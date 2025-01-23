#include "../../cub3d.h"

/*
maybe try:

bool	check;

check = true;
while (rgb[j] && check == true)
{
	while (rgb[j][k] && check == true)
	{
		if (ft_isdigit(rgb[j][k]) == false)
			check = false;
		k++;
	}
	if (check == false)
		break ;
	k = 0;
	j++;
}

*/

static bool	is_number(char **rgb)
{
	int		j;
	int		k;
	bool	check;
	//bool	is_num;

	k = 0;
	j = 0;

	check = true;
	while (rgb[j] && check == true)
	{
		while (rgb[j][k] && check == true)
		{
			if (ft_isdigit(rgb[j][k]) == false)
				check = false;
			k++;
		}
		if (check == false)
			break ;
		k = 0;
		j++;
	}
	return (check);
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
		i++;
	}
	ft_free_2d(rgb);
}

static void	get_rgb(t_game *game, int *rgb_color, char **split)
{
	char	**rgb;
	char	*s;

	s = ft_strtrim(split[1], "\n");
	if (!s)
		(ft_free_2d(split), exit_failure("ft_strtrim", game));
	rgb = ft_split(s, ',');
	free(s);
	if (!rgb)
		(ft_free_2d(split), exit_failure("ft_split fail", game));
	s = NULL;
	if (ft_arrlen(rgb) != 3)
	{
		ft_free_2d(split);
		ft_free_2d(rgb);
		exit_failure("wrong rgb", game);
	}
	convert_to_int_array(game, rgb, rgb_color);
}

int	add_color(t_game *game, char *line, int column)
{
	char **split_rgb;
	char *s;

	if (line[column + 1] && ascii_print(line[column + 1]))
		return (ERR);
	s = ft_strtrim(line, "\n");
	if (!s)
		exit_failure("ft_strtrim", game);
	split_rgb = ft_split(s, ' ');
	if (!split_rgb)
		(free(s), exit_failure("ft_split 1", game));
	if (!split_rgb[0] || !split_rgb[1] || split_rgb[2])
	{
		free(s);
		ft_free_2d(split_rgb);
		exit_failure("wrong rgb", game);
	}
	if (line[column] == 'F')
		get_rgb(game, game->data.floor_color, split_rgb);
	else if (line[column] == 'C')
		get_rgb(game, game->data.ceiling_color, split_rgb);
	ft_free_2d(split_rgb);
	free(s);
	return (SUCC);
}