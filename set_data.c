/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:54:39 by okaname           #+#    #+#             */
/*   Updated: 2025/02/20 21:17:00 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_set_mandelbrot(t_data *data)
{
	data->draw = ft_mandelbrot2;
	data->a = 0;
	data->b = 0;
}

static void	ft_set_julia(t_data *data)
{
	data->draw = ft_julia;
	data->a = 0.4;
	data->b = -0.325;
}

static void	ft_set_ship(t_data *data)
{
	data->draw = ft_ship;
	data->a = 0;
	data->b = 0;
}

int	ft_set_data(t_data *data, char *str)
{
	if (!(ft_strncmp("julia", str, 6)))
		ft_set_julia(data);
	else if (!(ft_strncmp("mandelbrot", str, 11)))
		ft_set_mandelbrot(data);
	else if (!(ft_strncmp("ship", str, 5)))
		ft_set_ship(data);
	else
		return (1);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, WIDTH, "fractal");
	if (!data->mlx_win)
	{
		free(data->mlx);
		return (1);
	}
	ft_clear_image(data);
	data->x = 500;
	data->y = 500;
	data->zoom = 1.0;
	return (0);
}
