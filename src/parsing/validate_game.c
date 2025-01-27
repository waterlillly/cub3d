#include "../../cub3d.h"

void	validate_input_file(char *file, t_game *game)
{
	int fd;

	if (!file || ft_strlen(file) <= 0)
		exit_failure("no .cub file found", game);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_failure("unable to open .cub file", game);
	parse_file(fd, game);
	close(fd);
}

void validate_game(t_game *game, char **av)
{
    validate_input_file(av[1], game);
	is_valid_map(game);
    // get_whole_file(game, av[1]);
	// file_data(game, game->data.file_data);
	// is_valid_map(game);//TODO: needs more checks
}