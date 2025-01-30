#include "../../cub3d.h"

static void	load_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (access(game->textures[i].name, R_OK))
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
	t_ivec	size;

	mlx_get_screen_size(game->cub.mlx_con, &size.x, &size.y);
	if (size.x < WIN_SIZE || size.y < WIN_SIZE)
		exit_failure("screensize too small", game);
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
	game->player.pos.x = (game->player.pos.x + 0.5) * game->macro.tile_size;
	game->player.pos.y = (game->player.pos.y + 0.5) * game->macro.tile_size;
	get_orientation(game);
	if (game->data.p_orientation == NORTH || game->data.p_orientation == SOUTH)
	{
		game->plane.x = tan(game->macro.fov / 2.0);
		game->plane.y = 0.0;
		if (game->data.p_orientation == SOUTH)
			game->plane.x *= -1;
	}
	else if (game->data.p_orientation == EAST || game->data.p_orientation == WEST)
	{
		game->plane.x = 0.0;
		game->plane.y = tan(game->macro.fov / 2.0);
		if (game->data.p_orientation == WEST)
			game->plane.y *= -1;
	}
	ft_bzero(&game->control, sizeof(t_control));
	game->player.move_speed = 3;
	game->player.turn_speed = 0.1;
}

void	init_cub(t_game *game)
{
	game->cub.mlx_con = mlx_init();
	if (!game->cub.mlx_con)
		exit_failure("mlx_con", game);
	init_mlx(game);
	init_macros(game);
	ft_bzero(&game->ray, sizeof(t_ray));
	get_colors(game);
	parse_doors(game);
	game->textures[DOOR].name = "assets/textures/metal_door_bars.xpm";
	load_textures(game);
	init_player(game);
}
