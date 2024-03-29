/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_pythagoras.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:51:46 by yruda             #+#    #+#             */
/*   Updated: 2019/07/03 18:57:59 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		color_for_pythagoras(t_mlx *m, t_fractal *f, int i)
{
	int		j;
	int		limits[4];

	j = 1;
	limits[0] = f->iterations;
	limits[1] = f->iterations * 5 / 6;
	limits[2] = f->iterations * 2 / 4;
	limits[3] = f->iterations * 0 / 4;
	while (i < limits[j])
		j++;
	return (color_grade(i, m, limits, j));
}

t_point	find_e(t_mlx *m, t_point t2, t_point vector)
{
	t_point	e;

	e.x = t2.x + (double)vector.x * cos(ANGLE * (45 + m->f->x_shift)) *
		sin(ANGLE * (45 + m->f->x_shift)) + (double)(-vector.y) * cos(ANGLE
		* (45 + m->f->x_shift)) * cos(ANGLE * (45 + m->f->x_shift));
	e.y = t2.y + (double)(vector.y) * cos(ANGLE * (45 + m->f->x_shift)) *
		sin(ANGLE * (45 + m->f->x_shift)) - (double)(-vector.x) *
		cos(ANGLE * (45 + m->f->x_shift)) * cos(ANGLE * (45 + m->f->x_shift));
	return (e);
}

void	p_t_recursion(t_mlx *m, t_point t0, t_point t1, int i)
{
	t_point	t2;
	t_point	t3;
	t_point	e;
	t_point vector;

	t2.x = t0.x + (t1.y - t0.y);
	t2.y = t0.y - (t1.x - t0.x);
	t3.x = t1.x + (t1.y - t0.y);
	t3.y = t1.y - (t1.x - t0.x);
	vector.x = t2.x - t0.x;
	vector.y = t2.y - t0.y;
	e = find_e(m, t2, vector);
	vector.color = color_for_pythagoras(m, m->f, i);
	if (abs(t0.x - t1.x) > abs(t0.y - t1.y))
		draw_square(m, t0, t1, vector);
	else
	{
		vector.x = t1.x - t0.x;
		vector.y = t1.y - t0.y;
		draw_square(m, t0, t2, vector);
	}
	if (i > 0)
		p_t_recursion(m, t2, e, i - 1);
	if (i > 0)
		p_t_recursion(m, e, t3, i - 1);
}

void	pythagoras_tree(t_mlx *m, t_fractal *f)
{
	t_point	t0;
	t_point	t1;

	image_background(m, m->f->colors[4]);
	t0.x = IMAGE_W / 2 - (IMAGE_W / 15);
	t0.y = IMAGE_H / 2 + (IMAGE_H / 3);
	t1.x = IMAGE_W / 2 + (IMAGE_W / 15);
	t1.y = IMAGE_H / 2 + (IMAGE_H / 3);
	p_t_recursion(m, t0, t1, f->iterations);
	mlx_put_image_to_window(m->mlx, m->win, m->img->ptr, WIN_W - IMAGE_W, 0);
}
