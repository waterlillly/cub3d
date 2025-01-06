#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#  ifndef M_PI
#   define M_PI 3.14159265358979323846
#  endif

//************* INCLUDES *************

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include <X11/ap_keysym.h>
// # include "minilibx-linux/mlx_int.h"//for mlx@home
// # include "minilibx-linux/mlx.h"//for mlx@home
# include <mlx.h>//for mlx@school
# include <errno.h>
# include <error.h>
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

# define WIN_HEIGHT				640
# define WIN_WIDTH				640
# define TILE_SIZE				64
# define MINIMAP_SIZE			TILE_SIZE / 5
# define MAP_HEIGHT				10 //
# define MAP_WIDTH				10 //
# define FOV					90 * (M_PI / 180)

# define BLACK					0x000000
# define WHITE					0xFFFFFF
# define BLUE					0x0000FF
# define RED					0xFF0000
# define GUNMETAL				0x2C3539
# define DEEPSPACE				0x1B263B
# define CHARCOAL				0x36454F

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

typedef struct s_player
{
	double		p_x;
	double		p_y;
	double		fov;
	double		angle;
	double		move_speed;
	double		turn_speed;
}			t_player;

typedef struct s_image
{
	char		*name;
	void		*img;
	char		*addr;
	int			bpp;
	int			len;
	int			endian;
	int			width;
	int			height;
}				t_image;

typedef struct s_cub
{
	void		*mlx_con;
	void		*mlx_win;
	t_image		img;
	t_player	player;
}			t_cub;

typedef struct s_textures
{
	t_image		north;
	t_image		south;
	t_image		east;
	t_image		west;
}				t_textures;

typedef struct s_raycast
{
	t_image		texture;
	double		dist;
	double		correct_dist;
	int			start;
	int			end;
	int			wall_height;
	double		ray_angle;
	double		tex_pos;
	int			step[2];
	int			map[2];
	double		side_dist[2];
	double		delta_dist[2];
	int			side;
}				t_raycast;

typedef struct s_game
{
	char		**map;
	char		**file_data;
	int			map_alloc;
	int			num_of_rows;
	int			num_of_columns;
	int			num_of_player;
	int			num_of_orientations;
	int 		exit_status;
	t_textures	txt;
	t_cub		cub;
	t_raycast	rays;
}			t_game;

//************** PROTOTYPES ************

// void	args_handler(int ac, char **av, t_game *game);
// void	mapValidator(t_game *game, char *av);
// char	*ft_strappend(char **s1, const char *s2);
// void	read_file(t_game *game, char *av, char **map_temp);
// void	initialization_of_vars(t_game *game);
// char	**msimic_split(char const *s, char c);
// void	ft_error_msg_free_exit(char *msg, t_game *game);
// void	get_map(t_game *game, char *av);

/*exit.c*/
void		exit_failure(char *s, t_game *game);
int			exit_success(t_game *game);

/*init.c*/
void		init_cub(t_game *game);

/*mlx_events.c*/
void		put_my_pixel(t_game *game, int x, int y, int color);
int			mlx_handler(t_game *game);

/*movement.c*/
bool		is_wall(t_game *game, double new_x, double new_y);
bool		corner(t_game *game, double new_x, double new_y);
bool		crash(t_game *game, double new_x, double new_y);
void		move_forward(t_game *game);
void		move_backward(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);
void		turn_left(t_game *game);
void		turn_right(t_game *game);

/*raycasting.c*/
void		raycasting(t_game *game);

/*minimap.c*/
void		render_minimap(t_game *game);

#endif