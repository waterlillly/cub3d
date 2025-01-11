#include "../../cub3d.h"

static void	destroy_mlx(t_game *game)
{
	if (game && game->cub.mlx_con && game->txts[EAST].img)
		mlx_destroy_image(game->cub.mlx_con, game->txts[EAST].img);
	if (game && game->cub.mlx_con && game->txts[WEST].img)
		mlx_destroy_image(game->cub.mlx_con, game->txts[WEST].img);
	if (game && game->cub.mlx_con && game->txts[NORTH].img)
		mlx_destroy_image(game->cub.mlx_con, game->txts[NORTH].img);
	if (game && game->cub.mlx_con && game->txts[SOUTH].img)
		mlx_destroy_image(game->cub.mlx_con, game->txts[SOUTH].img);
	if (game && game->cub.mlx_con && game->cub.img.img)
		mlx_destroy_image(game->cub.mlx_con, game->cub.img.img);
	if (game && game->cub.mlx_con && game->cub.mlx_win)
		mlx_destroy_window(game->cub.mlx_con, game->cub.mlx_win);
	if (game && game->cub.mlx_con)
	{
		mlx_destroy_display(game->cub.mlx_con);
		free(game->cub.mlx_con);
	}
}

static void	free_data(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		ft_free_2d(game->map);
	if (game->file_data)
		ft_free_2d(game->file_data);
	destroy_mlx(game);
}

void	exit_failure(char *s, t_game *game)
{
	ft_putendl_fd(s, STDERR_FILENO);
	free_data(game);
	exit(EXIT_FAILURE);
}

int	exit_success(t_game *game)
{
	free_data(game);
	exit(EXIT_SUCCESS);
}
