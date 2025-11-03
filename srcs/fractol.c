/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:47:27 by MP9               #+#    #+#             */
/*   Updated: 2025/11/03 17:42:51 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	data_init(t_data *data)
{
	data->image = ft_calloc(1, sizeof(t_image));
	if (!data->image)
	{
		free(data);
		exit(1);
	}
	data->image->zoom = 1.0;
	data->input.real = 0;
	data->input.imaginary = 0;
	data->color_shift = 0;
	data->image->center.imaginary = 0.0;
	data->image->center.real = 0.0;
	data->mlx = NULL;
	data->pars = 0;
}

void	rendering(t_data *data)
{
	if (data->pars == 1)
		mbrot((data->image), data);
	else
		julia(data->image, data);
}

void	start_screen(t_data *data, t_pixel *pixels)
{
	pixels->coordinate_y = 0;
	pixels->coordinate_x = 0;
	data->image->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data->mlx, data->image->img,
		pixels->coordinate_x, pixels->coordinate_y);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		exit(STDERR_FILENO);
	data_init(data);
	parssing(argc, argv, data);
	data->mlx = mlx_init(WIDTH, HEIGHT, "fractol", false);
	start_screen(data, &data->image->pixel);
	rendering(data);
	mlx_loop_hook(data->mlx, &ft_hook, data);
	mlx_scroll_hook(data->mlx, &scroll_hook, data);
	mlx_loop(data->mlx);
	mlx_delete_image(data->mlx, data->image->img);
	mlx_terminate(data->mlx);
	error_handle(data);
	return (0);
}
