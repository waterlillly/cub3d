#include "../cub3d.h"

void get_map(t_game *game, char *av)
{
	char	*file_temp;

	read_file(game, av, &file_temp);
	if (file_temp == NULL)
		ft_error_msg_free_exit(MALLOC_FAILED, game);
	game->file_data = NULL; // should be NULL????
	game->file_data = msimic_split(file_temp, '\n');
	if (game->file_data == NULL){
		free(file_temp);
        ft_error_msg_free_exit(MALLOC_FAILED, game);
	}
	game->map_alloc = 1;
	free(file_temp);
}