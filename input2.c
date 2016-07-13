/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 16:50:27 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/07/13 17:05:33 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		input_key2(int keycode, void *env, t_env *tmp)
{
	if (keycode == LEFT)
		tmp->f.x1 += (0.999999 / tmp->f.zoom) * 20;
	else if (keycode == RIGHT)
		tmp->f.x1 -= (0.999999 / tmp->f.zoom) * 20;
	else if (keycode == DEZOOM && tmp->f.zoom > 50)
		tmp->f.zoom -= 50;
	else if (keycode == ZOOM)
		tmp->f.zoom += 50;
	else if (keycode == ITER)
		tmp->f.iter += 20;
	else if (keycode == DEITER && tmp->f.iter > 20)
		tmp->f.iter -= 20;
	else if (keycode == COLOR)
	{
		if (tmp->f.color == 0x0000FF)
			tmp->f.color = 0x00FF00;
		else if (tmp->f.color == 0x00FF00)
			tmp->f.color = 0xFF0000;
		else
			tmp->f.color = 0x0000FF;
	}
	return (input_key3(keycode, env, tmp));
}

int		input_key3(int keycode, void *env, t_env *tmp)
{
	void	*img_clean;

	if (keycode == LOCK)
		tmp->lock = tmp->lock == 1 ? 0 : 1;
	else if (keycode == RINI)
	{
		tmp->lock = 0;
		tmp->f.zoom = 100;
		if (tmp->choose == 1)
		{
			tmp->f.c_r = 0.285;
			tmp->f.c_i = 0.01;
			tmp->f.iter = 100;
		}
		else if (tmp->choose == 2 || tmp->choose == 3)
			tmp->f.iter = 50;
	}
	img_clean = mlx_new_image(tmp->mlx, W_WIDTH, W_HEIGHT);
	mlx_put_image_to_window(tmp->mlx, tmp->win, img_clean, 0, 0);
	draw(env);
	return (0);
}
