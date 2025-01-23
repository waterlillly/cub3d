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
		toggle_door(game, game->ray.map.x / TILE_SIZE,
			game->ray.map.y / TILE_SIZE);
	}
	keypress(game);
	return (0);
}

static void handle_mouse_movement(double x_offset, double y_offset, t_game *game)
{
	static t_dvec	prev = {0, 0};
	t_dvec			d;
	double			norm;

	d.x = x_offset - prev.x;
	d.y = y_offset - prev.y;
	norm = sqrt(d.x * d.x + d.y * d.y);
	if (norm > 0.001)
	{
		d.x /= norm;
		d.y /= norm;
	}
	game->player.dir.x += d.x * game->player.turn_speed;
	game->player.dir.y += d.y * game->player.turn_speed;
	prev.x = x_offset;
	prev.y = y_offset;
}

static int mouse_loop(t_game *game)
{
	double	x_pos;
	double	y_pos;
	int		button;

	if ((button = mlx_get_mouse_button()) != -1)
	{
		mlx_get_mouse_pos(&x_pos, &y_pos);
		handle_mouse_movement(x_pos, y_pos, game);
		// usleep(16667); // ~60 FPS
	}
	return (0);
}

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
	mlx_hook(game->cub.mlx_win, MotionNotify, PointerMotionMask, mouse_loop, game);
	return (0);
}
