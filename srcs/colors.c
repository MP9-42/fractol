/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:47:49 by MP9               #+#    #+#             */
/*   Updated: 2025/10/23 00:25:27 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_color	assign_color(int counter, t_pixel pixel)
{
	float	t;
	t_color	color;

	color.alpha = 0;
	color.red = 0;
	color.blue = 0;
	color.green = 0;
	t = (float)counter / (float)MAX_ITERATIONS;
	if (counter == MAX_ITERATIONS)
	{
		color.alpha = 255;
		color.blue = 0;
		color.green = 0;
		color.red = 0;
		return (color);
	}
	else if (t < 0.5)
		color = near_colors(color, pixel);
	else
		color = far_colors(color, pixel);
	return (color);
}

t_color	near_colors(t_color color, t_pixel pixel)
{
	color.alpha = 255;
	if (pixel.coordinate_y <= 255)
	{
		color.blue = pixel.coordinate_y;
		color.red = 255 - pixel.coordinate_y;
	}
	else if (pixel.coordinate_y <= 510 && pixel.coordinate_y > 255)
	{
		color.blue = 510 - pixel.coordinate_y;
		color.green = pixel.coordinate_y - 255;
	}
	else if (pixel.coordinate_y <= 765 && pixel.coordinate_y > 510)
	{
		color.green = 765 - pixel.coordinate_y;
		color.red = pixel.coordinate_y - 510;
	}
	else if (pixel.coordinate_y <= 1020 && pixel.coordinate_y > 765)
	{
		color.red = 1020 - pixel.coordinate_y;
		color.blue = pixel.coordinate_y - 765;
	}
	else
		color.blue = pixel.coordinate_y - 825;
	return (color);
}

t_color	far_colors(t_color color, t_pixel pixel)
{
	color.alpha = 125;
	if (pixel.coordinate_y <= 255)
	{
		color.blue = pixel.coordinate_y;
		color.red = 255 - pixel.coordinate_y;
	}
	else if (pixel.coordinate_y <= 510 && pixel.coordinate_y > 255)
	{
		color.blue = 510 - pixel.coordinate_y;
		color.green = pixel.coordinate_y - 255;
	}
	else if (pixel.coordinate_y <= 765 && pixel.coordinate_y > 510)
	{
		color.green = 765 - pixel.coordinate_y;
		color.red = pixel.coordinate_y - 510;
	}
	else if (pixel.coordinate_y <= 1020 && pixel.coordinate_y > 765)
	{
		color.red = 1020 - pixel.coordinate_y;
		color.blue = pixel.coordinate_y - 765;
	}
	else
		color.blue = pixel.coordinate_y - 825;
	return (color);
}
