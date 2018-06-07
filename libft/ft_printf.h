/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:15:18 by cwu               #+#    #+#             */
/*   Updated: 2018/05/12 17:15:20 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <wchar.h>
# include <limits.h>
# include <locale.h>
# include "libft.h"

typedef struct	s_flags
{
	char		flag[5];
	int			mfw;
	int			perc;
	char		length[3];
	char		t;
}				t_flags;

typedef char	*(*fptr)(va_list, t_flags flag);

typedef	struct 	s_conv
{
	char		c;
	fptr		f;
}				t_conv;

typedef	struct 	s_table
{
	char		*key;
	char		*value;
}				t_table;

void			settext(int r, int g, int b);
void			setbackground(int r, int g, int b);
char			*setcolor(const char *restrict fmt);
void			print_color_block(int r, int g, int b);
int				del_zero(char *str, int perc);
void			unicode_to_str(wchar_t t, char *str);
int				wcharlen(wchar_t t);
int				wstrlen(wchar_t *tmp);
char			*printf_i(va_list al, t_flags flag);
char			*printf_i_std(va_list al, t_flags flag);
char			*printf_i_hh(va_list al, t_flags flag);
char			*printf_i_h(va_list al, t_flags flag);
char			*printf_i_l(va_list al, t_flags flag);
char			*printf_i_ll(va_list al, t_flags flag);
char			*printf_i_j(va_list al, t_flags flag);
char			*printf_c(va_list al, t_flags flag);
char			*printf_c(va_list al, t_flags flag);
char			*printf_cap_c(va_list al, t_flags flag);
char			*printf_s(va_list al, t_flags flag);
char			*printf_cap_s(va_list al, t_flags flag);
char			*printf_o(va_list al, t_flags flag);
char			*printf_o_std(va_list al, t_flags flag);
char			*printf_o_hh(va_list al, t_flags flag);
char			*printf_o_h(va_list al, t_flags flag);
char			*printf_o_l(va_list al, t_flags flag);
char			*printf_o_ll(va_list al, t_flags flag);
char			*printf_o_j(va_list al, t_flags flag);
char			*printf_x(va_list al, t_flags flag);
char			*printf_x_std(va_list al, t_flags flag);
char			*printf_x_hh(va_list al, t_flags flag);
char			*printf_x_h(va_list al, t_flags flag);
char			*printf_x_l(va_list al, t_flags flag);
char			*printf_x_ll(va_list al, t_flags flag);
char			*printf_x_j(va_list al, t_flags flag);
char			*printf_c_x(va_list al, t_flags flag);
char			*printf_c_x_std(va_list al, t_flags flag);
char			*printf_c_x_hh(va_list al, t_flags flag);
char			*printf_c_x_h(va_list al, t_flags flag);
char			*printf_c_x_l(va_list al, t_flags flag);
char			*printf_c_x_ll(va_list al, t_flags flag);
char			*printf_c_x_j(va_list al, t_flags flag);
char			*printf_u(va_list al, t_flags flag);
char			*printf_u_std(va_list al, t_flags flag);
char			*printf_u_hh(va_list al, t_flags flag);
char			*printf_u_h(va_list al, t_flags flag);
char			*printf_u_l(va_list al, t_flags flag);
char			*printf_u_ll(va_list al, t_flags flag);
char			*printf_u_j(va_list al, t_flags flag);
char			*printf_p(va_list al, t_flags flag);
char			*printf_percent(va_list al, t_flags flag);
char			*printf_n(va_list al, t_flags flag);
char			*printf_m(va_list al, t_flags flag);
int				ft_printf(const char *restrict fmt, ...);
int				cw_print(const char *restrict fmt, ...);

#endif
