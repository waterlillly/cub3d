#include "../cub3d.h"

static void check_top_and_bottom(t_game *game, int row, int column)
{
    
    if (!game->TheMapInfo.map || !game->TheMapInfo.map[row] || !game->TheMapInfo.map[row][column])
        free_all(game, "in check_top_and_bottom");
    while (game->TheMapInfo.map[row][column] == SPACE || game->TheMapInfo.map[row][column] == TAB
            || game->TheMapInfo.map[row][column] == CARRET_RETURN || game->TheMapInfo.map[row][column] == FORM_FEED
            || game->TheMapInfo.map[row][column] == VERTICAL_TAB)
        column++;
    while (game->TheMapInfo.map[row][column])
    {
        if (game->TheMapInfo.map[row][column] != '1')
            free_all(game, "Map not surrounded by walls");
        column++;
    }
}

static void map_border(t_game *game)
{
    int row;
    int column;

    check_top_and_bottom(game, 0, 0);
    row = 1;
    printf("ROWS: %d\n", game->TheMapInfo.num_of_rows);
    while (row < (game->TheMapInfo.num_of_rows - 1))
    {
        /*  
        
        |    |
        |    ||
        |    |
        

        */
        column = ft_strlen(game->TheMapInfo.map[row]);
        printf("%s\n", game->TheMapInfo.map[0]);
        if (game->TheMapInfo.map[row][column] != '1'){ //something wrong here
            printf("On row: %d and column: %d\n", row, column);
            free_all(game, "Map not surrounded by walls");
        }
        row++;
    }
    check_top_and_bottom(game, row, 0);
}

void valid_map(t_game *game)
{
    printf("valid_map\n");
    if (game->TheMapInfo.map == NULL)
        free_all(game, "Map missing");
    map_border(game);
    printf("ROWS: %d\n", game->TheMapInfo.num_of_rows);
    if (game->TheMapInfo.num_of_rows < 3)
        free_all(game, "Map is too small");
    
}
