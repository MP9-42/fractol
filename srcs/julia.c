/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:44:01 by MP9               #+#    #+#             */
/*   Updated: 2025/10/04 01:15:05 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia(t_data *data, t_fractal type, double c_r, double c_i)
{
	data->type = type;
	data->center_x = 0.0;
	data->center_y = 0.0;
	data->zoom = 1.0;
	data->c_r = c_r;
	data->c_i = c_i;
}
