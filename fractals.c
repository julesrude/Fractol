/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:06:44 by yruda             #+#    #+#             */
/*   Updated: 2019/07/02 15:15:31 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <complex.h>
#include <errno.h>

/*
** i - current y
** j - current x
*/

void	paint_fractal_transition(int i, int j, int count, t_mlx *m)
{
	t_fractal	*f;
	int			limits[5];
	int			a;
	int			color;

	limits[0] = MAXITER;
	limits[1] = 130;
	limits[2] = 25;
	limits[3] = 15;
	limits[4] = 5;
	a = 1;
	f = m->f;
	if (count < limits[4])
		ft_memcpy(&(m->img->addr[(i * IMAGE_W + j) * 4]), &f->colors[4], 4);
	else if (count == MAXITER)
		ft_memcpy(&(m->img->addr[(i * IMAGE_W + j) * 4]), &f->colors[0], 4);
	else
		while (a < 5)
		{
			if (count >= limits[a])
			{
				color = color_grade(count, m, limits, a);
				ft_memcpy(&(m->img->addr[(i * IMAGE_W + j) * 4]), &color, 4);
				return ;
			}
			a++;
		}
}

/*
** just 5 colors, without transition
*/

void	paint_fractal(int i, int j, int count, t_mlx *m)
{
	t_fractal	*f;
	int			limits[5];
	int			a;

	limits[0] = MAXITER;
	limits[1] = 45;
	limits[2] = 25;
	limits[3] = 15;
	limits[4] = 5;
	a = 0;
	f = m->f;
	while (a < 4)
	{
		if (count >= limits[a])
		{
			ft_memcpy(&(m->img->addr[(i * IMAGE_W + j) * 4]), &f->colors[a], 4);
			return ;
		}
		a++;
	}
	if (a == 4)
		ft_memcpy(&(m->img->addr[(i * IMAGE_W + j) * 4]), &f->colors[4], 4);
}

int		set_threads(t_mythread **thread_data, t_mlx *m) // сюди можн додати посилання на функцію яку треба
{
	int	i;

	i = 0;
	while(i < THREADS)
	{
		if (!(thread_data[i] = malloc(sizeof(t_mythread))))
			put_error("error: Failed to allocate threads for calculation\n");
		thread_data[i]->m = m;
		thread_data[i]->i = IMAGE_H * i / THREADS;
		thread_data[i]->j = 0;
		thread_data[i]->iterations = IMAGE_H / THREADS;
		if (m->f->f_type == Mandelbrot)
			if (pthread_create(&(thread_data[i]->t), NULL,
					thread_calcualtion_mandel, thread_data[i]))
				put_error(strerror(errno));
		if (m->f->f_type == Julia)
			if (pthread_create(&(thread_data[i]->t), NULL,
					thread_calcualtion_julia, thread_data[i]))
				put_error(strerror(errno));
		i++;
	}
	return (1);
}

void	draw_fractal(t_mlx *m, t_fractal *f)
{
	int				i;
	t_mythread		*thread_data[THREADS];

	if (f->f_type == Julia || f->f_type == Mandelbrot)
	{	
		set_threads(thread_data, m);
		i = 0;
		while (i < THREADS)
		{
			if (pthread_join(thread_data[i]->t, NULL))
				put_error(strerror(errno));
			free(thread_data[i]);
			i++;
		}
	}
	else
		pythagoras_tree(m, f);
	mlx_put_image_to_window(m->mlx, m->win, m->img->ptr, WIN_W - IMAGE_W, 0);
}
