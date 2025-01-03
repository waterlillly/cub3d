#include "../../cub3d.h"

// static void load_background(t_game *game)
// {
// 	if (access(game->cub.bg_file, F_OK) == -1)
// 		exit_failure("Error: background file not found", game);
// 	game->cub.bg_img = mlx_xpm_file_to_image(game->cub.mlx_con,
// 		game->cub.bg_file, &game->cub.bg_width, &game->cub.bg_height);
// 	if (!game->cub.bg_img)
// 		exit_failure("Error: mlx_xpm_file_to_image", game);
// }

static void	init_map(t_game *game)
{
	game->map = ft_calloc(MAP_HEIGHT, sizeof(char *));
	if (!game->map)
		exit_failure("Error: ft_calloc", game);
	game->map[0] = ft_strdup("1111111111");
	game->map[1] = ft_strdup("1000000001");
	game->map[2] = ft_strdup("1010100101");
	game->map[3] = ft_strdup("1010101001");
	game->map[4] = ft_strdup("1000000101");
	game->map[5] = ft_strdup("1111000101");
	game->map[6] = ft_strdup("1000000001");
	game->map[7] = ft_strdup("1011010011");
	game->map[8] = ft_strdup("1000010001");
	game->map[9] = ft_strdup("1111111111");
}

static void	init_mlx(t_game *game)
{
	game->cub.mlx_win = mlx_new_window(game->cub.mlx_con,
		WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (!game->cub.mlx_win)
		exit_failure("Error: mlx_new_window", game);
	game->cub.img.img_ptr = mlx_new_image(game->cub.mlx_con,
		WIN_WIDTH, WIN_HEIGHT);
	if (!game->cub.img.img_ptr)
		exit_failure("Error: mlx_new_image", game);
	game->cub.img.pxl_ptr = mlx_get_data_addr(game->cub.img.img_ptr, &game->cub.img.bpp,
			&game->cub.img.len, &game->cub.img.endian);
	if (!game->cub.img.pxl_ptr)
		exit_failure("Error: mlx_get_data_addr", game);
	// load_background(game);
}

static void	init_player(t_game *game)
{
	game->cub.player.p_x = TILE_SIZE * 5;//TODO: get actual x starting position!
	game->cub.player.p_y = TILE_SIZE * 3;//TODO: get actual y starting position!
	game->cub.player.angle = M_PI / 4;
	game->cub.player.fov = M_PI / 3;
	game->cub.player.move_speed = 5;
	game->cub.player.turn_speed = 0.05;
}

void	init_cub(t_game *game)
{
	game->cub.mlx_con = mlx_init();
	if (!game->cub.mlx_con)
		exit_failure("Error: mlx_con", game);
	// game->cub.bg_file = "assets/background/white_bg.xpm";
	init_map(game);
	init_mlx(game);
	init_player(game);
}
