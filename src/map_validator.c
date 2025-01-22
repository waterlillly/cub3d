#include "../cub3d.h"

int ft_strlen_skip_space(char *str)
{
    int i = 0;
    int j = 0;
    while (str[i] != '\0'){
        i++;
    }
    while (i > j)
    {
        if (str[i] == ' ')
            i--;
        else
            break;
    }
    return (i);
}

static void map_border(t_game *game)
{
    int row;
    int column;
    int width = 0;
    int height = game->TheMapInfo.num_of_rows;

    row = -1;
    while (game->TheMapInfo.map[++row])
    {
        width = ft_strlen_skip_space(game->TheMapInfo.map[row]);
        column = -1;
        while (game->TheMapInfo.map[row][++column])
        {
            if (game->TheMapInfo.map[row][column] != '1' && game->TheMapInfo.map[row][column] != ' ')
            {
                if (row == 0 || column == 0 || row == height - 1 || column == width - 1)
                    free_all(game, "Map not surrounded by walls 2");
                else if (game->TheMapInfo.map[row - 1][column - 1] == ' ' || game->TheMapInfo.map[row - 1][column] == ' '
                    || game->TheMapInfo.map[row - 1][column + 1] == ' ' || game->TheMapInfo.map[row][column + 1] == ' '
                    || game->TheMapInfo.map[row + 1][column + 1] == ' ' || game->TheMapInfo.map[row + 1][column] == ' '
                    || game->TheMapInfo.map[row + 1][column - 1] == ' ' || game->TheMapInfo.map[row][column - 1] == ' ')
                    free_all(game, "Map not surrounded by walls 3");
            }
        }
    }
    printf("SURROUNDED BY WALLS\n");
}

void valid_map(t_game *game)
{
    if (game->TheMapInfo.map == NULL)
        free_all(game, "Map missing");
    map_border(game); //still doesn't work on the right side of the map, don't know why
    if (game->TheMapInfo.num_of_rows < 3)
        free_all(game, "Map is too small");
    check_elements(game); //got orientation of the player and possition; Do I need to check if position is valid?
}
