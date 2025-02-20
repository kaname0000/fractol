/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:44:26 by okaname           #+#    #+#             */
/*   Updated: 2024/11/13 02:51:59 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ismean(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X')
		return (1);
	return (0);
}

int	ft_next_arg(const char *s)
{
	int	i;
	int	percent_flag;

	i = 0;
	percent_flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
			percent_flag++;
		if (percent_flag % 2 == 1 && ft_ismean(s[i]))
		{
			return (i);
		}
		if (s[i] != '%')
			percent_flag = 0;
		i++;
	}
	return (-1);
}
