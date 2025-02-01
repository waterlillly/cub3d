#include "../../cub3d_bonus.h"

static void	validate_row_and_column(t_game *game, int row, int column,
		int width)
{
	int	height;

	height = game->data.num_of_rows;
	if (row == 0 || column == 0 || row == height - 1 || column == width - 1)
		exit_failure("Map not surrounded by walls", game);
	else if (game->data.map[row - 1][column] == ' '
		|| game->data.map[row + 1][column] == ' '
		|| game->data.map[row][column + 1] == ' '
		|| game->data.map[row][column - 1] == ' ')
		exit_failure("Map not surrounded by walls", game);
}

void	validate_border(t_game *game)
{
	int	row;
	int	column;
	int	width;
	int	height;

	row = -1;
	height = game->data.num_of_rows;
	while (game->data.map[++row])
	{
		column = -1;
		width = ft_strlen_skip_space(game->data.map[row]);
		while (game->data.map[row][++column])
		{
			if (game->data.map[row][column] != '1'
				&& game->data.map[row][column] != ' ')
				validate_row_and_column(game, row, column, width);
		}
	}
}

