/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:33:39 by MP9               #+#    #+#             */
/*   Updated: 2025/10/22 23:35:42 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_point(t_pixel *pixel, mlx_image_t *img, double zoom)
{
	pixel->complex_num.real = ((-2) * zoom) + (4.0 * zoom)
		* pixel->coordinate_x / (img->width - 1);
	pixel->complex_num.imaginary = ((-2) * zoom) + (4.0 * zoom)
		* pixel->coordinate_y / (img->height - 1);
}

t_complex_num	z_sqrd(t_complex_num z)
{
	t_complex_num	z_sqrd;

	z_sqrd.imaginary = 2 * z.real * z.imaginary;
	z_sqrd.real = z.real * z.real - z.imaginary * z.imaginary;
	return (z_sqrd);
}

t_complex_num	znc_add(t_complex_num z_sqrd, t_complex_num c)
{
	t_complex_num	result;

	result.real = z_sqrd.real + c.real;
	result.imaginary = z_sqrd.imaginary + c.imaginary;
	return (result);
}

double	calc_magnitude(t_complex_num c)
{
	double	magnitude;

	magnitude = sqrt(c.real * c.real + c.imaginary * c.imaginary);
	return (magnitude);
}
