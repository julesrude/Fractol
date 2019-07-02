/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:43:00 by yruda             #+#    #+#             */
/*   Updated: 2019/07/02 14:46:28 by yruda            ###   ########.fr       */
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
	exit (EXIT_FAILURE);
}

void	draw_menu(void *mlx, void *win, int color1, int color2)
{
	mlx_string_put(mlx, win, 10, 100, color2, "RESET:");
	mlx_string_put(mlx, win, 10, 100, color1, "            press 'R'");
	mlx_string_put(mlx, win, 10, 200, color2, "FRACTALS");
	mlx_string_put(mlx, win, 10, 220, color2, "Julia:");
	mlx_string_put(mlx, win, 10, 220, color1, "            press 'J'");
	mlx_string_put(mlx, win, 10, 260, color2, "Mandelbrot:");
	mlx_string_put(mlx, win, 10, 260, color1, "            press 'M'");
	mlx_string_put(mlx, win, 10, 340, color2, "CHOOSE COLOR THEME:");
	mlx_string_put(mlx, win, 10, 380, color1, "            '1'");
	mlx_string_put(mlx, win, 10, 380, COLOR1_2, "|");
	mlx_string_put(mlx, win, 10, 380, COLOR1_4, " |");
	mlx_string_put(mlx, win, 10, 380, COLOR1_5, "  |");
	mlx_string_put(mlx, win, 10, 410, color1, "            '2'");
	mlx_string_put(mlx, win, 10, 410, COLOR2_2, "|");
	mlx_string_put(mlx, win, 10, 410, COLOR2_3, " |");
	mlx_string_put(mlx, win, 10, 410, COLOR2_5, "  |");
	mlx_string_put(mlx, win, 10, 440, color1, "            '3'");
	mlx_string_put(mlx, win, 10, 440, COLOR3_1, "|");
	mlx_string_put(mlx, win, 10, 440, COLOR3_2, " |");
	mlx_string_put(mlx, win, 10, 440, COLOR3_5, "  |");
	mlx_string_put(mlx, win, 10, 470, color1, "            '4'");
	mlx_string_put(mlx, win, 10, 470, COLOR4_2, "|");
	mlx_string_put(mlx, win, 10, 470, COLOR4_4, " |");
	mlx_string_put(mlx, win, 10, 470, COLOR4_5, "  |");
}

int		set_ftype(t_fractal *f, char *c)
{
	if(ft_strcmp(c, "Mandelbrot") == 0)
		f->f_type = Mandelbrot;
	else if(ft_strcmp(c, "Julia") == 0)
		f->f_type = Julia;
	else if(ft_strcmp(c, "Pythagoras") == 0)
		f->f_type = Pythagoras;
	else
		return (0);
	return (1);
}

int		init_mlx(t_mlx *m)
{
	if (!(m->mlx = mlx_init()))
		put_error("error: Couldn't initialize the connection between \
		your software and the display");
	m->img = (t_image *)malloc(sizeof(t_image));
	m->win = mlx_new_window(m->mlx, WIN_W, WIN_H, "jules");
	m->img->ptr = mlx_new_image(m->mlx, (WIN_W - MENU_W), WIN_H);
	m->img->addr = mlx_get_data_addr(m->img->ptr, &(m->img->bpp),
			&(m->img->size_line), &(m->img->endian));
	m->mouse = malloc(sizeof(t_mouse));
	m->mouse->is_pressed = 0;
	m->mouse->pause = 0;
	return (0);
}

int		init_frac(t_fractal *f)
{
	f->scale = 1;
	f->cs_number = 3;
	get_schemes(f, f->colors, f->cs_number);
	return (0);
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
		---> Mandelbrot\n\
		---> Julia\n\
		---> Pythagoras"));
	if (init_mlx(m))
		return (1);		
	draw_menu(m->mlx, m->win, COLOR_WHITE, COLOR_O1);
	redraw_image(m);
	set_fractal(m, m->f);
	draw_fractal(m, m->f);
	
	mlx_hook(m->win, 2, 0, key_press, m);
	mlx_hook(m->win, 4, 0, mouse_press, m);
	mlx_hook(m->win, 5, 0, mouse_release, m);
	mlx_hook(m->win, 6, 0, mouse_move, m);
	mlx_hook(m->win, 17, 0, ft_close, m);
	mlx_loop(m->mlx);
	return (0);
}
