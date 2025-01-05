#include "../../cub3d.h"

void	put_my_pixel(t_game *game, int x, int y, int color)
{
	char	*dest;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dest = game->cub.img.addr + (y * game->cub.img.len + x * (game->cub.img.bpp / 8));
		*(unsigned int *)dest = color;
	}
}

static int handle_keypress(int keycode, t_game *game)
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

static void	clear_frame(t_game *game)
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
			put_my_pixel(game, x, y, FLOOR_COLOR);
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
	mlx_put_image_to_window(game->cub.mlx_con, game->cub.mlx_win, game->cub.img.img, 0, 0);
	return (0);
}

int mlx_handler(t_game *game)
{
	mlx_loop_hook(game->cub.mlx_con, render, game);
	mlx_hook(game->cub.mlx_win, DestroyNotify, StructureNotifyMask, exit_success, game);
	mlx_hook(game->cub.mlx_win, KeyPress, KeyPressMask, handle_keypress, game);
	return (0);
}
