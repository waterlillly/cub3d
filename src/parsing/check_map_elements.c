#include "../../cub3d.h"

void	transfer_orient(char orientation, t_game *game)
{
	if (orientation == 'N')
		game->data.p_orientation = NORTH;
	if (orientation == 'S')
		game->data.p_orientation = SOUTH;
	if (orientation == 'E')
		game->data.p_orientation = EAST;
	if (orientation == 'W')
		game->data.p_orientation = WEST;
}

void check_elements(t_game *game)
{
    int row;
    int column;
    int players = 0;

    row = 0;
    while (game->data.map[row])
    {
        column = 0;
        while (game->data.map[row][column])
        {
            if (!ft_strchr(" 01NSEW", game->data.map[row][column])){
                printf("%c\n", game->data.map[row][column]);
                exit_failure("Invalid character in map", game);
            }
            if (ft_strchr("NSEW", game->data.map[row][column])){
				transfer_orient(game->data.map[row][column], game);
                game->player.pos.x = row;
                game->player.pos.y = column;
                players++;
            }
            column++;
        }
        row++;
    }
    if (players != 1)
        exit_failure("Player missing or too many players", game);
}
