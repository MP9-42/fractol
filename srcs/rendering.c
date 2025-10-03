/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 22:59:01 by MP9               #+#    #+#             */
/*   Updated: 2025/10/03 01:11:42 by MP9              ###   ########.fr       */
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

double	pixel_x(t_data *data, double x, int p_x)
{
	x = (data->center_x + (p_x - INITIAL_WIDTH / 2.0)
			* 4.0 / INITIAL_WIDTH / data->zoom);
	return (x);
}

double	pixel_y(t_data *data, double y, int p_y)
{
	y = (data->center_y + (p_y - INITIAL_HEIGHT / 2.0)
			* 4.0 / INITIAL_HEIGHT / data->zoom);
	return (y);
}
