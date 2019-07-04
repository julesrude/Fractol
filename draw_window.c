/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:55:54 by yruda             #+#    #+#             */
/*   Updated: 2019/07/03 19:55:20 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	image_background(t_mlx *m, int color)
{
	int		i;
	int		j;

	i = 0;
	j = IMAGE_H * IMAGE_W * 4;
	while (i < j)
	{
		ft_memcpy(&(m->img->addr[i]), &color, 4);
		i += 4;
	}
}

void	draw_iterations(t_mlx *m, int i, int whatwedo_bool)
{
	char	*temp;

	temp = ft_itoa(i);
	if (whatwedo_bool == 0)
		mlx_string_put(m->mlx, m->win, 140, 520, 0, temp);
	else
		mlx_string_put(m->mlx, m->win, 140, 520, COLOR_WHITE, temp);
	free(temp);
}

void	draw_menu2(void *mlx, void *win, int color1, int color2)
{
	mlx_string_put(mlx, win, 20, 680, color2, "CHOOSE COLOR THEME:");
	mlx_string_put(mlx, win, 20, 720, color1, "            '1'");
	mlx_string_put(mlx, win, 20, 720, COLOR1_2, "|");
	mlx_string_put(mlx, win, 20, 720, COLOR1_4, " |");
	mlx_string_put(mlx, win, 20, 720, COLOR1_5, "  |");
	mlx_string_put(mlx, win, 20, 750, color1, "            '2'");
	mlx_string_put(mlx, win, 20, 750, COLOR2_2, "|");
	mlx_string_put(mlx, win, 20, 750, COLOR2_3, " |");
	mlx_string_put(mlx, win, 20, 750, COLOR2_5, "  |");
	mlx_string_put(mlx, win, 20, 780, color1, "            '3'");
	mlx_string_put(mlx, win, 20, 780, COLOR3_1, "|");
	mlx_string_put(mlx, win, 20, 780, COLOR3_2, " |");
	mlx_string_put(mlx, win, 20, 780, COLOR3_5, "  |");
	mlx_string_put(mlx, win, 20, 810, color1, "            '4'");
	mlx_string_put(mlx, win, 20, 810, COLOR4_2, "|");
	mlx_string_put(mlx, win, 20, 810, COLOR4_4, " |");
	mlx_string_put(mlx, win, 20, 810, COLOR4_5, "  |");
}

void	draw_menu(void *mlx, void *win, int color1, int color2)
{
	mlx_string_put(mlx, win, 20, 20, color1, "WELCOME TO FRACTALS WORLD");
	mlx_string_put(mlx, win, 20, 40, color1, " here's what you can do:");
	mlx_string_put(mlx, win, 20, 200, color2, "RESET:");
	mlx_string_put(mlx, win, 20, 200, color1, "            press  'R'");
	mlx_string_put(mlx, win, 20, 240, color2, "/un/FREEZE:");
	mlx_string_put(mlx, win, 20, 240, color1, "            press  Space");
	mlx_string_put(mlx, win, 20, 400, color2, "FRACTALS");
	mlx_string_put(mlx, win, 20, 420, color2, "Julia:");
	mlx_string_put(mlx, win, 20, 420, color1, "            press  'J'");
	mlx_string_put(mlx, win, 20, 460, color2, "Mandelbrot:");
	mlx_string_put(mlx, win, 20, 460, color1, "            press  'M'");
	mlx_string_put(mlx, win, 20, 500, color2, "Pythagoras:");
	mlx_string_put(mlx, win, 20, 500, color1, "            press  'P'");
	mlx_string_put(mlx, win, 20, 540, color1, "            change:'+/-'");
	mlx_string_put(mlx, win, 20, 520, color1, "               iterations");
	draw_menu2(mlx, win, color1, color2);
}
