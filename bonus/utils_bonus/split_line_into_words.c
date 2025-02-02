/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line_into_words.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:33:35 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/02 20:33:36 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static char	*trim_inside_spaces(char *temp)
{
	int		i;
	int		j;
	int		space;
	char	*new;

	i = -1;
	space = 0;
	while (temp[++i])
	{
		if (temp[i] == ' ')
			space++;
	}
	new = ft_calloc(ft_strlen(temp) - space + 1, sizeof(char));
	if (!new)
		return (NULL);
	i = -1;
	j = -1;
	while (temp[++i])
	{
		if (temp[i] != ' ')
			new[++j] = temp[i];
	}
	return (new);
}

static char	**split_for_rgb(char *res)
{
	char	**new;
	char	*temp;

	if (!res || ft_strlen(res) < 3)
		return (NULL);
	new = ft_calloc(3, sizeof(char *));
	if (!new)
		return (NULL);
	if (res[1] != ' ')
		return (NULL);
	new[0] = ft_calloc(2, sizeof(char));
	if (!new[0])
		return (ft_free_2d(new), NULL);
	new[0] = ft_strncpy(new[0], res, 1);
	if (!new[0])
		return (ft_free_2d(new), NULL);
	temp = ft_strcpy(res, 1);
	if (!temp)
		return (ft_free_2d(new), NULL);
	new[1] = trim_inside_spaces(temp);
	free(temp);
	if (!new[1])
		return (ft_free_2d(new), NULL);
	return (new);
}

char	**split_line_into_words(char *line)
{
	char	*temp;
	char	**res;
	int		len;

	len = (int)ft_strlen(line) - 1;
	if (len <= 0)
		return (NULL);
	temp = ft_strtrim(line, "\n ");
	if (!temp)
		return (NULL);
	if (temp[0] == 'F' || temp[0] == 'C')
		res = split_for_rgb(temp);
	else
		res = ft_split(temp, ' ');
	free(temp);
	if (!res)
		return (NULL);
	return (res);
}
