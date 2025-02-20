/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:38:31 by okaname           #+#    #+#             */
/*   Updated: 2025/02/19 18:02:57 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb <= 0)
	{
		return (0);
	}
	while (i <= (nb / i))
	{
		if (nb == i * i)
		{
			return (i);
		}
		i++;
	}
	return (i);
}

void	ft_squared(float *x, float *y, float a, float b)
{
	float	tmp;

	tmp = (*x);
	(*x) = (*x) * (*x) - (*y) * (*y) + a;
	(*y) = 2 * tmp * (*y) + b;
}
