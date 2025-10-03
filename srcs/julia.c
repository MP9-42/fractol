/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:44:01 by MP9               #+#    #+#             */
/*   Updated: 2025/10/03 01:52:08 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia(t_data *data, t_fractal type, double c_r, double c_i)
{
	int		p_x;
	int		p_y;
	int		n;
	double	x;
	double	y;

	data->type = type;
	data->center_x = 0.0;
	data->center_y = 0.0;
	data->zoom = 1.0;
	data->c_r = c_r;
	data->c_i = c_i;
	if (!mlx_init_window(data))
		exit(ft_printf("%s", ERROR_MSG));
	while (p_x < INITIAL_WIDTH || p_y < INITIAL_HEIGHT)
	{
		x = pixel_x(data, x, p_x);
		y = pixel_y(data, y, p_y);
		n = julia2(x, y, data);
		julia3(data, n, p_x, p_y);
		p_x++;
		p_y++;
	}
}

int	julia2(double x, double y, t_data *data)
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	int		n;

	z_r = x;
	z_i = y;
	c_r = data->c_r;
	c_i = data->c_i;
	n = get_escape_time(z_r, z_i, c_r, c_i);
	return (n);
}

void	julia3(t_data *data, int n, int p_x, int p_y)
{
	unsigned int	color;

	color = get_color(n);
	mlx_put_pixel(data->image, p_x, p_y, color);
}
