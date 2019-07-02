/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 15:14:12 by yruda             #+#    #+#             */
/*   Updated: 2019/07/02 15:15:21 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				color_grade(int count, t_mlx *m, int *limits, int n)
{
	double		frac;
	int			r;
	int			g;
	int			b;
	t_fractal	*f;

	f = m->f;
	frac = (double)(count - limits[n]) / (double)(limits[n - 1] - limits[n]);
	r = (int)(frac * (((f->colors[n - 1] >> 16) & 0xFF) - ((f->colors[n] >> 16)
		& 0xFF)) + (double)((f->colors[n] >> 16) & 0xFF));
	g = (int)(frac * (((f->colors[n - 1] >> 8) & 0xFF) - ((f->colors[n] >> 8)
		& 0xFF)) + (double)((f->colors[n] >> 8) & 0xFF));
	b = (int)(frac * (((f->colors[n - 1]) & 0xFF) - ((f->colors[n]) & 0xFF)) +
		(double)((f->colors[n]) & 0xFF));
	return (r << 16 | g << 8 | b);
}

void			get_schemes(t_fractal *f, int *colors, int cs_num)
{
	t_colorscheme cs[4];

	if (f->f_type == Pythagoras)
	{
		cs[0] = (t_colorscheme){COLOR1_1, COLOR1_2, COLOR1_4, COLOR1_1, COLOR1_5};
		cs[1] = (t_colorscheme){COLOR2_1, COLOR2_2, COLOR2_3, COLOR2_4, COLOR2_5};
		cs[2] = (t_colorscheme){COLOR3_1, COLOR3_2, COLOR3_3, COLOR3_4, COLOR3_5};
		cs[3] = (t_colorscheme){COLOR4_5, COLOR4_2, COLOR4_3, COLOR4_4, COLOR4_6};
		colors[0] = cs[cs_num].col0;
		colors[1] = cs[cs_num].col1;
		colors[2] = cs[cs_num].col2;
		colors[3] = cs[cs_num].col3;
		colors[4] = cs[cs_num].col4;
	}
	else
	{
		cs[0] = (t_colorscheme){COLOR1_0, COLOR1_2, COLOR1_4, COLOR1_1, COLOR1_5};
		cs[1] = (t_colorscheme){COLOR2_0, COLOR2_1, COLOR2_2, COLOR2_3, COLOR2_5};
		cs[2] = (t_colorscheme){COLOR3_1, COLOR3_2, COLOR3_3, COLOR3_4, COLOR3_5};
		cs[3] = (t_colorscheme){COLOR4_1, COLOR4_2, COLOR4_3, COLOR4_4, COLOR4_5};
		colors[0] = cs[cs_num].col0;
		colors[1] = cs[cs_num].col1;
		colors[2] = cs[cs_num].col2;
		colors[3] = cs[cs_num].col3;
		colors[4] = cs[cs_num].col4;
	}
}
