/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:11:08 by MP9               #+#    #+#             */
/*   Updated: 2025/10/16 22:09:03 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	parssing(int argc, char **argv, t_data *data)
{
	if (argc < 2 || argc > 4)
	{
		print_parameters();
		error_handle(data);
	}
	else if (ft_strncmp(argv[1], "Mandelbrot", 11)
		|| ft_strncmp(argv[1], "mandelbrot", 11))
		mbrot(data);
	else if (ft_stncmp(argv[1], "Julia", 6)
		|| ft_strncmp(argv[1], "julia", 6))
		julia(data, argv);
	else
	{
		print_parameters();
		error_handle(data);
	}
}

void	error_handle(t_data *data)
{
	free(data->image);
	free(data->image->pixels);
	free(data);
	exit(1);
}

void print_parameters(void)
{
	ft_printf("Usage:\n");
	ft_printf("./fractol mandelbrot\n");
	ft_printf("./fractol julia <real_part> <imaginary_part>\n");
}
