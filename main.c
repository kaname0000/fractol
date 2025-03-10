/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:47:53 by okaname           #+#    #+#             */
/*   Updated: 2025/02/28 13:07:35 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	int		ans;

	if (argc == 1)
		ft_print_arg_error();
	ans = ft_set_data(&data, argv, argc);
	if (ans)
	{
		if (ans == 1)
			ft_print_arg_error();
		return (1);
	}
	data.draw(&data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	ft_setup_hooks(&data);
	mlx_loop(data.mlx);
}
