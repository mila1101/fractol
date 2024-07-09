/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:34:50 by msoklova          #+#    #+#             */
/*   Updated: 2024/07/08 15:35:06 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(mlx_image_t *img, double re, double im, t_fractal	*jul)
{
	//int			width;
	//int			height;
	int			i;
	int			max_i = 255;
	double		temp;
	//t_fractal	j_struct;
	//t_fractal	*jul;

	//jul = &j_struct;
	jul->y = 0;
	jul->cx = re;
	jul->cy = im;
	while (jul->y < HEIGHT)
	{
		jul->x = 0;
		while (jul->x < WIDTH)
		{
			jul->zx = (double)jul->x / WIDTH * 3.0 - 1.5;
			jul->zy = (double)jul->y / HEIGHT * 3.0 - 1.5;
			i = 0;
			while (jul->zx * jul->zx + jul->zy * jul->zy < 4 && i < max_i)
			{
				temp = jul->zx * jul->zx - jul->zy * jul->zy + jul->cx;
				jul->zy = 2 * jul->zx * jul->zy + jul->cy;
				jul->zx = temp;
				i++;
			}
			pixel_colour(img, jul, i, max_i);
			jul->x++;
		}
		jul->y++;
	}
}
