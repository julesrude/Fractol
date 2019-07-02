/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:06:58 by yruda             #+#    #+#             */
/*   Updated: 2019/06/28 16:15:31 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	paint_row(t_mlx *m, t_point vector, int x, int y)
{
	t_point	p1;
	t_point	p2;

	p1.x = x;
	p1.y = y;
	p2.x = x + vector.x;
	p2.y = y + vector.y;
	p1.color = vector.color;
	p2.color = 0;
	draw_line(m, p1, p2);
}

void	seg1_sq(t_mlx *m, t_point pt0, t_point pt1, t_point vector)
{
	int		x;
	int		y;
	int		current_diff;
	int		rise;
	int		run;

	run = abs(pt1.x - pt0.x);
	rise = abs(pt1.y - pt0.y);
	current_diff = 0;
	x = pt0.x;
	y = pt0.y;
	while (x != pt1.x)
	{
		paint_row(m, vector, x, y);
		if (x >= 0 && x < IMAGE_W && y >= 0 && y < IMAGE_H)
			ft_memcpy(&(m->img->addr[(y * IMAGE_W + x) * 4]), &vector.color, 4);
		(pt1.x >= pt0.x) ? x++ : x--;
		current_diff += rise;
		if (current_diff * 2 / run != 0)
		{
			(pt1.y >= pt0.y) ? y++ : y--;
			(pt1.x >= pt0.x) ? paint_row(m, vector, x - 1, y) : paint_row(m, vector, x + 1, y);
			(current_diff -= run);
		}
	}
}

void	seg2_sq(t_mlx *m, t_point pt0, t_point pt1, t_point vector)
{
	int		x;
	int		y;
	int		current_diff;
	int		rise;
	int		run;

	run = abs(pt1.x - pt0.x);
	rise = abs(pt1.y - pt0.y);
	current_diff = 0;
	x = pt0.x;
	y = pt0.y;
	while (y != pt1.y)
	{
		paint_row(m, vector, x, y);
		if (x >= 0 && x < IMAGE_W && y >= 0 && y < IMAGE_H)
			ft_memcpy(&(m->img->addr[(y * IMAGE_W + x) * 4]), &vector.color, 4);
		(pt1.y >= pt0.y) ? y++ : y--;
		current_diff += run;
		if (current_diff * 2 / rise != 0)
		{
			(pt1.x >= pt0.x) ? x++ : x--;
			(pt1.x >= pt0.x) ? paint_row(m, vector, x, y - 1) : paint_row(m, vector, x, y + 1);
			(current_diff -= rise);
		}
	}
}

void	draw_square(t_mlx *m, t_point pt0, t_point pt1, t_point vector)
{
	int		run;
	int		rise;
	int		current_diff;
	int		x;
	int		y;

	run = abs(pt1.x - pt0.x);
	rise = abs(pt1.y - pt0.y);
	current_diff = 0;
	x = pt0.x;
	y = pt0.y;
	if (rise == 0 && run == 0)
	{
		if (x >= 0 && x < IMAGE_W && y >= 0 && y < IMAGE_H)
			ft_memcpy(&(m->img->addr[(y * IMAGE_W + x) * 4]), &vector.color, 4);
	}
	else if (rise <= run)
		seg1_sq(m, pt0, pt1, vector);
	else
		seg2_sq(m, pt0, pt1, vector);
}
