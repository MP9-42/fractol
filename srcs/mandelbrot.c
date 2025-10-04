/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:42:43 by MP9               #+#    #+#             */
/*   Updated: 2025/10/04 01:57:29 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mbrot(t_data *data, t_fractal type, double c_r, double c_i)
{
	data->type = type;
	data->center_x = -0.75;  /* Center of the main cardioid */
	data->center_y = 0.0;
	data->zoom = 0.5;       /* Initial zoom to see the complete set */
	data->c_r = c_r;
	data->c_i = c_i;
}

