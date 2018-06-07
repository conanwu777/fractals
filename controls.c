/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:04:37 by cwu               #+#    #+#             */
/*   Updated: 2018/05/16 17:04:48 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	color_keys(int key, t_mlx *mlxp)
{
	t_color tmp;

	if ((key == 24 && mlxp->it < 230) || (key == 27 && mlxp->it > 20))
		mlxp->it += (key == 24 ? 20 : -20);
	else if (key == 12 || key == 13)
		mlxp->c_mx.r += (key == 12 ? 10 : -10);
	else if (key == 0 || key == 1)
		mlxp->c_mx.g += (key == 0 ? 10 : -10);
	else if (key == 6 || key == 7)
		mlxp->c_mx.b += (key == 6 ? 10 : -10);
	else if (key == 14 || key == 15)
		mlxp->c_mn.r += (key == 14 ? 10 : -10);
	else if (key == 2 || key == 3)
		mlxp->c_mn.g += (key == 2 ? 10 : -10);
	else if (key == 8 || key == 9)
		mlxp->c_mn.b += (key == 8 ? 10 : -10);
	else if (key == 49)
	{
		tmp = mlxp->c_mx;
		mlxp->c_mx = mlxp->c_mn;
		mlxp->c_mn = tmp;
	}
	set_color(*mlxp);
}

void	presets(int key, t_mlx *mlxp)
{
	if (key == 36)
		*mlxp = reset(*mlxp);
	else if (key == 18)
	{
		mlxp->c_mx = input_color(250, 250, 190);
		mlxp->c_mn = input_color(10, 20, 30);
	}
	else if (key == 19)
	{
		mlxp->c_mx = input_color(196, 136, 136);
		mlxp->c_mn = input_color(230, 240, 220);
	}
	else if (key == 20)
	{
		mlxp->c_mx = input_color(246, 236, 40);
		mlxp->c_mn = input_color(30, 110, 136);
	}
	else if (key == 21)
	{
		mlxp->c_mx = input_color(100, 18, 18);
		mlxp->c_mn = input_color(230, 250, 220);
	}
	set_color(*mlxp);
	if (key == 34)
		mlxp->info = (mlxp->info ? 0 : 1);
}

int		k_control(int key, void *addr)
{
	t_mlx	*mlxp;
	int		i;

	mlxp = (t_mlx*)addr;
	if (key == 125 || key == 126)
		(mlxp->o).y += (key == 125 ? -20 : 20);
	else if (key == 123 || key == 124)
		(mlxp->o).x += (key == 124 ? -20 : 20);
	else if (key == 30 || key == 33)
		mlxp->esc *= (key == 30 ? 1.2f : 0.8f);
	i = 0;
	while (iter[i].name && iter[i].key != key)
		i++;
	if (iter[i].name && iter[i].key == key)
		mlxp->iter = iter[i].fp;
	color_keys(key, mlxp);
	presets(key, mlxp);
	refresh((void*)mlxp);
	if (key == 53)
	{
		mlx_destroy_image(mlxp->mp, mlxp->img);
		exit(1);
	}
	return (0);
}

int		m_control(int button, int x, int y, void *addr)
{
	t_mlx	*mlxp;

	mlxp = (t_mlx*)addr;
	if (button == 5)
	{
		mlxp->o.x = (mlxp->o.x - x) * (mlxp->unit * 1.1) / mlxp->unit + x;
		mlxp->o.y = (mlxp->o.y - y) * (mlxp->unit * 1.1) / mlxp->unit + y;
		mlxp->unit *= 1.1;
	}
	else if (button == 4 && mlxp->unit > 0)
	{
		mlxp->o.x = (mlxp->o.x - x) * (mlxp->unit / 1.1) / mlxp->unit + x;
		mlxp->o.y = (mlxp->o.y - y) * (mlxp->unit / 1.1) / mlxp->unit + y;
		mlxp->unit /= 1.1;
	}
	refresh((void*)mlxp);
	return (0);
}

int		motion_control(int x, int y, void *addr)
{
	t_mlx	*mlxp;

	mlxp = (t_mlx*)addr;
	mlxp->c.r = (float)(x - mlxp->o.x) / mlxp->unit;
	mlxp->c.i = (float)(y - mlxp->o.y) / mlxp->unit;
	refresh((void*)mlxp);
	return (0);
}
