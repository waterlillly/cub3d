#include "../../cub3d.h"

// static void	init_map(t_game *game) // TODO: delete and get actual map
// {
// 	game->map = ft_calloc(100 + 1, sizeof(char *));
// 	if (!game->map)
// 		exit_failure("ft_calloc", game);
// 	game->map[0] = ft_strdup("1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");
// 	game->map[1] = ft_strdup("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001");
// 	game->map[2] = ft_strdup("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001");
// 	game->map[3] = ft_strdup("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001");
// 	game->map[4] = ft_strdup("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001");
// 	game->map[5] = ft_strdup("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001");
// 	game->map[6] = ft_strdup("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001");
// 	game->map[7] = ft_strdup("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001");
// 	game->map[8] = ft_strdup("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001");
// 	game->map[9] = ft_strdup("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001");
	
// 	// Long hallway starts
// 	for (int i = 10; i <= 90; i++)
// 		game->map[i] = ft_strdup("1111111111111111111111101111111111111111111111111011111111111111111111111011111111111111111111111111");

// 	// Map resumes
// 	game->map[91] = ft_strdup("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001");
// 	game->map[92] = ft_strdup("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001");
// 	game->map[93] = ft_strdup("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001");
// 	game->map[94] = ft_strdup("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001");
// 	game->map[95] = ft_strdup("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001");
// 	game->map[96] = ft_strdup("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001");
// 	game->map[97] = ft_strdup("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001");
// 	game->map[98] = ft_strdup("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001");
// 	game->map[99] = ft_strdup("1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");
// }

static void	init_map(t_game *game) // TODO: delete and get actual map
{
	game->map = ft_calloc(MAP_SIZE + 1, sizeof(char *));
	if (!game->map)
		exit_failure("ft_calloc", game);
	game->map[0] = ft_strdup("1111111111111111111111111");
	game->map[1] = ft_strdup("1000000000000000000000001");
	game->map[2] = ft_strdup("1011110111110111110111101");
	game->map[3] = ft_strdup("1010010000010000010000101");
	game->map[4] = ft_strdup("1010010111010111010111101");
	game->map[5] = ft_strdup("1010000000000000000000101");
	game->map[6] = ft_strdup("1110111111011111011110101");
	game->map[7] = ft_strdup("1000100011010001010000101");
	game->map[8] = ft_strdup("1011101111010111011111101");
	game->map[9] = ft_strdup("1000000000000100000000001");
	game->map[10] = ft_strdup("1010111011111111111011101");
	game->map[11] = ft_strdup("1010000010000000010000101");
	game->map[12] = ft_strdup("1011111010111111010111101");
	game->map[13] = ft_strdup("1000000010001000010000001");
	game->map[14] = ft_strdup("1011111111011111111111101");
	game->map[15] = ft_strdup("1010000000000000000000001");
	game->map[16] = ft_strdup("1010111111111111111011101");
	game->map[17] = ft_strdup("1000000000000000000000001");
	game->map[18] = ft_strdup("1011111011111011111011101");
	game->map[19] = ft_strdup("1000000010000010000010001");
	game->map[20] = ft_strdup("1111011110111111111110001");
	game->map[21] = ft_strdup("1000000000000000000000001");
	game->map[22] = ft_strdup("1011110111110111110111101");
	game->map[23] = ft_strdup("1000100001000000000000101");
	game->map[24] = ft_strdup("1111111111111111111111111");
}

// static void	init_map(t_game *game) // TODO: delete and get actual map
// {
// 	game->map = ft_calloc(MAP_SIZE + 1, sizeof(char *));
// 	if (!game->map)
// 		exit_failure("ft_calloc", game);
// 	game->map[0] = ft_strdup("1111111111");
// 	game->map[1] = ft_strdup("1000000001");
// 	game->map[2] = ft_strdup("1010100101");
// 	game->map[3] = ft_strdup("1010101001");
// 	game->map[4] = ft_strdup("1000000101");
// 	game->map[5] = ft_strdup("1111000101");
// 	game->map[6] = ft_strdup("1000000001");
// 	game->map[7] = ft_strdup("1011010011");
// 	game->map[8] = ft_strdup("1000010001");
// 	game->map[9] = ft_strdup("1111111111");
// }

static void	load_textures(t_game *game)
{
	int	i;

	i = 0;
	game->textures[NORTH].name = "assets/textures/moon.xpm";
	game->textures[SOUTH].name = "assets/textures/moon.xpm";
	game->textures[EAST].name = "assets/textures/pattern.xpm";
	game->textures[WEST].name = "assets/textures/pattern.xpm";
	while (i < 4)
	{
		if (access(game->textures[i].name, F_OK))
			exit_failure("texture not found", game);
		game->textures[i].img = mlx_xpm_file_to_image(game->cub.mlx_con,
				game->textures[i].name, &game->textures[i].width,
				&game->textures[i].height);
		if (!game->textures[i].img)
			exit_failure("mlx_xpm_file_to_image", game);
		game->textures[i].addr = mlx_get_data_addr(game->textures[i].img,
				&game->textures[i].bpp, &game->textures[i].len,
				&game->textures[i].endian);
		if (!game->textures[i].addr)
			exit_failure("mlx_get_data_addr", game);
		check_texture(game, i);
		i++;
	}
}

static void	init_mlx(t_game *game)
{
	game->cub.mlx_win = mlx_new_window(game->cub.mlx_con, WIN_SIZE, WIN_SIZE,
			"cub3d");
	if (!game->cub.mlx_win)
		exit_failure("mlx_new_window", game);
	game->cub.img.img = mlx_new_image(game->cub.mlx_con, WIN_SIZE, WIN_SIZE);
	if (!game->cub.img.img)
		exit_failure("mlx_new_image", game);
	game->cub.img.addr = mlx_get_data_addr(game->cub.img.img,
			&game->cub.img.bpp, &game->cub.img.len, &game->cub.img.endian);
	if (!game->cub.img.addr)
		exit_failure("mlx_get_data_addr", game);
}

static void	get_orientation(t_game *game)
{
	if (game->data.p_orientation == NORTH)
	{
		game->player.dir.x = 0;
		game->player.dir.y = -1;
	}
	else if (game->data.p_orientation == SOUTH)
	{
		game->player.dir.x = 0;
		game->player.dir.y = 1;
	}
	else if (game->data.p_orientation == EAST)
	{
		game->player.dir.x = 1;
		game->player.dir.y = 0;
	}
	else if (game->data.p_orientation == WEST)
	{
		game->player.dir.x = -1;
		game->player.dir.y = 0;
	}
	game->player.dir = norm(game->player.dir);
}

static void	init_player(t_game *game)
{
	game->player.pos.x = 8 * TILE_SIZE; // TODO: get actual x starting position!
	game->player.pos.y = 5.5 * TILE_SIZE; // TODO: get actual y starting position!
	game->data.p_orientation = EAST;   // TODO: get actual direction
	get_orientation(game);
	if (game->data.p_orientation == NORTH || game->data.p_orientation == SOUTH)
	{
		game->plane.x = tan(FOV / 2.0);
		game->plane.y = 0.0;
	}
	else
	{
		game->plane.x = 0.0;
		game->plane.y = tan(FOV / 2.0);
	}
	game->player.move_speed = 5;
	game->player.turn_speed = 0.05;
}

void	init_cub(t_game *game)
{
	game->cub.mlx_con = mlx_init();
	if (!game->cub.mlx_con)
		exit_failure("mlx_con", game);
	ft_bzero(&game->ray, sizeof(t_ray));
	game->data.ceiling_color[0] = 5;//TODO: get actual colors
	game->data.ceiling_color[1] = 10;
	game->data.ceiling_color[2] = 150;
	game->data.floor_color[0] = 0;
	game->data.floor_color[1] = 150;
	game->data.floor_color[2] = 50;
	get_colors(game);
	init_map(game);
	init_mlx(game);
	load_textures(game);
	init_player(game);
}
