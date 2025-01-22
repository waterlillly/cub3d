#include "../cub3d.h"

void check_elements(t_game *game)
{
    int row;
    int column;
    int players = 0;
    char orientation = '0';

    row = 0;
    while (game->TheMapInfo.map[row])
    {
        column = 0;
        while (game->TheMapInfo.map[row][column])
        {
            if (ft_strchr("NSEW", game->TheMapInfo.map[row][column]) && orientation == '0'){
                orientation = game->TheMapInfo.map[row][column];
                game->player.row = row;
                game->player.column = column;
                players++;
            }
            column++;
        }
        row++;
    }
    if (players != 1)
        free_all(game, "Player missing or too many players");
    game->p_direction = orientation;
    printf("PLAYER ORIENTATION: %c\n", game->p_direction);
}
