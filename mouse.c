/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:28:26 by msoklova          #+#    #+#             */
/*   Updated: 2024/07/22 11:28:42 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mouse_pos(t_fractal *fractal, double *x_pos, double *y_pos)
{
	mlx_get_mouse_pos(fractal->mlx, &fractal->x_pos, &fractal->y_pos);
	if (fractal->x_pos >= 0 && fractal->y_pos >= 0
		&& fractal->x_pos < (int32_t)WIDTH && fractal->y_pos < (int32_t)HEIGHT)
	{
		*x_pos = fractal->x_pos * (fractal->x_max - fractal->x_min) / WIDTH
			+ fractal->x_min;
		*y_pos = fractal->y_pos * (fractal->y_max - fractal->y_min) / HEIGHT
			+ fractal->y_min;
	}
}

void	ft_zoom(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;
	double		zoom;
	double		x_pos;
	double		y_pos;

	(void)xdelta;
	zoom = 0;
	x_pos = 0;
	y_pos = 0;
	fractal = (t_fractal *)param;
	if (ydelta > 0)
		zoom = 0.5;
	else if (ydelta < 0)
		zoom = 1.5;
	else
		return ;
	mouse_pos(fractal, &x_pos, &y_pos);
	fractal->x_min = x_pos + ((fractal->x_min - x_pos) * zoom);
	fractal->x_max = x_pos + ((fractal->x_max - x_pos) * zoom);
	fractal->y_min = y_pos + ((fractal->y_min - y_pos) * zoom);
	fractal->y_max = y_pos + ((fractal->y_max - y_pos) * zoom);
	fractal->draw = true;
}
