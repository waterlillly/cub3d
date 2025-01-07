#include "../cub3d.h"


void initialization_of_vars(t_game *game)
{
    game->num_of_columns = ft_strlen(game->file_data[0]);
    game->num_of_player = 0;
    game->num_of_orientations = 0;
    game->exit_status = 0;
}