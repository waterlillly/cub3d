#include "../cub3d.h"

// void args_handler(int ac, char **av)
// {
// 	int arg_len;

// 	arg_len = ft_strlen(av[1]);
// 	if (ac != 2)
// 		err("Error\nInvalid number of arguments\n", NULL);
// 	else if (arg_len <= 4)
// 		err("Error\nInvalid file name\n", NULL);
// 	else if (!ft_strnstr(&av[1][arg_len - 4], ".cub", 4))
// 		err("Error\nInvalid file extension\n", NULL);
// }

int	main(void)//(int ac, char **av)
{
	t_game		game;

	/******MO******/
	//args_handler(ac, av);

	/******LI******/
	ft_bzero(&game, sizeof(t_game));
	init_player(&game);
	init_cub(&game);
	//puts("DONE");
	//render(&game);
	//cast_rays(&game);
	mlx_loop(game.cub->mlx_con);
	//err(NULL, &pars);
	return (0);
}
