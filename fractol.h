/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:39:04 by okaname           #+#    #+#             */
/*   Updated: 2025/02/20 21:32:43 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "mlx/mlx.h"

# define WIDTH 1000
# define MIDDLE 500

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	x;
	double	y;
	double	a;
	double	b;
	double	zoom;
	void	(*draw)(struct s_data *img);
}			t_data;

int			ft_sqrt(int nb);
void		ft_squared(float *x, float *y, float a, float b);
void		ft_clear_image(t_data *img);
int			ft_close_window(t_data *data);
int			mouse_hook(int button, int x, int y, t_data *img);
void		ft_setup_hooks(t_data *data);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			ft_set_data(t_data *data, char *str);
void		ft_mandelbrot1(t_data *img);
void		ft_mandelbrot2(t_data *img);
void		ft_julia(t_data *img);
void		ft_ship(t_data *data);
void		ft_right_move(t_data *data);
void		ft_left_move(t_data *data);
void		ft_up_move(t_data *data);
void		ft_down_move(t_data *data);

#endif