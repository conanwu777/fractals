/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 00:28:29 by cwu               #+#    #+#             */
/*   Updated: 2018/05/13 00:28:30 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	unicode_to_str(wchar_t t, char *str)
{
	if (t < (1 << 7))
		str[0] = (unsigned char)t;
	else if (t < (1 << 11))
	{
		str[0] = (unsigned char)((t >> 6) | 0xC0);
		str[1] = (unsigned char)((t & 0x3F) | 0x80);
	}
	else if (t < (1 << 16))
	{
		str[0] = (unsigned char)(((t >> 12)) | 0xE0);
		str[1] = (unsigned char)(((t >> 6) & 0x3F) | 0x80);
		str[2] = (unsigned char)((t & 0x3F) | 0x80);
	}
	else if (t < (1 << 21))
	{
		str[0] = (unsigned char)(((t >> 18)) | 0xF0);
		str[1] = (unsigned char)(((t >> 12) & 0x3F) | 0x80);
		str[2] = (unsigned char)(((t >> 6) & 0x3F) | 0x80);
		str[3] = (unsigned char)((t & 0x3F) | 0x80);
	}
}

int		wcharlen(wchar_t t)
{
	if (t < (1 << 7))
		return (1);
	else if (t < (1 << 11))
		return (2);
	else if (t < (1 << 16))
		return (3);
	else if (t < (1 << 21))
		return (4);
	return (0);
}

int		wstrlen(wchar_t *tmp)
{
	int		count;
	wchar_t	*t;

	count = 0;
	t = tmp;
	while (*t)
	{
		count += wcharlen(*t);
		t++;
	}
	return (count);
}

char	*printf_cap_s(va_list al, t_flags flag)
{
	wchar_t	*tmp;
	char	*str;
	int		count;
	int		i;

	if (!(tmp = (wchar_t*)va_arg(al, wchar_t*)))
		return (flag.perc ? "(null)\0" : "\0");
	str = ft_strnew(wstrlen(tmp) + 1);
	count = 0;
	i = -1;
	while (tmp[++i])
	{
		unicode_to_str(tmp[i], str + count);
		count += wcharlen(tmp[i]);
	}
	count = 0;
	if (flag.perc != -1 && (int)ft_strlen(str) > flag.perc)
	{
		i = 0;
		while (count <= flag.perc && tmp[i])
			count += wcharlen(tmp[i]);
		str[count - wcharlen(tmp[i])] = '\0';
	}
	return (str);
}
