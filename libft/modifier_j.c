/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier_j.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:42:07 by cwu               #+#    #+#             */
/*   Updated: 2018/05/12 17:42:10 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*g_hex = "0123456789abcdef";
static char			*g_chex = "0123456789ABCDEF";
static char			*g_str;
static int			g_i;

char	*printf_i_j(va_list al, t_flags flag)
{
	intmax_t	n;
	short		neg;

	n = (intmax_t)va_arg(al, intmax_t);
	g_i = sizeof(intmax_t) * 4;
	g_str = ft_strnew(g_i + 1);
	g_str[g_i] = '\0';
	neg = (n < 0 ? -1 : 1);
	while (--g_i >= 0)
	{
		g_str[g_i] = '0' + neg * (n % 10);
		n /= 10;
	}
	while (g_str[++g_i] == '0')
		;
	if (neg == -1)
		g_str[--g_i] = '-';
	if (g_str[g_i] == '\0')
		g_i--;
	if (neg == 1 && ft_strchr(flag.flag, '+'))
		g_str[--g_i] = '+';
	g_str = cw_strchop(g_str, g_i);
	return (g_str);
}

char	*printf_u_j(va_list al, t_flags flag)
{
	uintmax_t	n;

	(void)flag;
	n = (uintmax_t)va_arg(al, uintmax_t);
	g_i = sizeof(uintmax_t) * 4;
	if (!(g_str = (char*)malloc(g_i + 1)))
		return (NULL);
	g_str[g_i] = '\0';
	while (--g_i >= 0)
	{
		g_str[g_i] = '0' + n % 10;
		n /= 10;
	}
	while (g_str[++g_i] == '0')
		;
	if (g_str[g_i] == '\0')
		g_i--;
	g_str = cw_strchop(g_str, g_i);
	return (g_str);
}

char	*printf_o_j(va_list al, t_flags flag)
{
	uintmax_t	n;

	n = (uintmax_t)va_arg(al, uintmax_t);
	g_i = sizeof(uintmax_t) * 4;
	g_str = (char*)malloc(g_i + 1);
	g_str[g_i] = '\0';
	while (--g_i >= 0)
	{
		g_str[g_i] = '0' + (n & 7);
		n = n >> 3;
	}
	while (g_str[++g_i] == '0')
		;
	if (g_str[g_i] == '\0' || ft_strchr(flag.flag, '#'))
		g_i--;
	g_str = cw_strchop(g_str, g_i);
	return (g_str);
}

char	*printf_x_j(va_list al, t_flags flag)
{
	uintmax_t	n;

	g_i = sizeof(uintmax_t) * 2 + 2;
	g_str = ft_strnew(g_i + 1);
	n = (uintmax_t)va_arg(al, uintmax_t);
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
