#include "../cub3d.h"

// void check_vars_from_parsing(t_game *game)
// {
// 	printf("\n***CHECKING VARS FROM PARSING***\n");
// 	//TEXTURES
// 	printf("\033[0;31m\tTEXTURES\033[0m\n");
// 	printf("NO: |%s|\n", game->textures[0].name);
// 	printf("SO: |%s|\n", game->textures[1].name);
// 	printf("WE: |%s|\n", game->textures[2].name);
// 	printf("EA: |%s|\n", game->textures[3].name);
// 	printf("DOOR: |%s|\n", game->textures[4].name);
// 	//COLORS
// 	printf("\033[0;31m\tCOLORS\033[0m\n");
// 	printf("FLOOR: |%d|, |%d|, |%d|\n", game->data.floor_color[0], game->data.floor_color[1], game->data.floor_color[2]);
// 	printf("CEILING: |%d|, |%d|, |%d|\n", game->data.ceiling_color[0], game->data.ceiling_color[1], game->data.ceiling_color[2]);
// 	//PLAYER
// 	printf("\033[0;31m\tPLAYER\033[0m\n");
// 	printf("POS: |%f|, |%f|\n", game->player.pos.x, game->player.pos.y);
// 	//GENERAL
// 	printf("\033[0;31m\tGENERAL\033[0m\n");
// 	printf("NUM OF ROWS: |%d|\n", game->data.num_of_rows);
// 	printf("NUM OF COLUMNS: |%d|\n", game->data.num_of_columns);
// 	printf("MAX COLUMN: |%zu|\n", game->data.max_column);
// 	printf("NUM OF PLAYER: |%d|\n", game->data.num_of_player);
// 	printf("NUM OF ORIENTATIONS: |%d|\n", game->data.num_of_orientations);
// 	printf("PLAYER ORIENTATION: |%d|\n", game->data.p_orientation);
// 	printf("FLOOR COLOR SET: |%d|\n", game->data.floor_color_set);
// 	printf("CEILING COLOR SET: |%d|\n", game->data.ceiling_color_set);
// 	// printf("COLORS: |%s|, |%s|\n", game->data.colors[0], game->data.colors[1]);
// 	printf("EXIT STATUS: |%d|\n", game->exit_status);
// 	//UNUSED VARS FROM STRUCT
// 	printf("\033[0;31m\tUNUSED VARS FROM STRUCT\033[0m\n");
// 	printf("TO BE CONTINUED...\n");
// 	printf("************************************************\n");
// 	//MAP
// 	printf("\033[0;31m\tMAP\033[0m\n");
// 	for (int i = 0; i < game->data.num_of_rows; i++)
// 	{
// 		printf("|%s|\n", game->data.map[i]);
// 	}
// 	printf("\n");
// }

int	main(int ac, char **av)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	initialization_of_vars(&game);
	args_handler(ac, av, &game);
	validate_game(&game, av);
	// check_vars_from_parsing(&game);
	init_cub(&game);
	if (mlx_handler(&game) != 0)
		exit_failure("mlx_handler", &game);
	mlx_do_key_autorepeatoff(game.cub.mlx_con);
	mlx_loop(game.cub.mlx_con);
	mlx_do_key_autorepeaton(game.cub.mlx_con);
	return (exit_success(&game));
}
