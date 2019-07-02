/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 20:04:41 by yruda             #+#    #+#             */
/*   Updated: 2019/06/27 19:12:44 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <float.h>

int		mouse_press(int key, int x, int y, t_mlx *m)
{
	if (key == 4 || key == 5)
		mouse_scroll(key, x, y, m);
	if (key == 1)
		m->mouse->is_pressed = 1;
	return (0);
}

int		mouse_release(int key, int x, int y, t_mlx *m)
{
	m->mouse->is_pressed = 0;
	return (0);
}

void	mouse_move_mandel(t_mlx *m, t_fractal *f, int diffx, int diffy)
{
	if (m->mouse->is_pressed == 1)
	{
		f->x_zero = f->x_zero + diffx;
		f->y_zero = f->y_zero + diffy;
	}
}

int		mouse_move(int x, int y, t_mlx *m)
{
	t_fractal *f;
	int	diffx;
	int	diffy;

	f = m->f;
	m->mouse->previous_x = m->mouse->x;
	m->mouse->previous_y = m->mouse->y;
	m->mouse->x = x;
	m->mouse->y = y;
	diffx = (m->mouse->x - m->mouse->previous_x);
	diffy = (m->mouse->y - m->mouse->previous_y);
	if ((f->f_type == Mandelbrot || f->f_type == Julia) && m->mouse->is_pressed == 1)
		mouse_move_mandel(m, f, diffx, diffy);
	else if (f->f_type == Julia && m->mouse->is_pressed == 0 && m->mouse->pause == 0)
	{
		f->c_r = (((x - f->x_zero)) / f->scale);
		f->c_i = (((x - f->y_zero)) / f->scale);
	}
	else if (f->f_type == Pythagoras && m->mouse->pause == 1) // тут змінити
	{
		f->x_shift = f->x_shift + diffx;
		if (f->y_shift + diffy > 0)
			f->y_shift = f->y_shift + diffy;
		//printf("%i \n", f->x_shift);
	}
	draw_fractal(m, f);
	return (0);
}

int		mouse_scroll(int key, int x, int y, t_mlx *m)
{
	double r;// current number mouse on
	double i;//10/06
	t_fractal *f = m->f;
	
	x = x - MENU_W;
	r = (x - f->x_zero) / f->scale;
	i = (y - f->y_zero) / f->scale;
	if (m->f->f_type == Pythagoras)
		return (0);
	if (key == 4)
	{
		if(f->scale < DBL_MAX / 1.1) ////////also
			f->scale *= ZOOM_STEP;
/*		f->maxi = f->maxi / ZOOM_STEP + i;
		f->mini = f->mini / ZOOM_STEP + i; // WHY maxi??????????????????????????????????????????????
		f->maxr = f->maxr / ZOOM_STEP + r;
		f->minr = f->minr / ZOOM_STEP + r;*/
		f->x_zero = (f->x_zero - x) * (ZOOM_STEP) + x;
		f->y_zero = (f->y_zero - y) * (ZOOM_STEP) + y;
	}
	if (key == 5)
	{
		f->scale /= (ZOOM_STEP);
/*		f->maxi = f->maxi / ZOOM_STEP - i;
		f->mini = f->maxi / ZOOM_STEP - i;
		f->maxr = f->maxr / ZOOM_STEP - r;
		f->minr = f->maxr / ZOOM_STEP - r;*/
		f->x_zero = (f->x_zero - x) / (ZOOM_STEP) + x;
		f->y_zero = (f->y_zero - y) / (ZOOM_STEP) + y;
	}
	draw_fractal(m, f);
	return (0);
}