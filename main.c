#include "fractol.h"

int			ft_quit()
{
	ft_putstr("./fractol <name_of_fractal> julia, mandelbrot, burningship\n");
	return (1);
}

int			main(int argc, char **argv)
{
	t_env my_env;
	ft_bzero(&my_env, sizeof(my_env));

	if (argc == 2)
	{
		if (!ft_strcmp(argv[1], "julia"))
			my_env.choose = 1;
		else if (!ft_strcmp(argv[1], "mandelbrot"))
			my_env.choose= 2;
		else if (!ft_strcmp(argv[1], "burningship"))
			my_env.choose = 3;
		else
			return (ft_quit());
		init(&my_env);
	}
	else
		return (ft_quit());
	return (0);
}
