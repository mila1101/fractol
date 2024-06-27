/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:34:56 by msoklova          #+#    #+#             */
/*   Updated: 2024/06/26 16:11:31 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbrot(mlx_image_t *img)
{
	int			width;
	int			height;
	int			i;
	int			max_i = 255;
	double		temp;
	t_fractal	m_struct;
	t_fractal	*mand;

	width = 1000;
	height = 1000;
	mand = &m_struct;
	mand->y = 0;
	while (mand->y < height)
	{
		mand->x = 0;
		while (mand->x < width)
		{
			mand->cx = (double)mand->x / width * 3.0 - 2.0;
			mand->cy = (double)mand->y / height * 4.0 - 2.0;
			mand->zx = 0;
			mand->zy = 0;
			i = 0;
			while (mand->zx * mand->zx + mand->zy * mand->zy < 4 && i < max_i)
			{
				temp = mand->zx * mand->zx - mand->zy * mand->zy + mand->cx;
				mand->zy = 2 * mand->zx * mand->zy + mand->cy;
				mand->zx = temp;
				i++;
			}
			pixel_colour(img, mand, i, max_i);
			mand->x++;
		}
		mand->y++;
	}
}


