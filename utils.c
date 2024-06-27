/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:14:57 by msoklova          #+#    #+#             */
/*   Updated: 2024/06/27 13:31:54 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void open_window(double re, double im, int flag)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(1000, 1000, "FRACT'OL", false);
	if (!mlx)
		exit (1);
	img = mlx_new_image(mlx, 1000, 1000);
	if (flag)
		draw_julia(img, re, im);
	else
		draw_mandelbrot(img);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
}

void	pixel_colour(mlx_image_t *img, t_fractal *fractal, int iter, int max_iter)
{
	int	red = 0;
	int blue = 0;
	int green = 0;

	if (iter == max_iter)
		fractal->colour = 0x000000;
	else
	{
		red = sin(0.3 * (double)iter) * 127 + 128;
		green = sin(0.3 * (double)iter + 2) * 127 + 128;
		blue = sin(0.3 * (double)iter + 4) * 127 + 128;
	}
	fractal->colour = (red << 24) | (green << 16) | (blue << 8) | 0xFF;
	mlx_put_pixel(img, fractal->x, fractal->y, fractal->colour);
}


double	ft_atof(const char *str)
{
	int		i;
	int		sign;
	double	num;
	double	div;

	i = 0;
	sign = 1;
	num = 0.0;
	div = 1.0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			num = (num * 10) + (str[i] - '0');
			div *= 10.0;
			i++;
		}
	}
	return (sign * (num / div));
}

