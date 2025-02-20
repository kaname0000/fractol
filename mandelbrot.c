/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:59:40 by okaname           #+#    #+#             */
/*   Updated: 2025/02/20 21:19:09 by okaname          ###   ########.fr       */
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
	while (n < 200)
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
			result = ft_check_convergence1((i - 500 + (data->x)) * scale, (j
						- 500 + (data->y)) * scale);
			if (result == 0)
				my_mlx_pixel_put(data, i, j, 0x00FF0000);
			j++;
		}
		i++;
	}
}

// void	ft_mandelbrot1(t_data *data)
// {
// 	double	scale = 1.0 / ;
// 	int		width = WIDTH;
// 	int		height = WIDTH;
// 	int		i, j, result;

// 	for (i = 0; i < width; i++)
// 	{
// 		double x0 = (i - width / 2) * scale + data->x;
// 		for (j = 0; j < height; j++)
// 		{
// 			double y0 = (j - height / 2) * scale + data->y;
// 			result = ft_check_convergence1(x0, y0);
// 			if (result == 400)
// 				my_mlx_pixel_put(data, i, j, 0x00FF0000);
// 		}
// 	}
// }

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
			result = ft_check_convergence1((i - MIDDLE + (data->x)) * scale, (j
						- MIDDLE + (data->y)) * scale);
			if (result == 0)
				color = 0x000000;
			else
				color = (result * 1) << 16 | (result * 10) << 8 | (result * 15);
			my_mlx_pixel_put(data, i, j, color);
			j++;
		}
		i++;
	}
}
