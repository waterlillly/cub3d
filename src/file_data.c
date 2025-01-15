#include "../cub3d.h"

static  int ascii_print(char c)
{
    printf("ascii_print\n");
    if (c >= 33 && c < 127)
        return (1);
    else
        return (0);
}

static int get_color_and_texture(t_game *game, char **file_data , int row, int column)
{
    printf("get_color_and_texture\n");
    while (file_data[row][column] == SPACE || file_data[row][column] == TAB || file_data[row][column] == NEWLINE)
        column++;
    if (ascii_print(file_data[row][column]) && !ft_isdigit(file_data[row][column]))
    {
        if (ascii_print(file_data[row][column + 1]) && !ft_isdigit(file_data[row][column + 1]))
        {
            if (add_texture(&game->Itex, file_data[row], column) == ERR)
                return (FAIL);
            return (BREAK);
        }
        else
        {
            //If the character is a number, it is a color
            printf("%c%c\n", file_data[row][column], file_data[row][column + 1]);
            if (add_color(&game->Itex, file_data[row], column) == ERR)
                return (FAIL);
            return (BREAK);
        }
    }
    else if (ft_isdigit(file_data[row][column]))
    {
        //Before comming here, what if there is number in tructures file name? Need to handle this?
        if (ft_map_crating(game, file_data, row) == ERR)
			return (FAIL);
		return (SUCC);
    }
    return (CONT);
}

int file_data(t_game *game, char **file_data)
{
    printf("file_data\n");
    int row = 0;
    int column = 0;
    int ret;

    while (file_data[row])
    {
        column = 0;
        while (file_data[row][column] && row < 11)
        {
            ret = get_color_and_texture(game, file_data, row, column);
            if (ret == BREAK)
                break;
            else if (ret == FAIL)
                return (FAIL);
            else if (ret == SUCC)
                return (SUCC);
            column++;
        }
        row++;
    }
    return (SUCC);
}