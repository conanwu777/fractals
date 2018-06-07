/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:14:07 by cwu               #+#    #+#             */
/*   Updated: 2018/05/12 17:14:09 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		del_zero(char *str, int perc)
{
	short	i;
	int		d;

	i = 0;
	while (str[i] == '0')
		i++;
	d = perc - ft_strlen(str + i);
	while (d-- > 0)
		i--;
	if (str[i] == '\0' && perc)
		i--;
	return (i);
}

char	*printf_i(va_list al, t_flags flag)
{
	if (!ft_strcmp(flag.length, "hh"))
		return (printf_i_hh(al, flag));
	if (!ft_strcmp(flag.length, "h"))
		return (printf_i_h(al, flag));
	if (!ft_strcmp(flag.length, "l"))
		return (printf_i_l(al, flag));
	if (!ft_strcmp(flag.length, "ll"))
		return (printf_i_ll(al, flag));
	if (!ft_strcmp(flag.length, "j"))
		return (printf_i_j(al, flag));
	if (!ft_strcmp(flag.length, "z"))
		return (printf_i_ll(al, flag));
	else
		return (printf_i_std(al, flag));
}

char	*printf_u(va_list al, t_flags flag)
{
	if (!ft_strcmp(flag.length, "hh"))
		return (printf_u_hh(al, flag));
	if (!ft_strcmp(flag.length, "h"))
		return (printf_u_h(al, flag));
	if (!ft_strcmp(flag.length, "l"))
		return (printf_u_l(al, flag));
	if (!ft_strcmp(flag.length, "ll"))
		return (printf_u_ll(al, flag));
	if (!ft_strcmp(flag.length, "j"))
		return (printf_u_j(al, flag));
	if (!ft_strcmp(flag.length, "z"))
		return (printf_u_ll(al, flag));
	else
		return (printf_u_std(al, flag));
}

char	*printf_o(va_list al, t_flags flag)
{
	if (!ft_strcmp(flag.length, "hh"))
		return (printf_o_hh(al, flag));
	if (!ft_strcmp(flag.length, "h"))
		return (printf_o_h(al, flag));
	if (!ft_strcmp(flag.length, "l"))
		return (printf_o_l(al, flag));
	if (!ft_strcmp(flag.length, "ll"))
		return (printf_o_ll(al, flag));
	if (!ft_strcmp(flag.length, "j"))
		return (printf_o_j(al, flag));
	if (!ft_strcmp(flag.length, "z"))
		return (printf_o_ll(al, flag));
	else
		return (printf_o_std(al, flag));
}

char	*printf_x(va_list al, t_flags flag)
{
	if (!ft_strcmp(flag.length, "hh"))
		return (printf_x_hh(al, flag));
	if (!ft_strcmp(flag.length, "h"))
		return (printf_x_h(al, flag));
	if (!ft_strcmp(flag.length, "l"))
		return (printf_x_l(al, flag));
	if (!ft_strcmp(flag.length, "ll"))
		return (printf_x_ll(al, flag));
	if (!ft_strcmp(flag.length, "j"))
		return (printf_x_j(al, flag));
	if (!ft_strcmp(flag.length, "z"))
		return (printf_x_ll(al, flag));
	else
		return (printf_x_std(al, flag));
}
