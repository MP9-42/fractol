/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:47:49 by MP9               #+#    #+#             */
/*   Updated: 2025/10/24 14:19:57 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_color	assign_color(int counter, t_data *data)
{
	float	t;
	t_color	color;

	color.alpha = 255;
	t = (float)counter / (float)MAX_ITERATIONS;
	if (counter == MAX_ITERATIONS)
	{
		color.blue = 0;
		color.green = 0;
		color.red = 0;
		return (color);
	}
	else
		color.colors = t;
	if (data->color_shift > 0)
		color.colors <<= data->color_shift;
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
		color.blue = 1275 - pixel.coordinate_y;
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
		color.blue = 1275 - pixel.coordinate_y;
	return (color);
}
