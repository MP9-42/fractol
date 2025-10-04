/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 23:27:33 by MP9               #+#    #+#             */
/*   Updated: 2025/10/04 01:57:55 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

unsigned int	get_color(int n)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	double			t;

	if (n == MAX_ITER)
		return (0xFF000000);  /* Black with full alpha */
	
	/* Advanced color mapping using smooth coloring */
	t = (double)n / MAX_ITER;
	t = sqrt(t);  /* Smooth the color transition */
	
	/* Create a psychedelic color palette */
	r = (unsigned char)(255.0 * (0.5 + 0.5 * sin(3.0 * M_PI * t)));
	g = (unsigned char)(255.0 * (0.5 + 0.5 * sin(3.0 * M_PI * (t + 0.33))));
	b = (unsigned char)(255.0 * (0.5 + 0.5 * sin(3.0 * M_PI * (t + 0.67))));
	
	/* RGBA format for MLX42 */
	return ((255 << 24) | (r << 16) | (g << 8) | b);
}

