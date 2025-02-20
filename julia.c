/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:46:57 by okaname           #+#    #+#             */
/*   Updated: 2025/02/20 16:24:06 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_check_convergence2(t_data *data, int i, int j)
{
	int		n;
	float	x;
	float	y;
	float	tmp;

	n = 0;
	x = (i / (1000 / 4.0)) - 2;
	y = (j / (1000 / 4.0)) - 2;
	while (n < 100)
	{
		if (x * x + y * y >= 4)
		{
			if (n % 2 == 1)
				return (1);
			return (2);
		}
		tmp = y;
		y = 2 * x * y + data->a;
		x = (x * x - tmp * tmp) + data->b;
		n++;
	}
	return (0);
}

void	ft_julia(t_data *data)
{
	double	scale;
	int		i;
	int		j;
	int		result;

	scale = 1.0 / data->zoom;
	i = 0;
	while (i < 1000)
	{
		j = 0;
		while (j < 1000)
		{
			result = ft_check_convergence2(data, ((i - (1000 / 2)) + data->x)
					* scale, ((j - (1000 / 2)) + data->y) * scale);
			if (result == 1)
				my_mlx_pixel_put(data, i, j, 0x0000BFFF);
			else if (result == 2)
				my_mlx_pixel_put(data, i, j, 0x0000FA9A);
			j++;
		}
		i++;
	}
}
