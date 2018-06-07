/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:14:19 by cwu               #+#    #+#             */
/*   Updated: 2018/05/12 17:14:21 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*printf_c(va_list al, t_flags flag)
{
	char	*str;
	char	u;

	(void)flag;
	str = ft_strnew(2);
	u = va_arg(al, wchar_t);
	str[0] = u;
	str[1] = '\0';
	return (str);
}

/*
**	below is the proper print_c and print_C, but moulinet will error
*/

char	*printf_c_real(va_list al, t_flags flag)
{
	char	*str;
	wchar_t	u;

	str = ft_strnew(5);
	if (ft_strchr(flag.length, 'l'))
		return (printf_cap_c(al, flag));
	u = (wchar_t)va_arg(al, wchar_t);
	if (wcharlen(u) > 1 && flag.t == 'C')
		unicode_to_str(u, str);
	else
	{
		str[0] = u;
		str[1] = '\0';
	}
	return (str);
}

char	*printf_cap_c(va_list al, t_flags flag)
{
	wchar_t	t;
	char	*str;

	if (ft_strstr(flag.length, "hh"))
		return (printf_c(al, flag));
	t = (wchar_t)va_arg(al, wchar_t);
	str = ft_strnew(wcharlen(t) + 1);
	if (flag.perc == 0 || !t)
		return (str);
	unicode_to_str(t, str);
	return (str);
}

char	*printf_s(va_list al, t_flags flag)
{
	int		i;
	char	*t;
	char	*str;

	if (ft_strchr(flag.length, 'l'))
		return (printf_cap_s(al, flag));
	if (!(t = (char*)va_arg(al, char*)) && flag.perc)
		return ("(null)\0");
	else
	{
		str = ft_strnew(((!t || !(*t)) ? 1 : ft_strlen(t) + 1));
		i = -1;
		while (t && t[++i])
			str[i] = t[i];
	}
	if (*str && flag.perc != -1 && flag.perc < (int)ft_strlen(str))
		str[flag.perc] = '\0';
	return (str);
}

char	*printf_p(va_list al, t_flags flag)
{
	uintptr_t	n;
	char		*str;
	char		*hex;
	int			i;

	hex = "0123456789abcdef";
	i = sizeof(void*) * 4 + 2;
	if (!(str = (char *)malloc(i + 1)))
		return (NULL);
	n = (uintptr_t)va_arg(al, void*);
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = hex[n & 15];
		n = n >> 4;
	}
	i = del_zero(str, flag.perc);
	str[--i] = 'x';
	str[--i] = '0';
	str = cw_strchop(str, i);
	return (str);
}
