/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:54:39 by okaname           #+#    #+#             */
/*   Updated: 2025/02/28 13:06:50 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_set_mandelbrot(t_data *data)
{
	data->draw = ft_mandelbrot2;
	data->a = 0;
	data->b = 0;
}

static void	ft_set_julia(t_data *data, char *a, char *b)
{
	data->draw = ft_julia;
	data->a = ft_atof(a);
	data->b = ft_atof(b);
}

static void	ft_set_ship(t_data *data)
{
	data->draw = ft_ship;
	data->a = 0;
	data->b = 0;
}

int	ft_set_data(t_data *data, char **argv, int argc)
{
	if (!(ft_strncmp("julia", argv[1], 6)) && argc == 4 && ft_isvalid(argv[2])
		&& ft_isvalid(argv[3]))
		ft_set_julia(data, argv[2], argv[3]);
	else if (!(ft_strncmp("mandelbrot", argv[1], 11)) && argc == 2)
		ft_set_mandelbrot(data);
	else if (!(ft_strncmp("ship", argv[1], 5)) && argc == 2)
		ft_set_ship(data);
	else
		return (1);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (-1);
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, WIDTH, "fractal");
	if (!data->mlx_win)
	{
		free(data->mlx);
		return (-1);
	}
	ft_clear_image(data);
	data->x = 0;
	data->y = 0;
	data->zoom = 1.0;
	data->sign = 1;
	return (0);
}
