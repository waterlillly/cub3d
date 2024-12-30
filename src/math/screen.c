#include "../../cub3d.h"

int screen(t_cub *cub)
{
	int		screen_width;
	int		screen_height;

	//puts("Calculating screensize...");
	if (mlx_get_screen_size(cub->mlx_con, &screen_width, &screen_height) != 0)
		return (ft_putendl_fd("Error while calculating screensize", 2), 1);
	cub->screen_width = screen_width / 2;
	cub->screen_height = screen_height / 2;
	if (cub->screen_width < 100 || cub->screen_height < 100)
		return (ft_putendl_fd("Screen too small", 2), 1);
	//ft_printf("Screensize: %dx%d\n", screen_width, screen_height);
	return (0);
}
