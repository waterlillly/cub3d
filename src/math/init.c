#include "../../cub3d.h"

static void load_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (access(game->txts[i].name, F_OK))
			exit_failure("Error: texture not found", game);
		game->txts[i].img = mlx_xpm_file_to_image(game->cub.mlx_con,
			game->txts[i].name, &game->txts[i].width, &game->txts[i].height);
		if (!game->txts[i].img)
			exit_failure("Error: mlx_xpm_file_to_image", game);
		game->txts[i].addr = mlx_get_data_addr(game->txts[i].img, &game->txts[i].bpp, &game->txts[i].len, &game->txts[i].endian);
		if (!game->txts[i].addr)
			exit_failure("Error: mlx_get_data_addr", game);
		i++;
	}
}

static void	init_map(t_game *game)
{
	game->map = ft_calloc(MAP_HEIGHT + 1, sizeof(char *));
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

static void	init_textures(t_game *game)
{
	game->txts[NORTH].name = "assets/textures/pattern.xpm";
	game->txts[SOUTH].name = "assets/textures/pattern.xpm";
	game->txts[EAST].name = "assets/textures/moon.xpm";
	game->txts[WEST].name = "assets/textures/moon.xpm";
	load_textures(game);
}

static void	init_mlx(t_game *game)
{
	game->cub.mlx_win = mlx_new_window(game->cub.mlx_con,
		WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (!game->cub.mlx_win)
		exit_failure("Error: mlx_new_window", game);
	game->cub.img.img = mlx_new_image(game->cub.mlx_con,
		WIN_WIDTH, WIN_HEIGHT);
	if (!game->cub.img.img)
		exit_failure("Error: mlx_new_image", game);
	game->cub.img.addr = mlx_get_data_addr(game->cub.img.img, &game->cub.img.bpp,
			&game->cub.img.len, &game->cub.img.endian);
	if (!game->cub.img.addr)
		exit_failure("Error: mlx_get_data_addr", game);
}

static void	init_player(t_game *game)
{
	game->cub.player.p_x = TILE_SIZE * 5;//TODO: get actual x starting position!
	game->cub.player.p_y = TILE_SIZE * 3;//TODO: get actual y starting position!
	game->cub.player.angle = M_PI / 4;
	game->cub.player.fov = FOV;
	game->cub.player.move_speed = 5;
	game->cub.player.turn_speed = 0.05;
}

void	init_cub(t_game *game)
{
	game->cub.mlx_con = mlx_init();
	if (!game->cub.mlx_con)
		exit_failure("Error: mlx_con", game);
	ft_bzero(&game->rays, sizeof(t_raycast));
	init_map(game);
	init_mlx(game);
	init_textures(game);
	init_player(game);
}
