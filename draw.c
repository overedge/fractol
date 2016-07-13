/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 16:48:39 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/07/13 16:50:04 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_put_pixel_image(t_env *e, int x, int y, int color)
{
	char	*y_pos;

	y_pos = e->img.data + (e->img.size_line * (y));
	y_pos += ((e->img.bpp / 8) * (x));
	*y_pos = color;
	y_pos += 1;
	*y_pos = (color >> 8);
	y_pos += 1;
	*y_pos = (color >> 16);
}

void	draw_burn(t_env *e)
{
	int			x;
	int			y;
	int			i;
	double		tmp;

	x = 0;
	while (x < W_WIDTH)
	{
		y = 0;
		while (y < W_HEIGHT)
		{
			e->f.c_r = x / e->f.zoom + e->f.x1;
			e->f.c_i = y / e->f.zoom + e->f.y1;
			e->f.z_r = 0;
			e->f.z_i = 0;
			i = 0;
			draw_burn2(e, &i, &tmp);
			if (i == e->f.iter)
				mlx_put_pixel_image(e, x, y, e->f.color);
			else
				mlx_put_pixel_image(e, x, y, (e->f.color * i) / e->f.iter);
			y++;
		}
		x++;
	}
}

void	draw_julia(t_env *e)
{
	int			x;
	int			y;
	int			i;
	double		tmp;

	x = 0;
	while (x < W_WIDTH)
	{
		y = 0;
		while (y < W_HEIGHT)
		{
			e->f.z_r = x / e->f.zoom + e->f.x1;
			e->f.z_i = y / e->f.zoom + e->f.y1;
			i = 0;
			draw_julia2(e, &i, &tmp);
			if (i == e->f.iter)
				mlx_put_pixel_image(e, x, y, e->f.color);
			else
				mlx_put_pixel_image(e, x, y, (e->f.color * i) / e->f.iter);
			y++;
		}
		x++;
	}
}

void	draw_mandel(t_env *e)
{
	int			x;
	int			y;
	int			i;
	double		tmp;

	x = 0;
	while (x < W_WIDTH)
	{
		y = 0;
		while (y < W_HEIGHT)
		{
			e->f.c_r = x / e->f.zoom + e->f.x1;
			e->f.c_i = y / e->f.zoom + e->f.y1;
			e->f.z_i = 0;
			e->f.z_r = 0;
			i = 0;
			draw_mandel2(e, &i, &tmp);
			if (i == e->f.iter)
				mlx_put_pixel_image(e, x, y, e->f.color);
			else
				mlx_put_pixel_image(e, x, y, (e->f.color * i) / e->f.iter);
			y++;
		}
		x++;
	}
}

void	draw(t_env *e)
{
	t_img	img;

	img.ptr = mlx_new_image(e->mlx, W_WIDTH, W_HEIGHT);
	img.data = mlx_get_data_addr(img.ptr, &img.bpp, &img.size_line, &img.edian);
	e->img = img;
	if (e->choose == 1)
		draw_julia(e);
	else if (e->choose == 2)
		draw_mandel(e);
	else if (e->choose == 3)
		draw_burn(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.ptr, 0, 0);
}
