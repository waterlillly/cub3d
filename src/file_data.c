#include "../cub3d.h"

static  int ascii_print(char c)
{
    if (c >= 33 && c <= 126)
        return (1);
    else
        return (0);
}

static int get_color_and_texture(t_game *game, char **file_data , int row, int column)
{
    (void)game;
    printf("row: %d\n", row);
    int ret = ascii_print(file_data[row][column]);
    printf("ret: %d\n", ret);
    /* while (map[row][column] == SPACE || map[row][column] == TAB || map[row][column] == NEWLINE)
        column++; */
    return (CONT); //just so it dosnt give a warning
}

int file_data(t_game *game, char **file_data)
{
    printf("file_data\n");
    /* int row = 0;
    int column = 0;
    int check; */
    int ret;

    (void)game;
    // (void)map;

    ret = get_color_and_texture(game, file_data,0, 0);
    printf("RET: %d\n", ret);
  /*   while (map[row])
    {
        column = 0;
        while (map[row][column])
        {
            //func that chacks 
            column++;
        }
        row++;
    } */
    
    return (SUCC);
}