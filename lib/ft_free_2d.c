/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:51:35 by codespace         #+#    #+#             */
/*   Updated: 2025/02/02 20:59:08 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_2d(char **in)
{
	int	i;

	i = -1;
	if (!in)
		return ;
	while (in && in[++i])
		free(in[i]);
	if (in)
		free(in);
}
