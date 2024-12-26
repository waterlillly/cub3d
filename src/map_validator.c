#include "../cub3d.h"

/*
NO, SO, WE, EA: Paths to wall textures.

F: Floor color in RGB format.
C: Ceiling color in RGB format.

- The map is represented using the letters 0 (empty space) and 1 (wall),
and the spawn point with the orientation N, S, E or W. The map must be
surrounded by walls.
*/

/*
	game->map.count_players = 0;
	game->map.count_pizza = 0;
	game->map.count_columns = ft_strlen(game->map.full[0]);
	game->map.count_exit = 0;
	game->movements = 0;
	game->player_sprite = P_RIGHT;
	game->exit_status = 0;

*/

void mapValidator(t_game *game, char *av)
{
	(void)av;
	(void)game;
}