#include "../../cub3d.h"

void	put_my_pixel(t_game *game, int x, int y, int color)
{
	char	*dest;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dest = game->cub.img.pxl_ptr + (y * game->cub.img.len + x * (game->cub.img.bpp / 8));
		*(unsigned int *)dest = color;
	}
}

void	render_map(t_game *game)
{
	int	x;
	int	y;
	int	color;
	int	px;
	int	py;

	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			if (game->map[y][x] == '1')
				color = 0xFFFFFF;
			else
				color = 0x000000;
			py = 0;
			while (py < TILE_SIZE)
			{
				px = 0;
				while (px < TILE_SIZE)
				{
					put_my_pixel(game, x * TILE_SIZE + px, y * TILE_SIZE + py, color);
					px++;
				}
				py++;
			}
			x++;
		}
		y++;
	}
}

void	render_player(t_game *game)
{
	int	a;
	int	b;

	b = 10;
	while (b < (TILE_SIZE - 10))
	{
		a = 10;
		while (a < (TILE_SIZE - 10))
		{
			put_my_pixel(game, game->cub.player.p_x * TILE_SIZE + a, game->cub.player.p_y * TILE_SIZE + b, 0xFF0000);
			a++;
		}
		b++;
	}
}

int	render(t_game *game)
{
	mlx_clear_window(game->cub.mlx_con, game->cub.mlx_win);
	render_map(game);
	render_player(game);
	mlx_put_image_to_window(game->cub.mlx_con, game->cub.mlx_win, game->cub.img.img_ptr, 0, 0);
	return (0);
}
