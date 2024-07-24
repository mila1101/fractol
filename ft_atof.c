/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:30:17 by msoklova          #+#    #+#             */
/*   Updated: 2024/07/24 15:00:02 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	atof_int(const char *str, int *i)
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

static double	atof_dec(const char *str, int *i)
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
	int		i;
	int		sign;
	double	num;

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
