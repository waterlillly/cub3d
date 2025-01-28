#include "../../cub3d.h"

static void	load_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 5)
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
	game->player.pos.x = 9.5 * game->macro.tile_size;
	game->player.pos.y = 5.5 * game->macro.tile_size;
	get_orientation(game);
	if (game->data.p_orientation == NORTH || game->data.p_orientation == SOUTH)
	{
		game->plane.x = tan(game->macro.fov / 2.0);
		game->plane.y = 0.0;
	}
	else
	{
		game->plane.x = 0.0;
		game->plane.y = tan(game->macro.fov / 2.0);
	}
	game->control.forward_velo = 0;
	game->control.backward_velo = 0;
	game->control.left_velo = 0;
	game->control.right_velo = 0;
	game->control.turn_left_velo = 0;
	game->control.turn_right_velo = 0;
	game->player.move_speed = 2;
	game->player.turn_speed = 0.1;
}

void	init_cub(t_game *game)
{
	game->cub.mlx_con = mlx_init();
	if (!game->cub.mlx_con)
		exit_failure("mlx_con", game);
	ft_bzero(&game->ray, sizeof(t_ray));
	game->data.ceiling_color[0] = 5;
	game->data.ceiling_color[1] = 10;
	game->data.ceiling_color[2] = 150;
	game->data.floor_color[0] = 0;
	game->data.floor_color[1] = 150;
	game->data.floor_color[2] = 50;
	get_colors(game);
	init_map_with_doors(game);
	parse_doors(game);
	init_mlx(game);
	game->textures[NORTH].name = "assets/textures/purple_brick_wall_trippy.xpm";
	game->textures[SOUTH].name = "assets/textures/purple_brick_wall_trippy.xpm";
	game->textures[EAST].name = "assets/textures/purple_brick_wall_trippy.xpm";
	game->textures[WEST].name = "assets/textures/purple_brick_wall_trippy.xpm";
	game->textures[DOOR].name = "assets/textures/metal_door_bars.xpm";
	load_textures(game);
	init_player(game);
}
