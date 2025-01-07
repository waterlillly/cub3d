#include "../cub3d.h"

static int get_color_and_texture(t_game *game, char **map, int row, int column)
{
    (void)game;

    while (map[row][column] == SPACE || map[row][column] == TAB || map[row][column] == NEWLINE)
        column++;
    
}

int file_data(t_game *game, char **map)
{
    int row = 0;
    int column = 0;
    int check;

    (void)check;
    (void)game;

    while (map[row])
    {
        column = 0;
        while (map[row][column])
        {
            //func that chacks 
            column++;
        }
        row++;
    }
    return (SUCC);
}