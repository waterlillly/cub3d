#include "../../cub3d.h"

static int	handle_keyrelease(int keycode, t_game *game)
{
	if (keycode == XK_W || keycode == XK_w)
		(game->control.forward = 0, game->control.forward_velo = 0);
	if (keycode == XK_S || keycode == XK_s)
		(game->control.backward = 0, game->control.backward_velo = 0);
	if (keycode == XK_A || keycode == XK_a)
		(game->control.left = 0, game->control.left_velo = 0);
	if (keycode == XK_D || keycode == XK_d)
		(game->control.right = 0, game->control.right_velo = 0);
	if (keycode == XK_Left)
		(game->control.turn_left = 0, game->control.turn_left_velo = 0);
	if (keycode == XK_Right)
		(game->control.turn_right = 0, game->control.turn_right_velo = 0);
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
	return (0);
}

static void handle_mouse_movement(int x_offset, int y_offset, t_game *game)
{
	static t_ivec	prev = {0, 0};
	t_ivec			d;
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
	t_ivec	pos;

	mlx_mouse_move(game->cub.mlx_con, game->cub.mlx_win, pos.x, pos.y);
	if (mlx_mouse_get_pos(game->cub.mlx_con, game->cub.mlx_win, &pos.x, &pos.y) != -1)
		handle_mouse_movement(pos.x, pos.y, game);
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

static void	check_doors(t_game *game)
{
	int	time;
	int	c;

	c = 0;
	time = get_time(game);
	if (time == -1)
		exit_failure("get time", game);
	time += 5;
	while (c < game->num_doors)
	{
		if (game->doors[c].open == true
			&& game->doors[c].open_time + 5000 <= time
			&& is_door(game, (int)game->player.pos.x / TILE_SIZE, (int)game->player.pos.y / TILE_SIZE) == -1)
		{
			game->doors[c].open = false;
			game->doors[c].open_time = 0;
		}
		c++;
	}
}

static int	render(t_game *game)
{
	check_doors(game);
	clear_frame(game);
	keypress(game);
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
