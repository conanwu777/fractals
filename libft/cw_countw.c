/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_countw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 00:04:33 by cwu               #+#    #+#             */
/*   Updated: 2018/04/17 00:04:34 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cw_countw(char const *s, char c)
{
	int start;
	int count;

	count = 0;
	while (*s)
	{
		start = 1;
		while (*s && *s == c)
		{
			start = 0;
			s++;
		}
		while (*s && *s != c)
		{
			start = 1;
			s++;
		}
		(start ? count++ : 1);
	}
	return (count);
}
