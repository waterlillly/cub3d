#include "../../cub3d.h"

bool	is_valid_map(t_game *game)
{
	int			i;
	// static int	player = 0;
	
	i = 0;
	while (game->data.map[i])
	{
		if (i == 0 || i == ft_arrlen(game->data.map) - 1)
		{
			// if (!check_top_bot(game->map[i], game))
			// 	return (false);
		}
		else
		{
			// if (!check_sides(game->map[i], &player, game, i))
			// 	return (false);
		}
		i++;
	}
	// if (!check_player(&player, game))
	// 	return (false);
	return (true);
}

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
	if (!is_valid_map(game))
		exit_failure("Invalid map", game);
}

void validate_game(t_game *game, char **av)
{
    validate_input_file(av[1], game);
    // get_whole_file(game, av[1]);
	// file_data(game, game->data.file_data);
	// is_valid_map(game);//TODO: needs more checks
}