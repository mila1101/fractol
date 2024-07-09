/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:48:00 by msoklova          #+#    #+#             */
/*   Updated: 2024/06/27 15:02:04 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	correct_use(void)
{
	write(1, "\nHow to use:\n", 13);
	write(1, "	./fractol [julia/mandelbrot] [optional params]\n\n", 50);
	exit(1);
}

int	main(int argc, char **argv)
{
	double re = 0.0;
	double im = 0.0;

	if (argc < 2)
		correct_use();
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
	{
		//write(1, "M\n", 2);
		open_window(0.0, 0.0, 0);
	}
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
	{
		re = ft_atof(argv[2]);
		im = ft_atof(argv[3]);
		//write(1, "J\n", 2);
		open_window(re, im, 1);
	}
	else
		correct_use();
	return (0);
}
