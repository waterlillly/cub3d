#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//************* INCLUDES *************

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include "lib/libft.h"

//************** MACROS **************

# define NORTH_PLAYER			'N'
# define SOUTH_PLAYER			'S'
# define EAST_PLAYER			'E'
# define WEST_PLAYER			'W'

# define NORTH_TEXTURE			'NO'
# define SOUTH_TEXTURE			'SO'
# define WEST_TEXTURE			'WE'
# define EAST_TEXTURE			'EA'

# define FLOOR					'F'
# define CEILING				'C'

//** ERROR MESSAGES **

# define ERROR "Error"
# define MALLOC_FAILED "Malloc failed"
# define MAP_FILE_NOT_FOUND "Map file not found"
# define INVALID_EXTENSION_CUB "Invalid extension OR no extension. Please provide a .cub file"
# define INVALID_EXTENSION_XPM "Invalid extension OR no extension. Please provide a .xpm file"
# define ERROR_PLAYER "More or less than one player on the map"
# define ERROR_INVALID_CHAR "Invalid character in the map"
# define ERROR_MAP "Invalid map"
# define ERROR_TEXTURE "Invalid texture"
# define ERROR_COLOR "Invalid color"
# define ERROR_FILE "Invalid file"
# define ERROR_ARGS "Invalid arguments OR Invalid number of arguments"
# define ERROR_MAP_LAST "Map is not the last in the file"
# define ERROR_MAP_NOT_SURROUNDED "Map is not surrounded by walls"
# define ERROR_MAP_EMPTY_LINE "Empty line in the map"
# define ERROR_PLAYER_ORIENTATION "Invalid player orientation"


//************** STRUCTS **************
typedef struct s_game
{
	char	**map;
	char	**file_data;
	int		map_alloc;
	int		num_of_rows;
	int		num_of_columns;
	int		num_of_player;
	int		num_of_orientations;

	int 	exit_status;
}			t_game;

//************** PROTOTYPES ************

void args_handler(int ac, char **av, t_game *game);
void mapValidator(t_game *game, char *av);
char	*ft_strappend(char **s1, const char *s2);
void read_file(t_game *game, char *av, char **map_temp);
void initialization_of_vars(t_game *game);
char	**msimic_split(char const *s, char c);
void	ft_error_msg_free_exit(char *msg, t_game *game);
void get_map(t_game *game, char *av);

///*UTILS*/
//int		err(char *s, t_pars *pars);
//bool	rest_space(char *s, int start);
//bool	check_spaces(char *line);
//bool	only_digits(char *s);
//
///*CHECK MAP*/
//bool	check_top_bot(char *s, t_pars *pars);
//bool	check_bot(t_pars *pars);
//bool	check_top(t_pars *pars);
//bool	check_sides(char *s, int *player, t_pars *pars, int x);
//bool	valid_symbol(int i, int *player, t_pars *pars, int x);
//
///*MAP*/
//bool	valid_map(t_pars *pars);
//bool	add_to_map(char *line, t_pars *pars);
//int		find_max_len(t_pars *pars);
//void	modify_map(t_pars *pars);
//
///*TEXTURE COLOR*/
//bool	is_texture(char *line);
////bool	check_path(char *trim);
//bool	is_color(char *trim);
//bool	check_rgb(char *trim);
//bool	check_color_element(char **split, int *col_count, t_pars *pars);
//bool	check_texture_element(char **split, int *tex_count, t_pars *pars);
//
///*CHECK FILE LINE*/
//char	**modify_line(char *line, t_pars *pars);
//bool	is_empty(char *s);
//bool	check_line(char *line, t_pars *pars);
//void	check_file(int fd, t_pars *pars);
//
///*OPEN AND INIT*/
//void	check_input_file(char *file, t_pars *pars);
//void	init_struct(t_pars *pars);

#endif