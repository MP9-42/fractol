/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:35:47 by MP9               #+#    #+#             */
/*   Updated: 2025/10/04 00:29:25 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	take_input(char **argv, int argc, t_data *data)
{
	double	c_r;
	double	c_i;

	if (argc < 2 || argc > 4)
	{
		print_parameters();
		free(data);
		exit(1);
	}
	c_r = 0.0;
	c_i = 0.0;
	if (strcmp(argv[1], "julia") == 0)
	{
		if (argc != 4)
		{
			print_parameters();
			free(data);
			exit(1);
		}
		c_r = ft_atodub(argv[2]);
		c_i = ft_atodub(argv[3]);
		julia(data, JULIA, c_r, c_i);
	}
	else if (strcmp(argv[1], "mandelbrot") == 0)
		mbrot(data, MANDELBROT, c_r, c_i);
	else
	{
		print_parameters();
		free(data);
		exit(1);
	}
}

void	print_parameters(void)
{
	ft_printf("Example 1: ./fractol julia -0.5 0.256\n");
	ft_printf("Example 2: ./fractol mandelbrot\n");
}
