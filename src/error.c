#include "../cub3d.h"


static void	ft_free_game(char *msg, t_game *game)
{
	printf("ft_free_game\n");
	int	str;

	if (game->map_alloc == 1)
	{
		str = 0;
		while (str < game->num_of_columns)
			free(game->map[str++]);
		free(game->map);
	}
	free(game);
	if (msg)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd(msg, 2);
	}
}

void	ft_error_msg_free_exit(char *msg, t_game *game)
{
	printf("ft_error_msg_free_exit\n");
	ft_free_game(msg, game);
	exit(1);
}