/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:45:18 by lbaumeis          #+#    #+#             */
/*   Updated: 2024/11/19 15:45:33 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_array_fd(char **arr, int fd)
{
	int	x;

	x = -1;
	while (arr[++x])
		ft_putendl_fd(arr[x], fd);
}
