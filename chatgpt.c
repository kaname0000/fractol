/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chatgpt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:26:14 by okaname           #+#    #+#             */
/*   Updated: 2025/02/20 21:27:15 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include <stdlib.h>

#define WIDTH 1000
#define HEIGHT 1000

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	double	zoom;
	double	x_offset;
	double	y_offset;
}			t_data;

// ピクセルを描画
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

// マンデルブロ集合の収束チェック
int	mandelbrot(double real, double imag)
{
	int		n;
	double	x;

	x = 0, y;
	n = 0;
	x = 0, y = 0, x_temp;
	while (x * x + y * y <= 4 && n < 100)
	{
		x_temp = x * x - y * y + real;
		y = 2 * x * y + imag;
		x = x_temp;
		n++;
	}
	return (n);
}

// マンデルブロ集合を描画
void	draw_mandelbrot(t_data *data)
{
	double	scale;
	double	real;
	double	imag;
	int		color;

	int x, y, iter;
	scale = 4.0 / (data->zoom * WIDTH);
	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			real = (x - WIDTH / 2) * scale + data->x_offset;
			imag = (y - HEIGHT / 2) * scale + data->y_offset;
			iter = mandelbrot(real, imag);
			color = (iter == 100) ? 0x000000 : (0x00FF0000 * iter / 100);
			my_mlx_pixel_put(data, x, y, color);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

// キーボード操作
int	key_hook(int keycode, t_data *data)
{
	double	old_zoom;
	double	new_zoom;
	double	mouse_x;
	double	mouse_y;
	double	scale;
	double	new_scale;
	double	real;
	double	imag;

	old_zoom = data->zoom;
	mouse_x = WIDTH / 2;
	mouse_y = HEIGHT / 2;
	scale = 4.0 / (old_zoom * WIDTH);
	if (keycode == 65307) // ESCキーで終了
		exit(0);
	else if (keycode == 61) // '=' キーで拡大
		data->zoom *= 1.1;
	else if (keycode == 45) // '-' キーで縮小
		data->zoom /= 1.1;
	new_zoom = data->zoom;
	new_scale = 4.0 / (new_zoom * WIDTH);
	// ズーム後の中心補正
	real = (mouse_x - WIDTH / 2) * scale + data->x_offset;
	imag = (mouse_y - HEIGHT / 2) * scale + data->y_offset;
	data->x_offset = real - (mouse_x - WIDTH / 2) * new_scale;
	data->y_offset = imag - (mouse_y - HEIGHT / 2) * new_scale;
	// 再描画
	draw_mandelbrot(data);
	return (0);
}

// メモリ解放 & 終了
int	close_window(t_data *data)
{
	exit(0);
}

// メイン関数
int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Mandelbrot");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_len,
			&data.endian);
	data.zoom = 1.0;
	data.x_offset = 0.0;
	data.y_offset = 0.0;
	draw_mandelbrot(&data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
}
