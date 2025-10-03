/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:28:49 by MP9               #+#    #+#             */
/*   Updated: 2025/10/02 23:09:10 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

bool	mlx_init_window(t_data *data)
{
	data->mlx = mlx_init(INITIAL_WIDTH, INITIAL_HEIGHT, "fractol", true);
	if (!data->mlx)
	{
		ft_printf("Failed to initialize MLX\n");
		free(data);
		return (false);
	}
	data->image = mlx_new_image(data->mlx, INITIAL_WIDTH, INITIAL_HEIGHT);
	if (!data->image)
	{
		ft_printf("Failed to create image\n");
		mlx_terminate(data->mlx);
		free(data);
		return (false);
	}
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) < 0)
	{
		ft_printf("Failed to display image\n");
		mlx_terminate(data->mlx);
		free(data);
		return (false);
	}
	return (true);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
		{
			mlx_close_window(data->mlx);
			mlx_terminate(data->mlx);
		}
	}
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_data	*data;
	double	factor;

	factor = 1.1;
	data = (t_data *)param;
	(void)xdelta;
	if (ydelta > 0)
		data->zoom *= factor;
	else if (ydelta < 0)
		data->zoom /= factor;
	draw_fractal(data);
}
