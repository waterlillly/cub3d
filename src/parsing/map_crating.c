#include "../../cub3d.h"

static size_t	max_column(char **file, int rows)
{
	size_t	max_column;

	max_column = ft_strlen(file[rows]);
	while (file[rows])
	{
		printf("|%s| -> %zu\n", file[rows], max_column);
		if (ft_strlen(file[rows]) > max_column)
			max_column = ft_strlen(file[rows]);
		rows++;
	}
	return (max_column);
}

static void	make_the_map(t_game *game, char **file, int rows)
{
	int	row;
	int	column;

	row = 0;
	game->data.max_column = max_column(file, rows);
	printf("%d\n", game->data.max_column);
	while (row < game->data.num_of_rows)
	{
		column = 0;
		game->data.map[row] = ft_calloc(sizeof(char), game->data.max_column + 1);
		if (!game->data.map[row])
			exit_failure("ft_calloc failed", game);
		ft_memset(game->data.map[row], ' ', game->data.max_column);
		ft_strlcpy(game->data.map[row], game->data.file_data[rows], ft_strlen(game->data.file_data[rows]));
		if (!game->data.map[row])
			exit_failure("invalid map", game);
		if (game->data.map[row][ft_strlen(game->data.map[row]) - 1] == '\n')
			game->data.map[row] = ft_strtrim(game->data.map[row], "\n");
		row++;
		rows++;
	}
}

static int	rows_in_the_map(t_game *game, char **file_data, int row)
{
	int	i;
	int	column;

	i = row;
	while (file_data[row])
	{
		column = 0;
		while (file_data[row][column] == SPACE || file_data[row][column] == TAB
			|| file_data[i][column] == CARRET_RETURN
			|| file_data[row][column] == VERTICAL_TAB
			|| file_data[row][column] == FORM_FEED)
			column++;
		if (file_data[row][column] != '1')
			break ;
		row++;
	}
	game->data.last_row = row;
	return (row - i);
}

static int	init_map(t_game *game, char **file, int row)
{
	game->data.num_of_rows = rows_in_the_map(game, file, row);
	game->data.map = ft_calloc(sizeof(char *), (game->data.num_of_rows + 1));
	if (!game->data.map)
		return (FAIL);
	make_the_map(game, file, row);
	return (SUCC);
}

int	map_crating(t_game *game, char **file, int row)
{
	if (game->textures[NORTH].name == NULL || game->textures[SOUTH].name == NULL
		|| game->textures[WEST].name == NULL
		|| game->textures[EAST].name == NULL)
		exit_failure("Texture missing OR map is not last", game);
	if (game->data.ceiling_color[0] == -1 || game->data.ceiling_color[1] == -1
		|| game->data.ceiling_color[2] == -1 || game->data.floor_color[0] == -1
		|| game->data.floor_color[1] == -1 || game->data.floor_color[2] == -1)
		exit_failure("Color missing OR map is not last", game);
	if (init_map(game, file, row) == FAIL)
		exit_failure(".. in init_map", game);
	for (int i = 0; i < game->data.num_of_rows; i++)
		printf("|%s|\n", game->data.map[i]);
	return (SUCC);
}
