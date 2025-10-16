/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:46:48 by MP9               #+#    #+#             */
/*   Updated: 2025/10/16 23:30:27 by MP9              ###   ########.fr       */
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

# define WIDTH 1920
# define HEIGHT 1080

typedef union color_u
{
	struct
	{
		uint8_t	alpha;
		uint8_t	blue; //blue
		uint8_t	green; //gruuun
		uint8_t	red; //rot
	};
	uint32_t	colors;
}	t_color;

typedef struct s_complex_nums
{
	double			real;
	double			imaginary;
}					t_complex_num;

typedef struct s_pixel
{
	uint32_t		coordinate_x;
	uint32_t		coordinate_y;
	t_complex_num	complex_num;
}					t_pixel;

typedef struct s_image
{
	mlx_image_t		*img;
	t_pixel			*pixels;
}					t_image;

typedef struct s_data
{
	mlx_t			*mlx;
	t_image			*image;
	char			**input;
	double			in_values;
}					t_data;

#endif