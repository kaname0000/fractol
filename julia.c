/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:46:57 by okaname           #+#    #+#             */
/*   Updated: 2025/02/23 16:28:38 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// static int	ft_check_convergence2(t_data *data, int i, int j)
// {
// 	int		n;
// 	float	x;
// 	float	y;
// 	float	tmp;

// 	n = 0;
// 	x = (i / (1000 / 4.0)) - 2;
// 	y = (j / (1000 / 4.0)) - 2;
// 	while (n < 100)
// 	{
// 		if (x * x + y * y >= 4)
// 		{
// 			if (n % 2 == 1)
// 				return (1);
// 			return (2);
// 		}
// 		tmp = y;
// 		y = 2 * x * y + data->a;
// 		x = (x * x - tmp * tmp) + data->b;
// 		n++;
// 	}
// 	return (0);
// }

// void	ft_julia(t_data *data)
// {
// 	double	scale;
// 	int		i;
// 	int		j;
// 	int		result;

// 	scale = 1.0 / data->zoom;
// 	i = 0;
// 	while (i < 1000)
// 	{
// 		j = 0;
// 		while (j < 1000)
// 		{
// 			result = ft_check_convergence2(data, ((i - (1000 / 2))) * scale
// 					+ data->x, ((j - (1000 / 2))) * scale + data->y);
// 			if (result == 1)
// 				my_mlx_pixel_put(data, i, j, 0x0000BFFF);
// 			else if (result == 2)
// 				my_mlx_pixel_put(data, i, j, 0x0000FA9A);
// 			j++;
// 		}
// 		i++;
// 	}
// }

static int	ft_check_convergence2(t_data *data, double i, double j)
{
	int		n;
	double	x;
	double	y;
	double	tmp;

	n = 0;
	x = i;
	y = j;
	while (n < 200)
	{
		if (x * x + y * y >= 4)
			return (n);
		tmp = y;
		y = 2 * x * y + data->b;
		x = (x * x - tmp * tmp) + data->a;
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
	int		color;

	scale = 4.0 / (data->zoom * WIDTH);
	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < WIDTH)
		{
			result = ft_check_convergence2(data, (i - MIDDLE) * scale + (data->x
						/ 250), (j - MIDDLE) * scale + (data->y / 250));
			color = (result * 15) << 16 | (result * 5) << 8 | (result);
			my_mlx_pixel_put(data, i, j, color);
			j++;
		}
		i++;
	}
}
