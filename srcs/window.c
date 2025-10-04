/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:28:49 by MP9               #+#    #+#             */
/*   Updated: 2025/10/04 06:40:19 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

bool	mlx_init_window(t_data *data)
{
	if (!data)
		return (false);
	data->mlx = mlx_init(INITIAL_WIDTH, INITIAL_HEIGHT, "fractol", true);
	if (!data->mlx)
	{
		ft_printf("Failed to initialize MLX\n");
		return (false);
	}
	data->image = mlx_new_image(data->mlx, INITIAL_WIDTH, INITIAL_HEIGHT);
	if (!data->image)
	{
		ft_printf("Failed to create image\n");
		mlx_terminate(data->mlx);
		data->mlx = NULL;
		return (false);
	}
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) < 0)
	{
		ft_printf("Failed to display image\n");
		mlx_delete_image(data->mlx, data->image);
		mlx_terminate(data->mlx);
		data->mlx = NULL;
		data->image = NULL;
		return (false);
	}
	mlx_key_hook(data->mlx, &key_hook, data);
	mlx_scroll_hook(data->mlx, &scroll_hook, data);
	ft_printf("[debug] Window setup complete.\n");
	return (true);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (!data || !data->mlx)
		return ;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(data->mlx);
	}
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_data	*data;
	double	factor;
	double	mouse_before_x;
	double	mouse_before_y;

	data = (t_data *)param;
	if (!data || !data->mlx)
		return ;
	(void)xdelta;
	factor = 1.1;
	/* Get mouse position before zoom */
	mouse_before_x = pixel_x(data, (int)mlx_get_pos(data->mlx));
	mouse_before_y = pixel_y(data, (int)mlx_get_pos(data->mlx));
	/* Apply zoom */
	if (ydelta > 0)
		data->zoom *= factor;
	else if (ydelta < 0)
		data->zoom /= factor;
	/* Center the view on mouse position */
	data->center_x = mouse_before_x + (data->center_x - mouse_before_x)
		/ factor;
	data->center_y = mouse_before_y + (data->center_y - mouse_before_y)
		/ factor;
	draw_fractal(data);
}
