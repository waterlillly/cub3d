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
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include <X11/ap_keysym.h>
# include "minilibx-linux/mlx_int.h"//for mlx@home
# include "minilibx-linux/mlx.h"//for mlx@home
//# include <mlx.h>//for mlx@school
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

# define WIN_HEIGHT	800
# define WIN_WIDTH	800
# define TILE_SIZE	80
# define MAP_HEIGHT	10 //
# define MAP_WIDTH	10 //

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
	int	p_x;
    int	p_y;
    int	dir_x;
    int	dir_y;
    int	move_speed;
}			t_player;

typedef struct s_image
{
	void	*img_ptr;
	char	*pxl_ptr;
	int		bpp;
	int		endian;
	int		len;
}				t_image;

typedef struct s_cub
{
	void		*mlx_con;
	void		*mlx_win;
	void		*bg_img;
	char		*bg_file;
	int			bg_height;
	int			bg_width;
	t_image		img;
	t_player	player;
}			t_cub;

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
	t_player	player;
	t_cub		cub;
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
void		destroy_mlx(t_cub *cub);
void		exit_failure(char *s, t_game *game);
int			exit_success(t_game *game);

/*player.c*/
void		init_player(t_game *game);
bool		is_wall(t_game *game, int x, int y);
bool		move_player(t_game *game, int new_x, int new_y);

/*init_cub.c*/
// void		load_background(t_game *game);
void		init_mlx(t_game *game);
void		init_map(t_game *game);
void		init_cub(t_game *game);

/*mlx_events.c*/
int			handle_keypress(int keycode, t_game *game);
void		center_mouse(t_cub *cub);
int			handle_mouse_move(int x, int y, t_game *game);
int			mlx_handler(t_game *game);

/*pixel.c*/
void		put_my_pixel(t_game *game, int x, int y, int color);
void		render_map(t_game *game);
void		render_player(t_game *game);
int			render(t_game *game);

/*movement.c*/
void		move_forward(t_game *game);
void		move_backward(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);

#endif