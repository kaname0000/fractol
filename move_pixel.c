/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:01:59 by okaname           #+#    #+#             */
/*   Updated: 2025/02/20 20:09:31 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_right_move(t_data *data)
{
	data->x -= 30;
	mlx_destroy_image(data->mlx, data->img);
	ft_clear_image(data);
	data->draw(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

void	ft_left_move(t_data *data)
{
	data->x += 30;
	mlx_destroy_image(data->mlx, data->img);
	ft_clear_image(data);
	data->draw(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

void	ft_up_move(t_data *data)
{
	data->y -= 30;
	mlx_destroy_image(data->mlx, data->img);
	ft_clear_image(data);
	data->draw(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

void	ft_down_move(t_data *data)
{
	data->y += 30;
	mlx_destroy_image(data->mlx, data->img);
	ft_clear_image(data);
	data->draw(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
