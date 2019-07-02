/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:31:56 by yruda             #+#    #+#             */
/*   Updated: 2019/07/02 15:08:58 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_press2(int key, t_mlx *m)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(m->mlx, m->win);
		system("leaks fractol");
		exit(EXIT_SUCCESS);
	}
}

int		key_press(int key, t_mlx *m)
{
	if (key == KEY_1u || key == KEY_2u || key == KEY_3u || key == KEY_4u)
	{
		m->f->cs_number = key - 18;
		get_schemes(m->f, m->f->colors, m->f->cs_number);
	}
	else if (key == KEY_R)
		set_fractal(m, m->f);
	else if (key == KEY_J || key == KEY_M || key == KEY_P)
	{
		if (key == KEY_J)
			m->f->f_type = Julia;
		else if (key == KEY_M)
			m->f->f_type = Mandelbrot;
		else if (key == KEY_P)
			m->f->f_type = Pythagoras;
		set_fractal(m, m->f);
	}
	else if (key == KEY_SPACE)
		m->mouse->pause = (m->mouse->pause == 0) ? 1 : 0;
	else
		key_press2(key, m);
	draw_fractal(m, m->f);
	return (0);
}
