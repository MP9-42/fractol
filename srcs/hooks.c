/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 00:56:56 by MP9               #+#    #+#             */
/*   Updated: 2025/10/27 13:48:49 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_data	*data;
	t_mouse	mouse;
	int32_t	mx;
	int32_t	my;

	(void)xdelta;
	data = (t_data *)param;
	mlx_get_mouse_pos(data->mlx, &mx, &my);
	mouse.x = mx;
	mouse.y = my;
	apply_zoom_at_mouse(data, ydelta, &mouse);
	rendering(data);
}

void	apply_zoom_at_mouse(t_data *data, double ydelta, t_mouse *mouse)
{
	double	old_zoom;
	double	new_zoom;

	old_zoom = data->image->zoom;
	get_mouse_complex(data, mouse);
	if (ydelta > 0)
		data->image->zoom *= 0.9;
	else if (ydelta < 0)
		data->image->zoom *= 1.1;
	new_zoom = data->image->zoom;
	data->image->center.real = mouse->real + 2.0 * new_zoom
		- (4.0 * new_zoom) * (double)mouse->x / (WIDTH - 1.0);
	data->image->center.imaginary = mouse->imaginary + 2.0 * new_zoom
		- (4.0 * new_zoom) * (double)mouse->y / (WIDTH - 1.0);
}

void	get_mouse_complex(t_data *data, t_mouse *mouse)
{
	double	zoom;
	double	w;
	double	h;

	zoom = data->image->zoom;
	w = data->image->img->width;
	h = data->image->img->height;
	mouse->real = data->image->center.real - 2.0 * zoom
		+ (4.0 * zoom) * (double)mouse->x / (w - 1.0);
	mouse->imaginary = data->image->center.imaginary - 2.0 * zoom
		+ (4.0 * zoom) * (double)mouse->y / (h - 1.0);
}

void	ft_hook(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_C))
	{
		data->color_shift += 1;
		if (data->color_shift > 2)
			data->color_shift = 0;
		rendering(data);
	}
}
