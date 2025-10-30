/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:19:53 by MP9               #+#    #+#             */
/*   Updated: 2025/10/24 14:20:09 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia(t_image *img, t_data *data)
{
	t_color	color;
	int		counter;

	counter = 0;
	img->pixel.coordinate_x = 0;
	while (img->pixel.coordinate_x < WIDTH)
	{
		img->pixel.coordinate_y = 0;
		while (img->pixel.coordinate_y < HEIGHT)
		{
			set_point(&img->pixel, img, img->zoom);
			counter = julia_iterations(img->pixel, data->input);
			color = assign_color(counter, data);
			mlx_put_pixel(img->img, img->pixel.coordinate_x,
				img->pixel.coordinate_y, color.colors);
			img->pixel.coordinate_y++;
		}
		img->pixel.coordinate_x++;
	}
}

int	julia_iterations(t_pixel point, t_complex_num input_num)
{
	int				counter;
	t_complex_num	fz_result;
	t_complex_num	z_squared;
	t_complex_num	c;

	fz_result.real = point.complex_num.real;
	fz_result.imaginary = point.complex_num.imaginary;
	c = input_num;
	counter = 0;
	while (calc_magnitude(fz_result) < CONVERGENCE_RADIUS
		&& counter < MAX_ITERATIONS)
	{
		z_squared = z_sqrd(fz_result);
		fz_result = znc_add(z_squared, c);
		counter++;
	}
	return (counter);
}
