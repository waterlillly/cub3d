#include "../cub3d.h"

static size_t max_column(char **file, int rows)
{
    printf("max_column\n");
    size_t max_column = ft_strlen(file[rows]);

    while (file[rows])
    {
        if (ft_strlen(file[rows]) > max_column)
            max_column = ft_strlen(file[rows]);
        rows++;
    }
    return (max_column);
}

static int make_the_map(t_game *game, char **file, int rows)
{
    printf("make_the_map\n");
    int row;
    int column;

    game->TheMapInfo.max_column = max_column(file, rows);
    row = 0;
    while (row < game->TheMapInfo.num_of_rows)
    {
        column = 0;
        game->TheMapInfo.map[row] = (char *)malloc(sizeof(char) * (game->TheMapInfo.max_column + 1));
        if (!game->TheMapInfo.map[row])
            return (FAIL); //free everything that was allocated
        while (game->file[rows][column] && game->file[rows][column] != NEWLINE)
        {
            game->TheMapInfo.map[row][column] = game->file[rows][column];
            column++;
        }
        while (column < game->TheMapInfo.max_column)
            game->TheMapInfo.map[row][column++] = '\0';
        row++;
        rows++;
    }
    game->TheMapInfo.map[row] = NULL;
    return (SUCC);
}

static int rows_in_the_map(t_game *game, char **file_data, int row)
{
    printf("rows_in_the_map\n");
    int i = row;
    int column;

    while (file_data[row])
    {
        column = 0;
        while (file_data[row][column] == SPACE || file_data[row][column] == TAB || file_data[i][column] == CARRET_RETURN
               || file_data[row][column] == VERTICAL_TAB || file_data[row][column] == FORM_FEED)
            column++;
        if (file_data[row][column] != '1')
            break ;
        row++;
    }
    game->TheMapInfo.last_row = row;
    return (row - i);
}

static int init_map(t_game *game, char **file, int row)
{
    printf("init_map\n");
    game->TheMapInfo.num_of_rows = rows_in_the_map(game, file, row);
    game->TheMapInfo.map = (char **)malloc(sizeof(char *) * (game->TheMapInfo.num_of_rows + 1));
    if (!game->TheMapInfo.map)
    {
        free_all(game, MALLOC_FAILED);
        return (FAIL);
    }
    game->TheMapInfo.map_mem_alloc = true;
    make_the_map(game , file, row);
    return (SUCC);
}

int map_crating(t_game *game, char **file, int row)
{
    printf("ft_map_crating\n");
    if (game->Itex.north == NULL || game->Itex.south == NULL || game->Itex.west == NULL || game->Itex.east == NULL
        || game->Itex.floor_color == NULL || game->Itex.ceiling_color == NULL)
    {
        free_all(game, "Texture or color missing OR map is not last");
        return (FAIL);
    }
    if (init_map(game, file, row) == FAIL){
        free_all(game, ".. in init_map");
        return (FAIL);
    }
    int i = 0;
    while (game->TheMapInfo.map[i])
    {
        printf("%s\n", game->TheMapInfo.map[i]);
        i++;
    }
    return (SUCC);
}

