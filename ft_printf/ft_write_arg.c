/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:16:52 by okaname           #+#    #+#             */
/*   Updated: 2024/11/21 21:40:45 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_arg(va_list *arg_ptr, int type_arg)
{
	char	tmp;

	if (type_arg == 1)
	{
		tmp = (char)va_arg(*arg_ptr, int);
		return (write(1, &tmp, 1));
	}
	if (type_arg == 2)
		return (ft_putstr(va_arg(*arg_ptr, char *)));
	if (type_arg == 3)
		return (ft_write_p(va_arg(*arg_ptr, void *)));
	if (type_arg == 4)
		return (ft_putnbr(va_arg(*arg_ptr, int)));
	if (type_arg == 5)
		return (ft_putnbr(va_arg(*arg_ptr, int)));
	if (type_arg == 6)
		return (ft_putnbr((unsigned int)va_arg(*arg_ptr, int)));
	if (type_arg == 7)
		return (ft_putnbr_hex((unsigned int)va_arg(*arg_ptr, int),
				"0123456789abcdef"));
	if (type_arg == 8)
		return (ft_putnbr_hex((unsigned int)va_arg(*arg_ptr, int),
				"0123456789ABCDEF"));
	return (0);
}
