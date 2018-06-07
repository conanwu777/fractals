/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 10:58:02 by cwu               #+#    #+#             */
/*   Updated: 2018/05/14 10:58:07 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <pthread.h>
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include "libft/ft_printf.h"
# define PIX mlx_pixel_put
# define STR mlx_string_put
# define W 1600
# define H 1000

typedef struct s_input	t_input;

typedef int				(*t_p)(int x, int y, t_input in);

typedef struct			s_iter
{
	char				*name;
	unsigned char		key;
	t_p					fp;
}						t_iter;

typedef struct			s_pt
{
	int					x;
	int					y;
}						t_pt;

typedef struct			s_cpt
{
	float				r;
	float				i;
}						t_cpt;

typedef struct			s_color
{
	unsigned char		b;
	unsigned char		g;
	unsigned char		r;
}						t_color;

typedef struct			s_mlx
{
	t_p					iter;
	void				*mp;
	void				*wp;
	void				*img;
	char				*s;
	int					bp;
	int					wl;
	int					endl;
	unsigned char		info;
	int					it;
	float				esc;
	int					unit;
	t_color				c_mx;
	t_color				c_mn;
	t_pt				o;
	t_cpt				c;
}						t_mlx;

typedef struct			s_input
{
	t_mlx				mlx;
	int					mod4;
}						t_input;

void					*write_str(void *input);
int						write_image(t_mlx mlx);
t_mlx					reset(t_mlx mlx);
void					set_color(t_mlx mlx);
int						refresh(void *addr);
t_mlx					reset(t_mlx mlx);
int						k_control(int key, void *addr);
int						m_control(int button, int x, int y, void *addr);
int						motion_control(int x, int y, void *addr);
int						cubeiter(int x, int y, t_input in);
int						jiter_dots(int x, int y, t_input in);
int						jiter(int x, int y, t_input in);
int						miter(int x, int y, t_input in);
int						rational1(int x, int y, t_input in);
int						rational2(int x, int y, t_input in);
void					print_info(int color, t_mlx mlx);
t_color					input_color(unsigned char r, unsigned char g,
	unsigned char b);

static t_iter			iter[] =
{	{"Julia", 83, &jiter},
	{"Mandelbrot", 84, &miter},
	{"Sierpinski", 85, &rational1},
	{"Poincare", 86, &rational2},
	{"Cubic", 87, &cubeiter},
	{"Dots", 88, &jiter_dots},
	{0, 0, 0}
};

static unsigned char	g_color[256][3];

#endif
