/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 20:40:02 by yruda             #+#    #+#             */
/*   Updated: 2019/07/03 18:55:04 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "mlx.h"
# include "libft.h"
# include <pthread.h>

# include <stdio.h>
# define COLOR_RED     "\x1b[31m"
# define COLOR_GREEN   "\x1b[32m"
# define COLOR_YELLOW  "\x1b[33m"
# define COLOR_BLUE    "\x1b[34m"
# define COLOR_MAGENTA "\x1b[35m"
# define COLOR_CYAN    "\x1b[36m"
# define COLOR_RESET   "\x1b[0m"

# define WIN_W 1500
# define WIN_H 1000
# define MENU_W 300
# define MENU_H 1000
# define IMAGE_W 1200
# define IMAGE_H 1000

# define WIN_BORD 100

# define MAXITER 125
# define THREADS 8

# define ANGLE (M_PI / 180)
# define ZOOM_STEP 1.25

# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_SPACE 49
# define KEY_1 83
# define KEY_2 84
# define KEY_3 85
# define KEY_4 86
# define KEY_5 87
# define KEY_6 88
# define KEY_7 89
# define KEY_8 91
# define KEY_9 92
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_I 34
# define KEY_T 17
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_J 38
# define KEY_P 35
# define KEY_M 46
# define KEY_1U 18
# define KEY_2U 19
# define KEY_3U 20
# define KEY_4U 21
# define KEY_5U 23
# define KEY_6U 22
# define KEY_7U 26

# define COLOR_O1 0xbbddcc
# define COLOR1_0 0
# define COLOR1_1 0x553344
# define COLOR1_2 0xffcc88
# define COLOR1_3 0x88aabb
# define COLOR1_4 0xbb7788
# define COLOR1_5 0x46b19e
# define COLOR2_0 0
# define COLOR2_1 0x4e092e
# define COLOR2_2 0xcc4e0c
# define COLOR2_3 0xf7ab37
# define COLOR2_4 0x38c2c0
# define COLOR2_5 0x4d4e5d
# define COLOR3_0 0
# define COLOR3_1 0xf4c095
# define COLOR3_2 0xee2e31
# define COLOR3_3 0x071e22
# define COLOR3_4 0x1d7874
# define COLOR3_5 0x679289
# define COLOR4_1 0
# define COLOR4_2 0x114b5f
# define COLOR4_3 0x114b5f
# define COLOR4_4 0x88d498
# define COLOR4_5 0x776688
# define COLOR4_6 0xfee4a7

# define COLOR_GREY 0x888888
# define COLOR_WHITE 0xffffff

enum				e_f_types{
	Mandelbrot,
	Julia,
	Pythagoras
};

typedef struct		s_point
{
	int				x;
	int				y;
	int				color;
}					t_point;

typedef struct		s_image
{
	void			*ptr;
	char			*addr;
	int				bpp;
	int				size_line;
	int				endian;
}					t_image;

typedef	struct		s_complex
{
	double			r;
	double			i;
}					t_complex;

typedef struct		s_colscheme
{
	int			col0;
	int			col1;
	int			col2;
	int			col3;
	int			col4;
}					t_colscheme;

/*
**	maxr & minr maximum and minimum rational number on real axis (J & M)
**	c_r & c_i are used for Julia
**	use x_shift for Pythagoras
**	cs_number - number color pallete from 0 to 3
*/

typedef	struct		s_fractal
{
	enum e_f_types	f_type;
	long int		x_zero;
	long int		y_zero;

	double			maxr;
	double			minr;
	double			scale;

	double			c_r;
	double			c_i;

	int				x_shift;
	int				iterations;

	int				cs_number;
	int				colors[5];
}					t_fractal;

typedef struct		s_mouse
{
	char			is_pressed;
	int				x;
	int				y;
	int				previous_x;
	int				previous_y;
	char			pause;
}					t_mouse;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_image			*img;
	t_fractal		*f;
	t_mouse			*mouse;
}					t_mlx;

typedef struct		s_mythread
{
	pthread_t		t;
	t_mlx			*m;
	int				i;
	int				iterations;
}					t_mythread;

/*
**	main.c
*/
int					put_error(char *str_error);

/*
**	init_and_set.c
*/
int					init_frac(t_fractal *f);
int					init_mlx(t_mlx *m);
void				set_julia(t_mlx *m, t_fractal *f);
void				set_fractal(t_mlx *m, t_fractal *f);

/*
**	draw_window.c
*/
void				image_background(t_mlx *m, int color);
void				draw_menu(void *mlx, void *win, int color1, int color2);
void				draw_iterations(t_mlx *m, int i, int whatwedo_bool);

/*
**	actions.c
*/
int					key_press(int key, t_mlx *m);
int					mouse_press(int key, int x, int y, t_mlx *m);
int					mouse_release(int key, int x, int y, t_mlx *m);
int					mouse_scroll(int key, int x, int y, t_mlx *m);
int					mouse_move(int x, int y, t_mlx *m);

/*
**	f_main.c
*/
void				draw_fractal(t_mlx *m, t_fractal *f);
void				paint_fractal_transition(int i, int j, int count, t_mlx *m);
void				*thread_calculation(void *data);

/*
**	f_color.c
*/
int					color_grade(int count, t_mlx *m, int *limits, int a);
void				get_schemes(t_fractal *f, int *colors, int cs_num);

/*
**	f_pythagoras.c
*/
void				pythagoras_tree(t_mlx *m, t_fractal *f);

/*
** bresenham.c and bresenham_square.c
*/
void				draw_line(t_mlx *m, t_point pt0, t_point pt1);
void				draw_square(t_mlx *m, t_point pt0, t_point pt1,
	t_point vector);

#endif
