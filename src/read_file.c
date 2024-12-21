#include "../cub3d.h"

void read_file(t_game *game, char *av, char **map_temp){
    char	*line_temp;
	int		fd;

    printf("\nREADING MAP FILE\n");
    fd = open(av, O_RDONLY);
	if (fd == -1){
		//ft_error_msg_free_exit("Map file not found [init map]", game);
        printf("Map file not found [init map]\n");
        free(game);
        exit(1);
    }
	*map_temp = ft_strdup("");
	if (*map_temp == NULL){
		//ft_error_msg_free_exit("Malloc failed [init map]", game);
        printf("Malloc failed [init map]\n");
        free(game);
        exit(1);
    }
	game->count_map_rows = 0;
    printf("Reading map file...\n");
	while (1)
	{
		line_temp = get_next_line(fd);
		if (line_temp == NULL)
			break ;
		*map_temp = ft_strappend(map_temp, line_temp);
		if (*map_temp == NULL){
			//ft_error_msg_free_exit("Malloc failed [init map]", game);
            printf("Malloc failed [init map]\n");
            free(game);
            exit(1);
        }
		game->count_map_rows++;
	}
    printf("\nCLOSING FILE\n");
	close(fd);
}