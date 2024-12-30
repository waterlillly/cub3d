#include "../../cub3d.h"

void load_background(t_game *game)
{
	if (access(game->cub->bg_file, F_OK) == -1)
		exit_failure("Error: background file not found", game);
	game->cub->bg_img = mlx_xpm_file_to_image(game->cub->mlx_con,
		game->cub->bg_file, &game->cub->bg_width, &game->cub->bg_height);
	if (!game->cub->bg_img)
		exit_failure("Error: mlx_xpm_file_to_image", game);
}

void	init_mlx(t_game *game)
{
	game->cub->mlx_win = mlx_new_window(game->cub->mlx_con,
		game->cub->screen_width, game->cub->screen_height, "cub3d");
	if (!game->cub->mlx_win)
		exit_failure("Error: mlx_new_window", game);
	game->cub->img.img_ptr = mlx_new_image(game->cub->mlx_con,
		game->cub->screen_width, game->cub->screen_height);
	if (!game->cub->img.img_ptr)
		exit_failure("Error: mlx_new_image", game);
	game->cub->img.pxl_ptr = mlx_get_data_addr(game->cub->img.img_ptr, &game->cub->img.bpp,
			&game->cub->img.len, &game->cub->img.endian);
	if (!game->cub->img.pxl_ptr)
		exit_failure("Error: mlx_get_data_addr", game);
	load_background(game);
}

void	init_cub(t_game *game)
{
	t_cub	*cub;

	cub = ft_calloc(1, sizeof(t_cub));
	if (!cub)
		exit_failure("Error: ft_calloc", game);
	ft_bzero(cub, sizeof(t_cub));
	game->cub = cub;
	game->cub->mlx_con = mlx_init();
	if (!game->cub->mlx_con)
		exit_failure("Error: mlx_con", game);
	if (screen(game->cub) == 1)
		exit_failure("Error: screen", game);
	game->cub->bg_file = "assets/background/white_bg.xpm";
	init_mlx(game);
	init_player(game);
	render_scene(game);
	if (mlx_handler(game) != 0)
		exit_failure("Error: mlx_handler", game);
	if (mlx_loop(game->cub->mlx_con) != 0)
		exit_failure("Error: mlx_loop", game);
}
