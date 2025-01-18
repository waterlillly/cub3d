#include "../cub3d.h"

void valid_map(t_game *game)
{
    printf("valid_map\n");
    if (game->TheMapInfo.map == NULL)
        exit(1); //and free all
}
