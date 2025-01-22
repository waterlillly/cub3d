#include "../../cub3d.h"

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
    int height = game->data.num_of_rows;

    row = -1;
    while (game->data.map[++row])
    {
        width = ft_strlen_skip_space(game->data.map[row]);
        column = -1;
        while (game->data.map[row][++column])
        {
            if (game->data.map[row][column] != '1' && game->data.map[row][column] != ' ')
            {
                if (row == 0 || column == 0 || row == height - 1 || column == width - 1)
                    exit_failure("Map not surrounded by walls 2", game);
                else if (game->data.map[row - 1][column - 1] == ' ' || game->data.map[row - 1][column] == ' '
                    || game->data.map[row - 1][column + 1] == ' ' || game->data.map[row][column + 1] == ' '
                    || game->data.map[row + 1][column + 1] == ' ' || game->data.map[row + 1][column] == ' '
                    || game->data.map[row + 1][column - 1] == ' ' || game->data.map[row][column - 1] == ' ')
                    exit_failure("Map not surrounded by walls 3", game);
            }
        }
    }
    printf("SURROUNDED BY WALLS\n");
}

void valid_map(t_game *game)
{
    if (game->data.map == NULL)
        exit_failure("Map missing", game);
    map_border(game); //still doesn't work on the right side of the map, don't know why
    if (game->data.num_of_rows < 3)
        exit_failure("Map is too small", game);
    check_elements(game); //got orientation of the player and possition; Do I need to check if position is valid?
}
