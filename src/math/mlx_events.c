#include "../../cub3d.h"

int handle_keypress(int keycode, t_game *game)
{
	if (keycode == XK_Escape || keycode == 17)
		exit_success(game);
	else if (keycode == XK_W || keycode == XK_w || keycode == XK_Up)
		move_forward(game, game->map);
	else if (keycode == XK_S || keycode == XK_s || keycode == XK_Down)
		move_backward(game, game->map);
	else if (keycode == XK_A || keycode == XK_a || keycode == XK_Left)
		move_left(game, game->map);
	else if (keycode == XK_D || keycode == XK_d || keycode == XK_Right)
		move_right(game, game->map);
	render_scene(game);
	return (0);
}

void center_mouse(t_cub *cub)
{
	int	center_x;
	int	center_y;

	center_x = cub->screen_width / 2;
	center_y = cub->screen_height / 2;
	mlx_mouse_move(cub->mlx_con, cub->mlx_win, center_x, center_y);
}

int handle_mouse_move(int x, int y, t_game *game)
{
	mlx_mouse_get_pos(game->cub->mlx_con, game->cub->mlx_win,
		&game->cub->screen_width, &game->cub->screen_height);//idk
	if (x < game->cub->screen_width / 2)
	{
		//rotate left
	}
	else if (x > game->cub->screen_width / 2)
	{
		//rotate right
	}
	if (x < 0 || x > game->cub->screen_width || y < 0 || y > game->cub->screen_height)
	{
		//ft_putendl_fd("Recentering mouse...", 1);
		center_mouse(game->cub);
	}
	render_scene(game);
	return (0);
}

int mlx_handler(t_game *game)
{
	//mlx_mouse_hide(game->cub->mlx_con, game->cub->mlx_win);//doesn't work?
	mlx_hook(game->cub->mlx_win, KeyPress, KeyPressMask, handle_keypress, game);
	//mlx_hook(game->cub->mlx_win, MotionNotify, PointerMotionMask, handle_mouse_move, game);//maybe 0 instead of PointerMotionMask
	mlx_hook(game->cub->mlx_win, DestroyNotify, StructureNotifyMask, exit_success, game);
	//mlx_loop_hook(game->cub->mlx_con, render_scene, game);
	return (0);
}
