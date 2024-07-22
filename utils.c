/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:14:57 by msoklova          #+#    #+#             */
/*   Updated: 2024/07/22 11:42:24 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

mlx_t	*init_mlx_img(mlx_image_t **image)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "FRACT'OL", false);
	if (!mlx)
		exit(1);
	*image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!image)
	{
		mlx_terminate(mlx);
		exit(1);
	}
	return (mlx);
}

t_fractal	*init_fractal(mlx_t *mlx, mlx_image_t *image, t_params *params)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)malloc(sizeof(t_fractal));
	if (!fractal)
	{
		mlx_delete_image(mlx, image);
		mlx_terminate(mlx);
		exit(1);
	}
	fractal->x_min = -2.0;
	fractal->x_max = 2.0;
	fractal->y_min = -2.0;
	fractal->y_max = 2.0;
	fractal->mlx = mlx;
	fractal->img = image;
	fractal->flg = params->flag;
	fractal->re = params->re;
	fractal->im = params->im;
	return (fractal);
}

void	free_data(t_fractal *fractal, t_params *params)
{
	free(fractal);
	free(params);
}

void	open_window(double re, double im, int flag)
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_fractal	*fractal;
	t_params	*params;

	params = malloc(sizeof(t_params));
	if (!params)
		return ;
	params->re = re;
	params->im = im;
	params->flag = flag;
	mlx = init_mlx_img(&image);
	fractal = init_fractal(mlx, image, params);
	if (flag)
		draw_julia(image, re, im, fractal);
	else
		draw_mandelbrot(image, fractal);
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
		mlx_close_window(mlx);
	mlx_scroll_hook(mlx, &ft_zoom, fractal);
	mlx_loop_hook(mlx, &update_img, fractal);
	mlx_loop(mlx);
	free_data(fractal, params);
	mlx_delete_image(mlx, image);
	mlx_terminate(mlx);
}

void	update_img(void *param)
{
	t_fractal	*fractal;
	mlx_t		*mlx;

	fractal = (t_fractal *)param;
	mlx = fractal->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (fractal->draw)
	{
		if (fractal->flg)
			draw_julia(fractal->img, fractal->re, fractal->im, fractal);
		else
			draw_mandelbrot(fractal->img, fractal);
		mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
		fractal->draw = false;
	}
	fractal->draw = false;
}
