/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 16:58:03 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/07/13 16:58:13 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_fract(t_env *e)
{
	e->f.zoom = 100;
	e->f.x1 = -1;
	e->f.y1 = -1.2;
	e->f.color = 0x0000FF;
	e->f.iter = 150;
	if (e->choose == 1)
	{
		e->f.c_r = 0.285;
		e->f.c_i = 0.01;
		e->lock = 1;
	}
	if (e->choose == 2)
	{
		e->f.iter = 50;
		e->lock = 1;
		e->f.z_r = 0;
		e->f.z_i = 0;
	}
}

void		init(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, W_WIDTH, W_HEIGHT, "fractol");
	init_fract(env);
	draw(env);
	mlx_expose_hook(env->win, input_expose, env);
	mlx_key_hook(env->win, input_key, env);
	mlx_mouse_hook(env->win, input_mouse, env);
	mlx_hook(env->win, 6, 1L << 6, mouse_motion_hook, env);
	mlx_loop(env->mlx);
}
