#include "../../cub3d.h"

int handle_keypress(int keycode, t_game *game)
{
	if (keycode == XK_Escape || keycode == 17)
		exit_success(game);
	else if (keycode == XK_W || keycode == XK_w || keycode == XK_Up)
		move_forward(game);
	else if (keycode == XK_S || keycode == XK_s || keycode == XK_Down)
		move_backward(game);
	else if (keycode == XK_A || keycode == XK_a || keycode == XK_Left)
		move_left(game);
	else if (keycode == XK_D || keycode == XK_d || keycode == XK_Right)
		move_right(game);
	render(game);
	return (0);
}

void center_mouse(t_cub *cub)//???
{
	int	center_x;
	int	center_y;

	center_x = WIN_WIDTH / 2;
	center_y = WIN_HEIGHT / 2;
	mlx_mouse_move(cub->mlx_con, cub->mlx_win, center_x, center_y);
}

int handle_mouse_move(int x, int y, t_game *game)
{
	mlx_mouse_get_pos(game->cub.mlx_con, game->cub.mlx_win,
		(int *)WIN_WIDTH, (int *)WIN_HEIGHT);//idk
	if (x < WIN_WIDTH / 2)
	{
		ft_putendl_fd("Rotating left...", 1);
		//rotate left
	}
	else if (x > WIN_WIDTH / 2)
	{
		ft_putendl_fd("Rotating right...", 1);
		//rotate right
	}
	if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT)//???
	{
		ft_putendl_fd("Recentering mouse...", 1);
		center_mouse(&(*game).cub);
	}
	render(game);
	return (0);
}

int mlx_handler(t_game *game)
{
	//mlx_mouse_hide(game->cub->mlx_con, game->cub->mlx_win);//doesn't work?
	mlx_hook(game->cub.mlx_win, KeyPress, KeyPressMask, handle_keypress, game);
	mlx_hook(game->cub.mlx_win, MotionNotify, 0, handle_mouse_move, game);//doesnt work yet
	mlx_hook(game->cub.mlx_win, DestroyNotify, StructureNotifyMask, exit_success, game);
	mlx_loop_hook(game->cub.mlx_con, render, game);
	return (0);
}
