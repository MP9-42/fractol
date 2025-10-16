/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:33:39 by MP9               #+#    #+#             */
/*   Updated: 2025/10/16 23:38:25 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_complex_num z_iterate(t_complex_num z, t_color color)
{
	t_complex_num	z_sqrd;

	z_sqrd.imaginary = 2 * z.real * z.imaginary;
	z_sqrd.real = z.real * z.real - z.imaginary * z.imaginary;
	return (z_sqrd);
}

