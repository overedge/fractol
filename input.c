#include "fractol.h"

int		input_expose(void *env)
{
	t_env	*tmp;
	void	*img_clean;

	tmp = env;
	img_clean = mlx_new_image(tmp->mlx, W_WIDTH, W_HEIGHT);
	mlx_put_image_to_window(tmp->mlx, tmp->win, img_clean, 0, 0);
	draw(env);
	return (0);
}

int		input_key(int keycode, void *env)
{
	t_env	*tmp;

	tmp = env;
	if (keycode == ECS)
		exit(EXIT_FAILURE);
	else if (keycode == ENTER)
	{
		tmp->choose == 3 ? tmp->choose = 1 : tmp->choose++;
		if (tmp->choose == 1)
		{
			tmp->f.c_r = 0.285;
			tmp->f.c_i = 0.01;
		}
		else if (tmp->choose == 2)
		{
			tmp->f.z_r = 0;
			tmp->f.z_i = 0;
		}
	}
	else if (keycode == UP)
		tmp->f.y1 += (0.9999999 / tmp->f.zoom) * 20;
	else if (keycode == DOWN)
		tmp->f.y1 -= (0.9999999 / tmp->f.zoom) * 20;
	return (input_key2(keycode, env, tmp));
}

int		input_mouse(int button, int x, int y, void *env)
{
	t_env	*tmp;
	void	*img_clean;

	env = (t_env*)env;
	x += 10;
	y += 10;
	tmp = env;
	if (button == MDEZOOM  && tmp->f.zoom > 50)
		tmp->f.zoom -= 50;
	else if (button == MZOOM)
		tmp->f.zoom += 50;
	img_clean = mlx_new_image(tmp->mlx, W_WIDTH, W_HEIGHT);
	mlx_put_image_to_window(tmp->mlx, tmp->win, img_clean, 0, 0);
	draw(env);
	return (0);
}

int		mouse_motion_hook(int x, int y, void *env)
{
	t_env	*tmp = env;
	void	*img_clean;

	if (tmp->choose == 1 && tmp->lock == 1 && x <= W_WIDTH && x >= 0
	&& y <= W_HEIGHT && y >= 0)
	{
		tmp->f.c_r = 0.285;
		tmp->f.c_i = 0.01;
		tmp->f.c_r = (x - 250) * 0.002;
		tmp->f.c_i = (y - 250) * 0.002;
		img_clean = mlx_new_image(tmp->mlx, W_WIDTH, W_HEIGHT);
		mlx_put_image_to_window(tmp->mlx, tmp->win, img_clean, 0, 0);
		draw(env);
	}
	return (0);
}
