/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:06:28 by yruda             #+#    #+#             */
/*   Updated: 2019/07/03 16:45:12 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		init_mlx(t_mlx *m)
{
	if (!(m->mlx = mlx_init()))
		put_error("error: failed to connect software and the display");
	if (!(m->img = (t_image *)malloc(sizeof(t_image))))
		put_error("error: failed to allocate memory");
	if (!(m->win = mlx_new_window(m->mlx, WIN_W, WIN_H, "jules")))
		put_error("error: failed to create new window");
	if (!(m->img->ptr = mlx_new_image(m->mlx, (WIN_W - MENU_W), WIN_H)))
		put_error("error: failed to create image");
	if (!(m->img->addr = mlx_get_data_addr(m->img->ptr, &(m->img->bpp),
			&(m->img->size_line), &(m->img->endian))))
		put_error("error: failed to get image address");
	if (!(m->mouse = malloc(sizeof(t_mouse))))
		put_error("error: failed to allocate memory");
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

void	set_julia(t_mlx *m, t_fractal *f)
{
	f->maxr = 2.0;
	f->minr = -2.0;
	f->scale = IMAGE_W / (f->maxr - f->minr);
	f->x_zero = IMAGE_W - f->maxr * f->scale;
	f->y_zero = IMAGE_H / 2;
	f->c_i = 0.5;
	f->c_r = 0.5;
	m->mouse->pause = 0;
}

void	set_fractal(t_mlx *m, t_fractal *f)
{
	if (f->f_type == Mandelbrot)
	{
		f->maxr = 1.0;
		f->minr = -2.0;
		f->scale = IMAGE_W / (f->maxr - f->minr);
		f->x_zero = IMAGE_W - f->maxr * f->scale;
		f->y_zero = IMAGE_H / 2;
	}
	else if (f->f_type == Julia)
		set_julia(m, f);
	else if (f->f_type == Pythagoras)
	{
		f->x_shift = 0;
		f->iterations = 7;
		draw_iterations(m, m->f->iterations + 1, 1);
		m->mouse->pause = 1;
	}
}
