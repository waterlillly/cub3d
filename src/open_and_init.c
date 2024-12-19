#include "../cub3d.h"

void	check_input_file(char *file, t_pars *pars)
{
	int fd;

	if (!file || ft_strlen(file) <= 0)
		err("Error: no .cub file found", pars);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		err("Error: unable to open .cub file", pars);
	check_file(fd, pars);
	close(fd);
	modify_map(pars);
	if (!valid_map(pars))
		err("Error: Invalid map", pars);
}

void	init_struct(t_pars *pars)
{
	pars->colors = ft_calloc(3, sizeof(char *));
	if (!pars->colors)
		err("Error: calloc failed", pars);
	pars->textures = ft_calloc(5, sizeof(char *));
	if (!pars->textures)
		err("Error: calloc failed", pars);
	pars->map = ft_calloc(2, sizeof(char *));
	if (!pars->map)
		err("Error: calloc failed", pars);
	pars->map_len = 0;
	pars->map_line = NULL;
}
