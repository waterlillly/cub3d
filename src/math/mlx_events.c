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

int	mouse_moves(int button, int x, int y, t_cub *cub)
{
	if (button == Button5)
	{
		cub->x_move -= (x - WIDTH / 2) * (1 / (WIDTH / 2));
		cub->y_move += (y - HEIGHT / 2) * (1 / (HEIGHT / 2));
	}
	else if (button == Button4)
	{
		cub->x_move += (x - WIDTH / 2) * (1 / (WIDTH / 2));
		cub->y_move -= (y - HEIGHT / 2) * (1 / (HEIGHT / 2));
	}
	render(cub);
	return (0);
}
