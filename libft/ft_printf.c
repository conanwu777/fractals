/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:13:39 by cwu               #+#    #+#             */
/*   Updated: 2018/05/12 17:13:40 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_conv	g_conv[] =
{	{'i', &printf_i},
	{'d', &printf_i},
	{'D', &printf_i_l},
	{'u', &printf_u},
	{'U', &printf_u_l},
	{'o', &printf_o},
	{'O', &printf_o_l},
	{'x', &printf_x},
	{'X', &printf_x},
	{'c', &printf_c},
	{'C', &printf_c},
	{'s', &printf_s},
	{'S', &printf_cap_s},
	{'p', &printf_p},
	{'%', &printf_percent},
	{'n', &printf_n},
	{'m', &printf_m},
	{0, 0}
};
static t_flags	g_f;
static va_list	g_al;
static fptr		g_function;
static int		g_ret;
static int		g_i;
static char		*g_str;
static char		*g_t;
static int		g_color;

static fptr		ft_switch(char c)
{
	g_i = 0;
	while (g_conv[g_i].c && g_conv[g_i].c != c)
		g_i++;
	return (g_conv[g_i].c == c ? g_conv[g_i].f : 0);
}

static char		*getflags(char *t)
{
	g_i = 0;
	while (*t == ' ' || *t == '#' || *t == '0' || *t == '-' || *t == '+')
		g_f.flag[g_i++] = *t++;
	g_f.flag[g_i] = '\0';
	if (ft_strchr(g_f.flag, '-') && ft_strchr(g_f.flag, '0'))
		*ft_strchr(g_f.flag, '0') = '-';
	g_f.mfw = (ft_isdigit(*t) ? ft_atoi(t) : -1);
	(*t == '*' ? g_f.mfw = (int)va_arg(g_al, int) : 1);
	while (ft_isdigit(*t) || *t == '*')
		t++;
	g_f.perc = (*t == '.' ? ft_atoi(++t) : -1);
	while (ft_isdigit(*t))
		t++;
	g_i = 0;
	while (*t == 'h' || *t == 'l' || *t == 'j' || *t == 'z')
		g_f.length[g_i++] = *t++;
	g_f.length[g_i] = '\0';
	g_f.length[2] = '\0';
	while (*t == ' ')
		t++;
	if ((g_f.t = *t) == 'n')
		g_f.mfw = g_ret;
	if (*t != '\0')
		t++;
	return (t);
}

static char		*print_prefix(char *tmp)
{
	g_i = 0;
	if (ft_strchr(g_f.flag, '0') && g_f.perc == -1)
	{
		if (g_f.t == 'd' && (*tmp == '-' || *tmp == '+' || *tmp == ' '))
		{
			write(1, tmp, 1);
			g_i += 1;
		}
		if ((g_f.t == 'x' && *(tmp + 1) && *(tmp + 1) == 'x')
			|| (g_f.t == 'X' && *(tmp + 1) && *(tmp + 1) == 'X')
			|| (g_f.t == 'p' && *(tmp + 1) && *(tmp + 1) == 'x'))
		{
			write(1, tmp, 2);
			g_i += 2;
		}
	}
	tmp = cw_strchop(tmp, g_i);
	return (tmp);
}

static int		print_arg(char *tmp)
{
	int		r;
	int		len;
	int		d;
	char	c;

	if (g_f.t == 'n')
		return (0);
	len = (((g_f.t == 'c' || g_f.t == 'C') && !ft_strlen(tmp)) ?
		1 : ft_strlen(tmp));
	r = len;
	c = ((ft_strchr(g_f.flag, '0') && g_f.perc <= 0) ? '0' : ' ');
	(ft_strchr(g_f.flag, '-') ? write(1, tmp, len) : 1);
	if ((d = g_f.mfw - len) > 0)
	{
		r += d;
		tmp = print_prefix(tmp);
		len = ((g_f.t != 'c' || ft_strlen(tmp)) ? ft_strlen(tmp) : 1);
		while (d--)
			write(1, &c, 1);
	}
	if (!ft_strchr(g_f.flag, '-'))
		write(1, tmp, len);
	if (ft_strcmp(tmp, "(null)\0"))
		ft_strdel(&tmp);
	return (r);
}

int				ft_printf(const char *restrict fmt, ...)
{
	g_ret = 0;
	g_color = ((setcolor(fmt) - fmt) ? 1 : 0);
	fmt = setcolor(fmt);
	va_start(g_al, fmt);
	while ((g_t = ft_strchr(fmt, '%')))
	{
		write(1, fmt, g_t - fmt);
		g_ret += g_t - fmt;
		fmt = getflags(g_t + 1);
		if (g_f.t)
		{
			if (!(g_function = ft_switch(g_f.t)))
			{
				g_str = ft_strnew(2);
				g_str[0] = g_f.t;
			}
			else
				g_str = g_function(g_al, g_f);
			g_ret += print_arg(g_str);
		}
	}
	va_end(g_al);
	write(1, fmt, ft_strlen(fmt));
	(g_color ? write(1, "\e[0m", 4) : 1);
	return (g_ret + ft_strlen(fmt));
}
