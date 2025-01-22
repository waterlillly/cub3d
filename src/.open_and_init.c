#include "../cub3d.h"

void	check_input_file(char *file, t_game *game)
{
	int fd;

	if (!file)// || ft_strlen(file) == 0)
		exit_failure("no .cub file found", game);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_failure("unable to open .cub file", game);
	check_file(fd, game);
	close(fd);
	modify_map(game);
	if (!valid_map(game))
		exit_failure("Invalid map", game);
}

void	init_struct(t_game *game)
{
	game->data.colors = ft_calloc(3, sizeof(char *));
	if (!game->data.colors)
		exit_failure("calloc failed", game);
	game->data.textures = ft_calloc(5, sizeof(char *));
	if (!game->data.textures)
		exit_failure("calloc failed", game);
	game->data.map = ft_calloc(2, sizeof(char *));
	if (!game->data.map)
		exit_failure("calloc failed", game);
	game->data.map_len = 0;
	game->data.map_line = NULL;
}
