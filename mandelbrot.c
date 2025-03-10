/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:59:40 by okaname           #+#    #+#             */
/*   Updated: 2025/02/23 16:14:13 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_check_convergence1(double i, double j)
{
	int		n;
	double	x;
	double	y;
	double	tmp;

	n = 0;
	x = 0;
	y = 0;
	while (n < 400)
	{
		if (x * x + y * y >= 4)
			return (n);
		tmp = y;
		y = 2 * x * y + j;
		x = x * x - tmp * tmp + i;
		n++;
	}
	return (0);
}

void	ft_mandelbrot1(t_data *data)
{
	double	scale;
	int		i;
	int		j;
	int		result;

	scale = 4.0 / (data->zoom * WIDTH);
	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < WIDTH)
		{
			result = ft_check_convergence1((i - MIDDLE) * scale + (data->x)
					/ 250, (j - MIDDLE) * scale + (data->y) / 250);
			if (result == 0)
				my_mlx_pixel_put(data, i, j, 0x00FF0000);
			j++;
		}
		i++;
	}
}

void	ft_mandelbrot2(t_data *data)
{
	double	scale;
	int		i;
	int		j;
	int		result;
	int		color;

	scale = 4.0 / (data->zoom * WIDTH);
	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < WIDTH)
		{
			result = ft_check_convergence1((i - MIDDLE) * scale + (data->x
						/ 250), (j - MIDDLE) * scale + (data->y / 250));
			color = (result) << 16 | (result * 10) << 8 | (result * 15);
			my_mlx_pixel_put(data, i, j, color);
			j++;
		}
		i++;
	}
}
