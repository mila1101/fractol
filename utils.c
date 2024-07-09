/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:14:57 by msoklova          #+#    #+#             */
/*   Updated: 2024/07/09 11:13:19 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void open_window(double re, double im, int flag)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_fractal	*fractal;

	mlx = mlx_init(WIDTH, HEIGHT, "FRACT'OL", false);
	if (!mlx)
		exit (1);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
	{
		mlx_terminate(mlx);
		exit(1);
	}
	fractal = (t_fractal *)malloc(sizeof(t_fractal));
	if (!fractal)
	{
		mlx_delete_image(mlx, img);
		mlx_terminate(mlx);
		exit(1);
    }
	fractal->x_min = -2.0;
	fractal->x_max = 2.0;
	fractal->y_min = -2.0;
	fractal->y_max = 2.0;
	fractal->mlx = mlx;
	if (flag)
		draw_julia(img, re, im, fractal);
	else
		draw_mandelbrot(img, fractal);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_scroll_hook(mlx, &ft_zoom, fractal);
	mlx_loop(mlx);
	free(fractal);
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

//void	mouse(double x, double y, void *param)
//{
//	(void)param;
//	//int button;
//	t_fractal *fractal = NULL;
//	fractal->x_pos = x;
//	fractal->y_pos = y;
//	if (fractal->button == 4)
//	{
//		ft_zoom(0, 1, fractal);
//	}
//	else if (fractal->button == 5)
//	{
//		ft_zoom(0, -1, fractal);
//	}
//	//if (fractal->draw)
//	//{
//	//}
//}

void ft_zoom(double xdelta, double ydelta, void *param)
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
	mlx_get_mouse_pos(fractal->mlx, &fractal->x_pos, &fractal->y_pos);
	if (fractal->x_pos >= 0 && fractal->y_pos >= 0 && fractal->x_pos < (int32_t)WIDTH && fractal->y_pos < (int32_t)HEIGHT)
	{
		x_pos = fractal->x_pos * (fractal->x_max - fractal->x_min) / WIDTH + fractal->x_min;
		y_pos = fractal->y_pos * (fractal->y_max - fractal->y_min) / HEIGHT + fractal->y_min;
	}
	if (ydelta > 0)
	{
		zoom = 0.5;
		puts("zooom ouuut");
	}
	else if (ydelta < 0)
	{
		zoom = 1.5;
		puts("in");
	}
}



