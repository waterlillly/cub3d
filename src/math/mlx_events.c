#include "../../cub3d.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == XK_Escape || keycode == 17)
		exit_success(game);
	if (keycode == XK_W || keycode == XK_w)
		move_forward(game);
	if (keycode == XK_S || keycode == XK_s)
		move_backward(game);
	if (keycode == XK_A || keycode == XK_a)
		move_left(game);
	if (keycode == XK_D || keycode == XK_d)
		move_right(game);
	if (keycode == XK_Left)
		turn_left(game);
	if (keycode == XK_Right)
		turn_right(game);
	return (0);
}

void	clear_frame(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	mlx_clear_window(game->cub.mlx_con, game->cub.mlx_win);
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			put_my_pixel(game, x, y, BLACK);
			x++;
		}
		y++;
	}
}

int	render(t_game *game)
{
	clear_frame(game);
	raycasting(game);
	render_minimap(game);
	buffer_to_image(game);
	mlx_put_image_to_window(game->cub.mlx_con, game->cub.mlx_win, game->cub.img.img, 0, 0);
	return (0);
}

int	mlx_handler(t_game *game)
{
	mlx_loop_hook(game->cub.mlx_con, render, game);
	mlx_hook(game->cub.mlx_win, DestroyNotify, StructureNotifyMask, exit_success, game);
	mlx_hook(game->cub.mlx_win, KeyPress, KeyPressMask, handle_keypress, game);
	return (0);
}
