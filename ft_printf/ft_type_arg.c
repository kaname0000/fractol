/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:08:29 by okaname           #+#    #+#             */
/*   Updated: 2024/11/13 02:51:57 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_arg(char c)
{
	if (c == 'c')
		return (1);
	if (c == 's')
		return (2);
	if (c == 'p')
		return (3);
	if (c == 'd')
		return (4);
	if (c == 'i')
		return (5);
	if (c == 'u')
		return (6);
	if (c == 'x')
		return (7);
	if (c == 'X')
		return (8);
	return (0);
}
