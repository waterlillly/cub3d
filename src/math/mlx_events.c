#include "../../cub3d.h"

static int	handle_keyrelease(int keycode, t_game *game)
{
	if (keycode == XK_W || keycode == XK_w)
		(game->control.forward = 0);
	if (keycode == XK_S || keycode == XK_s)
		(game->control.backward = 0);
	if (keycode == XK_A || keycode == XK_a)
		(game->control.left = 0);
	if (keycode == XK_D || keycode == XK_d)
		(game->control.right = 0);
	if (keycode == XK_Left)
		(game->control.turn_left = 0);
	if (keycode == XK_Right)
		(game->control.turn_right = 0);
	return (0);
}

static int	keypress(t_game *game)
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
	return (0);
}

static int	handle_keypress(int keycode, t_game *game)
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
	if (keycode == XK_space)
	{
		toggle_door(game, game->player.pos.x / TILE_SIZE,
			game->player.pos.y / TILE_SIZE);
	}
	keypress(game);
	return (0);
}

// static int	handle_mouse_motion(int x, int y, t_game *game)
// {
// 	static int	prev_x = -1;
// 	int			delta_x;
// 	double		angle;

// 	(void)y;
// 	if (prev_x == -1)
// 		prev_x = x;
// 	delta_x = x - prev_x;
// 	prev_x = x;
// 	angle = delta_x * game->player.turn_speed;
// 	rotate_dir(game, angle);
// 	rotate_plane(game, angle);
// 	return (0);
// }

static void	clear_frame(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	mlx_clear_window(game->cub.mlx_con, game->cub.mlx_win);
	while (y < WIN_SIZE)
	{
		x = 0;
		while (x < WIN_SIZE)
		{
			put_my_pixel(game, x, y, BLACK);
			x++;
		}
		y++;
	}
}

static int	render(t_game *game)
{
	clear_frame(game);
	raycasting(game);
	render_minimap(game);
	buffer_to_image(game);
	mlx_put_image_to_window(game->cub.mlx_con, game->cub.mlx_win,
		game->cub.img.img, 0, 0);
	return (0);
}

int	mlx_handler(t_game *game)
{
	mlx_loop_hook(game->cub.mlx_con, render, game);
	mlx_hook(game->cub.mlx_win, DestroyNotify, StructureNotifyMask,
		exit_success, game);
	mlx_hook(game->cub.mlx_win, KeyRelease, KeyReleaseMask, handle_keyrelease,
		game);
	mlx_hook(game->cub.mlx_win, KeyPress, KeyPressMask, handle_keypress, game);
	// mlx_hook(game->cub.mlx_win, MotionNotify, PointerMotionMask, handle_mouse_motion, game);
	return (0);
}
