#include "../cub3d.h"

void mapValidator(t_pars *pars, char *av)
{
    (void)pars;
    printf("path: %s\n", av);
    pars->map = malloc(sizeof(char *) * 10);
    pars->map[0] = ft_strdup("11111");
    pars->map[1] = ft_strdup("10001");
    printf("map: %s\n", pars->map[0]);
    printf("map: %s\n", pars->map[1]);

}

/*
void	read_map_file(t_game *game, char *av, char **map_temp)
{
	char	*line_temp;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error_msg_free_exit("Map file not found [init map]", game);
	*map_temp = ft_strdup("");
	if (*map_temp == NULL)
		ft_error_msg_free_exit("Malloc failed [init map]", game);
	game->map.count_rows = 0;
	while (1)
	{
		line_temp = get_next_line(fd);
		if (line_temp == NULL)
			break ;
		*map_temp = ft_strappend(map_temp, line_temp);
		if (*map_temp == NULL)
			ft_error_msg_free_exit("Malloc failed [init map]", game);
		game->map.count_rows++;
	}
	close(fd);
}

void	initialization_of_map(t_game *game, char *av)
{
	char	*map_temp;

	read_map_file(game, av, &map_temp);
	check_empty_line(map_temp, game);
	game->map.full = ft_split(map_temp, '\n');
	if (game->map.full == NULL)
		ft_error_msg_free_exit("Malloc failed [init map]", game);
	game->map_alloc = 1;
	free(map_temp);
}
*/