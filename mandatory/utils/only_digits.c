/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_digits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:36:54 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/02 20:36:55 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	only_digits(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
			return (false);
	}
	return (true);
}
