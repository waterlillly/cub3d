
#include "../../cub3d.h"

void	exit_failure(char *s, t_game *game)
{
	ft_putstr_fd(s, STDERR_FILENO);
	destroy_mlx(game->cub);
	exit(EXIT_FAILURE);
}

int	exit_success(t_game *game)
{
	destroy_mlx(game->cub);
	exit(EXIT_SUCCESS);
}

void	destroy_mlx(t_cub *cub)
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
}
