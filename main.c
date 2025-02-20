/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:47:53 by okaname           #+#    #+#             */
/*   Updated: 2025/02/20 16:28:24 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2 || ft_set_data(&data, argv[1]))
	{
		ft_printf("./fractol <mandelbrot or julia or ship>\n");
		return (0);
	}
	data.draw(&data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	ft_setup_hooks(&data);
	mlx_loop(data.mlx);
}
