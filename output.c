/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:55:10 by cwu               #+#    #+#             */
/*   Updated: 2018/05/16 16:55:13 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_color	input_color(unsigned char r, unsigned char g, unsigned char b)
{
	t_color tmp;

	tmp.r = r;
	tmp.g = g;
	tmp.b = b;
	return (tmp);
}

int		refresh(void *addr)
{
	t_mlx	*mlxp;
	int		color;

	mlxp = (t_mlx*)addr;
	color = (mlxp->c_mx.r << 16) + (mlxp->c_mx.g << 8) + mlxp->c_mx.b;
	write_image(*mlxp);
	mlx_put_image_to_window(mlxp->mp, mlxp->wp, mlxp->img, 0, 0);
	if (mlxp->info)
		print_info(color, *mlxp);
	return (0);
}

t_mlx	reset(t_mlx mlx)
{
	(mlx.o).x = W / 2;
	(mlx.o).y = H / 2;
	mlx.unit = H / 3;
	mlx.it = 100;
	mlx.esc = 200;
	mlx.info = 1;
	mlx.c_mx = input_color(140, 210, 34);
	mlx.c_mn = input_color(4, 8, 46);
	set_color(mlx);
	return (mlx);
}

void	print_info(int color, t_mlx mlx)
{
	static char str[100];

	sprintf(str, "Iterations: %-7d '- +'", mlx.it);
	STR(mlx.mp, mlx.wp, 50, 30, color, str);
	sprintf(str, "Escape:  %-7.1f '[ ]'", mlx.esc);
	STR(mlx.mp, mlx.wp, 50, 60, color, str);
	sprintf(str, "FGcolor: %-4d%-4d%-4d", mlx.c_mx.r, mlx.c_mx.g, mlx.c_mx.b);
	STR(mlx.mp, mlx.wp, 50, 90, color, str);
	STR(mlx.mp, mlx.wp, 50, 120, color, "R:'q w'; G:'a s'; B:'z x'");
	sprintf(str, "BGcolor: %-4d%-4d%-4d", mlx.c_mn.r, mlx.c_mn.g, mlx.c_mn.b);
	STR(mlx.mp, mlx.wp, 50, 150, color, str);
	STR(mlx.mp, mlx.wp, 50, 180, color, "R:'e r'; G:'d f'; B:'c v'");
	sprintf(str, "Origin:  %-8d%-8d", mlx.o.x, mlx.o.y);
	STR(mlx.mp, mlx.wp, 50, 210, color, str);
	sprintf(str, "Unit:    %d", mlx.unit);
	STR(mlx.mp, mlx.wp, 50, 240, color, str);
	STR(mlx.mp, mlx.wp, 50, 270, color, "Reset:   'Enter'");
	STR(mlx.mp, mlx.wp, 50, 300, color, "Reverse: 'Space'");
	STR(mlx.mp, mlx.wp, 50, 330, color, "Fractals:");
	STR(mlx.mp, mlx.wp, 50, 360, color, "  1. Julia");
	STR(mlx.mp, mlx.wp, 50, 390, color, "  2. Mandelbrot");
	STR(mlx.mp, mlx.wp, 50, 420, color, "  3. Sierpinski");
	STR(mlx.mp, mlx.wp, 50, 450, color, "  4. Poincare");
	STR(mlx.mp, mlx.wp, 50, 480, color, "  5. Cubic");
	STR(mlx.mp, mlx.wp, 50, 510, color, "  6. Dots");
	STR(mlx.mp, mlx.wp, 50, 540, color, "Color presets:");
	STR(mlx.mp, mlx.wp, 50, 570, color, "  #1. Film");
	STR(mlx.mp, mlx.wp, 50, 600, color, "  #2. Sakura");
	STR(mlx.mp, mlx.wp, 50, 630, color, "  #3. Summer");
	STR(mlx.mp, mlx.wp, 50, 660, color, "  #4. Blood");
	STR(mlx.mp, mlx.wp, 50, 690, color, "Display info: 'i'");
}

int		miter(int x, int y, t_input in)
{
	t_cpt	c;
	t_cpt	z;
	t_cpt	tmp;
	int		iter;

	c.r = (float)(x - in.mlx.o.x) / in.mlx.unit;
	c.i = (float)(y - in.mlx.o.y) / in.mlx.unit;
	z.r = 0;
	z.i = 0;
	iter = 1;
	while (iter < in.mlx.it && z.r * z.r + z.i * z.i <= in.mlx.esc)
	{
		tmp.r = z.r * z.r - z.i * z.i + c.r;
		tmp.i = 2 * z.r * z.i + c.i;
		z = tmp;
		iter++;
	}
	return (iter);
}
