/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:45:06 by okaname           #+#    #+#             */
/*   Updated: 2025/02/23 16:12:04 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_check_convergence3(double i, double j)
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
		if (x < 0)
			x *= -1;
		if (y < 0)
			y *= -1;
		tmp = y;
		y = 2 * x * y + j;
		x = x * x - tmp * tmp + i;
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
	int		color;

	scale = 4.0 / (data->zoom * WIDTH);
	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < WIDTH)
		{
			result = ft_check_convergence3((i - MIDDLE) * scale + (data->x
						/ 250), (j - MIDDLE) * scale + (data->y / 250));
			color = (result) << 16 | (result * 10) << 8 | (result * 15);
			my_mlx_pixel_put(data, i, j, color);
			j++;
		}
		i++;
	}
}
