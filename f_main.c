/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:06:44 by yruda             #+#    #+#             */
/*   Updated: 2019/07/03 18:49:37 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <complex.h>
#include <errno.h>

/*
** different color for every number of iterations needed to blow up the func
*/

void	paint_fractal_transition(int i, int j, int count, t_mlx *m)
{
	t_fractal	*f;
	int			limits[5];
	int			a;
	int			color;

	limits[0] = MAXITER;
	limits[1] = 115;
	limits[2] = 25;
	limits[3] = 15;
	limits[4] = 5;
	a = 1;
	f = m->f;
	if (count < limits[4])
		ft_memcpy(&(m->img->addr[(i * IMAGE_W + j) * 4]), &f->colors[4], 4);
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
	limits[1] = 115;
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

/*
** i - current y
** j - current x
*/

int		set_threads(t_mythread **thread, t_mlx *m)
{
	int	i;

	i = 0;
	while (i < THREADS)
	{
		if (!(thread[i] = malloc(sizeof(t_mythread))))
			put_error("error: Failed to allocate threads for calculation\n");
		thread[i]->m = m;
		thread[i]->i = IMAGE_H * i / THREADS;
		thread[i]->iterations = IMAGE_H / THREADS;
		if (pthread_create(&(thread[i]->t), NULL,
				thread_calculation, thread[i]))
			put_error(strerror(errno));
		i++;
	}
	return (1);
}

/*
**	integral function for drawing any fractal,
**	because it contains branching to different functions
*/

void	draw_fractal(t_mlx *m, t_fractal *f)
{
	int				i;
	t_mythread		*thread[THREADS];

	if (f->f_type == Julia || f->f_type == Mandelbrot)
	{
		set_threads(thread, m);
		i = 0;
		while (i < THREADS)
		{
			if (pthread_join(thread[i]->t, NULL))
				put_error(strerror(errno));
			free(thread[i]);
			i++;
		}
	}
	else
		pythagoras_tree(m, f);
	mlx_put_image_to_window(m->mlx, m->win, m->img->ptr, WIN_W - IMAGE_W, 0);
}
