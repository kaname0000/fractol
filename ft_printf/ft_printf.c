/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:41:18 by okaname           #+#    #+#             */
/*   Updated: 2024/11/21 18:24:01 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	arg_ptr;
	int		next_arg;
	int		i;
	int		count;

	i = 0;
	next_arg = 0;
	count = 0;
	if (s == NULL)
		return (-1);
	va_start(arg_ptr, s);
	while (next_arg != -1)
	{
		next_arg = ft_next_arg(&s[i]);
		if (next_arg != -1)
		{
			count += ft_putnstr(&s[i], next_arg - 1);
			i += next_arg;
			count += ft_write_arg(&arg_ptr, ft_type_arg(s[i]));
			i++;
		}
	}
	count += ft_putstr(&s[i]);
	va_end(arg_ptr);
	return (count);
}
