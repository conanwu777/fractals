/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base10_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:11:25 by cwu               #+#    #+#             */
/*   Updated: 2018/05/12 17:11:31 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*g_str;
static short	g_i;
static short	g_neg;

char	*printf_i_std(va_list al, t_flags flag)
{
	int		n;

	n = va_arg(al, int);
	g_i = sizeof(int) * 4;
	g_str = ft_strnew(g_i + 1);
	g_neg = (n < 0 ? -1 : 1);
	while (--g_i >= 0)
	{
		g_str[g_i] = '0' + g_neg * (n % 10);
		n /= 10;
	}
	g_i = del_zero(g_str, flag.perc);
	if (g_neg == -1)
		g_str[--g_i] = '-';
	else if (ft_strchr(flag.flag, '+'))
		g_str[--g_i] = '+';
	else if (ft_strchr(flag.flag, ' '))
		g_str[--g_i] = ' ';
	g_str = cw_strchop(g_str, g_i);
	return (g_str);
}

char	*printf_i_hh(va_list al, t_flags flag)
{
	signed char	n;

	n = (signed char)va_arg(al, int);
	g_i = sizeof(signed char) * 4;
	g_str = ft_strnew(g_i + 1);
	g_neg = (n < 0 ? -1 : 1);
	while (--g_i >= 0)
	{
		g_str[g_i] = '0' + g_neg * (n % 10);
		n /= 10;
	}
	g_i = del_zero(g_str, flag.perc);
	if (g_neg == -1)
		g_str[--g_i] = '-';
	else if (ft_strchr(flag.flag, '+'))
		g_str[--g_i] = '+';
	else if (ft_strchr(flag.flag, ' '))
		g_str[--g_i] = ' ';
	g_str = cw_strchop(g_str, g_i);
	return (g_str);
}

char	*printf_i_h(va_list al, t_flags flag)
{
	short	n;

	n = (short)va_arg(al, int);
	g_i = sizeof(short) * 4;
	g_str = ft_strnew(g_i + 1);
	g_neg = (n < 0 ? -1 : 1);
	while (--g_i >= 0)
	{
		g_str[g_i] = '0' + g_neg * (n % 10);
		n /= 10;
	}
	g_i = del_zero(g_str, flag.perc);
	if (g_neg == -1)
		g_str[--g_i] = '-';
	else if (ft_strchr(flag.flag, '+'))
		g_str[--g_i] = '+';
	else if (ft_strchr(flag.flag, ' '))
		g_str[--g_i] = ' ';
	g_str = cw_strchop(g_str, g_i);
	return (g_str);
}

char	*printf_i_l(va_list al, t_flags flag)
{
	long	n;

	n = va_arg(al, long);
	g_i = sizeof(long) * 4;
	g_str = ft_strnew(g_i + 1);
	g_neg = (n < 0 ? -1 : 1);
	while (--g_i >= 0)
	{
		g_str[g_i] = '0' + g_neg * (n % 10);
		n /= 10;
	}
	g_i = del_zero(g_str, flag.perc);
	if (g_neg == -1)
		g_str[--g_i] = '-';
	else if (ft_strchr(flag.flag, '+'))
		g_str[--g_i] = '+';
	else if (ft_strchr(flag.flag, ' '))
		g_str[--g_i] = ' ';
	g_str = cw_strchop(g_str, g_i);
	return (g_str);
}

char	*printf_i_ll(va_list al, t_flags flag)
{
	long long	n;

	n = va_arg(al, long long);
	g_i = sizeof(long long) * 4;
	g_str = ft_strnew(g_i + 1);
	g_neg = (n < 0 ? -1 : 1);
	while (--g_i >= 0)
	{
		g_str[g_i] = '0' + g_neg * (n % 10);
		n /= 10;
	}
	g_i = del_zero(g_str, flag.perc);
	if (g_neg == -1)
		g_str[--g_i] = '-';
	else if (ft_strchr(flag.flag, '+'))
		g_str[--g_i] = '+';
	else if (ft_strchr(flag.flag, ' '))
		g_str[--g_i] = ' ';
	g_str = cw_strchop(g_str, g_i);
	return (g_str);
}
