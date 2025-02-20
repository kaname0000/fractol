/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:04:01 by okaname           #+#    #+#             */
/*   Updated: 2024/11/17 18:53:35 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

int	ft_next_arg(const char *s);
int	ft_printf(const char *s, ...);
int	ft_type_arg(char c);
int	ft_write_arg(va_list *arg_ptr, int type_arg);
int	ft_putnstr(const char *s, int n);
int	ft_putnbr_hex(uintptr_t n, char *hex);
int	ft_write_p(void *p);
int	ft_putstr(const char *s);
int	ft_putnbr(long n);

#endif