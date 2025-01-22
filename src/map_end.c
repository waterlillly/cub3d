#include "../cub3d.h"

void check_if_map_is_last(t_game *game)
{
    int row;
    int column;

    row = 0;
    while (game->file[row])
    {
        column = 0;
        while (game->file[row][column])
        {
            
            column++;
        }
        row++;
    }
    printf("MAP IS LAST\n");
}