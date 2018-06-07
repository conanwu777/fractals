/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base16_x1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:12:32 by cwu               #+#    #+#             */
/*   Updated: 2018/05/12 17:12:36 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*g_hex = "0123456789abcdef";
static char			*g_chex = "0123456789ABCDEF";
static char			*g_str;
static int			g_i;

char	*printf_x_std(va_list al, t_flags flag)
{
	unsigned int	n;

	g_i = sizeof(int) * 2 + 2;
	if (flag.perc > g_i - 2)
		g_i = flag.perc + 2;
	g_str = ft_strnew(g_i + 1);
	n = va_arg(al, unsigned int);
	while (--g_i >= 0)
	{
		g_str[g_i] = (flag.t == 'x' ? g_hex[n & 15] : g_chex[n & 15]);
		n = n >> 4;
	}
	g_i = del_zero(g_str, flag.perc);
	if (ft_strchr(flag.flag, '#') && ft_atoi(g_str + g_i))
	{
		g_str[--g_i] = flag.t;
		g_i--;
	}
	g_str = cw_strchop(g_str, g_i);
	return (g_str);
}

char	*printf_x_hh(va_list al, t_flags flag)
{
	unsigned char	n;

	g_i = sizeof(unsigned char) * 2 + 2;
	if (flag.perc > g_i - 2)
		g_i = flag.perc + 2;
	g_str = ft_strnew(g_i + 1);
	n = (unsigned char)va_arg(al, unsigned int);
	while (--g_i >= 0)
	{
		g_str[g_i] = (flag.t == 'x' ? g_hex[n & 15] : g_chex[n & 15]);
		n = n >> 4;
	}
	g_i = del_zero(g_str, flag.perc);
	if (ft_strchr(flag.flag, '#') && ft_atoi(g_str + g_i))
	{
		g_str[--g_i] = flag.t;
		g_i--;
	}
	g_str = cw_strchop(g_str, g_i);
	return (g_str);
}

char	*printf_x_h(va_list al, t_flags flag)
{
	unsigned short	n;

	g_i = sizeof(unsigned short) * 2 + 2;
	if (flag.perc > g_i - 2)
		g_i = flag.perc + 2;
	g_str = ft_strnew(g_i + 1);
	n = (unsigned short)va_arg(al, unsigned int);
	while (--g_i >= 0)
	{
		g_str[g_i] = (flag.t == 'x' ? g_hex[n & 15] : g_chex[n & 15]);
		n = n >> 4;
	}
	g_i = del_zero(g_str, flag.perc);
	if (ft_strchr(flag.flag, '#') && ft_atoi(g_str + g_i))
	{
		g_str[--g_i] = flag.t;
		g_i--;
	}
	g_str = cw_strchop(g_str, g_i);
	return (g_str);
}

char	*printf_x_l(va_list al, t_flags flag)
{
	unsigned long	n;

	g_i = sizeof(unsigned long) * 2 + 2;
	if (flag.perc > g_i - 2)
		g_i = flag.perc + 2;
	g_str = ft_strnew(g_i + 1);
	n = (unsigned long)va_arg(al, unsigned long);
	while (--g_i >= 0)
	{
		g_str[g_i] = (flag.t == 'x' ? g_hex[n & 15] : g_chex[n & 15]);
		n = n >> 4;
	}
	g_i = del_zero(g_str, flag.perc);
	if (ft_strchr(flag.flag, '#') && ft_atoi(g_str + g_i))
	{
		g_str[--g_i] = flag.t;
		g_i--;
	}
	g_str = cw_strchop(g_str, g_i);
	return (g_str);
}

char	*printf_x_ll(va_list al, t_flags flag)
{
	unsigned long long	n;

	g_i = sizeof(unsigned long long) * 2 + 2;
	if (flag.perc > g_i - 2)
		g_i = flag.perc + 2;
	g_str = ft_strnew(g_i + 1);
	n = (unsigned long long)va_arg(al, unsigned long long);
	while (--g_i >= 0)
	{
		g_str[g_i] = (flag.t == 'x' ? g_hex[n & 15] : g_chex[n & 15]);
		n = n >> 4;
	}
	g_i = del_zero(g_str, flag.perc);
	if (ft_strchr(flag.flag, '#') && ft_atoi(g_str + g_i))
	{
		g_str[--g_i] = flag.t;
		g_i--;
	}
	g_str = cw_strchop(g_str, g_i);
	return (g_str);
}
