#include "../cub3d.h"

static int line_count(t_game *game, char *path)
{
	printf("line_count\n");
	int	fd;
	int line_count;
	char *line;

	line_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		free_all(game, MAP_FILE_NOT_FOUND);
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
		free_all(game, MALLOC_FAILED);
	game->file_mem_alloc = true;
	game->fd = open(path, O_RDONLY);
	if (game->fd < 0){
		free_array((void **)game->file);
		free_all(game, MAP_FILE_NOT_FOUND);
	}
	else
	{
		get2D_array(game);
		close(game->fd);
	}
	// free game->file out of scope 
}