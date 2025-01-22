#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//*************************************
//************* INCLUDES **************
//*************************************

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include "lib/libft.h"

//*************************************
//************** ENUMS ****************
//*************************************

enum output
{
	SUCC = 0,
	FAIL = 1,
	ERR = 2,
	BREAK = 3,
	CONT = 4
};

//*************************************
//************** DEFINES **************
//*************************************

# define NORTH_PLAYER			0 //N
# define SOUTH_PLAYER			1 //S
# define EAST_PLAYER			2 //E
# define WEST_PLAYER			3 //W

# define NORTH_TEXTURE			'NO'
# define SOUTH_TEXTURE			'SO'
# define WEST_TEXTURE			'WE'
# define EAST_TEXTURE			'EA'

# define WALL					'1'
# define FLOOR					'0'

# define WINDOW_WIDTH			640
# define WINDOW_HEIGHT			480

#define SPACE ' '
#define TAB '\t'
#define NEWLINE '\n'
#define CARRET_RETURN '\r'
#define VERTICAL_TAB '\v'
#define FORM_FEED '\f'

//*************************************
//************** ERROR MSG ************
//*************************************

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

//*************************************
//************** STRUCTS **************
//*************************************

typedef struct s_TheMap
{
	char	**map;
	bool   	map_mem_alloc;
	int		num_of_rows;
	int		max_column;
	int		last_row;
}		t_TheMap;


typedef struct s_texture
{
	char	*north;
	bool   	north_mem_alloc;
	char	*south;
	bool   	south_mem_alloc;
	char	*west;
	bool   	west_mem_alloc;
	char	*east;
	bool   	east_mem_alloc;
	int		*floor_color;
	bool   	floor_mem_alloc;
	int		*ceiling_color;
	bool   	ceiling_mem_alloc;
}		t_texture;

typedef struct s_player
{
	int		row;
	int		column;
	char	orientation;
}		t_player;

typedef struct s_game
{
	char	**file;
	bool	file_mem_alloc;
	char	*path;
	int		fd;
	int		line_count;
	int		num_of_rows;
	int		num_of_columns;
	int		num_of_player;
	int		num_of_orientations;

	int		win_width;
	int		win_height;

	int		**texture_px;
	int		**texture;

	char	p_direction;

	//structs
	t_texture	Itex;
	t_TheMap	TheMapInfo;
	t_player	player;

	int 	exit_status;
}		t_game;

//**************************************
//************** PROTOTYPES ************
//**************************************

//************** PARS **************
int 	add_color(t_texture *Itex, char *line, int column);
int		add_texture(t_texture *Itex, char *line, int column);
void	args_handler(int ac, char **av, t_game *game);
void	validator(t_game *game, char **av);
void	read_file(t_game *game, char *av, char **map_temp);
void	ft_error_msg_free_exit(char *msg, t_game *game);
void	get_whole_file(t_game *game, char *path);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		file_data(t_game *game, char **file_data);
void	free_array(void **array);
int		map_crating(t_game *game, char **file, int row);
void 	valid_map(t_game *game);
void 	check_elements(t_game *game);

//************** UTILS **************
int 	ascii_print(char c);
void 	free_all(t_game *game, char *errMSG);
void	initialization_of_vars(t_game *game);
char	**m_split(char const *s, char c);
char	*ft_strappend(char **s1, const char *s2);

#endif