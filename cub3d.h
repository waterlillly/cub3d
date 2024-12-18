#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include "cub3D/lib/libft.h"

typedef struct s_pars
{
	char	**textures;
	char	**colors;
	char	**map;
	char	*map_line;
	char	player;
	int		map_len;
}			t_pars;

/*UTILS*/
int		err(char *s, t_pars *pars);
bool	rest_space(char *s, int start);
bool	check_spaces(char *line);
bool	only_digits(char *s);

/*CHECK MAP*/
bool	check_top_bot(char *s, t_pars *pars);
bool	check_bot(t_pars *pars);
bool	check_top(t_pars *pars);
bool	check_sides(char *s, int *player, t_pars *pars, int x);
bool	valid_symbol(int i, int *player, t_pars *pars, int x);

/*MAP*/
bool	valid_map(t_pars *pars);
bool	add_to_map(char *line, t_pars *pars);
int		find_max_len(t_pars *pars);
void	modify_map(t_pars *pars);

/*TEXTURE COLOR*/
bool	is_texture(char *line);
//bool	check_path(char *trim);
bool	is_color(char *trim);
bool	check_rgb(char *trim);
bool	check_color_element(char **split, int *col_count, t_pars *pars);
bool	check_texture_element(char **split, int *tex_count, t_pars *pars);

/*CHECK FILE LINE*/
char	**modify_line(char *line, t_pars *pars);
bool	is_empty(char *s);
bool	check_line(char *line, t_pars *pars);
void	check_file(int fd, t_pars *pars);

/*OPEN AND INIT*/
void	check_input_file(char *file, t_pars *pars);
void	init_struct(t_pars *pars);

#endif