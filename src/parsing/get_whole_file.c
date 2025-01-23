#include "../../cub3d.h"

static int	line_count(t_game *game, char *path)
{
	int		fd;
	int		line_count;
	char	*line;

	line_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_failure(MAP_FILE_NOT_FOUND, game);
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			line_count++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (line_count);
}

static void	get2D_array(t_game *game)
{
	int		i;
	int		row;
	size_t	column;
	char	*line;

	i = 0;
	row = 0;
	column = 0;
	line = get_next_line(game->data.fd);
	while (line != NULL)
	{
		game->data.file_data[row] = ft_calloc(ft_strlen(line) + 1,
				sizeof(char));
		if (!game->data.file_data[row])
			exit_failure(MALLOC_FAILED, game);
		while (line[i] != '\0')
			game->data.file_data[row][column++] = line[i++];
		game->data.file_data[row++][column] = '\0';//TODO: not needed because calloc was used
		column = 0;
		i = 0;
		free(line);
		line = get_next_line(game->data.fd);
	}
	game->data.file_data[row] = NULL;
}

void	get_whole_file(t_game *game, char *path)
{
	game->data.line_count = line_count(game, path);
	game->data.path = path;
	game->data.file_data = malloc(sizeof(char *) * (game->data.line_count + 1));
	if (!game->data.file_data)
		exit_failure(MALLOC_FAILED, game);
	game->data.fd = open(path, O_RDONLY);
	if (game->data.fd < 0)
		exit_failure(MAP_FILE_NOT_FOUND, game);
	else
	{
		get2D_array(game);
		close(game->data.fd);
	}
}