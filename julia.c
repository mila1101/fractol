/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:34:50 by msoklova          #+#    #+#             */
/*   Updated: 2024/07/20 15:57:34 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//void	draw_julia(mlx_image_t *img, double re, double im, t_fractal *jul)
//{
//	int			i;
//	int			max_i;
//	double		temp;

//	max_i = 255;
//	jul->y = 0;
//	jul->cx = re;
//	jul->cy = im;
//	while (jul->y < HEIGHT)
//	{
//		jul->x = 0;
//		while (jul->x < WIDTH)
//		{
//			jul->zx = jul->x_min + (double)jul->x
//					/ WIDTH * (jul->x_max - jul->x_min);
//			jul->zy = jul->y_min + (double)jul->y
//					/ HEIGHT * (jul->y_max - jul->y_min);
//			i = 0;
//			while (jul->zx * jul->zx + jul->zy * jul->zy < 4 && i < max_i)
//			{
//				temp = jul->zx * jul->zx - jul->zy * jul->zy + jul->cx;
//				jul->zy = 2 * jul->zx * jul->zy + jul->cy;
//				jul->zx = temp;
//				i++;
//			}
//			pixel_colour(img, jul, i, max_i);
//			jul->x++;
//		}
//		jul->y++;
//	}
//}

void	calculate_julia(mlx_image_t *img, t_fractal *jul, int i, t_axis params)
{
	int		max_i;
	double	temp;

	max_i = 255;
	jul->zx = jul->x_min + (double)jul->x
		/ WIDTH * (jul->x_max - jul->x_min);
	jul->zy = jul->y_min + (double)jul->y
		/ HEIGHT * (jul->y_max - jul->y_min);
	i = 0;
	while (jul->zx * jul->zx + jul->zy * jul->zy < 4 && i < max_i)
	{
		temp = jul->zx * jul->zx - jul->zy * jul->zy + params.re;
		jul->zy = 2 * jul->zx * jul->zy + params.im;
		jul->zx = temp;
		i++;
	}
	pixel_colour(img, jul, i, max_i);
}

void	draw_julia(mlx_image_t *img, double re, double im, t_fractal *jul)
{
	int		i;
	t_axis	params;

	i = 0;
	jul->y = 0;
	jul->cx = re;
	jul->cy = im;
	params.re = jul->cx;
	params.im = jul->cy;
	while (jul->y < HEIGHT)
	{
		jul->x = 0;
		while (jul->x < WIDTH)
		{
			calculate_julia(img, jul, i, params);
			jul->x++;
		}
		jul->y++;
	}
}
