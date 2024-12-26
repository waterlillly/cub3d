#include "../cub3d.h"

/*
	game->map.count_players = 0;
	game->map.count_pizza = 0;
	game->map.count_columns = ft_strlen(game->map.full[0]);
	game->map.count_exit = 0;
	game->movements = 0;
	game->player_sprite = P_RIGHT;
	game->exit_status = 0;

*/

void initialization_of_vars(t_game *game)
{
    game->num_of_columns = 0;
    game->num_of_player = 0;
    game->num_of_orientations = 0;
}