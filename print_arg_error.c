/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:26:31 by okaname           #+#    #+#             */
/*   Updated: 2025/02/23 15:36:58 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_print_arg_error(void)
{
	write(2, "write like this\n\n", 17);
	write(2, "./fractol mandelbrot\n\n", 22);
	write(2, "./fractol ship\n\n", 16);
	write(2, "if you choose julia\n\n", 21);
	write(2, "./fractol julia double double\n", 30);
}
