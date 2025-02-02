#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

//************* INCLUDES *************

# include <X11/X.h>
# include <X11/ap_keysym.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
// # include "minilibx-linux/mlx_int.h"//for mlx@home
// # include "minilibx-linux/mlx.h"//for mlx@home
# include "../lib/libft.h"
# include <errno.h>
# include <error.h>
# include <mlx.h> //for mlx@school
# include <sys/time.h>

//************** ERROR MSG ***********

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

//************** MACROS **************

# define NORTH_PLAYER 0 // N
# define SOUTH_PLAYER 1 // S
# define EAST_PLAYER 2  // E
# define WEST_PLAYER 3  // W

# define NORTH_TEXTURE 'NO'
# define SOUTH_TEXTURE 'SO'
# define WEST_TEXTURE 'WE'
# define EAST_TEXTURE 'EA'

# define WALL '1'
# define FLOOR '0'

# define SPACE ' '
# define TAB '\t'
# define NEWLINE '\n'
# define CARRET_RETURN '\r'
# define VERTICAL_TAB '\v'
# define FORM_FEED '\f'

# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000
# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define BLUE 0x000000FF
# define GREEN 0x0000FF00

//************** STRUCTS **************

enum				output
{
	SUCC = 0,
	FAIL = 1,
	ERR = 2,
	BREAK = 3,
	CONT = 4
};

typedef struct s_dvec
{
	double			x;
	double			y;
}					t_dvec;

typedef struct s_ivec
{
	int				x;
	int				y;
}					t_ivec;

enum				e_num_txts
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3,
	DOOR = 4
};

typedef struct s_map
{
	bool			map_mem_alloc;
	int				num_of_rows;
	int				max_column;
	int				last_row;

}					t_map;

typedef struct s_player
{
	t_dvec			pos;
	t_dvec			dir;
	double			move_speed;
	double			turn_speed;
}					t_player;

typedef struct s_image
{
	char			*name;
	void			*img;
	char			*addr;
	int				bpp;
	int				len;
	int				endian;
	int				width;
	int				height;
}					t_image;

typedef struct s_cub
{
	void			*mlx_con;
	void			*mlx_win;
	t_image			img;
	unsigned int	buffer[WIN_HEIGHT][WIN_WIDTH];
}					t_cub;

typedef struct s_ray
{
	t_image			texture;
	t_dvec			dir;
	t_dvec			deltadist;
	t_dvec			sidedist;
	t_ivec			map;
	t_ivec			step;
	t_ivec			tex;
	unsigned int	color;
	double			tex_pos;
	double			correct_dist;
	double			wall_x;
	double			s;
	int				wall_height;
	int				wall_width;
	int				bot;
	int				top;
	int				side;
}					t_ray;

typedef struct s_data
{
	char			**file_data;
	char			*data;
	t_map 			map_info;
	char 			**map;
	int				fd;   
	int 			map_width;
	int 			map_height;
	int				win_height;
	int				win_width;
	int				**texture_px;
	int				**texture;
	char			*path;
	int				line_count;
	int				last_row;
	int				num_of_rows;
	int				num_of_columns;
	size_t			max_column;
	int				num_of_player;
	int				num_of_orientations;
	int				p_orientation;
	int				floor_color[3];
	bool			floor_color_set;
	int				ceiling_color[3];
	bool			ceiling_color_set;
}					t_data;

typedef struct s_control
{
	bool			forward;
	bool			backward;
	bool			left;
	bool			right;
	bool			turn_left;
	bool			turn_right;
	bool			sprint;
	double			forward_velo;
	double			backward_velo;
	double			left_velo;
	double			right_velo;
	double			turn_left_velo;
	double			turn_right_velo;
}					t_control;

typedef struct s_doors
{
	bool			open;
	t_ivec			pos;
	int				open_time;
}					t_doors;

typedef struct s_macros
{
	double			tile_width;
	double			tile_height;
	double			minimap_width;
	double			minimap_height;
	double			mini_tile_size;
	double			mini_tile_width;
	double			mini_tile_height;
	double			fov;
}					t_macros;

typedef struct s_game
{
	t_data			data;
	t_image 		textures[5];
	t_control		control;
	t_cub			cub;
	t_player		player;
	t_ray			ray;
	t_dvec			plane;
	t_doors			*doors;
	t_macros		macro;
	int				c_color;
	int				f_color;
	int				num_doors;
}					t_game;

/* ************ PROTOTYPES ************ */

/* maps.c */
void				init_map_with_doors(t_game *game);
void				init_map_hallway(t_game *game);
void				init_map_tiny(t_game *game);

// ************** PARS **************
void				args_handler(int ac, char **av, t_game *game);
void				validate_game(t_game *game, char **av);
void				is_valid_map(t_game *game);
void				max_line_len(t_game *game);
void				validate_input_file(char *file, t_game *game);
void				parse_file(int fd, t_game *game);
void				validate_border(t_game *game);

// ************** UTILS **************
void				initialization_of_vars(t_game *game);
bool				only_digits(char *s);
bool				is_line_empty(char *s);
char				**split_line_into_words(char *line);
bool				is_texture_identifier(char *line);
bool				is_color_identifier(char *trim);
int 				ft_strlen_skip_space(char *str);
void				get_player_orientation(char orientation, t_game *game);
bool				append_line_to_map(char *line, t_game *game);
bool				validate_and_set_rgb(char *split, t_game *game, int fc);
bool				validate_color_element(char **split, int *col_count, t_game *game);
bool				validate_texture_element(char **split, int *tex_count, t_game *game);
bool 				is_rgb_valid_format(char *str);
bool				split_map_into_grid(t_game *game);

/* exit.c */
void 				free_all(t_game *game);
void				exit_failure(char *s, t_game *game);
int					exit_success(t_game *game);

/* init.c */
void				init_cub(t_game *game);

/* BONUS: doors.c */
int					is_door(t_game *game, int x, int y);
bool				is_open(t_game *game, int nbr);
void				toggle_door(t_game *game, int x, int y);
void				parse_doors(t_game *game);

/* mlx_events.c */
void				init_macros(t_game *game);
int					mlx_handler(t_game *game);

/* mlx_handle_input.c */
int					handle_keyrelease(int keycode, t_game *game);
int					keypress(t_game *game);
int					handle_keypress(int keycode, t_game *game);

/* movement.c */
void				move_forward(t_game *game);
void				move_backward(t_game *game);
void				move_left(t_game *game);
void				move_right(t_game *game);
void				sprint(t_game *game);

/* rotation.c */
void				rotate_plane(t_game *game, double angle);
void				rotate_dir(t_game *game, double angle);
void				turn_left(t_game *game);
void				turn_right(t_game *game);

/* pixels.c */
void				put_my_pixel(t_game *game, int x, int y, int color);
void				buffer_to_image(t_game *game);

/* raycasting.c */
void				raycasting(t_game *game);

/* raycasting2.c */
void				floor_ceiling(t_game *game, int x);
void				calc_side_dist(t_game *game);
void				get_direction(t_game *game);

/* checking.c */
void				get_colors(t_game *game);
void				check_texture(t_game *game, int i);
bool				is_wall(t_game *game, double new_x, double new_y);
void				check_doors(t_game *game);//BONUS

/* utils.c */
int					get_time(t_game *game);//BONUS
t_dvec				norm(t_dvec vec);
bool				crashed(t_game *game, double x1, double y1);

/* minimap.c */
void				render_minimap(t_game *game);//BONUS

#endif
