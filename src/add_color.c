#include "../cub3d.h"

static  int ascii_print(char c)
{
    printf("ascii_print\n");
    if (c >= 33 && c < 127)
        return (1);
    else
        return (0);
}

static int *convert_to_int_array(char **rgb, int *rgb_int)
{
    int i;
    bool is_number;
    int j;
    int k;

    k = 0;
    j = 0;
    i = 0;
    //************************************************
    //** MAKE IN ANOTHER FUNC - is_number
    is_number = false;
    while (rgb[j])
    {
        while (rgb[j][k])
        {
            if (ft_isdigit(rgb[j][k]) == 1)
                is_number = true;
            k++;
        }
        if (is_number == false)
            break;
        k = 0;
        j++;
    }
    //************************************************
    while (rgb[i])
    {
        rgb_int[i] = ft_atoi(rgb[i]);
        if (rgb_int[i] < 0 || is_number == false) //check if RGB array is not a number
        {
            free_array((void **)rgb);
            free(rgb_int);
            //also free Itex->path_texture {north, south, west, east}
            return (NULL);
        }
        i++;
    }
    free_array((void **)rgb);
    return (rgb_int);
}

static int *get_rgb(char *line)
{
    printf("get_rgb\n");
    char **rgb;
    int *rgb_int;
    int len;

    rgb = ft_split(line, ',');
    len = 0;
    while (rgb[len])
        len++;
    if (len != 3)
    {
        free_array((void **)rgb);
        //also free Itex->path_texture {north, south, west, east}
        return (NULL);
    }
    rgb_int = (int *)malloc(sizeof(int) * 3);
    if (!rgb_int)
    {
        free_array((void **)rgb);
        //also free Itex->path_texture {north, south, west, east}
        return (NULL);
    }
    rgb_int = convert_to_int_array(rgb, rgb_int);
    return (rgb_int);
}

int add_color(t_texture *Itex, char *line, int column)
{
    printf("add_color\n");
    if (line[column + 1] && ascii_print(line[column + 1]))
        return (ERR);
    if (!Itex->floor_color && line[column] == 'F')
    {
        Itex->floor_color = get_rgb(line + column + 1);
        if (Itex->floor_color == 0){
            printf("Error\n");
            return (ERR);
        }
        printf("floor_color: %d %d %d\n", Itex->floor_color[0], Itex->floor_color[1], Itex->floor_color[2]);
    }
    else if (!Itex->ceiling_color && line[column] == 'C')
    {
        Itex->ceiling_color = get_rgb(line + column + 1);
        if (Itex->ceiling_color == 0){
            printf("Error\n");
            return (ERR);
        }
        printf("ceiling_color: %d %d %d\n", Itex->ceiling_color[0], Itex->ceiling_color[1], Itex->ceiling_color[2]);
    }
    else
        printf("Error\n");
    return (SUCC);
}