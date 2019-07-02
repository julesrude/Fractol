/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:55:54 by yruda             #+#    #+#             */
/*   Updated: 2019/06/27 15:29:29 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	image_background(t_mlx *m, int color)
{
	int		i;
	int		j;
	//int		color;

	i = 0;
	j = IMAGE_H * IMAGE_W * 4;
	//color = COLOR_GREY;
	while(i < j)
	{
		ft_memcpy(&(m->img->addr[i]), &color, 4);
		i += 4;
	}
}

void	redraw_image(t_mlx *m)
{
	image_background(m, COLOR_GREY);
	mlx_put_image_to_window(m->mlx, m->win, m->img->ptr, WIN_W - IMAGE_W, 0);
}
