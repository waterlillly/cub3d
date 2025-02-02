#ifndef CUB3D_H
# define CUB3D_H

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
# include "lib/libft.h"
# include <errno.h>
# include <error.h>
# include <mlx.h> //for mlx@school
# include <sys/time.h>

//************** ERROR MSG ***********

# define MAP_FILE_NOT_FOUND "Map file not found"
# define INVALID_EXTENSION_CUB "Invalid extension OR no extension. \
								Please provide a .cub file"
# define ERROR_ARGS "Invalid arguments OR Invalid number of arguments"

//************** MACROS **************

//TODO: change macro-function and add them to init
# define WIN_SIZE 640
# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define BLUE 0x000000FF
# define GREEN 0x0000FF00

//************** STRUCTS **************

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
	unsigned int	buffer[WIN_SIZE][WIN_SIZE];
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
	char			**map;
	int				fd;
	int				map_width;
	int				map_height;
	int				win_height;
	int				win_width;
	int				**texture; // not used??
	char			*path; // not used??
	int				num_of_rows;
	size_t			max_column;
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
	double			tile_size;
	double			minimap_size;
	double			mini_tile_width;
	double			mini_tile_height;
	double			fov;
}					t_macros;

typedef struct s_game
{
	t_data			data;
	t_image			textures[4];
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
int					ft_strlen_skip_space(char *str);
void				get_player_orientation(char orientation, t_game *game);
bool				append_line_to_map(char *line, t_game *game);
bool				validate_and_set_rgb(char *split, t_game *game, int fc);
bool				validate_color_element(char **split, int *col_count,
						t_game *game);
bool				validate_texture_element(char **split, int *tex_count,
						t_game *game);
bool				is_rgb_valid_format(char *str);
bool				split_map_into_grid(t_game *game);

// ************** MATH ****************
void				init_cub(t_game *game);
void				init_macros(t_game *game);
int					mlx_handler(t_game *game);
int					handle_keyrelease(int keycode, t_game *game);
int					keypress(t_game *game);
int					handle_keypress(int keycode, t_game *game);
void				move_forward(t_game *game);
void				move_backward(t_game *game);
void				move_left(t_game *game);
void				move_right(t_game *game);
void				rotate_plane(t_game *game, double angle);
void				rotate_dir(t_game *game, double angle);
void				turn_left(t_game *game);
void				turn_right(t_game *game);
void				put_my_pixel(t_game *game, int x, int y, int color);
void				buffer_to_image(t_game *game);
void				raycasting(t_game *game);
void				floor_ceiling(t_game *game, int x);
void				calc_side_dist(t_game *game);
void				get_direction(t_game *game);
void				get_colors(t_game *game);
void				check_texture(t_game *game, int i);
bool				is_wall(t_game *game, double new_x, double new_y);
t_dvec				norm(t_dvec vec);
bool				crashed(t_game *game, double x1, double y1);
void				exit_failure(char *s, t_game *game);
int					exit_success(t_game *game);

#endif
