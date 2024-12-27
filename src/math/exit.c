
#include "../../cub3d.h"

void	exit_failure(char *s, t_game *game)
{
	ft_putstr_fd(s, STDERR_FILENO);
	destroy_mlx(game);
	exit(EXIT_FAILURE);
}

int	exit_success(t_game *game)
{
	destroy_mlx(game);
	exit(EXIT_SUCCESS);
}

void	destroy_mlx(t_game *game)
{
	if (game->cub->mlx_con)
		mlx_destroy_image(game->cub->mlx_con, game->cub->img.img_ptr);
	if (game->cub->mlx_win)
		mlx_destroy_window(game->cub->mlx_con, game->cub->mlx_win);
	if (game->cub->mlx_con)
	{
		mlx_destroy_display(game->cub->mlx_con);
		free(game->cub->mlx_con);
	}
}
