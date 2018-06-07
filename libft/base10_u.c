/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base10_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:11:58 by cwu               #+#    #+#             */
/*   Updated: 2018/05/12 17:12:01 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*g_str;
static int		g_i;

char	*printf_u_std(va_list al, t_flags flag)
{
	unsigned	n;

	n = va_arg(al, unsigned int);
	g_i = sizeof(unsigned int) * 4;
	if (!(g_str = (char*)malloc(g_i + 1)))
		return (NULL);
	g_str[g_i] = '\0';
	while (--g_i >= 0)
	{
		g_str[g_i] = '0' + n % 10;
		n /= 10;
	}
	g_i = del_zero(g_str, flag.perc);
	g_str = cw_strchop(g_str, g_i);
	return (g_str);
}

char	*printf_u_hh(va_list al, t_flags flag)
{
	unsigned char	n;

	n = (unsigned char)va_arg(al, unsigned int);
	g_i = sizeof(unsigned char) * 4;
	if (!(g_str = (char*)malloc(g_i + 1)))
		return (NULL);
	g_str[g_i] = '\0';
	while (--g_i >= 0)
	{
		g_str[g_i] = '0' + n % 10;
		n /= 10;
	}
	g_i = del_zero(g_str, flag.perc);
	g_str = cw_strchop(g_str, g_i);
	return (g_str);
}

char	*printf_u_h(va_list al, t_flags flag)
{
	unsigned short	n;

	n = (unsigned short)va_arg(al, unsigned int);
	g_i = sizeof(unsigned short) * 4;
	if (!(g_str = (char*)malloc(g_i + 1)))
		return (NULL);
	g_str[g_i] = '\0';
	while (--g_i >= 0)
	{
		g_str[g_i] = '0' + n % 10;
		n /= 10;
	}
	g_i = del_zero(g_str, flag.perc);
	g_str = cw_strchop(g_str, g_i);
	return (g_str);
}

char	*printf_u_l(va_list al, t_flags flag)
{
	unsigned long	n;

	n = (unsigned long)va_arg(al, unsigned long);
	g_i = sizeof(unsigned long) * 4;
	if (!(g_str = (char*)malloc(g_i + 1)))
		return (NULL);
	g_str[g_i] = '\0';
	while (--g_i >= 0)
	{
		g_str[g_i] = '0' + n % 10;
		n /= 10;
	}
	g_i = del_zero(g_str, flag.perc);
	g_str = cw_strchop(g_str, g_i);
	return (g_str);
}

char	*printf_u_ll(va_list al, t_flags flag)
{
	unsigned long long	n;

	n = (unsigned long long)va_arg(al, unsigned long long);
	g_i = sizeof(unsigned long long) * 4;
	if (!(g_str = (char*)malloc(g_i + 1)))
		return (NULL);
	g_str[g_i] = '\0';
	while (--g_i >= 0)
	{
		g_str[g_i] = '0' + n % 10;
		n /= 10;
	}
	g_i = del_zero(g_str, flag.perc);
	g_str = cw_strchop(g_str, g_i);
	return (g_str);
}
