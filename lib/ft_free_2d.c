/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:51:35 by codespace         #+#    #+#             */
/*   Updated: 2025/01/06 15:46:04 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_2d(char **in)
{
	int i;

	i = 0;
	if (!in)
		return ;
	while (in[i])
	{
		free(in[i]);
		in[i] = NULL;
		i++;
	}
	free(in);
	in = NULL;
}