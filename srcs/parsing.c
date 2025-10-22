/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:11:08 by MP9               #+#    #+#             */
/*   Updated: 2025/10/22 22:31:19 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	parssing(int argc, char **argv, t_data *data)
{
	if (argc < 2 || argc > 4)
	{
		print_parameters();
		error_handle(data);
	}
	else if (ft_strncmp(argv[1], "Mandelbrot", 11)
		|| ft_strncmp(argv[1], "mandelbrot", 11))
		data->pars = 1;
	else if (ft_strncmp(argv[1], "Julia", 6)
		|| ft_strncmp(argv[1], "julia", 6))
	{
		data->pars = 2;
		data->input[0] = argv[2];
		data->input[1] = argv[3];
	}
	else
	{
		print_parameters();
		error_handle(data);
	}
}

void	rendering(t_data *data)
{
	if (data->pars == 1)
		mbrot((data->image));
	// else
	// 	julia(data);
}

void	error_handle(t_data *data)
{
	free(data->image);
	free(data);
	exit(1);
}

void	print_parameters(void)
{
	ft_printf("Usage:\n");
	ft_printf("./fractol mandelbrot\n");
	ft_printf("./fractol julia <real_part> <imaginary_part>\n");
}
