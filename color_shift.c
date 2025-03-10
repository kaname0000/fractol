/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:32:06 by okaname           #+#    #+#             */
/*   Updated: 2025/02/23 17:02:12 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_red(t_data *data)
{
	char			*dst;
	unsigned int	color;
	int				adjusted_red;
	int				i;
	int				j;

	i = -1;
	while (++i < WIDTH)
	{
		j = 0;
		while (j < WIDTH)
		{
			dst = data->addr + (j * data->line_length + i
					* (data->bits_per_pixel / 8));
			color = *(unsigned int *)dst;
			adjusted_red = ((color >> 16) & 0xFF) + (data->sign * 10);
			if (adjusted_red > 255)
				adjusted_red = 255;
			else if (adjusted_red < 0)
				adjusted_red = 0;
			*(unsigned int *)dst = (color & 0xFF00FFFF) | (adjusted_red << 16);
			j++;
		}
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

void	ft_green(t_data *data)
{
	char			*dst;
	unsigned int	color;
	int				adjusted_green;
	int				i;
	int				j;

	i = -1;
	while (++i < WIDTH)
	{
		j = 0;
		while (j < WIDTH)
		{
			dst = data->addr + (j * data->line_length + i
					* (data->bits_per_pixel / 8));
			color = *(unsigned int *)dst;
			adjusted_green = ((color >> 8) & 0xFF) + (data->sign * 10);
			if (adjusted_green > 255)
				adjusted_green = 255;
			else if (adjusted_green < 0)
				adjusted_green = 0;
			*(unsigned int *)dst = (color & 0xFFFF00FF) | (adjusted_green << 8);
			j++;
		}
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

void	ft_blue(t_data *data)
{
	char			*dst;
	unsigned int	color;
	int				adjusted_blue;
	int				i;
	int				j;

	i = -1;
	while (++i < WIDTH)
	{
		j = 0;
		while (j < WIDTH)
		{
			dst = data->addr + (j * data->line_length + i
					* (data->bits_per_pixel / 8));
			color = *(unsigned int *)dst;
			adjusted_blue = (color & 0xFF) + (data->sign * 10);
			if (adjusted_blue > 255)
				adjusted_blue = 255;
			else if (adjusted_blue < 0)
				adjusted_blue = 0;
			*(unsigned int *)dst = (color & 0xFFFFFF00) | adjusted_blue;
			j++;
		}
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
