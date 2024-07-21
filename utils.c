/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:14:57 by msoklova          #+#    #+#             */
/*   Updated: 2024/07/21 17:12:30 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void open_window(double re, double im, int flag)
//{
//	mlx_t		*mlx;
//	mlx_image_t	*image;
//	t_fractal	*fractal;

//	mlx = mlx_init(WIDTH, HEIGHT, "FRACT'OL", false);
//	if (!mlx)
//		exit (1);
//	image = mlx_new_image(mlx, WIDTH, HEIGHT);
//	if (!image)
//	{
//		mlx_terminate(mlx);
//		exit(1);
//	}
//	fractal = (t_fractal *)malloc(sizeof(t_fractal));
//	if (!fractal)
//	{
//		mlx_delete_image(mlx, image);
//		mlx_terminate(mlx);
//		exit(1);
//	}
//	fractal->x_min = -2.0;
//	fractal->x_max = 2.0;
//	fractal->y_min = -2.0;
//	fractal->y_max = 2.0;
//	fractal->mlx = mlx;
//	fractal->img = image;
//	fractal->flg = flag;
//	fractal->re = re;
//	fractal->im = im;
//	if (flag)
//		draw_julia(image, re, im, fractal);
//	else
//		draw_mandelbrot(image, fractal);
//	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
//		mlx_close_window(mlx);
//	mlx_scroll_hook(mlx, &ft_zoom, fractal);
//	mlx_loop_hook(mlx, &update_img, fractal);
//	mlx_loop(mlx);
//	free(fractal);
//	mlx_delete_image(mlx, image);
//	mlx_terminate(mlx);
//}

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
		// mlx_delete_image(fractal->mlx, fractal->img);
		if (fractal->flg)
			draw_julia(fractal->img, fractal->re, fractal->im, fractal);
		else
			draw_mandelbrot(fractal->img, fractal);
		mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
		fractal->draw = false;
	}
	fractal->draw = false;
}

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

double	atof_int(const char *str, int *i)
{
	double	num;

	num = 0.0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		num = (num * 10) + (str[*i] - '0');
		(*i)++;
	}
	return (num);
}

double	atof_dec(const char *str, int *i)
{
	double	num;
	double	div;

	num = 0.0;
	div = 1.0;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			num = (num * 10) + (str[*i] - '0');
			div *= 10.0;
			(*i)++;
		}
	}
	return (num / div);
}

double	ft_atof(const char *str)
{
	int i;
	int sign;
	double num;

	i = 0;
	sign = 1;
	num = 0.0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	num = atof_int(str, &i);
	num += atof_dec(str, &i);

	return (sign * num);
}

//double	ft_atof(const char *str)
//{
//	int		i;
//	int		sign;
//	double	num;
//	double	div;

//	i = 0;
//	sign = 1;
//	num = 0.0;
//	div = 1.0;
//	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
//		i++;
//	if (str[i] == '-')
//	{
//		sign = -1;
//		i++;
//	}
//	else if (str[i] == '+')
//		i++;
//	while (str[i] >= '0' && str[i] <= '9')
//	{
//		num = (num * 10) + (str[i] - '0');
//		i++;
//	}
//	if (str[i] == '.')
//	{
//		i++;
//		while (str[i] >= '0' && str[i] <= '9')
//		{
//			num = (num * 10) + (str[i] - '0');
//			div *= 10.0;
//			i++;
//		}
//	}
//	return (sign * (num / div));
//}

// void	mouse(double x, double y, void *param)
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
	mlx_get_mouse_pos(fractal->mlx, &fractal->x_pos, &fractal->y_pos);
	if (fractal->x_pos >= 0 && fractal->y_pos >= 0
		&& fractal->x_pos < (int32_t)WIDTH && fractal->y_pos < (int32_t)HEIGHT)
	{
		x_pos = fractal->x_pos * (fractal->x_max - fractal->x_min) / WIDTH
			+ fractal->x_min;
		y_pos = fractal->y_pos * (fractal->y_max - fractal->y_min) / HEIGHT
			+ fractal->y_min;
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
