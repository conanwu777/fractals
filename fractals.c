/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:50:22 by cwu               #+#    #+#             */
/*   Updated: 2018/05/16 17:50:24 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	cubeiter(int x, int y, t_input in)
{
	t_cpt	z;
	t_cpt	tmp;
	int		iter;

	z.r = (float)(x - in.mlx.o.x) / in.mlx.unit;
	z.i = (float)(y - in.mlx.o.y) / in.mlx.unit;
	iter = 1;
	while (iter < in.mlx.it && z.r * z.r + z.i * z.i <= in.mlx.esc)
	{
		tmp.r = z.r * z.r * z.r - 3 * z.r * z.i * z.i + in.mlx.c.r;
		tmp.i = 3 * z.r * z.r * z.i - z.i * z.i * z.i + in.mlx.c.i;
		z = tmp;
		iter++;
	}
	if (iter == in.mlx.it)
		return (0);
	return (iter);
}

int	jiter_dots(int x, int y, t_input in)
{
	t_cpt	z;
	t_cpt	tmp;
	int		iter;

	z.r = (float)(x - in.mlx.o.x) / in.mlx.unit;
	z.i = (float)(y - in.mlx.o.y) / in.mlx.unit;
	iter = 1;
	while (iter < in.mlx.it && z.r * z.r + z.i * z.i <= in.mlx.esc)
	{
		tmp.r = z.r * z.r - z.i * z.i + in.mlx.c.r;
		tmp.i = 2 * z.r * z.i + in.mlx.c.i;
		z = tmp;
		iter++;
		if (1.0f / (z.r * z.r + z.i * z.i) > in.mlx.esc)
			break ;
	}
	return (iter);
}

int	jiter(int x, int y, t_input in)
{
	t_cpt	z;
	t_cpt	tmp;
	int		iter;

	z.r = (float)(x - in.mlx.o.x) / in.mlx.unit;
	z.i = (float)(y - in.mlx.o.y) / in.mlx.unit;
	iter = 1;
	while (iter < in.mlx.it && z.r * z.r + z.i * z.i <= in.mlx.esc)
	{
		tmp.r = z.r * z.r - z.i * z.i + in.mlx.c.r;
		tmp.i = 2 * z.r * z.i + in.mlx.c.i;
		z = tmp;
		iter++;
	}
	return (iter);
}

int	rational1(int x, int y, t_input in)
{
	t_cpt	z;
	t_cpt	tmp;
	int		iter;
	float	d;

	z.r = (float)(x - in.mlx.o.x) / in.mlx.unit;
	z.i = (float)(y - in.mlx.o.y) / in.mlx.unit;
	iter = 1;
	while (iter < in.mlx.it && z.r * z.r + z.i * z.i <= in.mlx.esc)
	{
		d = (z.r * z.r + z.i * z.i);
		tmp.r = z.r * z.r - z.i * z.i + in.mlx.c.r * z.r / d
		+ in.mlx.c.i * z.i / d;
		tmp.i = 2 * z.r * z.i - in.mlx.c.r * z.i / d
		+ in.mlx.c.i * z.r / d;
		z = tmp;
		iter++;
	}
	return (iter);
}

int	rational2(int x, int y, t_input in)
{
	t_cpt	z;
	t_cpt	tmp;
	int		iter;
	float	d;

	z.r = (float)(x - in.mlx.o.x) / in.mlx.unit;
	z.i = (float)(y - in.mlx.o.y) / in.mlx.unit;
	iter = 1;
	while (iter < in.mlx.it && z.r * z.r + z.i * z.i <= in.mlx.esc)
	{
		d = (pow((z.r * z.r - z.i * z.i), 2) - 4 * z.r * z.r * z.i * z.i) * 10;
		tmp.r = z.r * z.r - z.i * z.i + in.mlx.c.r * (z.r * z.r - z.i * z.i) / d
		+ in.mlx.c.i * 2 * z.r * z.i / d;
		tmp.i = 2 * z.r * z.i - in.mlx.c.r * 2 * z.r * z.i / d
		+ in.mlx.c.i * (z.r * z.r - z.i * z.i) / d;
		z = tmp;
		iter++;
	}
	return (iter);
}
