/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:09:49 by MP9               #+#    #+#             */
/*   Updated: 2025/10/22 23:37:30 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mbrot(t_image *img)
{
	t_color	color;
	int		counter;

	counter = 0;
	img->pixel.coordinate_x = 0;
	img->pixel.coordinate_y = 0;
	while (img->pixel.coordinate_x < img->img->width)
	{
		img->pixel.coordinate_y = 0;
		while (img->pixel.coordinate_y < img->img->height)
		{
			set_point(&img->pixel, img->img, img->zoom);
			counter = mbrot_iterations(img->pixel.complex_num);
			color = assign_color(counter, img->pixel);
			mlx_put_pixel(img->img, img->pixel.coordinate_x,
				img->pixel.coordinate_y, color.colors);
			img->pixel.coordinate_y++;
		}
		img->pixel.coordinate_x++;
	}
}

int	mbrot_iterations(t_complex_num c)
{
	int				counter;
	t_complex_num	fz_result;
	t_complex_num	z_squared;

	fz_result.real = c.real;
	counter = 0;
	fz_result.imaginary = c.imaginary;
	while (calc_magnitude(fz_result) < CONVERGENCE_RADIUS
		&& counter < MAX_ITERATIONS)
	{
		z_squared = z_sqrd(fz_result);
		fz_result = znc_add(z_squared, c);
		counter++;
	}
	return (counter);
}
