#include "../../cub3d.h"

static bool is_number(char **rgb)
{
    int j;
    int k;
    bool is_number;

    k = 0;
    j = 0;
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
    return (is_number);
}

static int *convert_to_int_array(char **rgb, int *rgb_int)
{
    int i;
    bool is_num;

    i = 0;
    is_num = is_number(rgb);
    while (rgb[i])
    {
        rgb_int[i] = ft_atoi(rgb[i]);
        if ((rgb_int[i] < 0 || rgb_int[i] > 255) || is_num == false)
        {
            free_array((void **)rgb);
            free(rgb_int);
            return (NULL);
        }
        i++;
    }
    free_array((void **)rgb);
    return (rgb_int);
}

static int *get_rgb(char *line)
{
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
        return (NULL);
    }
    rgb_int = (int *)malloc(sizeof(int) * 3);
    if (!rgb_int)
    {
        free_array((void **)rgb);
        return (NULL);
    }
    rgb_int = convert_to_int_array(rgb, rgb_int);
    return (rgb_int);
}

int add_color(t_texture *Itex, char *line, int column)
{
    if (line[column + 1] && ascii_print(line[column + 1]))
        return (ERR);
    if (!Itex->floor_color && line[column] == 'F')
    {
        Itex->floor_color = get_rgb(line + column + 1);
        if (Itex->floor_color == 0){
            return (ERR);
        }
        Itex->floor_mem_alloc = true;
    }
    else if (!Itex->ceiling_color && line[column] == 'C')
    {
        Itex->ceiling_color = get_rgb(line + column + 1);
        if (Itex->ceiling_color == 0)
            return (ERR);
        Itex->ceiling_mem_alloc = true;
    }
    else
        return (ERR);
    return (SUCC);
}