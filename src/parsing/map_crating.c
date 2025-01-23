#include "../../cub3d.h"

static size_t	max_column(char **file, int rows)
{
	size_t	max_column;
	size_t	actual_size;//TODO: just an idea

	max_column = 0;//TODO: just an idea
	//max_column = ft_strlen(file[rows]);
	while (file[rows])
	{
		actual_size = ft_strlen(file[rows]);//TODO: just an idea
		if (file[rows][actual_size - 1] == '\n')//TODO: just an idea
			actual_size--;//TODO: just an idea
		if (actual_size > max_column)//TODO: just an idea
			max_column = actual_size;//TODO: just an idea
		//if (ft_strlen(file[rows]) > max_column)
			//max_column = ft_strlen(file[rows]);
		printf("|%s| -> %zu\n", file[rows], max_column);
		rows++;
	}
	return (max_column);
}

static void	make_the_map(t_game *game, char **file, int rows)
{
	int		row;
	int		column;
	char	*tmp;//TODO: just an idea

	row = 0;
	game->data.max_column = max_column(file, rows);
	printf("%d\n", game->data.max_column);
	while (row < game->data.num_of_rows)
	{
		column = 0;
		tmp = ft_strtrim(file[rows], "\n");//TODO: just an idea
		game->data.map[row] = ft_calloc(sizeof(char), game->data.max_column + 1);
		if (!game->data.map[row])
			(free(tmp), tmp = NULL, exit_failure("ft_calloc failed", game));
		ft_memset(game->data.map[row], ' ', game->data.max_column);
		ft_memcpy(game->data.map[row], game->data.file_data[rows], ft_strlen(game->data.file_data[rows]));//TODO: if we use the idea: change all game->data.file_data[rows] to tmp
		(free(tmp), tmp = NULL);//TODO: just an idea
		if (!game->data.map[row])
			exit_failure("invalid map", game);
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
		while (file_data[row][column] == SPACE || file_data[row][column] == TAB//TODO: can ONLY have spaces inside the map and ONE newline at the end of a line (no newlines at the start)
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
	make_the_map(game, file, row);//TODO: before making the map: check for newline at the end of each line and trim it off
	return (SUCC);
}

int	map_creating(t_game *game, char **file, int row)
{
	if (game->textures[NORTH].name == NULL || game->textures[SOUTH].name == NULL
		|| game->textures[WEST].name == NULL
		|| game->textures[EAST].name == NULL)
		exit_failure("Texture missing OR map is not last", game);
	if (game->data.ceiling_color[0] == -1 || game->data.ceiling_color[1] == -1
		|| game->data.ceiling_color[2] == -1 || game->data.floor_color[0] == -1
		|| game->data.floor_color[1] == -1 || game->data.floor_color[2] == -1)
		exit_failure("Color missing OR map is not last", game);//TODO: instead of this check: add bool variable in struct for each color once it is set and checked?
	if (init_map(game, file, row) == FAIL)
		exit_failure(".. in init_map", game);
	for (int i = 0; i < game->data.num_of_rows; i++)
		printf("|%s|\n", game->data.map[i]);
	return (SUCC);
}
