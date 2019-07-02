/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 20:40:02 by yruda             #+#    #+#             */
/*   Updated: 2019/07/02 15:11:44 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTOL_H
# define FACTOL_H

# include <math.h>
# include "mlx.h"
# include "libft.h"
#include <pthread.h>

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

#define MAXITER 145
#define THREADS 8

# define ANGLE (M_PI / 180)/*
# define MOVE_STEP 10*/
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
# define KEY_1u 18
# define KEY_2u 19
# define KEY_3u 20
# define KEY_4u 21
# define KEY_5u 23
# define KEY_6u 22
# define KEY_7u 26

# define COLOR_O1 0xbbddcc
# define COLOR1_0 0
# define COLOR1_1 0x553344// Barossa, dark grape
# define COLOR1_2 0xffcc88// Cherokee, light yellow
# define COLOR1_3 0x88aabb// light grayish blue
# define COLOR1_4 0xbb7788// Turkish rose
# define COLOR1_5 0x46b19e// Medium Turquoise but darker, green-blue #48d1cc 
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
# define COLOR4_2 0x114b5f//approx Astronaut Blue
# define COLOR4_3 0x114b5f//approx Astronaut Blue
# define COLOR4_4 0x88d498//approx De York
# define COLOR4_5 0x776688//0xff8877
# define COLOR4_6 0xfee4a7

# define COLOR_GREY 0xbebebe
# define COLOR_WHITE 0xffffff

enum frac_types {
	Mandelbrot,
	Julia,
	Pythagoras	
};

typedef struct	s_point
{
	int			x;
	int			y;
	int			color;
}				t_point;

/*
** pts[y][x]
** x starts with start_x
** y starts with 0
** z starts with start_y
*/

typedef struct	s_image
{
	void		*ptr;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
}				t_image;

typedef	struct		s_complex
{
	double			r;
	double			i;
}					t_complex;

typedef struct	s_colorscheme
{
	int			col0;
	int			col1;
	int			col2;
	int			col3;
	int			col4;
}				t_colorscheme;

/*
**	c_r && c_i are used for Julia
**	use x_shift && y_shift for Pythagoras
*/

typedef	struct		s_fractal
{
	enum frac_types	f_type;
	long int		x_zero;
	long int		y_zero;

	double			maxr; // максимальне число по осі реальних чисел в кадрі
	double			minr; // зайві операції???????????????????????????????????
	double			scale;

	double			c_r;
	double			c_i;

	int				x_shift;
	int				y_shift;
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
	int				j;
	int				iterations;
}					t_mythread;

/*
**	main.c
*/
int					put_error(char *str_error);
int					init_frac(t_fractal *f);

/*
**	image_draw.c
*/
void				redraw_image(t_mlx *m);
void				image_background(t_mlx *m, int color);

/*
**	fractals.c
*/
void				draw_fractal(t_mlx *m, t_fractal *f);
void				paint_fractal_transition(int i, int j, int count, t_mlx *m);

/*
**	actions.c
*/
int					key_press(int key, t_mlx *m);

/*
**	color.c
*/
int					color_grade(int count, t_mlx *m, int *limits, int a);
void				get_schemes(t_fractal *f, int *colors, int cs_num);

/*
**	mouse.c
*/
int					mouse_press(int key, int x, int y, t_mlx *m);
int					mouse_release(int key, int x, int y, t_mlx *m);
int					mouse_scroll(int key, int x, int y, t_mlx *m);
int					mouse_move(int x, int y, t_mlx *m);

/*
**	fractals_specific.c
*/
void				*thread_calcualtion_mandel(void *data);
void				*thread_calcualtion_julia(void *data);
void				set_mandelbrot(t_mlx *m, t_fractal *f);
void				set_julia(t_mlx *m, t_fractal *f);
void				set_fractal(t_mlx *m, t_fractal *f);
void				pythagoras_tree(t_mlx *m, t_fractal *f);

/*
** bresenham.c and bresenham_square.c
*/
void				draw_line(t_mlx *m, t_point pt0, t_point pt1);
void				draw_square(t_mlx *m, t_point pt0, t_point pt1, t_point vector);

#endif
