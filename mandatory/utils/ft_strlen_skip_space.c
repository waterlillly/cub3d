/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_skip_space.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:36:21 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/02 20:36:22 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen_skip_space(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	while (i > j)
	{
		if (str[i] == ' ' || str[i] == '\n')
			i--;
		else
			break ;
	}
	return (i);
}
