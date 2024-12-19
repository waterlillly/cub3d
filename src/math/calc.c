#include "calc.h"

void	error_exit(char *s, t_cub *cub)
{
	ft_putstr_fd(s, STDERR_FILENO);
	close_and_exit(cub);
	exit(EXIT_FAILURE);
}

int	exit_success(t_cub *cub)
{
	close_and_exit(cub);
	exit(EXIT_SUCCESS);
}

void	init_data(t_cub *cub)
{
	cub->esc_value = 4;
	cub->x_move = 1.0;//cub->player->x;
	cub->y_move = 1.0;//cub->player->y;
}

void	init_events(t_cub *cub)
{
	mlx_hook(cub->mlx_win, KeyPress, KeyPressMask, key_press, cub);
	mlx_mouse_hook(cub->mlx_win, mouse_moves, cub);
	mlx_hook(cub->mlx_win, DestroyNotify, StructureNotifyMask, exit_success, cub);
}

void	init_cub(t_cub *cub)
{
	cub->name = "cub3d";
	cub->mlx_con = mlx_init();
	if (!cub->mlx_con)
		error_exit("Error: mlx_con\n", NULL);
	cub->mlx_win = mlx_new_window(cub->mlx_con, WIDTH, HEIGHT, cub->name);
	if (!cub->mlx_win)
	{
		mlx_destroy_display(cub->mlx_con);
		error_exit("Error: mlx_new_window\n", cub);
	}
	cub->img.img_ptr = mlx_new_image(cub->mlx_con, WIDTH, HEIGHT);
	if (!cub->img.img_ptr)
	{
		mlx_destroy_window(cub->mlx_con, cub->mlx_win);
		mlx_destroy_display(cub->mlx_con);
		error_exit("Error: mlx_new_image\n", cub);
	}
	cub->img.pxl_ptr = mlx_get_data_addr(cub->img.img_ptr, &cub->img.bpp,
			&cub->img.len, &cub->img.endian);
	init_events(cub);
	init_data(cub);
}