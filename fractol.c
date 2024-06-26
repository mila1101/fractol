/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:48:00 by msoklova          #+#    #+#             */
/*   Updated: 2024/06/24 11:15:14 by msoklova         ###   ########.fr       */
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
	if (argc < 2)
		correct_use();
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
	{
		write(1, "M\n", 2);
		open_window();
	}
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
	{
		write(1, "J\n", 2);
		open_window();
	}
	else
		correct_use();
	return (0);
}
