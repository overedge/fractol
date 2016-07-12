#ifndef HEADER_H
# define HEADER_H

#include "libft/includes/libft.h"
#include "mlx/mlx.h"
#include <stdlib.h>
#include <math.h>
# define W_WIDTH 500
# define W_HEIGHT 500
# define ECS 53
# define ENTER 36
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define DEZOOM 37 //78
# define ZOOM 31   //69
# define COLOR 8
# define ITER 34
# define DEITER 40
# define LOCK 7
# define RINI 15
# define MZOOM 5
# define MDEZOOM 4

typedef struct s_fractol
{
	double		x1;
	double		y1;
	double		zoom;
	int			iter;
	double		image_x;
	double		image_y;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	int			color;
}				t_fractol;

typedef struct s_img
{
	char	*data;
	int		bpp;
	int		size_line;
	int		edian;
	void	*ptr;
}				t_img;

typedef struct s_env
{
	char	choose;
	void	*mlx;
	void	*win;
	char	lock;
	t_img	img;
	t_fractol f;
}				t_env;


void	init(t_env *env);
int		input_key(int keycode, void *env);
int		input_mouse(int button, int x, int y, void *env);
int		mouse_motion_hook(int x, int y, void *env);
void	draw(t_env *e);
int		input_expose(void *env);
int		input_key2(int keycode, void *env, t_env *tmp);
int		input_key3(int keycode, void *env, t_env *tmp);
void	draw_julia2(t_env *e, int *i, double *tmp);
void	draw_mandel2(t_env *e, int *i, double *tmp);
void	draw_burn2(t_env *e, int *i, double *tmp);
#endif
