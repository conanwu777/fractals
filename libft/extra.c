/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:14:40 by cwu               #+#    #+#             */
/*   Updated: 2018/05/12 17:14:41 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_table	g_emoji[] =
{	{"^_^", "😊 "},
	{":D", "😁 "},
	{"><", "🤣 "},
	{".^_^.", "🤗 "},
	{"*.*", "🤩 "},
	{"-_-", "😑 "},
	{"=(", "😢 "},
	{"=|", "😐 "},
	{"=)", "😃 "},
	{": ", "😶 "},
	{"doughnut", "🍩 "},
	{"cheese", "🧀 "},
	{"blub", "💡 "},
	{"apple", "🍎 "},
	{"lemon", "🍋 "},
	{"banana", "🍌 "},
	{"heart", "♥️ "},
	{"clove", "☘️ "},
	{"tree", "🌲 "},
	{"sun", "☀️ "},
	{"star", "⭐ "},
	{"lightning", "⚡ "},
	{"snow", "❄️ "},
	{"whale", "🐳 "},
	{"bee", "🐝 "},
	{"poop", "💩 "},
	{"eggplant", "🍆 "},
	{"peach", "🍑 "},
	{0, 0}
};

char	*printf_m(va_list al, t_flags flag)
{
	int		i;
	char	*key;
	char	*str;

	(void)flag;
	key = (char*)va_arg(al, char*);
	i = 0;
	while (g_emoji[i].key)
	{
		if (!ft_strcmp(g_emoji[i].key, key))
		{
			write(1, g_emoji[i].value, ft_strlen(g_emoji[i].value));
			break ;
		}
		i++;
	}
	str = (char*)malloc(1);
	str[0] = '\0';
	return (str);
}

char	*printf_n(va_list al, t_flags flag)
{
	int			*ptr;
	char		*str;

	str = (char*)malloc(1);
	str[0] = '\0';
	ptr = (int*)va_arg(al, int*);
	*ptr = flag.mfw;
	return (str);
}

char	*printf_percent(va_list al, t_flags flag)
{
	char *str;

	(void)flag;
	(void)al;
	str = ft_strnew(2);
	str[0] = '%';
	return (str);
}

int		cw_print(const char *restrict fmt, ...)
{
	int		g;
	int		b;
	char	str[10];

	str[0] = '\e';
	str[1] = '[';
	str[2] = '0' + (ft_strlen(fmt) + 6) / 10;
	str[3] = '0' + (ft_strlen(fmt) + 6) % 10;
	str[4] = 'D';
	str[5] = '\0';
	g = 0;
	while (++g <= 300)
	{
		b = 0;
		while (++b <= 700)
		{
			settext(2, (g / 50) % 6 + 5, (b / 100) % 11);
			ft_printf("   %s   ", fmt);
			write(1, str, 6);
			write(1, "\e[18D", 6);
		}
	}
	write(1, "\e[0m", 5);
	return (ft_printf(fmt));
}
