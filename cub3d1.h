#ifndef CUB3D1_H
# define CUB3D1_H

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

# define WIN_HEIGHT				640
# define WIN_WIDTH				640
# define TILE_SIZE				64
# define MINIMAP_SIZE			floor(TILE_SIZE / 5)
# define MAP_SIZE				10
# define FOV					60 * (M_PI / 180)

# define BLACK					0x00000000
# define WHITE					0x00FFFFFF
# define RED					0x00FF0000
# define BLUE					0x000000FF
# define GREEN					0x0000FF00

//************** STRUCTS **************

typedef struct s_dvec
{
    double	x;
    double	y;
}			t_dvec;

typedef struct s_ivec
{
	int	x;
	int	y;
}		t_ivec;

enum e_num_txts
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

typedef struct s_player
{
	t_dvec		pos;
	t_dvec		dir;
	t_dvec		plane;
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
	void			*mlx_con;
	void			*mlx_win;
	t_image			img;
	unsigned int	buffer[WIN_WIDTH][WIN_HEIGHT];
}					t_cub;

typedef struct s_ray
{
	t_image			texture;
	double			camera;
    t_dvec			dir;
    t_dvec			pos;
    t_dvec			deltadist;
    t_dvec			sidedist;
    t_ivec			step;
	t_ivec			tex;
    double			correct_dist;
    unsigned int	color;
    int				wall_height;
    int				bot;
    int				top;
	double			wall_x;
    int				side;
}					t_ray;

typedef struct s_data
{
	char		**file_data;
	int			map_alloc;
	int			num_of_rows;
	int			num_of_columns;
	int			num_of_player;
	int			num_of_orientations;
	int			p_orientation;
}				t_data;

typedef struct s_game
{
	char		**map;
	t_data		data;
	t_image		textures[4];
	t_cub		cub;
	t_player	player;
	t_ray		ray;
	int 		exit_status;
}			t_game;

/* ************ PROTOTYPES ************ */

/* exit1.c */
void	destroy_mlx(t_game *game);
void	free_data(t_game *game);
void	exit_failure(char *s, t_game *game);
int		exit_success(t_game *game);

/* init1.c */
void	init_map(t_game *game);
void	check_texture(t_game *game, int i);
void	load_textures(t_game *game);
void	init_textures(t_game *game);
void	init_mlx(t_game *game);
void	get_orientation(t_game *game);
void	init_player(t_game *game);
void	init_cub(t_game *game);

/* mlx_events1.c */
int		handle_keypress(int keycode, t_game *game);
void	clear_frame(t_game *game);
int		render(t_game *game);
int		mlx_handler(t_game *game);

/* movement1.c */
bool	is_wall(t_game *game, double new_x, double new_y);
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	turn_left(t_game *game);
void	turn_right(t_game *game);

/* raycasting1.c */
// void	draw_vertical_line(t_game *game, int x, t_ray *ray);
void	put_my_pixel(t_game *game, int x, int y, int color);
void	buffer_to_image(t_game *game);
void	calc_side_dist(t_ray *ray);
void	get_direction(t_ray *ray, t_game *game);
void	calc_side(t_game *game, t_ray *ray);
void	calc_wall(t_ray *ray);
void	cast_ray(t_game *game, t_ray *ray, int x);
void	raycasting(t_game *game);

/* utils1.c */
t_dvec	normalize(t_dvec vec);
double	vector_to_angle(t_dvec vec);
t_dvec	angle_to_vector(double angle);
bool	crashed(t_game *game, double x1, double y1);

// /* minimap1.c */
void	render_mini_player(t_game *game);
void	render_minimap(t_game *game);

#endif