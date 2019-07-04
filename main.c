/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:43:00 by yruda             #+#    #+#             */
/*   Updated: 2019/07/03 16:38:06 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <fcntl.h>
#include <sys/errno.h>

int		ft_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int		put_error(char *str_error)
{
	ft_putendl(str_error);
	exit(EXIT_FAILURE);
}

int		set_ftype(t_fractal *f, char *c)
{
	if (ft_strcmp(c, "Mandelbrot") == 0)
		f->f_type = Mandelbrot;
	else if (ft_strcmp(c, "Julia") == 0)
		f->f_type = Julia;
	else if (ft_strcmp(c, "Pythagoras") == 0)
		f->f_type = Pythagoras;
	else
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_mlx		*m;
	t_fractal	*f;
	int			fd;

	m = (t_mlx *)malloc(sizeof(t_mlx));
	m->f = (t_fractal *)malloc(sizeof(t_fractal));
	if (argc == 2 && set_ftype(m->f, argv[1]))
		init_frac(m->f);
	else
		return (put_error("usage: ./fratol type_of_fractal\n\
		---> Mandelbrot\n		---> Julia\n		---> Pythagoras"));
	if (init_mlx(m))
		return (EXIT_FAILURE);
	draw_menu(m->mlx, m->win, COLOR_WHITE, COLOR_O1);
	set_fractal(m, m->f);
	draw_fractal(m, m->f);
	mlx_hook(m->win, 2, 0, key_press, m);
	mlx_hook(m->win, 4, 0, mouse_press, m);
	mlx_hook(m->win, 5, 0, mouse_release, m);
	mlx_hook(m->win, 6, 0, mouse_move, m);
	mlx_hook(m->win, 17, 0, ft_close, m);
	mlx_loop(m->mlx);
	return (EXIT_SUCCESS);
}
