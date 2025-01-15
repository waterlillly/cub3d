#include "../cub3d.h"

static  int ascii_print(char c)
{
    printf("ascii_print\n");
    if (c >= 33 && c < 127)
        return (1);
    else
        return (0);
}

static char *texture_path(char *line, int column)
{
    printf("texture_path\n");
    int row;
    int length;
    char *path_to_texture;

    while (line[column] && (line[column] == ' ' || line[column] == '\t'))
        column++;
    length = column;
    while (line[length] && (line[length] != ' ' && line[length] != '\t'))
        length++;
    path_to_texture = malloc(sizeof(char) * (length - column + 1));
    if (!path_to_texture)
        return (NULL);
    //i need to check when I call the function, if the return is NULL, I need to free the memory
    row = 0;
    while (line[column] && (line[length] != ' ' && line[length] != '\t' && line[length] != '\n'))
        path_to_texture[row++] = line[column++];
    path_to_texture[row] = '\0';
    while (line[column] && (line[column] == ' ' || line[column] == '\t'))
        column++;
    if (line[column] && line[column] != '\n')
    {
        free(path_to_texture);
        path_to_texture = NULL;
    }
    return (path_to_texture);
}

int add_texture(t_texture *Itex, char *line, int column)
{
    printf("add_texture\n");
    if (line[column + 2] && ascii_print(line[column + 2]))
        return (ERR);
    if (line[column] == 'N' && line[column + 1] == 'O' && !(Itex->north))
        Itex->north = texture_path(line, column + 2);
    else if (line[column] == 'S' && line[column + 1] == 'O' && !(Itex->south))
        Itex->south = texture_path(line, column + 2);
    else if (line[column] == 'W' && line[column + 1] == 'E' && !(Itex->west))
        Itex->west = texture_path(line, column + 2);
    else if (line[column] == 'E' && line[column + 1] == 'A' && !(Itex->east))
        Itex->east = texture_path(line, column + 2);
    else
        return (ERR);
    return (SUCC);
}