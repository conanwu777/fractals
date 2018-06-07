/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:25:26 by cwu               #+#    #+#             */
/*   Updated: 2018/05/16 15:29:11 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	set_color(t_mlx mlx)
{
	int i;

	g_color[0][0] = mlx.c_mx.r;
	g_color[0][1] = mlx.c_mx.g;
	g_color[0][2] = mlx.c_mx.b;
	i = 1;
	while (i < 255)
	{
		g_color[i][0] = (unsigned char)(mlx.c_mn.r + (mlx.c_mx.r - mlx.c_mn.r)
			* sqrt(i) / sqrt(mlx.it));
		g_color[i][1] = (unsigned char)(mlx.c_mn.g + (mlx.c_mx.g - mlx.c_mn.g)
			* sqrt(i) / sqrt(mlx.it));
		g_color[i][2] = (unsigned char)(mlx.c_mn.b + (mlx.c_mx.b - mlx.c_mn.b)
			* sqrt(i) / sqrt(mlx.it));
		i++;
	}
}

void	*write_str(void *input)
{
	t_pt	p;
	int		pos;
	int		n;
	t_input	*in;

	in = (t_input*)input;
	p.y = in->mod4;
	while (p.y < H)
	{
		p.x = 0;
		pos = p.y * W;
		while (p.x < W)
		{
			n = (in->mlx.iter)(p.x, p.y, *in);
			in->mlx.s[(pos << 2) + 0] = g_color[n][2];
			in->mlx.s[(pos << 2) + 1] = g_color[n][1];
			in->mlx.s[(pos << 2) + 2] = g_color[n][0];
			p.x++;
			pos++;
		}
		p.y += 4;
	}
	return (0);
}

int		write_image(t_mlx mlx)
{
	pthread_t	th[4];
	t_input		*input;
	t_input		*tmp;
	int			i;

	input = (t_input*)malloc(sizeof(t_input) * 4);
	tmp = input;
	i = -1;
	while (++i < 4)
	{
		tmp->mod4 = i;
		tmp->mlx = mlx;
		pthread_create(&th[i], 0, write_str, (void*)tmp);
		tmp++;
	}
	pthread_join(th[0], 0);
	pthread_join(th[1], 0);
	pthread_join(th[2], 0);
	pthread_join(th[3], 0);
	return (0);
}

int		error(void)
{
	int i;

	ft_putstr("Available parameters: ");
	i = 0;
	while (iter[i].name)
	{
		ft_putstr(iter[i].name);
		ft_putstr(" | ");
		i++;
	}
	write(1, "\n", 1);
	return (-1);
}

int		main(int ac, char **av)
{
	t_mlx	mlx;
	int		i;

	i = 0;
	while (ac == 2 && iter[i].name && ft_strcmp(iter[i].name, av[1]))
		i++;
	if (ac != 2 || !iter[i].name)
		return (error());
	else
		mlx.iter = iter[i].fp;
	mlx = reset(mlx);
	mlx.mp = mlx_init();
	mlx.wp = mlx_new_window(mlx.mp, W, H, "Fractol");
	mlx.img = mlx_new_image(mlx.mp, W, H);
	mlx.s = mlx_get_data_addr(mlx.img, &mlx.bp, &mlx.wl, &mlx.endl);
	set_color(mlx);
	refresh((void*)&mlx);
	mlx_hook(mlx.wp, 2, 0, &k_control, (void*)(&mlx));
	mlx_hook(mlx.wp, 4, 0, &m_control, (void*)(&mlx));
	mlx_hook(mlx.wp, 6, 0, &motion_control, (void*)(&mlx));
	mlx_expose_hook(mlx.wp, &refresh, (void*)(&mlx));
	mlx_loop(mlx.mp);
	return (0);
}
