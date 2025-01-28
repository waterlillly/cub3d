#include "../../cub3d.h"

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

static int	mouse_loop(int x, int y, t_game *game)
{
	static int	i = 0;

	if (i == 0)
	{
		game->cub.mouse_pos.x = x;
		game->cub.mouse_pos.y = y;
		i++;
		return (0);
	}
	if (x < game->cub.mouse_pos.x)
	{
		rotate_dir(game, -game->player.turn_speed * 0.2);
		rotate_plane(game, -game->player.turn_speed * 0.2);
	}
	else
	{
		rotate_dir(game, game->player.turn_speed * 0.2);
		rotate_plane(game, game->player.turn_speed * 0.2);
	}
	game->cub.mouse_pos.x = x;
	game->cub.mouse_pos.y = y;
	return (0);
}

static int	render(t_game *game)
{
	clear_frame(game);
	keypress(game);
	check_doors(game);
	raycasting(game);
	render_minimap(game);
	buffer_to_image(game);
	mlx_put_image_to_window(game->cub.mlx_con, game->cub.mlx_win,
		game->cub.img.img, 0, 0);
	return (0);
}

int	mlx_handler(t_game *game)
{
	mlx_hook(game->cub.mlx_win, DestroyNotify, StructureNotifyMask,
		exit_success, game);
	mlx_hook(game->cub.mlx_win, KeyRelease, KeyReleaseMask, handle_keyrelease,
		game);
	mlx_hook(game->cub.mlx_win, KeyPress, KeyPressMask, handle_keypress, game);
	mlx_hook(game->cub.mlx_win, MotionNotify, PointerMotionMask, mouse_loop,
		game);
	mlx_loop_hook(game->cub.mlx_con, render, game);
	return (0);
}
