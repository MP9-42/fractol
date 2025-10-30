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
	{
		assign_opaque(&color.alpha, t);
		colours(&color, t);
	}
	if (data->color_shift > 0)
		color.colors <<= 2;
	return (color);
}

void	colours(t_color *color, float t)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	r = (uint8_t)(255.0f * powf(t, 0.3f));
	g = (uint8_t)(255.0f * powf(t, 0.6f));
	b = (uint8_t)(255.0f * t);
	color->red = r;
	color->green = g;
	color->blue = b;
}

void	assign_opaque(uint8_t *alpha, float t)
{
	if (t < 0.0001)
		*alpha = 255 / 10;
	else if (t < 0.00009)
		*alpha = 255 / 9;
	else if (t < 0.0002)
		*alpha = 255 / 8;
	else if (t < 0.0006)
		*alpha = 255 / 7;
	else if (t < 0.0008)
		*alpha = 255 / 6;
	else if (t < 0.003)
		*alpha = 255 / 5;
	else if (t < 0.007)
		*alpha = 255 / 4;
	else if (t < 0.04)
		*alpha = 255 / 3;
	else if (t < 0.09)
		*alpha = 255 / 2;
	else if (t < 0.5)
		*alpha = 255;
}
