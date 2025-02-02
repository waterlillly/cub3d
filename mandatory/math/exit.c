#include "../cub3d.h"

void	free_all(t_game *game)
{
	if (game->data.map)
		ft_free_2d(game->data.map);
	if (game->data.data)
		free(game->data.data);
	if (game->data.file_data)
		ft_free_2d(game->data.file_data);
	if (game->textures[NORTH].name)
		free(game->textures[NORTH].name);
	if (game->textures[SOUTH].name)
		free(game->textures[SOUTH].name);
	if (game->textures[EAST].name)
		free(game->textures[EAST].name);
	if (game->textures[WEST].name)
		free(game->textures[WEST].name);
}

static void	destroy_mlx(t_game *game)
{
	if (game && game->cub.mlx_con && game->textures[EAST].img)
		mlx_destroy_image(game->cub.mlx_con, game->textures[EAST].img);
	if (game && game->cub.mlx_con && game->textures[WEST].img)
		mlx_destroy_image(game->cub.mlx_con, game->textures[WEST].img);
	if (game && game->cub.mlx_con && game->textures[NORTH].img)
		mlx_destroy_image(game->cub.mlx_con, game->textures[NORTH].img);
	if (game && game->cub.mlx_con && game->textures[SOUTH].img)
		mlx_destroy_image(game->cub.mlx_con, game->textures[SOUTH].img);
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
	free_all(game);
	destroy_mlx(game);
}

void	exit_failure(char *s, t_game *game)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(s, STDERR_FILENO);
	get_next_line(-1);
	if (game->cub.mlx_win)
		mlx_do_key_autorepeaton(game->cub.mlx_con);
	free_data(game);
	exit(EXIT_FAILURE);
}

int	exit_success(t_game *game)
{
	if (game->cub.mlx_win)
		mlx_do_key_autorepeaton(game->cub.mlx_con);
	free_data(game);
	exit(EXIT_SUCCESS);
}
