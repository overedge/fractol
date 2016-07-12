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
	while (((e->f.z_r * e->f.z_r) + (e->f.z_i * e->f.z_i) < 4) && *i < e->f.iter)
	{
		*tmp = e->f.z_r;
		e->f.z_r = e->f.z_r * e->f.z_r - e->f.z_i * e->f.z_i + e->f.c_r;
		e->f.z_i = 2 * e->f.z_i * *tmp + e->f.c_i;
		*i += 1;
	}

}

void	draw_burn2(t_env *e, int *i, double *tmp)
{
	while (((e->f.z_r * e->f.z_r) + (e->f.z_i * e->f.z_i) < 4) && *i < e->f.iter)
	{
		*tmp = e->f.z_r;
		e->f.z_r = e->f.z_r * e->f.z_r - e->f.z_i * e->f.z_i + e->f.c_r;
		e->f.z_i = 2 * fabs(e->f.z_i) * fabs(*tmp) + e->f.c_i;
		*i += 1;
	}
}
