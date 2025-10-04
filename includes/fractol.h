/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:29:17 by MP9               #+#    #+#             */
/*   Updated: 2025/10/04 01:53:41 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include "MLX42.h"
# include "../libft/libft.h"

# define INITIAL_WIDTH 800
# define INITIAL_HEIGHT 600
# define MAX_ITER 100

# ifndef ERROR_MSG
#  define ERROR_MSG "Error\n"
# endif

typedef enum e_fractal
{
	MANDELBROT,
	JULIA
}			t_fractal;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_fractal		type;
	double			center_x;
	double			center_y;
	double			zoom;
	double			c_r;
	double			c_i;
}				t_data;

//mandelbrot
void			mbrot(t_data *data, t_fractal type, double c_r, double c_i);

//julia
void			julia(t_data *data, t_fractal type, double c_r, double c_i);

//window
void			key_hook(mlx_key_data_t keydata, void *param);
bool			mlx_init_window(t_data *data);

//parsing
void			print_parameters(void);
void			take_input(char **argv, int argc, t_data *data);
t_data 			*get_struct(void);

//rendering
double			pixel_x(t_data *data, int p_x);
double			pixel_y(t_data *data, int p_y);
int				get_escape_time(double real, double imag, double cr, double ci);
unsigned int	get_color(int n);
void			draw_fractal(t_data *data);
void			scroll_hook(double xdelta, double ydelta, void *param);


#endif
