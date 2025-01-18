#include "../cub3d.h"

void read_file(t_game *game, char *av, char **map_temp){
    printf("read_file\n");
	char	*line_temp;
	int		fd;

    fd = open(av, O_RDONLY);
	if (fd == -1)
        free_all(game, MAP_FILE_NOT_FOUND);
	*map_temp = ft_strdup(""); //mem alloc
	if (*map_temp == NULL)
        free_all(game, MALLOC_FAILED);
	game->num_of_rows = 0;
	while (1)
	{
		line_temp = get_next_line(fd);
		if (line_temp == NULL)
			break ;
		*map_temp = ft_strappend(map_temp, line_temp);
		free(line_temp);//added this
		if (*map_temp == NULL)
            free_all(game, MALLOC_FAILED);
		game->num_of_rows++;
	}
    ft_putstr_fd("\nCLOSING FILE\n\n", 1);
	close(fd);
}