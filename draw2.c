/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 16:55:43 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/07/13 16:56:17 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia2(t_env *e, int *i, double *tmp)
{
	while (e->f.z_r * e->f.z_r + e->f.z_i * e->f.z_i < 4 && *i < e->f.iter)
	{
		*tmp = e->f.z_r;
		e->f.z_r = e->f.z_r * e->f.z_r - e->f.z_i * e->f.z_i + e->f.c_r;
		e->f.z_i = 2 * e->f.z_i * *tmp + e->f.c_i;
		*i += 1;
	}
}

void	draw_mandel2(t_env *e, int *i, double *tmp)
{
	while (((e->f.z_r * e->f.z_r) + (e->f.z_i * e->f.z_i) < 4) &&
			*i < e->f.iter)
	{
		*tmp = e->f.z_r;
		e->f.z_r = e->f.z_r * e->f.z_r - e->f.z_i * e->f.z_i + e->f.c_r;
		e->f.z_i = 2 * e->f.z_i * *tmp + e->f.c_i;
		*i += 1;
	}
}

void	draw_burn2(t_env *e, int *i, double *tmp)
{
	while (((e->f.z_r * e->f.z_r) + (e->f.z_i * e->f.z_i) < 4) &&
			*i < e->f.iter)
	{
		*tmp = e->f.z_r;
		e->f.z_r = e->f.z_r * e->f.z_r - e->f.z_i * e->f.z_i + e->f.c_r;
		e->f.z_i = 2 * fabs(e->f.z_i) * fabs(*tmp) + e->f.c_i;
		*i += 1;
	}
}
