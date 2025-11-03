/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:11:08 by MP9               #+#    #+#             */
/*   Updated: 2025/11/03 17:50:10 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	parssing(int argc, char **argv, t_data *data)
{
	if (argc < 2 || argc > 4)
		print_parameters(data);
	else if (ft_strncmp(argv[1], "Mandelbrot", 11) == 0
		|| ft_strncmp(argv[1], "mandelbrot", 11) == 0)
	{
		if (argc == 2)
			data->pars = 1;
		else
			print_parameters(data);
	}
	else if (ft_strncmp(argv[1], "Julia", 6) == 0
		|| ft_strncmp(argv[1], "julia", 6) == 0 || ft_strlen(argv[1]) > 11)
	{
		if (argc == 2 || argc == 4)
			data->pars = 2;
		else
			print_parameters(data);
		input_take(&argv[1], data);
	}
	else
		print_parameters(data);
}

void	input_take(char **numbers, t_data *data)
{
	char	**matrix;

	matrix = NULL;
	if (ft_strlen(numbers[0]) > 7)
	{
		matrix = ft_split(numbers[0], ' ');
		input_check(data, matrix[1]);
		input_check(data, matrix[2]);
		data->input.real = ft_atodub(matrix[1]);
		data->input.imaginary = ft_atodub(matrix[2]);
		ft_free_matrix(matrix);
	}
	else
	{
		input_check(data, numbers[1]);
		input_check(data, numbers[2]);
		data->input.real = ft_atodub(numbers[1]);
		data->input.imaginary = ft_atodub(numbers[2]);
	}
}

void	error_handle(t_data *data)
{
	free(data->image);
	free(data);
	exit(69);
}

void	print_parameters(t_data *data)
{
	ft_printf("Usage:\n");
	ft_printf("./fractol mandelbrot\n");
	ft_printf("./fractol julia <real_part> <imaginary_part>\n");
	error_handle(data);
}
