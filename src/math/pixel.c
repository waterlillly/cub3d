#include "../../cub3d.h"

void	draw_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->cub->screen_height)
	{
		x = 0;
		while (x < game->cub->screen_width)
		{
			mlx_put_image_to_window(game->cub->mlx_con, game->cub->mlx_win, game->cub->bg_img, x, y);
			x += game->cub->bg_width;
		}
		y += game->cub->bg_height;
	}
}

int	render_scene(t_game *game)
{
	//mlx_clear_window(cub->mlx_con, cub->mlx_win);
	//load_background(game, game->bg_file);
	draw_background(game);
	mlx_pixel_put(game->cub->mlx_con, game->cub->mlx_win,
		game->cub->screen_width / 2, game->cub->screen_height / 2, 0xFF0000);
	//mlx_put_image_to_window(game->cub->mlx_con, game->cub->mlx_win, game->cub->img.img_ptr, 0, 0);
	return (0);
}
