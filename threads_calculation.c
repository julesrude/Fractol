/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_calculation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 16:32:29 by yruda             #+#    #+#             */
/*   Updated: 2019/06/26 16:32:57 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*thread_calcualtion_julia(void *data)
{
	t_mythread		*thread_data;
	int				i;
	int				j;
	int				count;

	t_complex		c;
	t_complex		z;
	double			temp;

	thread_data = (t_mythread *)data;
	
	i = thread_data->i;
	j = thread_data->j;
	count = 0;
	temp = 0.0;
	
	while(i < thread_data->i + thread_data->iterations)
	{
		while(j < IMAGE_W)
		{
			z.r = (((j - thread_data->m->f->x_zero)) / thread_data->m->f->scale);
			z.i = (((i - thread_data->m->f->y_zero)) / thread_data->m->f->scale);
			while((z.r * z.r + z.i * z.i) < 4.0 && count < MAXITER)
			{
				temp = z.r;
				z.r = (z.r * z.r) - (z.i * z.i) + thread_data->m->f->c_r;
				z.i = 2 * z.i * temp + thread_data->m->f->c_i;
				count++;
			}
			paint_fractal_transition(i, j, count, thread_data->m);
			count = 0;
			j++;
		}
		i++;
		j = 0;
	}
	return (NULL);
}

void	*thread_calcualtion_mandel(void *data)
{
	t_mythread		*thread_data;
	int				i;
	int				j;
	int				count;

	t_complex		c;
	t_complex		z;
	double			temp;

	thread_data = (t_mythread *)data;
	
	i = thread_data->i;
	j = thread_data->j;
	count = 0;
	temp = 0.0;
	z.r = 0.0;
	z.i = 0.0;
	while(i < thread_data->i + thread_data->iterations)
	{
		while(j < IMAGE_W)
		{
			c.r = (((j - thread_data->m->f->x_zero)) / thread_data->m->f->scale);
			c.i = (((i - thread_data->m->f->y_zero)) / thread_data->m->f->scale);
			while((z.r * z.r + z.i * z.i) < 4.0 && count < MAXITER)
			{
				temp = z.r;
				z.r = (z.r * z.r) - (z.i * z.i) + c.r;
				z.i = 2 * z.i * temp + c.i;
				count++;
			}
			paint_fractal_transition(i, j, count, thread_data->m);
			count = 0;
			z.r = 0.0;
			z.i = 0.0;
			j++;
		}
		i++;
		j = 0;
	}
	return (NULL);
}
