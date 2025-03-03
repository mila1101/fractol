/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:48:04 by msoklova          #+#    #+#             */
/*   Updated: 2024/07/24 14:59:58 by msoklova         ###   ########.fr       */
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
# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_fractal
{
	mlx_t		*mlx;
	int			x;
	int			y;
	double		zx;
	double		zy;
	double		cx;
	double		cy;
	double		x_max;
	double		x_min;
	double		y_max;
	double		y_min;
	int32_t		x_pos;
	int32_t		y_pos;
	int			colour;
	double		zoom;
	bool		draw;
	mlx_image_t	*img;
	int			flg;
	double		re;
	double		im;
}	t_fractal;

typedef struct s_params
{
	double	re;
	double	im;
	int		flag;
}	t_params;

typedef struct s_axis
{
	double	re;
	double	im;
}	t_axis;

mlx_t		*init_mlx_img(mlx_image_t **image);
t_fractal	*init_fractal(mlx_t *mlx, mlx_image_t *image, t_params *params);
void		free_data(t_fractal *fractal, t_params *params);
void		open_window(double re, double im, int flag);
void		update_img(void *param);
void		pixel_colour(mlx_image_t *img, t_fractal *fr,
				int iter, int max_iter);
void		draw_mandelbrot(mlx_image_t *img, t_fractal *mand);
void		draw_julia(mlx_image_t *img, double re,
				double im, t_fractal	*jul);
double		ft_atof(const char *str);
void		mouse_pos(t_fractal *fractal, double *x_pos, double *y_pos);
void		ft_zoom(double deltaX, double deltaY, void *parameters);

#endif
