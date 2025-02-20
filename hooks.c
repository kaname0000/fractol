/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:58:44 by okaname           #+#    #+#             */
/*   Updated: 2025/02/20 21:12:16 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_close_window(data);
	else if (keycode == 65361)
		ft_right_move(data);
	else if (keycode == 65362)
		ft_up_move(data);
	else if (keycode == 65363)
		ft_left_move(data);
	else if (keycode == 65364)
		ft_down_move(data);
	else if (keycode == 45)
		mouse_hook(5, 500, 500, data);
	else if (keycode == 61)
		mouse_hook(4, 500, 500, data);
	return (0);
}

void	ft_setup_hooks(t_data *data)
{
	mlx_mouse_hook(data->mlx_win, mouse_hook, data);
	mlx_key_hook(data->mlx_win, ft_key_hook, data);
	mlx_hook(data->mlx_win, 17, 0, ft_close_window, data);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	if (button == 4)
	{
		data->zoom *= 1.1;
		data->x += (x - MIDDLE) / data->zoom;
		data->y += (y - MIDDLE) / data->zoom;
	}
	else if (button == 5)
	{
		data->zoom /= 1.1;
		data->x -= (x - MIDDLE) / data->zoom;
		data->y -= (y - MIDDLE) / data->zoom;
	}
	printf("%f,%f\n", data->x, data->y);
	mlx_destroy_image(data->mlx, data->img);
	ft_clear_image(data);
	data->draw(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}

// int	mouse_hook(int button, int x, int y, t_data *data)
// {
// 	double	old_zoom;
// 	double	new_zoom;
// 	double	mouse_x;
// 	double	mouse_y;

// 	// 現在のズーム値を保存
// 	old_zoom = data->zoom;
// 	// ズーム処理
// 	if (button == 4) // ズームイン
// 		data->zoom *= 1.1;
// 	else if (button == 5) // ズームアウト
// 		data->zoom /= 1.1;
// 	// 新しいズーム値
// 	new_zoom = data->zoom;
// 	// ズーム前のマウス位置（フラクタル座標）
// 	mouse_x = ((double)x / 1000.0) * 4.0 / old_zoom + data->x - 2.0 / old_zoom;
// 	mouse_y = ((double)y / 1000.0) * 4.0 / old_zoom + data->y - 2.0 / old_zoom;
// 	// ズーム後の視点補正（マウス位置を固定する）
// 	data->x = mouse_x - ((double)x / 1000.0) * 4.0 / new_zoom + 2.0 / new_zoom;
// 	data->y = mouse_y - ((double)y / 1000.0) * 4.0 / new_zoom + 2.0 / new_zoom;
// 	// 画面を更新
// 	mlx_destroy_image(data->mlx, data->img);
// 	ft_clear_image(data);
// 	data->draw(data);
// 	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
// 	return (0);
// }
