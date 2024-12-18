#include "../../cub3d.h"

bool	is_texture(char *line)
{
	if (ft_strcmp(line, "NO") && ft_strcmp(line, "SO")
		&& ft_strcmp(line, "WE") && ft_strcmp(line, "EA"))
		return (false);
	return (true);
}

// bool	check_path(char *trim)
// {
// 	if (access(trim, F_OK) == 0)
// 		return (true);
// 	return (false);
// }

bool	is_color(char *trim)
{
	if (ft_strcmp(trim, "F") && ft_strcmp(trim, "C"))
		return (false);
	return (true);
}

bool	check_rgb(char *split)
{
	char	**rgb;
	int		nbr;
	int		i;

	rgb = ft_split(split, ',');
	if (!rgb)
		return (ft_putendl_fd("Error: split failed", 2), false);
	if (ft_arrlen(rgb) != 3)
		return (false);
	i = 0;
	while (rgb[i])
	{
		if (ft_strlen(rgb[i]) > 3 || ft_strlen(rgb[i]) <= 0
			|| !only_digits(rgb[i]))
			return (ft_free_2d(rgb), false);
		nbr = ft_atoi(rgb[i]);
		if (nbr < 0 || nbr > 255)
			return (ft_free_2d(rgb), false);
		i++;
	}
	return (ft_free_2d(rgb), true);
}

bool	check_color_element(char **split, int *col_count, t_pars *pars)
{
	char	*temp;

	if (split[1] && check_rgb(split[1]))
	{
		temp = ft_strjoin(split[0], " ");
		if (!temp)
			return (ft_putendl_fd("Error: strjoin failed", 2), false);
			//err("Error: strjoin failed", pars);
		pars->colors[*col_count] = ft_strjoin(temp, split[1]);
		(free(temp), temp = NULL);
		if (!pars->colors[*col_count])
			return (ft_putendl_fd("Error: strjoin failed", 2), false);
			//err("Error: strjoin failed", pars);
		(*col_count)++;
		return (true);
	}
	return (false);
}

bool	check_texture_element(char **split, int *tex_count, t_pars *pars)
{
	char	*temp;

	if (split[1])//check_path(split[1]))
	{
		temp = ft_strjoin(split[0], " ");
		if (!temp)
			return (ft_putendl_fd("Error: strjoin failed", 2), false);
			//err("Error: strjoin failed", pars);
		pars->textures[*tex_count] = ft_strjoin(temp, split[1]);
		(free(temp), temp = NULL);
		if (!pars->textures[*tex_count])
			return (ft_putendl_fd("Error: strjoin failed", 2), false);
			//err("Error: strjoin failed", pars);
		(*tex_count)++;
		return (true);
	}
	return (false);
}
