#include "calc.h"

static void	create_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pxl_ptr + offset) = color;
}

void	pixel(int x, int y, t_cub *cub)
{
	t_complex	z;
	t_complex	c;

	ft_bzero(&c, (sizeof(t_complex)));
	z.x = (scale(x, map_values((WIDTH / 2) * -1, (WIDTH / 2), 0, WIDTH)))
		+ cub->x_move;
	z.y = (scale(y, map_values((HEIGHT / 2), (HEIGHT / 2) * -1, 0, HEIGHT)))
		+ cub->y_move;
	create_pixel(x, y, &(cub->img), 0x000000);
}

int	render(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel(x, y, cub);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(cub->mlx_con, cub->mlx_win, cub->img.img_ptr, 0, 0);
	return (0);
}
