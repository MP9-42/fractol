/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:29:17 by MP9               #+#    #+#             */
/*   Updated: 2025/10/03 01:51:11 by MP9              ###   ########.fr       */
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

# define INITIAL_WIDTH 1000
# define INITIAL_HEIGHT 800
# define MAX_ITER 1000

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
int				julia2(double x, double y, t_data *data);
void			julia3(t_data *data, int n, int p_x, int p_y);

//window
void			key_hook(mlx_key_data_t keydata, void *param);
bool			mlx_init_window(t_data *data);

//parsing
void			print_parameters(void);
void			take_fractal(char *name);
void			take_input(char **argv, int argc, t_data *data);

//rendering
double			pixel_x(t_data *data, double x, int p_x);
double			pixel_y(t_data *data, double y, int p_y);
int				get_escape_time(double real, double imag, double cr, double ci);
unsigned int	get_color(int n);


#endif
