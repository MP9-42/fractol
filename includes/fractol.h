/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:46:48 by MP9               #+#    #+#             */
/*   Updated: 2025/10/27 13:49:47 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <MLX42.h>
# include <math.h>
# include <stdlib.h>

# define JULIA 2
# define MBROT 0

# define WIDTH 600
# define HEIGHT 400

# define CONVERGENCE_RADIUS 2
# define MAX_ITERATIONS 350

typedef union color_u
{
	struct
	{
		uint8_t	alpha;
		uint8_t	blue;
		uint8_t	green;
		uint8_t	red;
	};
	uint32_t	colors;
}	t_color;

typedef struct s_complex_nums
{
	double			real;
	double			imaginary;
}					t_complex_num;

typedef struct s_mouse
{
	int32_t			x;
	int32_t			y;
	double			real;
	double			imaginary;
}					t_mouse;

typedef struct s_pixel
{
	uint32_t		coordinate_x;
	uint32_t		coordinate_y;
	t_complex_num	complex_num;
}					t_pixel;

typedef struct s_image
{
	mlx_image_t		*img;
	t_pixel			pixel;
	double			zoom;
	t_complex_num	center;
}					t_image;

typedef struct s_data
{
	mlx_t			*mlx;
	t_image			*image;
	t_color			color;
	int				pars;
	char			**input;
	int				color_shift;
	double			in_values;
}					t_data;

t_complex_num	z_sqrd(t_complex_num z);
void			mbrot(t_image *img, t_data *data);
int				mbrot_iterations(t_complex_num c);
void			parssing(int argc, char **argv, t_data *data);
void			error_handle(t_data *data);
void			print_parameters(void);
double			calc_magnitude(t_complex_num c);
t_complex_num	znc_add(t_complex_num z_sqrd, t_complex_num c);
void			set_point(t_pixel *pixel, t_image *img, double zoom);
void			data_init(t_data *data);
void			ft_hook(void *param);
void			start_screen(t_data *data, t_pixel *pixels);
void			near_colors(t_color *color, t_pixel pixel, float t);
t_color			far_colors(t_color color, t_pixel pixel);
void			rendering(t_data *data);
void			scroll_hook(double xdelta, double ydelta, void *param);
void			apply_zoom_at_mouse(t_data *data, double ydelta,
					t_mouse *mouse);
void			assign_opaque(uint8_t *alpha, float t);
void			get_mouse_complex(t_data *data, t_mouse *mouse);
t_color			assign_color(int counter, t_data *data);
void			colours(t_color *color, float t);

#endif