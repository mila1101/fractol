/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:48:04 by msoklova          #+#    #+#             */
/*   Updated: 2024/06/25 15:43:18 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <MLX42/MLX42.h>

typedef struct s_fractal
{
	mlx_t	*mlx;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		colour;
}	t_fractal;


void	open_window();
void	draw_mandelbrot(mlx_image_t *img);
void	pixel_colour(mlx_image_t *img, t_fractal *fractal, int iter, int max_iter);

#endif
