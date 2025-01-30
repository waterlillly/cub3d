#include "../../cub3d.h"

void	validate_game(t_game *game, char **av)
{
	validate_input_file(av[1], game);
	is_valid_map(game);
}
