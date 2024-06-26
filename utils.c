/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:14:57 by msoklova          #+#    #+#             */
/*   Updated: 2024/06/25 15:44:55 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void open_window(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(1000, 1000, "FRACT'OL", false);
	if (!mlx)
		exit (1);
	img = mlx_new_image(mlx, 1000, 1000);
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
