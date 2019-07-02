/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:06:58 by yruda             #+#    #+#             */
/*   Updated: 2019/06/27 18:58:12 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	seg1(t_mlx *m, t_point pt0, t_point pt1, int run)
{
	int		x;
	int		y;
	int		current_diff;
	int		rise;

	rise = abs(pt1.y - pt0.y);
	current_diff = 0;
	x = pt0.x;
	y = pt0.y;
	while (x != pt1.x)
	{
		ft_memcpy(&(m->img->addr[(y * IMAGE_W + x) * 4]), &pt0.color, 4);
		(pt1.x >= pt0.x) ? x++ : x--;
		current_diff += rise;
		if (current_diff * 2 / run != 0)
		{
			(pt1.y >= pt0.y) ? y++ : y--;
			(current_diff -= run);
		}
	}
	
}

void	seg2(t_mlx *m, t_point pt0, t_point pt1, int run)
{
	int		x;
	int		y;
	int		current_diff;
	int		rise;

	rise = abs(pt1.y - pt0.y);
	current_diff = 0;
	x = pt0.x;
	y = pt0.y;
	while (y != pt1.y)
	{
		ft_memcpy(&(m->img->addr[(y * IMAGE_W + x) * 4]), &pt0.color, 4);
		(pt1.y >= pt0.y) ? y++ : y--;
		current_diff += run;
		if (current_diff * 2 / rise != 0)
		{
			(pt1.x >= pt0.x) ? x++ : x--;
			(current_diff -= rise);
		}
	}
}

void	draw_line(t_mlx *m, t_point pt0, t_point pt1)
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
		ft_memcpy(&(m->img->addr[(y * IMAGE_W + x) * 4]), &pt0.color, 4);
	else if (rise <= run)
		seg1(m, pt0, pt1, run);
	else
		seg2(m, pt0, pt1, run);
}
