/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_calculation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 16:32:29 by yruda             #+#    #+#             */
/*   Updated: 2019/07/03 18:42:31 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	cycle_julia(t_complex z, t_mythread *thread, int i)
{
	int		j;
	int		count;
	double	temp;

	j = 0;
	count = 0;
	temp = 0.0;
	while (j < IMAGE_W)
	{
		z.r = (((j - thread->m->f->x_zero)) / thread->m->f->scale);
		z.i = (((i - thread->m->f->y_zero)) / thread->m->f->scale);
		while ((z.r * z.r + z.i * z.i) < 4.0 && count < MAXITER)
		{
			temp = z.r;
			z.r = (z.r * z.r) - (z.i * z.i) + thread->m->f->c_r;
			z.i = 2 * z.i * temp + thread->m->f->c_i;
			count++;
		}
		paint_fractal_transition(i, j, count, thread->m);
		count = 0;
		j++;
	}
}

void	cycle_mandel(t_complex z, t_mythread *thread, int i)
{
	int				j;
	int				count;
	double			temp;
	t_complex		c;

	j = 0;
	count = 0;
	temp = 0.0;
	while (j < IMAGE_W)
	{
		c.r = (((j - thread->m->f->x_zero)) / thread->m->f->scale);
		c.i = (((i - thread->m->f->y_zero)) / thread->m->f->scale);
		while ((z.r * z.r + z.i * z.i) < 4.0 && count < MAXITER)
		{
			temp = z.r;
			z.r = (z.r * z.r) - (z.i * z.i) + c.r;
			z.i = 2 * z.i * temp + c.i;
			count++;
		}
		paint_fractal_transition(i, j, count, thread->m);
		count = 0;
		z.r = 0.0;
		z.i = 0.0;
		j++;
	}
}

void	*thread_calculation(void *data)
{
	t_mythread		*thread;
	int				i;
	t_complex		z;

	thread = (t_mythread *)data;
	i = thread->i;
	if (thread->m->f->f_type == Julia)
		while (i < thread->i + thread->iterations)
		{
			cycle_julia(z, thread, i);
			i++;
		}
	else if (thread->m->f->f_type == Mandelbrot)
		while (i < thread->i + thread->iterations)
		{
			cycle_mandel(z, thread, i);
			i++;
		}
	return (NULL);
}
