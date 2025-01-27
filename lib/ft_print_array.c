/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:40:16 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/01/27 15:55:44 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_print_array(char **arr)
// {
// 	int	x;

// 	x = -1;
// 	while (arr[++x])
// 		ft_putendl_fd(arr[x], 1);
// }

void	ft_print_array(char **arr)
{
	int	x;

	x = 0;
	while (arr[x])
	{
		printf("|%s|\n", arr[x]);
		x++;
	}
}