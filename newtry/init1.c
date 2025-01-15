#include "../cub3d1.h"

void	init_map(t_game *game)
{
	game->map = ft_calloc(MAP_SIZE + 1, sizeof(char *));
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

void	check_texture(t_game *game, int i)
{
	if (game->textures[i].width != game->textures[i].height)
	{
		ft_putstr_fd(game->textures[i].name, 2);
		exit_failure(" does not have the same width and height", game);
	}
	if (game->textures[i].bpp != 32)
		exit_failure("Error: Texture format not supported (must be 32bpp)", game);
}

void	load_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (access(game->textures[i].name, F_OK))
			exit_failure("Error: texture not found", game);
		game->textures[i].img = mlx_xpm_file_to_image(game->cub.mlx_con,
			game->textures[i].name, &game->textures[i].width, &game->textures[i].height);
		if (!game->textures[i].img)
			exit_failure("Error: mlx_xpm_file_to_image", game);
		game->textures[i].addr = mlx_get_data_addr(game->textures[i].img, &game->textures[i].bpp, &game->textures[i].len, &game->textures[i].endian);
		if (!game->textures[i].addr)
			exit_failure("Error: mlx_get_data_addr", game);
		check_texture(game, i);
		i++;
	}
}

void	init_textures(t_game *game)
{
	game->textures[NORTH].name = "assets/textures/moon.xpm";
	game->textures[SOUTH].name = "assets/textures/texture.xpm";
	game->textures[EAST].name = "assets/textures/pattern.xpm";
	game->textures[WEST].name = "assets/textures/pattern.xpm";
	load_textures(game);
}

void	init_mlx(t_game *game)
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

/* Convert given direction of player first to an angle,
	then normalize it and store it as the player direction */
void	get_orientation(t_game *game)
{
	// double	angle;

	// angle = 0.0;
	// if (game->data.p_orientation == NORTH)
	// 	angle = 90.0;
	// else if (game->data.p_orientation == SOUTH)
	// 	angle = 270.0;
	// else if (game->data.p_orientation == EAST)
	// 	angle = 0.0;
	// else if (game->data.p_orientation == WEST)
	// 	angle = 180.0;
	// game->player.dir = angle_to_vector(angle);
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


void	init_player(t_game *game)
{
	game->player.pos.x = 5 * TILE_SIZE;//TODO: get actual x starting position!
	game->player.pos.y = 5 * TILE_SIZE;//TODO: get actual y starting position!
	game->data.p_orientation = NORTH;//TODO: get actual direction
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
		exit_failure("Error: mlx_con", game);
	ft_bzero(&game->ray, sizeof(t_ray));
	init_map(game);
	init_mlx(game);
	init_textures(game);
	init_player(game);
}
