#include "calc.h"

void	close_and_exit(t_cub *cub)
{
	if (cub->mlx_con)
		mlx_destroy_image(cub->mlx_con, cub->img.img_ptr);
	if (cub->mlx_win)
		mlx_destroy_window(cub->mlx_con, cub->mlx_win);
	if (cub->mlx_con)
	{
		mlx_destroy_display(cub->mlx_con);
		free(cub->mlx_con);
	}
	//exit(EXIT_SUCCESS);
}

int	key_press(int key, t_cub *cub)
{
	if (key == XK_Escape)
	{
		close_and_exit(cub);
		exit(EXIT_SUCCESS);
	}
	if (key == XK_Left)
		cub->x_move -= 0.5;
	else if (key == XK_Right)
		cub->x_move += 0.5;
	else if (key == XK_Up)
		cub->y_move += 0.5;
	else if (key == XK_Down)
		cub->y_move -= 0.5;
	render(cub);
	return (0);
}

int handle_mouse_move(int x, int y, void *param)
{
	(void)x;
	(void)y;
	(void)param;
	return (0);
}