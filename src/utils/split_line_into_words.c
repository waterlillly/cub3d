/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line_into_words.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:36:15 by msimic            #+#    #+#             */
/*   Updated: 2025/01/29 15:47:02 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static bool	check_len_and_newline(char *line, int len);

char	**split_line_into_words(char *line)
{
	char	*temp;
	char	**res;
	int		len;

	len = ft_strlen(line) - 1;
	if (!check_len_and_newline(line, len))
		return (NULL);
	temp = ft_substr(line, 0, len);
	if (!temp)
		return (NULL);
	res = NULL;
	res = ft_split(temp, ' ');
	free(temp);
	if (!res)
		return (NULL);
	return (res);
}

static bool	check_len_and_newline(char *line, int len)
{
	if (len < 0 || line[len] != '\n')
		return (false);
	return (true);
}
