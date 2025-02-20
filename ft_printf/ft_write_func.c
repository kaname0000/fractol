/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:24:14 by okaname           #+#    #+#             */
/*   Updated: 2024/11/17 20:13:04 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnstr(const char *s, int n)
{
	int	i;
	int	percent_flag;
	int	percent_count;

	percent_count = 0;
	percent_flag = 0;
	i = 0;
	while (s[i] != '\0' && i < n)
	{
		if (s[i] == '%')
			percent_flag++;
		if (s[i] != '%' || percent_flag % 2)
			write(1, &s[i], 1);
		else
		{
			percent_flag = 0;
			percent_count++;
		}
		i++;
	}
	return (i - percent_count);
}

int	ft_putnbr_hex(unsigned long n, char *hex)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_putnbr_hex(n / 16, hex);
	count += write(1, &hex[n % 16], 1);
	return (count);
}

int	ft_write_p(void *p)
{
	unsigned long	l_p;

	if (p == 0)
		return (write(1, "(nil)", 5));
	l_p = (unsigned long)p;
	write(1, "0x", 2);
	return (ft_putnbr_hex(l_p, "0123456789abcdef") + 2);
}

int	ft_putstr(const char *s)
{
	int	i;
	int	percent_flag;
	int	percent_count;

	percent_count = 0;
	percent_flag = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
			percent_flag++;
		if (s[i] != '%' || percent_flag % 2)
			write(1, &s[i], 1);
		else
		{
			percent_flag = 0;
			percent_count++;
		}
		i++;
	}
	return (i - percent_count);
}

int	ft_putnbr(long n)
{
	char	num;
	int		count;

	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		if (n == -2147483648)
		{
			write(1, "2147483648", 10);
			return (11);
		}
		n = -n;
	}
	if (n > 9)
	{
		count += ft_putnbr(n / 10);
	}
	num = (n % 10 + '0');
	count += write(1, &num, 1);
	return (count);
}
