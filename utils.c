/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:14:57 by msoklova          #+#    #+#             */
/*   Updated: 2024/07/09 15:43:43 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void open_window(double re, double im, int flag)
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_fractal	*fractal;

	mlx = mlx_init(WIDTH, HEIGHT, "FRACT'OL", false);
	if (!mlx)
		exit (1);
	image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!image)
	{
		mlx_terminate(mlx);
		exit(1);
	}
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
	fractal->flg = flag;
	fractal->re = re;
	fractal->im = im;
	if (flag)
		draw_julia(image, re, im, fractal);
	else
		draw_mandelbrot(image, fractal);
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_scroll_hook(mlx, &ft_zoom, fractal);
	mlx_loop_hook(mlx, &update_img, fractal);
	mlx_loop(mlx);
	free(fractal);
	mlx_delete_image(mlx, image);
	mlx_terminate(mlx);
}

void update_img(void *param)
{
	t_fractal *fractal = (t_fractal *)param;

	if (fractal->draw)
	{
		//mlx_delete_image(fractal->mlx, fractal->img);
		if (fractal->flg)
			draw_julia(fractal->img, fractal->re, fractal->im, fractal);
		else
			draw_mandelbrot(fractal->img, fractal);
		mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
		fractal->draw = false;
	}
	fractal->draw = false;
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
		puts("in");
	}
	else if (ydelta < 0)
	{
		zoom = 1.5;
		puts("zooom ouuut");
	}
	else
		return ;
	fractal->x_min = x_pos + ((fractal->x_min - x_pos) * zoom);
	fractal->x_max = x_pos + ((fractal->x_max - x_pos) * zoom);
	fractal->y_min = y_pos + ((fractal->y_min - y_pos) * zoom);
	fractal->y_max = y_pos + ((fractal->y_max - y_pos) * zoom);

	fractal->draw = true;
}



