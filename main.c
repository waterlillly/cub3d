#include "cub3d.h"

int	main(int ac, char **av)
{
	t_pars	pars;
	int		i;

	ft_bzero(&pars, sizeof(t_pars *));
	init_struct(&pars);
	if (ac == 2 && av[1])
	{
		check_input_file(av[1], &pars);
		if (pars.colors)
			ft_print_array_fd(pars.colors, 1);
		ft_putendl_fd("", 1);
		if (pars.textures)
			ft_print_array_fd(pars.textures, 1);
		ft_putendl_fd("", 1);
		if (pars.map)
		{
			i = -1;
			while (pars.map[++i])
				printf("|%s|\n", pars.map[i]);
		}
	}
	err(NULL, &pars);
	return (0);
}
