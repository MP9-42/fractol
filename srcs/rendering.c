/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 22:59:01 by MP9               #+#    #+#             */
/*   Updated: 2025/10/04 01:35:39 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	get_escape_time(double real, double imag, double cr, double ci)
{
	double	z_r;
	double	z_i;
	double	temp_r;
	int		i;

	z_r = real;
	z_i = imag;
	i = 0;
	while (i < MAX_ITER)
	{
		if ((z_r * z_r + z_i * z_i) > 4.0)
			return (i);
		temp_r = z_r * z_r - z_i * z_i + cr;
		z_i = 2.0 * z_r * z_i + ci;
		z_r = temp_r;
		i++;
	}
	return (MAX_ITER);
}

double	pixel_x(t_data *data, int p_x)
{
	double	scale;

	scale = (data->type == MANDELBROT) ? 2.5 : 3.0;
	return (data->center_x + (p_x - INITIAL_WIDTH / 2.0) * scale / INITIAL_WIDTH
		/ data->zoom);
}

double	pixel_y(t_data *data, int p_y)
{
	double	scale;

	scale = (data->type == MANDELBROT) ? 2.5 : 3.0;
	return (data->center_y + (p_y - INITIAL_HEIGHT / 2.0) * scale
		/ INITIAL_HEIGHT / data->zoom);
}

void	draw_fractal(t_data *data)
{
	int		p_x;
	int		p_y;
	int		n;
	double	x;
	double	y;

	if (!data || !data->mlx || !data->image)
	{
		ft_printf("Error: Invalid data structure\n");
		return ;
	}
	p_y = 0;
	while (p_y < INITIAL_HEIGHT)
	{
		p_x = 0;
		while (p_x < INITIAL_WIDTH)
		{
			x = pixel_x(data, p_x);
			y = pixel_y(data, p_y);
			if (data->type == JULIA)
				n = get_escape_time(x, y, data->c_r, data->c_i);
			else /* For Mandelbrot: z0 = (0,0), c = (x,y) */
				n = get_escape_time(0.0, 0.0, x, y);
			mlx_put_pixel(data->image, p_x, p_y, get_color(n));
			p_x++;
		}
		p_y++;
	}
}
