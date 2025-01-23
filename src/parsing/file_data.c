#include "../../cub3d.h"

static int get_color_texture_and_map(t_game *game, char **file_data , int row, int column)
{
    while (file_data[row][column] == SPACE || file_data[row][column] == NEWLINE)
        column++;
    if (ascii_print(file_data[row][column]) && !ft_isdigit(file_data[row][column]))
    {
        if (ascii_print(file_data[row][column + 1]) && !ft_isdigit(file_data[row][column + 1]))
        {
            if (add_texture(game, file_data[row], column) == ERR)
                exit_failure("Error in texture", game);
            return (BREAK);//TODO: we are already exiting the program if there is an error
        }
        else
        {
            if (add_color(game, file_data[row], column) == ERR)
                exit_failure("Error in color", game);
            return (BREAK);//TODO: we are already exiting the program if there is an error
        }
    }
    else if (ft_isdigit(file_data[row][column]))
    {
        if (map_creating(game, file_data, row) == ERR)
			exit_failure("Error in map", game);
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
        while (file_data[row][column] && row < 11)//TODO: what does 11 mean?
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