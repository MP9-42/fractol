/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:41:31 by MP9               #+#    #+#             */
/*   Updated: 2025/10/04 01:56:47 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// void	fractol(t_data *data)
// {
	
// }

t_data	*get_struct(void)
{
	static t_data	*data;

	if (!data)
	{
		data = malloc(sizeof(t_data) * 1);
		if (!data)
			exit(ft_printf("Could not extract data\n"));
	}
	data->mlx = NULL;
	data->image = NULL;
	data->zoom = 1.0;
	data->center_x = 0.0;
	data->center_y = 0.0;
	data->c_r = 0.0;
	data->c_i = 0.0;
	return (data);
}


int	main(int argc, char **argv)
{
	t_data	*data;

	data = get_struct();

	/* Initialize default values */


	take_input(argv, argc, data);
	if (!mlx_init_window(data))
	{
		free(data);
		return (1);
	}
	
	/* Draw initial fractal */
	draw_fractal(data);

	/* Start the main loop */
	mlx_loop(data->mlx);

	/* Cleanup when loop ends */
	if (data)
	{
		if (data->image)
			mlx_delete_image(data->mlx, data->image);
		if (data->mlx)
			mlx_terminate(data->mlx);
		free(data);
	}
	return (0);
}
