/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:42:43 by MP9               #+#    #+#             */
/*   Updated: 2025/10/03 01:51:32 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mbrot(t_data *data, t_fractal type, double c_r, double c_i)
{
	data->type = type;
	data->center_x = -0.5;
	data->center_y = 0.0;
	data->zoom = 1.0;
	data->c_r = c_r;
	data->c_i = c_i;

	if (!mlx_init_window(data))
		exit(ft_printf("%s", ERROR_MSG));
}

