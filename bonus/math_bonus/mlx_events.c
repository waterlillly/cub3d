#include "../../cub3d.h"

void	init_macros(t_game *game)
{
	game->macro.tile_size = WIN_SIZE * 0.1;
	game->macro.minimap_size = floor(WIN_SIZE * 0.2);
	game->macro.mini_tile_width = (game->macro.minimap_size
			/ game->data.map_width);
	game->macro.mini_tile_height = (game->macro.minimap_size
			/ game->data.map_height);
	game->macro.fov = 60 * (M_PI / 180);
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

static int	mouse_loop(int x, int y, t_game *game)
{
	(void)y;
	if (x < WIN_SIZE / 2)
	{
		rotate_dir(game, -game->player.turn_speed * 0.2);
		rotate_plane(game, -game->player.turn_speed * 0.2);
	}
	else if (x > WIN_SIZE / 2)
	{
		rotate_dir(game, game->player.turn_speed * 0.2);
		rotate_plane(game, game->player.turn_speed * 0.2);
	}
	if (x < (WIN_SIZE / 2) || x > (WIN_SIZE / 2))
		mlx_mouse_move(game->cub.mlx_con, game->cub.mlx_win, WIN_SIZE / 2,
			WIN_SIZE / 2);
	mlx_mouse_hide(game->cub.mlx_con, game->cub.mlx_win);
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
