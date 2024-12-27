#include "../../cub3d.h"

void	init_events(t_cub *cub)
{
	mlx_hook(cub->mlx_win, KeyPress, KeyPressMask, move_player, cub);
	//mlx_mouse_hook(cub->mlx_win, mouse_moves, cub);
	//mlx_hook(cub->mlx_win, 6, PointerMotionMask, handle_mouse_move, NULL);
	mlx_hook(cub->mlx_win, DestroyNotify, StructureNotifyMask, exit_success, cub);
	//ft_putendl_fd("init_events done", 1);
}

void	init_cub(t_game *game)
{
	t_cub	cub;

	ft_bzero(&cub, sizeof(t_cub));
	game->cub = &cub;
	game->cub->name = "cub3d";
	game->cub->mlx_con = mlx_init();
	if (!game->cub->mlx_con)
		exit_failure("Error: mlx_con\n", game);
	game->cub->mlx_win = mlx_new_window(game->cub->mlx_con, WIDTH, HEIGHT, game->cub->name);
	if (!game->cub->mlx_win)
		exit_failure("Error: mlx_new_window\n", game);
	game->cub->img.img_ptr = mlx_new_image(game->cub->mlx_con, WIDTH, HEIGHT);
	if (!game->cub->img.img_ptr)
		exit_failure("Error: mlx_new_image\n", game);
	game->cub->img.pxl_ptr = mlx_get_data_addr(game->cub->img.img_ptr, &game->cub->img.bpp,
			&game->cub->img.len, &game->cub->img.endian);
	//ft_putendl_fd("init_cub done", 1);
	init_events(game->cub);
}