/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:45:06 by okaname           #+#    #+#             */
/*   Updated: 2025/02/20 16:26:38 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_check_convergence3(int i, int j)
{
	int		n;
	float	x;
	float	y;

	n = 0;
	x = 0;
	y = 0;
	while (n < 100)
	{
		if (x * x + y * y >= 4)
		{
			if (n % 2 == 1)
				return (1);
			return (2);
		}
		if (x < 0)
			x *= -1;
		if (y < 0)
			y *= -1;
		ft_squared(&x, &y, (i / (1000 / 4.0)) - 2, (j / (1000 / 4.0)) - 2);
		n++;
	}
	return (0);
}

void	ft_ship(t_data *data)
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
			result = ft_check_convergence3((i - (1000 / 2) + data->x) * scale,
					(j - (1000 / 2) + data->y) * scale);
			if (result == 1)
				my_mlx_pixel_put(data, i, j, 0x00FF00FF);
			else if (result == 2)
				my_mlx_pixel_put(data, i, j, 0x00FF0000);
			j++;
		}
		i++;
	}
}
