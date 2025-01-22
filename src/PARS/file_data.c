#include "../../cub3d.h"

static int get_color_texture_and_map(t_game *game, char **file_data , int row, int column)
{
    while (file_data[row][column] == SPACE || file_data[row][column] == TAB || file_data[row][column] == NEWLINE)
        column++;
    if (ascii_print(file_data[row][column]) && !ft_isdigit(file_data[row][column]))
    {
        if (ascii_print(file_data[row][column + 1]) && !ft_isdigit(file_data[row][column + 1]))
        {
            if (add_texture(&game->Itex, file_data[row], column) == ERR)
                free_all(game, "Error in texture");
            return (BREAK);
        }
        else
        {
            if (add_color(&game->Itex, file_data[row], column) == ERR)
                free_all(game, "Error in color");
            return (BREAK);
        }
    }
    else if (ft_isdigit(file_data[row][column]))
    {
        if (map_crating(game, file_data, row) == ERR)
			free_all(game, "Error in map");
		return (SUCC);
    }
    return (CONT);
}

int file_data(t_game *game, char **file_data)
{
    int row = 0;
    int column = 0;
    int ret;

    while (file_data[row])
    {
        column = 0;
        while (file_data[row][column] && row < 11)
        {
            ret = get_color_texture_and_map(game, file_data, row, column);
            if (ret == BREAK)
                break;
            else if (ret == SUCC)
                return (SUCC);
            column++;
        }
        row++;
    }
    return (SUCC);
}