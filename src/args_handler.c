#include "../cub3d.h"

void args_handler(int ac, char **av)
{
	int arg_len;

	arg_len = ft_strlen(av[1]);
	if (ac != 2){
		printf("Error\nInvalid number of arguments\n");
		exit(1);
	}
	else if (arg_len <= 4){
		printf("Error\nInvalid file extension OR no extension\n");
		exit(1);
	}
	else if (!ft_strnstr(&av[1][arg_len - 4], ".cub", 4)){
		printf("Error\nInvalid file extension\n");
		exit(1);
	}
}