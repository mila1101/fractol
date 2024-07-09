/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:48:04 by msoklova          #+#    #+#             */
/*   Updated: 2024/07/09 14:14:44 by msoklova         ###   ########.fr       */
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


#define WIDTH 1000
#define HEIGHT 1000

typedef struct s_fractal
{
	mlx_t	*mlx;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	x_max;
	double	x_min;
	double	y_max;
	double	y_min;
	int32_t	x_pos;
	int32_t	y_pos;
	int		colour;
	double	zoom;
	bool	draw;
	mlx_image_t	*img;
	int		flg;
	double	re;
	double	im;
}	t_fractal;


void	open_window();
//void	draw_mandelbrot(mlx_image_t *img);
void draw_mandelbrot(mlx_image_t *img, t_fractal *mand);
void	pixel_colour(mlx_image_t *img, t_fractal *fractal, int iter, int max_iter);
//void	draw_julia(mlx_image_t *img, double re, double im);
void	draw_julia(mlx_image_t *img, double re, double im, t_fractal	*jul);
double	ft_atof(const char *str);
//void	mouse(double x, double y, void *param);
void 	ft_zoom(double deltaX, double deltaY, void *parameters);
void update_img(void *param);

#endif
