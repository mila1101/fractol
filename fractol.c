/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:48:00 by msoklova          #+#    #+#             */
/*   Updated: 2024/07/22 15:42:37 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	correct_use(void)
{
	write(1, "\nHow to use:\n", 13);
	write(1, "	./fractol mandelbrot\n", 22);
	write(1, "or:\n", 4);
	write(1, "	./fractol julia [number] [number]\n", 35);
	write(1, "\nsome [number] combination examples:\n", 37);
	write(1, "				-0.75 0.11\n", 15);
	write(1, "				-0.8 0.156\n", 15);
	write(1, "				0.258 0.01\n", 15);
	write(1, "				0.355 0.355\n", 16);
	exit(1);
}

int	main(int argc, char **argv)
{
	double	re;
	double	im;

	re = 0.0;
	im = 0.0;
	if (argc < 2)
		correct_use();
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		open_window(0.0, 0.0, 0);
	else if (ft_strncmp(argv[1], "julia", 5) == 0 && argc == 4)
	{
		re = ft_atof(argv[2]);
		im = ft_atof(argv[3]);
		open_window(re, im, 1);
	}
	else
		correct_use();
	return (0);
}
