/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:13:09 by cwu               #+#    #+#             */
/*   Updated: 2018/05/12 17:13:10 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*printf_o_std(va_list al, t_flags flag)
{
	unsigned int	n;
	char			*str;
	int				i;

	n = va_arg(al, unsigned int);
	i = sizeof(int) * 4 + 1;
	str = (char*)malloc(i + 1);
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = '0' + (n & 7);
		n = n >> 3;
	}
	i = del_zero(str, flag.perc);
	if ((ft_strchr(flag.flag, '#') &&
		((flag.perc == -1 && ft_atoi(str)) || (flag.perc == 0)))
		|| (!ft_atoi(str) && flag.perc > 0))
		i--;
	str = cw_strchop(str, i);
	return (str);
}

char	*printf_o_hh(va_list al, t_flags flag)
{
	unsigned char	n;
	char			*str;
	int				i;

	n = (unsigned char)va_arg(al, unsigned int);
	i = sizeof(unsigned char) * 4 + 1;
	str = (char*)malloc(i + 1);
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = '0' + (n & 7);
		n = n >> 3;
	}
	i = del_zero(str, flag.perc);
	if ((ft_strchr(flag.flag, '#') &&
		((flag.perc == -1 && ft_atoi(str)) || (flag.perc == 0)))
		|| (!ft_atoi(str) && flag.perc > 0))
		i--;
	str = cw_strchop(str, i);
	return (str);
}

char	*printf_o_h(va_list al, t_flags flag)
{
	unsigned short	n;
	char			*str;
	int				i;

	n = (unsigned short)va_arg(al, unsigned int);
	i = sizeof(unsigned short) * 4 + 1;
	str = (char*)malloc(i + 1);
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = '0' + (n & 7);
		n = n >> 3;
	}
	i = del_zero(str, flag.perc);
	if ((ft_strchr(flag.flag, '#') &&
		((flag.perc == -1 && ft_atoi(str)) || (flag.perc == 0)))
		|| (!ft_atoi(str) && flag.perc > 0))
		i--;
	str = cw_strchop(str, i);
	return (str);
}

char	*printf_o_l(va_list al, t_flags flag)
{
	unsigned long	n;
	char			*str;
	int				i;

	n = (unsigned long)va_arg(al, unsigned long);
	i = sizeof(unsigned long) * 4 + 1;
	str = (char*)malloc(i + 1);
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = '0' + (n & 7);
		n = n >> 3;
	}
	i = del_zero(str, flag.perc);
	if ((ft_strchr(flag.flag, '#') &&
		((flag.perc == -1 && ft_atoi(str)) || (flag.perc == 0)))
		|| (!ft_atoi(str) && flag.perc > 0))
		i--;
	str = cw_strchop(str, i);
	return (str);
}

char	*printf_o_ll(va_list al, t_flags flag)
{
	unsigned long long	n;
	char				*str;
	int					i;

	n = (unsigned long long)va_arg(al, unsigned long long);
	i = sizeof(unsigned long long) * 4 + 1;
	str = (char*)malloc(i + 1);
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = '0' + (n & 7);
		n = n >> 3;
	}
	i = del_zero(str, flag.perc);
	if ((ft_strchr(flag.flag, '#') &&
		((flag.perc == -1 && ft_atoi(str)) || (flag.perc == 0)))
		|| (!ft_atoi(str) && flag.perc > 0))
		i--;
	str = cw_strchop(str, i);
	return (str);
}
