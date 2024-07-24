/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:37:41 by msoklova          #+#    #+#             */
/*   Updated: 2024/07/24 15:00:40 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_colour(mlx_image_t *img, t_fractal *fr, int iter, int max_iter)
{
	int	red;
	int	blue;
	int	green;

	red = 0;
	blue = 0;
	green = 0;
	if (iter == max_iter)
		fr->colour = 0x000000;
	else
	{
		red = sin(0.3 * (double)iter) * 127 + 128;
		green = sin(0.3 * (double)iter + 2) * 127 + 128;
		blue = sin(0.3 * (double)iter + 4) * 127 + 128;
	}
	fr->colour = (red << 24) | (green << 16) | (blue << 8) | 0xFF;
	mlx_put_pixel(img, fr->x, fr->y, fr->colour);
}
