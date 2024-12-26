#include "../cub3d.h"

void read_file(t_game *game, char *av, char **map_temp){
    char	*line_temp;
	int		fd;

    printf("\nREADING MAP FILE\n");
    fd = open(av, O_RDONLY);
	if (fd == -1)
        ft_error_msg_free_exit(MALLOC_FAILED, game);
	*map_temp = ft_strdup(""); //mem alloc
	if (*map_temp == NULL)
        ft_error_msg_free_exit(MALLOC_FAILED, game);
	game->num_of_rows = 0;
	while (1)
	{
		line_temp = get_next_line(fd);
		if (line_temp == NULL)
			break ;
		*map_temp = ft_strappend(map_temp, line_temp);
		if (*map_temp == NULL)
            ft_error_msg_free_exit(MALLOC_FAILED, game);
		game->num_of_rows++;
	}
    printf("\nCLOSING FILE\n\n");
	close(fd);
}