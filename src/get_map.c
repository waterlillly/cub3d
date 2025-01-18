#include "../cub3d.h"

void free_array(void **array)
{
	printf("free_array\n");
	size_t i = 0;

	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	if (array){
		free(array);
		array = NULL;
	}
}

static int line_count(t_game *game, char *path)
{
	printf("line_count\n");
	int	fd;
	int line_count;
	char *line;

	line_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error_msg_free_exit(MAP_FILE_NOT_FOUND, game);
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
	return line_count;
}

static void get2D_array(t_game *game)
{
	printf("get2D_array\n");
	int i = 0;
	int row = 0;
	size_t column = 0;
	char *line;

	line = get_next_line(game->fd);
	while (line != NULL)
	{
		game->file[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!game->file[row]){
			printf("Error\n%s", MALLOC_FAILED); // change
			return (free_array((void **)game->file));
		}
		while (line[i] != '\0')
			game->file[row][column++] = line[i++];
		game->file[row++][column] = '\0';
		column = 0;
		i = 0;
		free(line);
		line = get_next_line(game->fd);
	}
	game->file[row] = NULL;
}

void get_whole_file(t_game *game, char *path)
{
	printf("get_map\n");
	game->line_count = line_count(game, path);
	game->path = path;
	game->file = malloc(sizeof(char *) * (game->line_count + 1));
	if (!game->file)
		ft_error_msg_free_exit(MALLOC_FAILED, game);
	game->fd = open(path, O_RDONLY);
	if (game->fd < 0){
		free_array((void **)game->file);
		ft_error_msg_free_exit(MAP_FILE_NOT_FOUND, game);
	}
	else
	{
		get2D_array(game);
		close(game->fd);
	}
	// free game->file out of scope 
}