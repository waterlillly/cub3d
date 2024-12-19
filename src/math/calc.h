#ifndef CALC_H
# define CALC_H

# include <math.h>
# include "../../cub3d.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include <X11/ap_keysym.h>
# include <mlx.h>
# include <errno.h>
# include <error.h>

# define WIDTH 500
# define HEIGHT 500

typedef struct s_player
{
	char	dir;
	float	x;
	float	y;
	float	view;
}			t_player;

typedef struct s_map
{
	float	nl;
	float	nh;
	float	ol;
	float	oh;
}				t_map;

typedef struct s_complex
{
	float	x;
	float	y;
}				t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pxl_ptr;
	int		bpp;
	int		endian;
	int		len;
}				t_img;

typedef struct s_cub
{
	char		*name;
	void		*mlx_con;
	void		*mlx_win;
	t_img		img;
	float		esc_value;
	float		x_move;
	float		y_move;
	t_player	*player;
}			t_cub;

/*pixel.c*/
void		pixel(int x, int y, t_cub *cub);
int			render(t_cub *cub);

/*mlx_events.c*/
void		close_and_exit(t_cub *cub);
int			key_press(int key, t_cub *cub);
int			mouse_moves(int button, int x, int y, t_cub *cub);

/*complex_values.c*/
t_map		map_values(float nl, float nh, float ol, float oh);
float		scale(float i, t_map map);

/*player.c*/
void		init_player(t_player *player);
void		move_player(t_player *player, float xd, float yd);
void		cast_rays(t_player *player);

/*calc.c*/
void		error_exit(char *s, t_cub *cub);
int			exit_success(t_cub *cub);
void		init_data(t_cub *cub);
void		init_events(t_cub *cub);
void		init_cub(t_cub *cub);

#endif