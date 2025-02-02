/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handle_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:35:18 by lbaumeis          #+#    #+#             */
/*   Updated: 2025/02/02 20:35:19 by lbaumeis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	reset_velo_on_keyrelease(t_game *game)
{
	if (game->control.forward == 0)
		game->control.forward_velo = 0;
	if (game->control.backward == 0)
		game->control.backward_velo = 0;
	if (game->control.left == 0)
		game->control.left_velo = 0;
	if (game->control.right == 0)
		game->control.right_velo = 0;
	if (game->control.turn_left == 0)
		game->control.turn_left_velo = 0;
	if (game->control.turn_right == 0)
		game->control.turn_right_velo = 0;
}

int	handle_keyrelease(int keycode, t_game *game)
{
	if (keycode == XK_W || keycode == XK_w)
		game->control.forward = 0;
	if (keycode == XK_S || keycode == XK_s)
		game->control.backward = 0;
	if (keycode == XK_A || keycode == XK_a)
		game->control.left = 0;
	if (keycode == XK_D || keycode == XK_d)
		game->control.right = 0;
	if (keycode == XK_Left)
		game->control.turn_left = 0;
	if (keycode == XK_Right)
		game->control.turn_right = 0;
	if (keycode == XK_Q || keycode == XK_q)
		game->control.sprint = 0;
	reset_velo_on_keyrelease(game);
	return (0);
}

int	keypress(t_game *game)
{
	if (game->control.forward == 1)
		move_forward(game);
	if (game->control.backward == 1)
		move_backward(game);
	if (game->control.left == 1)
		move_left(game);
	if (game->control.right == 1)
		move_right(game);
	if (game->control.turn_left == 1)
		turn_left(game);
	if (game->control.turn_right == 1)
		turn_right(game);
	if (game->control.sprint == 1)
		sprint(game);
	return (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == XK_Escape || keycode == 17)
		exit_success(game);
	if (keycode == XK_W || keycode == XK_w)
		game->control.forward = 1;
	if (keycode == XK_S || keycode == XK_s)
		game->control.backward = 1;
	if (keycode == XK_A || keycode == XK_a)
		game->control.left = 1;
	if (keycode == XK_D || keycode == XK_d)
		game->control.right = 1;
	if (keycode == XK_Left)
		game->control.turn_left = 1;
	if (keycode == XK_Right)
		game->control.turn_right = 1;
	if (keycode == XK_Q || keycode == XK_q)
		game->control.sprint = 1;
	return (0);
}
